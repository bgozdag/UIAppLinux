#include "appstylesheets.h"
#include "authscreen.h"
#include "chargeritem.h"
#include "homescreen.h"
#include "innerscreen.h"
#include "languagemanager.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "emergencybuttondialog.h"
#include <model/headers/ac22charger.h>
#include <model/headers/ac43charger.h>
#include <model/headers/ccscharger.h>
#include <model/headers/chademocharger.h>

#include <qboxlayout.h>
#include <qsizepolicy.h>
#include <QDebug>
#include <QFontDatabase>
#include <QGraphicsOpacityEffect>
#include <qprocess.h>

#include "chargingscreen.h"
#include "connectionscreen.h"
#include "disconnectionscreen.h"
#include "evc05homescreen.h"
#include "errorinfo.h"
#include "preparingforchargingscreen.h"
#include "stopchargingscreen.h"
#include "zmq.h"
#include "appreciatescreen.h"
#include "firmwareupdatemessagedialog.h"
#include "dimensions.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <model/headers/schukocharger.h>
#include <languages/generated/appstrings.h>
#include <utils/headers/stringutils.h>
#include <utils/headers/uiutils.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , defaultLanguageTimer(new QTimer())
    , languageDialogTimeoutTimer(new QTimer())
{
    ui->setupUi(this);

    zmqHandler = new ZmqHandler(this);
    connect(zmqHandler, SIGNAL(changeScreenSignal(int, int)), this, SLOT(onScreenChangeEvent(int, int)));
    connect(zmqHandler, SIGNAL(showErrorDialogSignal(int)), this, SLOT(onShowErrorDialogEvent(int)));
    connect(zmqHandler, &ZmqHandler::stateChangedSignal, this, &MainWindow::onStateChangedEvent);
    connect(zmqHandler, &ZmqHandler::meterValueSignal, this, &MainWindow::onMeterValueEvent);
    connect(zmqHandler, &ZmqHandler::clearMeterValueSignal, this, &MainWindow::onClearMeterValueEvent);
    connect(zmqHandler, &ZmqHandler::deviceStateReceivedSignal, this, &MainWindow::onDeviceStateReceived);
    connect(zmqHandler, &ZmqHandler::logoUpdatedSignal, this, &MainWindow::onLogoUpdated);
    connect(zmqHandler, &ZmqHandler::logoVisibilityReceivedSignal, this, &MainWindow::onChangeLogoVisibilityEvent);
    connect(zmqHandler, &ZmqHandler::logoVisibilityChangedSignal, this, &MainWindow::onChangeLogoVisibilityEvent);
    connect(zmqHandler, &ZmqHandler::connectorConfigurationSignal, this, &MainWindow::onConnectorConfigurationReceived);
    connect(zmqHandler, &ZmqHandler::displayLogoDimensionReceivedSignal, this, &MainWindow::onDisplayLogoDimensionReceived);
    connect(zmqHandler, &ZmqHandler::firmwareUpdateSignal, this, &MainWindow::onFirmwareUpdateEvent);
    connect(zmqHandler, &ZmqHandler::firmwareUpdateEndedSignal, this, &MainWindow::onFirmwareUpdateEndedEvent);
    connect(zmqHandler, &ZmqHandler::projectTypeCodeReceivedSignal, this, &MainWindow::projectTypeCodeReceived);
    connect(zmqHandler, &ZmqHandler::serviceContactInfoReceivedSignal, this, &MainWindow::serviceContactInfoReceived);
    connect(zmqHandler, &ZmqHandler::chargePointIdSignal, this, &MainWindow::onChargePointIdReceived);
    connect(zmqHandler, &ZmqHandler::lidErrorUpdateSignal, this, &MainWindow::onLidErrorUpdated);
    connect(zmqHandler, &ZmqHandler::setInitializingStepSignal, this, &MainWindow::setInitializingProgressBarBootStepWidth);
    connect(zmqHandler, &ZmqHandler::operationModeSignal, this, &MainWindow::onOperationModeReceived);
    connect(zmqHandler, &ZmqHandler::brandReceivedSignal, this, &MainWindow::onBrandReceived);

    qRegisterMetaType<Language>("Language");
    qRegisterMetaType<std::string>("std::string");
    qRegisterMetaType<std::vector<Language>>("std::vector<Language>");
    qRegisterMetaType<std::vector<UnavailableReason::UnavailableReason>>("std::vector<UnavailableReason::UnavailableReason>");
    qRegisterMetaType<FaultReason::FaultReason>("FaultReason::FaultReason");
    connect(zmqHandler, &ZmqHandler::changeLanguageSignal, this, &MainWindow::changeLanguage);
    connect(zmqHandler, &ZmqHandler::changeDefaultLanguageSignal, this, &MainWindow::changeDefaultLanguage);
    connect(zmqHandler, &ZmqHandler::alternativePaymentMethodSignal, this, &MainWindow::setVisibilityAlternativePaymentMethod);
    connect(zmqHandler, &ZmqHandler::excludedLanguagesReceivedSignal, this, &MainWindow::onExcludedLanguagesReceived);

    languageIdSetting = new PersistentSettings(LANGUAGE_SETTING_PATH);
    if (languageIdSetting->isKeyExist(languageKey))
    {
        setDefaultLanguageFromCache();
    }
    onLanguageChanged();
    initializeUiElements();
    initializeCursorWidget(false); // TODO : May need to tie this to a configuration, in case it's needed in the future.
    AppStyleSheets::getInstance()->loadStylesheets();

    initializationDialog = new InitializeMessageDialog(this);
    initializationDialog->show();
    hideHomeCancelButton(false, true);

    uptimeTimer.start();
    ui->language_button->setAttribute(Qt::WA_TransparentForMouseEvents); // This is set so that the whole background container can handle touch.
    displayExternalLogosIfFound();
    defaultLanguageTimer->setSingleShot(true);
    defaultLanguageTimer->connect(defaultLanguageTimer, &QTimer::timeout, [this]() {
        onDefaultLanguageTimeout();
    });

    languageDialogTimeoutTimer->setSingleShot(true);
    languageDialogTimeoutTimer->connect(languageDialogTimeoutTimer, &QTimer::timeout, [this]() {
        onLanguageDialogTimeout();
    });

    ui->home_button_clicked->setVisible(false);
    ui->language_button_background_clicked->setVisible(false);
    ui->cancel_button_clicked->setVisible(false);

    ui->topNotificationBar->setCustomStyleSheet(AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::INNER_SCREEN_NOTIFICATION_OUT_OF_ORDER));
    ui->topNotificationBar->setVisible(false);
    connect(ui->topNotificationBar, &TopNotificationBar::onClickedNotificationBarSignal, this, &MainWindow::notificationBarClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::event(QEvent* event)
{
    if (event->type() == QEvent::HoverMove) {
        sendScreenActivityEvent();
        QHoverEvent * hoverEvent = static_cast<QHoverEvent *>(event);
        if (cursor_widget != nullptr) {
            cursor_widget->move(hoverEvent->pos().x() - cursor_widget->width()/2, hoverEvent->pos().y() - cursor_widget->height()/2);
        }
    }

    return QWidget::event(event);
}

void MainWindow::initializeUiElements()
{
    QFontDatabase::addApplicationFont(":/assets/fonts/mulisemibold.ttf");
    QFontDatabase::addApplicationFont(":/assets/fonts/mulibold.ttf");
    QFontDatabase::addApplicationFont(":/assets/fonts/muliblack.ttf");
    setStyleSheet(".QLabel {font-family: 'Muli SemiBold'}");
    ui->left_logo->setVisible(leftLogoStatus);
    ui->right_logo->setVisible(rightLogoStatus);

    connect(ui->home_button_container, SIGNAL(clickedSignal()), this, SLOT(onHomeButtonClicked()));
    connect(ui->language_button_container, SIGNAL(clickedSignal()), this, SLOT(onLanguageButtonClicked()));
}

void MainWindow::setupBrand(QString brand)
{
    qDebug() << "MainWindow " <<  brand << endl;
}

void MainWindow::changeScreen(Screen * screen)
{
    // Refresh bottom buttons, they are all displayed by default.
    hideHomeCancelButton(false, true);
    ui->language_button_container->show();
    showCustomerLogo(rightLogoStatus);
    showVestelLogo(leftLogoStatus);
    showStationWideFault();

    if (initializationDialog != nullptr) {
        initializationDialog->setDeleteOnClose(false);
        initializationDialog->close();
        initializationDialog->deleteLater();
        initializationDialog = nullptr;
        sendDeviceStateRequest(); // Once the initialization dialog is no longer needed, we can request device state safely.
    }

    if (currentScreen != nullptr) {
        currentScreen->hide();
        currentScreen->deleteLater();
    }

    connect(this, &MainWindow::languageChangedSignal, screen, &Screen::onLanguageChanged);
    currentScreen = screen;
    currentScreen->setupUi(this);
    currentScreen->onLanguageChanged();
    currentScreen->setupBrand(brand);
    currentScreen->show();

    ui->footer->raise();
    ui->right_logo->raise();
    ui->left_logo->raise();
    ui->topNotificationBar->raise();
    if (cursor_widget != nullptr) {
        cursor_widget->raise();
    }

    ui->home_button_clicked->setVisible(false);
}

void MainWindow::changeDefaultLanguage(Language language) {
    defaultLanguage = language;
    changeLanguage(defaultLanguage, true);
}

void MainWindow::changeLanguage(Language language, bool saveParam)
{
    const std::lock_guard<std::mutex> lock(languageDialogLock);
    LanguageManager::getInstance()->changeLanguage(language);

    if (saveParam == true)
    {
        languageIdSetting->setInt(languageKey, LanguageManager::getInstance()->getLanguageIndex());
    }
    emit languageChangedSignal();

    if (languageMessageDialog) {
        languageMessageDialog->close();
        languageMessageDialog->deleteLater();
        languageMessageDialog = nullptr;
        languageDialogTimeoutTimer->stop();
    }

    switch (language) {
        case Language::ENGLISH:
            ui->language_button->setObjectName(QStringLiteral("english_small_button"));
            break;
        case Language::TURKISH:
            ui->language_button->setObjectName(QStringLiteral("turkish_small_button"));
            break;
        case Language::HEBREW:
            ui->language_button->setObjectName(QStringLiteral("hebrew_small_button"));
            break;
        case Language::CZECH:
            ui->language_button->setObjectName(QStringLiteral("czech_small_button"));
            break;
        case Language::DANISH:
            ui->language_button->setObjectName(QStringLiteral("danish_small_button"));
            break;
        case Language::GERMAN:
            ui->language_button->setObjectName(QStringLiteral("german_small_button"));
            break;
        case Language::SPANISH:
            ui->language_button->setObjectName(QStringLiteral("spanish_small_button"));
            break;
        case Language::FINNISH:
            ui->language_button->setObjectName(QStringLiteral("finnish_small_button"));
            break;
        case Language::FRENCH:
            ui->language_button->setObjectName(QStringLiteral("french_small_button"));
            break;
        case Language::HUNGARIAN:
            ui->language_button->setObjectName(QStringLiteral("hungarian_small_button"));
            break;
        case Language::ITALIAN:
            ui->language_button->setObjectName(QStringLiteral("italian_small_button"));
            break;
        case Language::NORWEGIAN:
            ui->language_button->setObjectName(QStringLiteral("norwegian_small_button"));
            break;
        case Language::POLISH:
            ui->language_button->setObjectName(QStringLiteral("polish_small_button"));
            break;
        case Language::ROMANIAN:
            ui->language_button->setObjectName(QStringLiteral("romanian_small_button"));
            break;
        case Language::SLOVAKIAN:
            ui->language_button->setObjectName(QStringLiteral("slovakian_small_button"));
            break;
        case Language::SWEDISH:
            ui->language_button->setObjectName(QStringLiteral("swedish_small_button"));
            break;
    }

    onLanguageChanged();

    string languageStylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::LANGUAGES);
    UIUtils::updateStyleSheet(ui->language_button, languageStylesheet.c_str());
    updateDefaultLanguageTimer();
}

