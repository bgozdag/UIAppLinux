#include "zmqhandler.h"
#include "string.h"
#include "qdebug.h"
#include "utils/headers/stringutils.h"

ZmqHandler::ZmqHandler(QObject* parent) : QObject(parent), std::thread(&ZmqHandler::run, this)
{
    outgoingMessageQueue.reserve(10);
}

void ZmqHandler::addToQueue(std::string message)
{
    outgoingMessageQueueLock.lock();
    outgoingMessageQueue.push_back(message);
    outgoingMessageQueueLock.unlock();
}

void ZmqHandler::run()
{
    void* context = zmq_ctx_new();
    void* zmqSocket = zmq_socket(context, ZMQ_DEALER);
    zmq_setsockopt(zmqSocket, ZMQ_IDENTITY, id, strlen(id));
    zmq_connect(zmqSocket, "tcp://127.0.0.1:5565");

    zmq_pollitem_t pollItems[1];
    pollItems[0].socket = zmqSocket;
    pollItems[0].events = ZMQ_POLLIN;

    QJsonDocument jsonDoc;
    QJsonObject jsonObj;
    QString parameter;
    while(true){
        zmq_poll(pollItems, 1, 500);
        if (pollItems[0].revents & ZMQ_POLLIN)
        {
            int size = zmq_recv(zmqSocket, data, BUFFER_SIZE, 0);
            data[size] = 0; // Null termination
            qDebug() << "data received: " << data;
            jsonDoc = QJsonDocument::fromJson(data);
            jsonObj = jsonDoc.object();
            handleCommand(jsonObj);
        }
        outgoingMessageQueueLock.lock();
        for (std::string outgoingMessage : outgoingMessageQueue)
        {
            zmq_send(zmqSocket, outgoingMessage.c_str(), outgoingMessage.size(), 0);
            qDebug() << "data sent: " << outgoingMessage.c_str();
        }
        outgoingMessageQueue.clear();
        outgoingMessageQueueLock.unlock();
    }
}

