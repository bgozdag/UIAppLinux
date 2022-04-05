#ifndef ZMQHANDLER_H
#define ZMQHANDLER_H

#include "zmq.h"
#include <thread>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <mutex>
#include "languagemanager.h"
#include "unavailablereason.h"
#include "faultreason.h"

class ZmqHandler : public QObject, std::thread
{
    Q_OBJECT
public:
    ZmqHandler(QObject* parent);
    void addToQueue(std::string);

private:
    static const int BUFFER_SIZE = 4096;
    char const* id = "UIVisual";
    char data[BUFFER_SIZE];
    std::vector<std::string> outgoingMessageQueue;
    std::mutex outgoingMessageQueueLock;
    void run();
    void handleCommand(const QJsonObject & jsonObj);

signals:
    void changeScreenSignal(int screenId, int connectorId);
    void showErrorDialogSignal(int errorType);
    void stateChangedSignal(unsigned int connectorId, bool inUse, bool charging, bool reserved, bool initializing, bool faulted, bool unavailable, bool chargeProgressing, std::vector<UnavailableReason::UnavailableReason> unavailableReasonVector, FaultReason::FaultReason faultReason);
    void meterValueSignal(unsigned int, double, double, int, int);
    void clearMeterValueSignal(unsigned int);
    void changeLanguageSignal(Language language, bool saveParam);
    void changeDefaultLanguageSignal(Language language);
    void projectTypeCodeReceivedSignal(std::string projectType);
    void serviceContactInfoReceivedSignal(std::string serviceContactInfo);
    void deviceStateReceivedSignal(QString hmiSoftwareVersion);
    void logoUpdatedSignal();
    void logoVisibilityReceivedSignal(bool leftLogoStatus, bool rightLogoStatus);
    void logoVisibilityChangedSignal(bool leftLogoStatus, bool rightLogoStatus);
    void connectorConfigurationSignal(std::string connectorTypes, std::string connectorMaxPowers);
    void displayLogoDimensionReceivedSignal(int width, int height);
    void chargePointIdSignal(std::string chargePointId);
    void brandReceivedSignal(QString brand);
    void firmwareUpdateSignal();
    void firmwareUpdateEndedSignal();
    void lidErrorUpdateSignal(int, bool);
    void setInitializingStepSignal(int completedBootStep, int totalBootStep);
    void operationModeSignal(int operationMode);
    void alternativePaymentMethodSignal(bool);
    void firmwareUpdateProgressSignal(int, int, int);
    void excludedLanguagesReceivedSignal(std::vector<Language> excludedLanguages);
};

#endif // ZMQHANDLER_H