void MainWindow::setDefaultLanguageFromCache()
{
    defaultLanguage = (Language)languageIdSetting->getInt(languageKey);
    LanguageManager::getInstance()->changeLanguage(defaultLanguage);
    languageIdSetting->setInt(languageKey, LanguageManager::getInstance()->getLanguageIndex());
}

void MainWindow::onDefaultLanguageTimeout() {
    qDebug() << "Default language timeout detected! Reverting display language to default";
    changeLanguage(defaultLanguage, true);
}

void MainWindow::onLanguageDialogTimeout() {
    const std::lock_guard<std::mutex> lock(languageDialogLock);
    qDebug() << "Language dialog timeout! Closing language dialog.";
    if (languageMessageDialog) {
        languageMessageDialog->close();
        languageMessageDialog->deleteLater();
        languageMessageDialog = nullptr;
    }
}

void MainWindow::updateDefaultLanguageTimer() {
    if (LanguageManager::getInstance()->getCurrentLanguage() != defaultLanguage) {
        qDebug() << "Restarting default language timeout with" << DEFAULT_LANGUAGE_TIMEOUT << "milliseconds!";
        defaultLanguageTimer->start(DEFAULT_LANGUAGE_TIMEOUT);
    } else {
        qDebug() << "Default language timeout stopped!";
        defaultLanguageTimer->stop();
    }
}