void ZmqHandler::handleCommand(const QJsonObject & jsonObj)
{
    QString command = jsonObj["command"].toString();

    if (command == "UI_ScreenChangeEvent")
    {
        emit changeScreenSignal(jsonObj["screenId"].toInt(), jsonObj["connectorId"].toInt());
    } else if (command == "UI_ErrorDialogEvent")
    {
        emit showErrorDialogSignal(jsonObj["errorId"].toInt());
    } else if (command == "UI_StateChangedEvent") {
        std::vector<UnavailableReason::UnavailableReason> unavailableReasonVector = std::vector<UnavailableReason::UnavailableReason>();
        QJsonArray unavailableReasons = jsonObj["unavailableReasons"].toArray();
        for (auto reason : unavailableReasons) {
            int reasonValue = reason.toInt();
            unavailableReasonVector.push_back((UnavailableReason::UnavailableReason) reasonValue);
        }

        emit stateChangedSignal(static_cast<unsigned int>(jsonObj["connectorId"].toInt()),
                jsonObj["inUse"].toBool(),
                jsonObj["charging"].toBool(),
                jsonObj["reserved"].toBool(),
                jsonObj["initializing"].toBool(),
                jsonObj["faulted"].toBool(),
                jsonObj["unavailable"].toBool(),
                jsonObj["chargeProgressing"].toBool(),
                unavailableReasonVector,
                FaultReason::getFaultReasonFromId(jsonObj["faultReason"].toInt()));
    } else if (command == "UIVisual_MeterValueEvent")
    {
        emit meterValueSignal(static_cast<unsigned int>(jsonObj["connectorId"].toInt()),
                jsonObj["energy"].toDouble(),
                jsonObj["power"].toDouble(),
                jsonObj["percentage"].toInt(),
                jsonObj["remainingTime"].toInt());
    } else if (command == "UIVisual_ClearMeterValueEvent")
    {
        emit clearMeterValueSignal(static_cast<unsigned int>(jsonObj["connectorId"].toInt()));
    }
    else if (command == "WebUI_ChangeUILanguageRequest")
    {
        Language language = (Language)jsonObj["languageId"].toInt();
        emit changeLanguageSignal(language, true);
    } else if (command == "GetDeviceStateResponse")
    {
        QJsonObject deviceStatesJsonObject = QJsonDocument::fromJson(jsonObj["deviceStateConfigs"].toString().toStdString().c_str()).object();
        qDebug() << "UIVisual - HMI Software Version Received = " << deviceStatesJsonObject["hmiSoftwareVersion"].toString();

        QJsonObject boardSoftwareVersionsJsonObject = deviceStatesJsonObject["boardVersions"].toObject();
        QString powerBoardVersion = "";
        if (!boardSoftwareVersionsJsonObject.isEmpty()) {
            if (boardSoftwareVersionsJsonObject.contains("ACCT")) {
                QJsonArray acctVersions = boardSoftwareVersionsJsonObject["ACCT"].toArray();
                for (short int i = 0; i < acctVersions.count(); i++) {
                    powerBoardVersion += acctVersions.at(i).toObject().value("version").toString();
                    if (i < acctVersions.count()-1) {
                        powerBoardVersion += "_";
                    }
                }
            } else {
                QJsonArray ctbVersions = boardSoftwareVersionsJsonObject["CTB"].toArray();
                for (short int i = 0; i < ctbVersions.count(); i++) {
                    powerBoardVersion += ctbVersions.at(i).toObject().value("version").toString();
                    if (i < ctbVersions.count()-1) {
                        powerBoardVersion += "_";
                    }
                }

                QJsonArray ccsBoardVersions = boardSoftwareVersionsJsonObject["CCS_BOARD"].toArray();
                for (short int i = 0; i < ccsBoardVersions.count(); i++) {
                    powerBoardVersion += "_";
                    powerBoardVersion += ccsBoardVersions.at(i).toObject().value("version").toString();
                }
            }
        }
        qDebug() << "UIVisual - Power Board Version Received = " << powerBoardVersion;

        emit deviceStateReceivedSignal(deviceStatesJsonObject["hmiSoftwareVersion"].toString() + " / " + powerBoardVersion);
    } else if (command == "UIVisual_DisplayLogoChangedEvent")
    {
        emit logoUpdatedSignal();
    } else if (command == "PreBootCompletedEvent")
    {
        QJsonObject vfactoryJsonObject = QJsonDocument::fromJson(jsonObj["vfactory"].toString().toStdString().c_str()).object();
        if(vfactoryJsonObject.isEmpty())
        {
            qDebug() << "Vfactory is null";
            return;
        }
        QJsonObject innerVfactoryJsonObject = vfactoryJsonObject.value("vfactory").toObject();
        std::string projectType = innerVfactoryJsonObject["chargePointModel"].toString().toStdString();
        emit projectTypeCodeReceivedSignal(projectType);
        QString brand = innerVfactoryJsonObject["brand"].toString();
        emit brandReceivedSignal(brand);

        QJsonObject evseConfigsJsonObject = QJsonDocument::fromJson(jsonObj["evseConfigs"].toString().toStdString().c_str()).object();
        if(evseConfigsJsonObject.isEmpty())
        {
            qDebug() << "EvseConfigs is null";
            return;
        }

        QJsonObject jsonObject = evseConfigsJsonObject.value("Other").toObject();
        Language language = (Language)jsonObject["defaultLanguage"].toInt();
        emit changeDefaultLanguageSignal(language);

        std::string serviceContactInfo = jsonObject["serviceContactInfo"].toString().toStdString();
        emit serviceContactInfoReceivedSignal(serviceContactInfo);

        QStringList dimensionList = jsonObject["displayLogoDimension"].toString().split("X");
        emit displayLogoDimensionReceivedSignal(dimensionList[0].toInt(), dimensionList[1].toInt());

        jsonObject = evseConfigsJsonObject.value("ConnectorConfigs").toObject();
        std::string connectorTypes = jsonObject["connectorTypes"].toString().toStdString();
        std::string connectorMaxPowers = jsonObject["connectorMaxPowers"].toString().toStdString();
        emit connectorConfigurationSignal(connectorTypes, connectorMaxPowers);

        QJsonObject displayLogoJsonObject = evseConfigsJsonObject.value("DisplayLogo").toObject();
        emit logoVisibilityReceivedSignal(displayLogoJsonObject["leftLogo"].toBool(), displayLogoJsonObject["rightLogo"].toBool());

        jsonObject = evseConfigsJsonObject.value("OCPP").toObject();
        std::string chargePointId = jsonObject["ocppChargePointID"].toString().toStdString();
        int operationMode = jsonObject["operationMode"].toInt();
        emit chargePointIdSignal(chargePointId);
        emit operationModeSignal(operationMode);

        jsonObject = evseConfigsJsonObject.value("UI").toObject();
        emit alternativePaymentMethodSignal(jsonObject["alternativePaymentMethod"].toBool());

        jsonObject = evseConfigsJsonObject.value("Other").toObject();
        if (!jsonObject["excludedLanguages"].isNull()) {
            std::vector<std::string> excludedStringLanguages = StringUtils::split(jsonObject["excludedLanguages"].toString().toStdString(), ",");
            std::vector<Language> excludedLanguages;
            for (const auto& excludedLanguage : excludedStringLanguages) {
                if (!excludedLanguage.empty()) {
                    excludedLanguages.push_back((Language) atoi(excludedLanguage.c_str()));
                }
            }
            emit excludedLanguagesReceivedSignal(excludedLanguages);
        }
    } else if (command == "UIVisual_ChangeDisplayLogoVisibilityEvent")
    {
        emit logoVisibilityChangedSignal(jsonObj["leftLogo"].toBool(), jsonObj["rightLogo"].toBool());
    } else if (command == "UIVisual_FirmwareUpdateEvent")
    {
        qDebug() << "Firmware is updating...";
        emit firmwareUpdateSignal();
    } else if (command == "UIVisual_FirmwareUpdateEndedEvent")
    {
        qDebug() << "Firmware updating ended...";
        emit firmwareUpdateEndedSignal();
    } else if (command == "UIVisual_LidErrorEvent") {
        bool lidErrorStatus = jsonObj["lidErrorStatus"].toBool();
        int connectorId = jsonObj["connectorId"].toInt();
        emit lidErrorUpdateSignal(connectorId, lidErrorStatus);
    } else if (command == "UIVisual_BootStateEvent") { // TODO: Event name may be changed.
        emit setInitializingStepSignal(jsonObj["completedBootStep"].toInt(), jsonObj["totalBootStep"].toInt());
    } else if (command == "UIVisual_FirmwareUpgradeProgressEvent") {
        emit firmwareUpdateProgressSignal(jsonObj["deviceType"].toInt(), jsonObj["progress"].toInt(), jsonObj["firmwareUpdateState"].toInt());
    }
}
