#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <model/headers/charger.h>
#include "chargeritem.h"
#include "persistentsettings.h"
#include "screen.h"
#include "languagemanager.h"
#include "zmqhandler.h"
#include "languagemessagedialog.h"
#include "warningmessagedialog.h"
#include "initializemessagedialog.h"
#include "operationmode.h"
#include "unavailablereason.h"

#include <QMainWindow>
#include <qelapsedtimer.h>
#include <qlabel.h>
#include <mutex>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum ScreenList
    {
        HomeScreenId,
        AuthScreenId,
        ChargingScreenId,
        ConnectionScreenId,
        DisconnectionScreenId,
        PreparingForChargingScreenId,
        StopChargingScreenId,
        AppreciateScreenId
    };

    enum ProjectType
    {
        Evc03,
        Evc05,
        Evc06
    };

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool event(QEvent* event) override;
    void setupBrand(QString brand);
    void initializeUiElements();
    void changeScreen(Screen * screen);
    void changeHomeScreen();
    void hideHomeButton();
    void hideCancelButton();
    void showVestelLogo(bool show);
    void showCustomerLogo(bool show);
    void onLanguageChanged();
    void displayExternalLogosIfFound();
    bool loadExternalLogo(const std::string& externalPath, QLabel* logoWidget, Qt::Alignment alignment);
    void hideHomeCancelButton(bool homeButtonStatus, bool cancelButtonStatus);
    void setDisplayLogoDimension(int width, int height);
    void setProjectEnumType(std::string projectTypes);
    bool isThereStationWideFault();
    ProjectType currentProjectType;
    string chargePointId = ""; // TODO : Move some of these "global" configurations away from mainwindow
    string serviceContact = "";
    OperationMode operationMode = OperationMode::TRADITIONAL_OCPP;
    string getCommonProjectTypeAsStringForStyling(ProjectType projectType);
    string getProjectTypeAsString(ProjectType projectType);
    bool leftLogoStatus = false;
    bool rightLogoStatus = false;
    bool stateAlternativePaymentMethod;

private:
    const std::string LEFT_LOGO_PATH = "/var/lib/vestel/displayLeftLogo.png";
    const std::string DEFAULT_LEFT_LOGO_PATH = "/run/media/mmcblk1p3/displayLeftLogo.png";
    const std::string RIGHT_LOGO_PATH = "/var/lib/vestel/displayRightLogo.png";
    const std::string DEFAULT_RIGHT_LOGO_PATH = "/run/media/mmcblk1p3/displayRightLogo.png";
    const QString LANGUAGE_SETTING_PATH = "/home/root/uisettings.conf";
    const int DEFAULT_LANGUAGE_TIMEOUT = 3*60*1000; // 3 Minutes in msec
    const int LANGUAGE_DIALOG_TIMEOUT = 1*60*1000; // 1 Minute in msec
    Ui::MainWindow *ui;
    Screen * currentScreen = nullptr;
    InitializeMessageDialog * initializationDialog = nullptr;
    MessageDialog * firmwareUpdatingDialog = nullptr;
    PersistentSettings * languageIdSetting = nullptr;
    vector<Charger> chargers;
    QElapsedTimer uptimeTimer;
    QTimer * defaultLanguageTimer;
    QTimer * languageDialogTimeoutTimer;
    QString softwareVersion;
    Language defaultLanguage = Language::ENGLISH;
    vector<Language> excludedLanguages;
    FaultReason::FaultReason stationWideFault = FaultReason::NO_ERROR;
    void dumpAvailableFonts();
    void sendChargerSelectedEvent(int connectorId);
    void sendHomeButtonClickedEvent();
    void sendScreenActivityEvent();
    void sendAuthorizationRequest(bool, int);
    void sendDeviceStateRequest();
    void sendNotSupportedConnectorReadyToStartRequest(int);
    void sendUnlockConnectorRequest(int);
    void initializeCursorWidget(bool);
    void updateDefaultLanguageTimer();
    void registerCharger(unsigned int connectorId, Charger::Type chargerType, unsigned int maxPower);
    void setDefaultLanguageFromCache();
    void checkForStationWideFaults();
    void showStationWideFault();
    ZmqHandler * zmqHandler;
    LanguageMessageDialog * languageMessageDialog = nullptr;
    WarningMessageDialog * warningMessageDialog = nullptr;
    std::mutex warningMessageDialogLock;
    std::mutex languageDialogLock;
    QWidget* cursor_widget = nullptr;
    QString languageKey = "Language";
    QString brand = "";

signals:
    void languageChangedSignal();
    void meterValueSignal();
    void warningMessageReceivedSignal();

public slots:
    void onChargerSelected(int connectorId);
    void onScreenChangeEvent(int screenId, int connectorId);
    void setInitializingProgressBarBootStepWidth(int completedBootStep, int totalBootStep);
    void onShowErrorDialogEvent(int);
    void onHomeButtonClicked();
    void onLanguageButtonClicked();
    void changeLanguage(Language language, bool saveParam);
    void changeDefaultLanguage(Language language);
    void onDefaultLanguageTimeout();
    void onLanguageDialogTimeout();
    void projectTypeCodeReceived(std::string);
    void serviceContactInfoReceived(std::string serviceContactInfo);
    void onAuthorizeRequest(bool, int);
    void onStateChangedEvent(unsigned int, bool, bool, bool, bool, bool, bool, bool, std::vector<UnavailableReason::UnavailableReason>, FaultReason::FaultReason);
    void onMeterValueEvent(unsigned int, double, double, int, int);
    void onClearMeterValueEvent(unsigned int);
    void onDeviceStateReceived(QString softwareVersion);
    void onLogoUpdated();
    void onChangeLogoVisibilityEvent(bool leftLogoStatus, bool rightLogoStatus);
    void onConnectorConfigurationReceived(std::string, std::string);
    void onDisplayLogoDimensionReceived(int width, int height);
    void onChargePointIdReceived(std::string chargePointId);
    void onFirmwareUpdateEvent();
    void onFirmwareUpdateEndedEvent();
    void notSupportedConnectorReadyToStartRequest(int);
    void unlockConnectorRequest(int);
    void onLidErrorUpdated(int, bool);
    void onOperationModeReceived(int);
    void setVisibilityAlternativePaymentMethod(bool);
    void onExcludedLanguagesReceived(std::vector<Language> excludedLanguages);
    void notificationBarClicked();
    void onBrandReceived(QString brand);
};
#endif // MAINWINDOW_H