void MainWindow::onExcludedLanguagesReceived(std::vector<Language> excludedLanguages)
{
    this->excludedLanguages = excludedLanguages;
}

void MainWindow::notificationBarClicked()
{
    if (stationWideFault == FaultReason::EMERGENCY_BUTTON_ERROR) {
        EmergencyButtonDialog* emergencyButtonDialog = new EmergencyButtonDialog(this); // WA_DeleteOnClose is set, no need to delete manually.
        emergencyButtonDialog->show();
    }
}

void MainWindow::onOperationModeReceived(int operationMode)
{
    if (operationMode >= 0 && operationMode < OperationMode::COUNT) {
        this->operationMode = (OperationMode) operationMode;
        qDebug() << "Operation Mode : " << this->operationMode;
    } else {
        qDebug() << "Unexpected Operation Mode received : " << operationMode;
    }
}

void MainWindow::onChargePointIdReceived(std::string chargePointId)
{
    this->chargePointId = chargePointId;
}

void MainWindow::projectTypeCodeReceived(std::string projectType)
{
    setProjectEnumType(projectType);
}

void MainWindow::serviceContactInfoReceived(std::string serviceContactInfo)
{
    this->serviceContact = serviceContactInfo;
}

void MainWindow::setProjectEnumType(std::string projectType)
{
    if ((QString::fromStdString(projectType).toLower()).toStdString().compare("evc05") == 0)
    {
        currentProjectType = ProjectType::Evc05;
    }
    else if ((QString::fromStdString(projectType).toLower()).toStdString().compare("evc03") == 0)
    {
        currentProjectType = ProjectType::Evc03;
    }
    else if ((QString::fromStdString(projectType).toLower()).toStdString().compare("evc06") == 0)
    {
        currentProjectType = ProjectType::Evc06;
    }
    else if ((QString::fromStdString(projectType).toLower()).toStdString().compare("evc10") == 0)
    {
        currentProjectType = ProjectType::Evc05; // This is intentional, EVC10 will have its own UI, temporarily treating as evc05 for tests. TODO: Remove when no longer needed.
        ui->footer->move(0, 550);
    }
}

/*
    This is used to map multiple projects into a base project in case it's needed.
    For example, EVC06 derives from EVC03. In order to avoid image/stylesheet duplications,
    this workaround is done.
*/
string MainWindow::getCommonProjectTypeAsStringForStyling(ProjectType projectType)
{
    if (projectType == ProjectType::Evc05 or projectType == ProjectType::Evc03)
    {
        return getProjectTypeAsString(projectType);
    }
    else if (projectType == ProjectType::Evc06)
    {
        return "evc03"; // evc03 is intentional here.
    }
}

string MainWindow::getProjectTypeAsString(ProjectType projectType)
{
    if (projectType == ProjectType::Evc05)
    {
        return "evc05";
    }
    else if (projectType == ProjectType::Evc03)
    {
        return "evc03";
    }
    else if (projectType == ProjectType::Evc06)
    {
        return "evc06";
    }
}

void MainWindow::changeHomeScreen()
{
    if (currentProjectType == MainWindow::Evc05)
    {
        changeScreen(new Evc05HomeScreen(ui->main_background, chargers));
    }
    else if (currentProjectType == MainWindow::Evc03 or currentProjectType == MainWindow::Evc06)
    {
        changeScreen(new HomeScreen(ui->main_background, chargers));
    }
}

void MainWindow::onChargerSelected(int connectorId)
{
    sendChargerSelectedEvent(connectorId);
}

void MainWindow::setInitializingProgressBarBootStepWidth(int completedBootStep, int totalBootStep)
{
    if (initializationDialog != nullptr)
    {
        initializationDialog->updateInitializingProgressBarWithBootStepWidth(completedBootStep, totalBootStep);
    }
}

void MainWindow::onScreenChangeEvent(int screenId, int connectorId)
{
    // TODO: Type of jsonObj["screenId"] in the received message is int, later it can be done string to be more clear. In this case, screen names should be converted to screen ids.
    switch(screenId)
    {
      case HomeScreenId:
        changeHomeScreen();
        break;
      case AuthScreenId:
        changeScreen(new AuthScreen(ui->main_background, chargers[connectorId - 1]));
        break;
      case ChargingScreenId:
        changeScreen(new ChargingScreen(ui->main_background, chargers[connectorId - 1]));
        break;
      case ConnectionScreenId:
        changeScreen(new ConnectionScreen(ui->main_background, chargers[connectorId - 1]));
        break;
      case DisconnectionScreenId:
        changeScreen(new DisconnectionScreen(ui->main_background, chargers[connectorId - 1]));
        break;
      case PreparingForChargingScreenId:
        changeScreen(new PreparingForChargingScreen(ui->main_background, chargers[connectorId - 1]));
        break;
      case StopChargingScreenId:
        changeScreen(new StopChargingScreen(ui->main_background, chargers[connectorId - 1]));
        break;
      case AppreciateScreenId:
        changeScreen(new AppreciateScreen(ui->main_background, chargers[connectorId - 1]));
        break;
      default:
        break;
    }
}

void MainWindow::onShowErrorDialogEvent(int errorId)
{
    if (errorId <= ErrorInfo::NO_ERROR || errorId >= ErrorInfo::COUNT) {
        qDebug() << this->objectName() << "| Unexpected error id received in onShowErrorDialogEvent! - errorId = " << errorId;
        return;
    }

    warningMessageDialogLock.lock();

    emit warningMessageReceivedSignal();
    if (warningMessageDialog == nullptr)
    {
        warningMessageDialog = new WarningMessageDialog(this);
        warningMessageDialog->setDeleteOnClose(false);
    }

    // TODO : This switch will be changed to hashmap in the future.
    switch (errorId)
    {
        case ErrorInfo::PAYMENT_REJECTED_OFFLINE:
            warningMessageDialog->setMessage(AppStrings::error_reason_payment_rejected_offline.getForLocale().c_str());
            break;
        case ErrorInfo::PAYMENT_REJECTED_BLOCKED:
            warningMessageDialog->setMessage(AppStrings::error_reason_payment_blocked.getForLocale().c_str());
            break;
        case ErrorInfo::PAYMENT_REJECTED_CONCURRENTTX:
            warningMessageDialog->setMessage(AppStrings::error_reason_payment_rejected_concurrenttx.getForLocale().c_str());
            break;
        case ErrorInfo::PAYMENT_ID_MISMATCH:
            warningMessageDialog->setMessage(AppStrings::error_reason_payment_id_mismatch.getForLocale().c_str());
            break;
        case ErrorInfo::PAYMENT_UNKNOWN_ID:
            warningMessageDialog->setMessage(AppStrings::error_reason_payment_unknown_id.getForLocale().c_str());
            break;
        case ErrorInfo::PAYMENT_EXPIRED:
            warningMessageDialog->setMessage(AppStrings::error_reason_payment_expired.getForLocale().c_str());
            break;
        case ErrorInfo::PAYMENT_REJECTED_CONNECTOR_RESERVED:
            warningMessageDialog->setMessage(AppStrings::error_reason_payment_connector_reserved.getForLocale().c_str());
            break;
        case ErrorInfo::FAULT_DETECTED:
            warningMessageDialog->setMessage(AppStrings::error_reason_faulted.getForLocale().c_str());
            break;
        case ErrorInfo::CHARGE_STOP_FAIL:
            warningMessageDialog->setMessage(AppStrings::error_reason_charge_stop_failed.getForLocale().c_str());
            break;
        case ErrorInfo::CHARGE_START_FAIL:
            warningMessageDialog->setMessage(AppStrings::error_reason_charge_start_failed.getForLocale().c_str());
            break;
        case ErrorInfo::PLUG_NOT_CONNECTED_PROPERLY:
            warningMessageDialog->setMessage(AppStrings::error_reason_cable_not_connected_properly.getForLocale().c_str());
            break;
        case ErrorInfo::AUTHORIZATION_TIMEOUT:
            warningMessageDialog->setMessage(AppStrings::error_reason_payment_authorization_timeout.getForLocale().c_str());
            break;
        case ErrorInfo::UNAVAILABLE_DETECTED:
            warningMessageDialog->setMessage(AppStrings::error_reason_charge_start_failed_unavailable_detected.getForLocale().c_str());
            break;
        case ErrorInfo::LOCK_FAIL:
            warningMessageDialog->setMessage(AppStrings::error_reason_charge_start_failed_lock_failure.getForLocale().c_str());
            break;
        case ErrorInfo::CHARGE_START_CONDITION_FAIL:
            warningMessageDialog->setMessage(AppStrings::error_reason_charge_start_failed_not_ready_to_start.getForLocale().c_str());
            break;
        case ErrorInfo::CHARGE_START_FAIL_ENERGY_READ_ERROR:
            warningMessageDialog->setMessage(AppStrings::error_reason_charge_start_failed_energy_read_error.getForLocale().c_str());
            break;
        case ErrorInfo::CONNECTOR_INITIALIZING:
            warningMessageDialog->setMessage(AppStrings::error_reason_connector_is_initializing.getForLocale().c_str());
            break;
        case ErrorInfo::LID_ERROR:
            warningMessageDialog->setMessage(AppStrings::error_reason_lid_error.getForLocale().c_str());
            break;
    }
    warningMessageDialog->show();
    warningMessageDialogLock.unlock();
}

void MainWindow::onStateChangedEvent(unsigned int connectorId, bool inUse, bool charging, bool reserved, bool initializing, bool faulted, bool unavailable, bool chargeProgressing, std::vector<UnavailableReason::UnavailableReason> unavailableReasons, FaultReason::FaultReason faultReason)
{
    if (connectorId <= 0 || connectorId > chargers.size()) {
        qDebug() << "Unexpected connector id received in onStateChanged! - connectorId = " << connectorId;
        return;
    }

    Charger & charger = chargers[connectorId - 1];
    charger.setInUse(inUse);
    charger.setCharging(charging);
    charger.setReserved(reserved);
    charger.setInitializing(initializing);
    charger.setFaultReason(faultReason);
    charger.setOutOfOrder(faulted || unavailable);
    charger.setChargeProgressing(chargeProgressing);
    charger.setUnavailableReasons(unavailableReasons);
    checkForStationWideFaults();
}

void MainWindow::checkForStationWideFaults()
{
    if (std::any_of(chargers.begin(), chargers.end(), [](const Charger& charger) { return charger.getFaultReason() == FaultReason::EMERGENCY_BUTTON_ERROR; })) {
        stationWideFault = FaultReason::EMERGENCY_BUTTON_ERROR;
    } else {
        stationWideFault = FaultReason::NO_ERROR;
    }
}

bool MainWindow::isThereStationWideFault()
{
    return stationWideFault != FaultReason::NO_ERROR;
}

void MainWindow::showStationWideFault()
{
    if (isThereStationWideFault()) {
        ui->topNotificationBar->setVisible(true);
        switch(stationWideFault) {
            case FaultReason::EMERGENCY_BUTTON_ERROR:
                ui->topNotificationBar->setNotificationHeaderText(AppStrings::emergency_button_error_notification_header.getForLocale());
                ui->topNotificationBar->setNotificationDetails(AppStrings::emergency_button_error_notification_details.getForLocale());
                break;
        }
    } else {
        ui->topNotificationBar->setVisible(false);
    }
}

void MainWindow::onHomeButtonClicked()
{
    sendHomeButtonClickedEvent();
    ui->home_button_clicked->setVisible(true);
}

void MainWindow::onLanguageButtonClicked()
{
    const std::lock_guard<std::mutex> lock(languageDialogLock);
    if (languageMessageDialog) {
        languageMessageDialog->close();
        languageMessageDialog->deleteLater();
        languageMessageDialog = nullptr;
    }

    ui->language_button_background_clicked->setVisible(true);
    ui->language_button_background_clicked->repaint();

    languageMessageDialog = new LanguageMessageDialog(this, excludedLanguages);
    languageMessageDialog->setSoftwareVersions(softwareVersion);
    languageMessageDialog->show();

    ui->language_button_background_clicked->setVisible(false);
    ui->language_button_background_clicked->repaint();

    languageDialogTimeoutTimer->start(LANGUAGE_DIALOG_TIMEOUT);
}

void MainWindow::onLanguageChanged()
{
    ui->language_button_label->setText(AppStrings::text_language.getForLocale().c_str());
    ui->home_button_label->setText(AppStrings::text_home.getForLocale().c_str());
    ui->cancel_button_label->setText(AppStrings::text_cancel.getForLocale().c_str());
    showStationWideFault();
}

void MainWindow::onBrandReceived(QString brand)
{
    this->brand = brand;
    AppStyleSheets::getInstance()->loadStylesheets(brand);
    setupBrand(brand);
}

void MainWindow::onAuthorizeRequest(bool startAuthorization, int connectorId)
{
    sendAuthorizationRequest(startAuthorization, connectorId);
}

void MainWindow::onMeterValueEvent(unsigned int connectorId, double energy, double power, int percentage, int remainingTime)
{
    if (connectorId > 0 && connectorId <= chargers.size()) {
        Charger & charger = chargers[connectorId - 1];
        charger.setEnergy(energy);
        charger.setPower(power);
        charger.setChargePercentage(percentage);
        charger.setRemainingTime(remainingTime);
        emit meterValueSignal();
    } else {
        qDebug() << "Unexpected connectorId is received with meter value event! connectorId = " << connectorId;
    }
}

void MainWindow::onClearMeterValueEvent(unsigned int connectorId)
{
    if (connectorId > 0 && connectorId <= chargers.size()) {
        Charger & charger = chargers[connectorId - 1];
        charger.clearChargeValues();
    } else {
        qDebug() << "Unexpected connectorId is received with clear meter value event! connectorId = " << connectorId;
    }
}

void MainWindow::onFirmwareUpdateEvent()
{
    firmwareUpdatingDialog = new FirmwareUpdateMessageDialog(this);
    connect(zmqHandler, SIGNAL(firmwareUpdateProgressSignal(int, int, int)), firmwareUpdatingDialog, SLOT(onFirmwareUpdateProgress(int, int, int)));
    firmwareUpdatingDialog->show();
}

void MainWindow::onFirmwareUpdateEndedEvent()
{
    if (firmwareUpdatingDialog != nullptr) {
        firmwareUpdatingDialog->close();
        firmwareUpdatingDialog = nullptr;
    }
}

void MainWindow::notSupportedConnectorReadyToStartRequest(int connectorId)
{
    sendNotSupportedConnectorReadyToStartRequest(connectorId);
}

void MainWindow::unlockConnectorRequest(int connectorId)
{
    sendUnlockConnectorRequest(connectorId);
}

void MainWindow::onDeviceStateReceived(QString softwareVersion)
{
    this->softwareVersion = softwareVersion;
}

void MainWindow::onDisplayLogoDimensionReceived(int width, int height)
{
    setDisplayLogoDimension(width, height);
}

void MainWindow::setDisplayLogoDimension(int width, int height)
{
    qDebug() << "The dimensions of Display Logos were changed. [WIDTH: " << width << " HEIGHT: " << height << "]";
    ui->left_logo->resize(width, height);
    ui->right_logo->resize(width, height);
}

void MainWindow::onChangeLogoVisibilityEvent(bool leftLogoStatus, bool rightLogoStatus)
{
    this->leftLogoStatus = leftLogoStatus;
    this->rightLogoStatus = rightLogoStatus;
    ui->left_logo->setVisible(leftLogoStatus);
    ui->right_logo->setVisible(rightLogoStatus);
}

void MainWindow::onConnectorConfigurationReceived(std::string connectorTypes, std::string connectorMaxPowers)
{
    if (chargers.size() != 0) {
        qDebug() << "Received connector configurations when they're already initialized!";
        return;
    }

    std::vector<std::string> connectors = StringUtils::split(connectorTypes, ",");
    std::vector<std::string> maxPowers = StringUtils::split(connectorMaxPowers, ",");

    for (unsigned int connectorId = 1; connectorId <= connectors.size(); connectorId++) {
        Charger::Type chargerType = Charger::getTypeFromString(connectors.at(connectorId - 1));
        unsigned int maxPower = std::atoi(maxPowers.at(connectorId - 1).c_str());
        registerCharger(connectorId, chargerType, maxPower);
    }
}

void MainWindow::registerCharger(unsigned int connectorId, Charger::Type chargerType, unsigned int maxPower)
{
    switch (chargerType) {
        case Charger::Type::AC_22:
            chargers.push_back(Ac22Charger(connectorId, maxPower));
            break;
        case Charger::Type::AC_43:
            chargers.push_back(Ac43Charger(connectorId, maxPower));
            break;
        case Charger::Type::SCHUKO:
            chargers.push_back(SchukoCharger(connectorId, maxPower));
            break;
        case Charger::Type::CHADEMO:
            chargers.push_back(ChademoCharger(connectorId, maxPower));
            break;
        case Charger::Type::CCS:
            chargers.push_back(CcsCharger(connectorId, maxPower));
            break;
    }
}

void MainWindow::onLogoUpdated()
{
    displayExternalLogosIfFound();
}

void MainWindow::onLidErrorUpdated(int connectorId, bool lidErrorStatus)
{
    if (connectorId <= 0 || connectorId > chargers.size()) {
        qDebug() << "Lid error received for unexpected connector " << connectorId;
        return;
    }
    chargers[connectorId - 1].setLidError(lidErrorStatus);
}

void MainWindow::hideHomeButton()
{
    ui->home_button_container->setHidden(true);
}

void MainWindow::hideCancelButton()
{
    ui->cancel_button_container->setHidden(true);
}

void MainWindow::showVestelLogo(bool show)
{
    ui->left_logo->setVisible(leftLogoStatus && show);
}

void MainWindow::showCustomerLogo(bool show)
{
    ui->right_logo->setVisible(rightLogoStatus && show);
}

void MainWindow::dumpAvailableFonts() {
    QFontDatabase db;
    for(int i=0; i < db.families().size(); i++) {
      qDebug() << "Registered font = " << db.families().at(i);
    }
}

void MainWindow::sendChargerSelectedEvent(int connectorId)
{
    QJsonObject jsonObj;
    jsonObj["command"] = "UI_ConnectorSelectedEvent";
    jsonObj["connectorId"] = connectorId;
    jsonObj["messageId"] = "1271357"; // TODO: Message Id value will be generated randomly.
    zmqHandler->addToQueue(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact).toStdString());
}

void MainWindow::sendHomeButtonClickedEvent()
{
    QJsonObject jsonObj;
    jsonObj["command"] = "UI_HomeScreenSelectedEvent";
    jsonObj["messageId"] = "194894"; // TODO: Message Id value will be generated randomly.
    zmqHandler->addToQueue(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact).toStdString());
}

void MainWindow::sendScreenActivityEvent()
{
    static const long CONSECUTIVE_SCREEN_ACTIVITY_IGNORE_TIME = 5000; // We don't want to send an event with each user input since it might potentially produce too many messages.
    static long lastScreenActivityEventTime = 0;

    if (uptimeTimer.elapsed() - lastScreenActivityEventTime >= CONSECUTIVE_SCREEN_ACTIVITY_IGNORE_TIME) {
        lastScreenActivityEventTime = uptimeTimer.elapsed();
        QJsonObject jsonObj;
        jsonObj["command"] = "UI_ScreenActivityEvent";
        jsonObj["messageId"] = "984191"; // TODO: Message Id value will be generated randomly.
        zmqHandler->addToQueue(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact).toStdString());
        updateDefaultLanguageTimer();
    }
}

void MainWindow::sendAuthorizationRequest(bool startAuthorization, int connectorId)
{
    QJsonObject jsonObj;
    jsonObj["command"] = "UIVisual_AuthorizationRequest";
    jsonObj["connectorId"] = connectorId;
    jsonObj["startAuthorization"] = startAuthorization;
    jsonObj["messageId"] = "2997132"; // TODO: Message Id value will be generated randomly.
    zmqHandler->addToQueue(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact).toStdString());
}

void MainWindow::sendDeviceStateRequest()
{
    QJsonObject jsonObj;
    jsonObj["command"] = "GetDeviceStateRequest";
    jsonObj["messageId"] = "1135479"; // TODO: Message Id value will be generated randomly.
    zmqHandler->addToQueue(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact).toStdString());
}

void MainWindow::sendNotSupportedConnectorReadyToStartRequest(int connectorId)
{
    QJsonObject jsonObj;
    jsonObj["command"] = "UIVisual_NotSupportedConnectorReadyToStart";
    jsonObj["connectorId"] = connectorId;
    jsonObj["messageId"] = "7945187"; // TODO: Message Id value will be generated randomly.
    zmqHandler->addToQueue(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact).toStdString());
}

void MainWindow::sendUnlockConnectorRequest(int connectorId)
{
    QJsonObject jsonObj;
    jsonObj["command"] = "UIVisual_UnlockConnectorReq";
    jsonObj["connectorId"] = connectorId;
    jsonObj["messageId"] = "2756671"; // TODO: Message Id value will be generated randomly.
    zmqHandler->addToQueue(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact).toStdString());
}

void MainWindow::displayExternalLogosIfFound()
{
    loadExternalLogo(LEFT_LOGO_PATH, ui->left_logo, Qt::AlignLeft | Qt::AlignTop) || loadExternalLogo(DEFAULT_LEFT_LOGO_PATH, ui->left_logo, Qt::AlignLeft | Qt::AlignTop);
    loadExternalLogo(RIGHT_LOGO_PATH, ui->right_logo, Qt::AlignRight | Qt::AlignTop) || loadExternalLogo(DEFAULT_RIGHT_LOGO_PATH, ui->right_logo, Qt::AlignRight | Qt::AlignTop);
}

bool MainWindow::loadExternalLogo(const std::string& externalPath, QLabel* logoWidget, Qt::Alignment alignment)
{
    QPixmap logo(QString(externalPath.c_str()));
    if (logo.isNull()) {
        qDebug() << "Logo Image is not found = " << externalPath.c_str();
        return false;
    } else {
        logoWidget->setStyleSheet("");
        logoWidget->setPixmap(logo);
        logoWidget->setAlignment(alignment);
        return true;
    }
}

void MainWindow::initializeCursorWidget(bool showCursorWidget)
{
    if (showCursorWidget) {
        cursor_widget = new QWidget(this);
        cursor_widget->setStyleSheet("background-color:red");
        cursor_widget->setGeometry(0,0,15,15);
        cursor_widget->setAttribute(Qt::WA_TransparentForMouseEvents);
    } else {
        cursor_widget = nullptr;
    }
}

void MainWindow::hideHomeCancelButton(bool homeButtonStatus, bool cancelButtonStatus)
{
    ui->home_button_container->setHidden(homeButtonStatus);
    ui->cancel_button_container->setHidden(cancelButtonStatus);

    if(homeButtonStatus && cancelButtonStatus) // only languageButton visible
    {
        ui->bottom_buttons->setGeometry(Dimensions::ONLY_LANGUAGE_BUTTON_CASE_X_AXIS,
                                        Dimensions::BOTTOM_BUTTONS_Y,
                                        Dimensions::ONLY_LANGUAGE_BUTTON_CASE_WIDTH,
                                        Dimensions::BOTTOM_BUTTONS_HEIGHT);
    }
    else if(homeButtonStatus || cancelButtonStatus) // 2 buttons: languageButton and (homeButton OR cancelButton) visible
    {
        ui->bottom_buttons->setGeometry(Dimensions::LANGUAGE_AND_ONE_MORE_BUTTON_CASE_X_AXIS,
                                        Dimensions::BOTTOM_BUTTONS_Y,
                                        Dimensions::LANGUAGE_AND_ONE_MORE_BUTTON_CASE_WIDTH,
                                        Dimensions::BOTTOM_BUTTONS_HEIGHT);
    }
}

void MainWindow::setVisibilityAlternativePaymentMethod(bool state)
{
    stateAlternativePaymentMethod = state;
}
