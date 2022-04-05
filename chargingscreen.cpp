#include "appstylesheets.h"
#include "dimensions.h"
#include "chargingscreen.h"
#include "ui_chargingscreen.h"

#include <utils/headers/stringutils.h>
#include <utils/headers/uiutils.h>

#include <languages/generated/appstrings.h>
#include <iomanip>

ChargingScreen::ChargingScreen(QWidget *parent, Charger & charger) :
    InnerScreen(parent, charger),
    ui(new Ui::ChargingScreen)
{
    ui->setupUi(this);
    ui->chargeProgressBar->setIndeterminate(charger.getCurrentType() == Charger::CurrentType::AC);
}

ChargingScreen::~ChargingScreen()
{
    delete ui;
    if (authMessageDialog != nullptr)
    {
        authMessageDialog->deleteLater();
        authMessageDialog = nullptr;
    }
}

void ChargingScreen::setupUi(MainWindow * mainWindow)
{
    InnerScreen::setupUi(mainWindow);

    // Stop Charge button is removed in Free Mode only for AC connectors, since stop button on some of the vehicles do not work with DC connectors
    if (mainWindow->operationMode == OperationMode::FIXED_IDTAG_OCPP && getCharger().getCurrentType() == Charger::CurrentType::AC) {
        ui->stopChargingButton->hide();
    }

    if (getCharger().getCurrentType() == Charger::AC)
    {
        ui->remainingTimeLabel->hide();
        ui->remainingTimeValue->hide();
        ui->durationRemainingSeparator->hide();
        ui->percentageLabel->hide();
    }

    // Stop progress bar if AC type connector is not charging
    if (!getCharger().isChargeProgressing() && getCharger().getCurrentType() == Charger::CurrentType::AC) {
        ui->chargeProgressBar->setIndeterminate(false);
        ui->chargeProgressBar->setProgress(0);
    }
    string charging_screen_stylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::CHARGING_SCREEN);

    UIUtils::setStyleSheetAndUpdate(this,
                                    UIUtils::getStyleSheetForProjectAndChargerType(mainWindow->getProjectTypeAsString(mainWindow->currentProjectType),
                                                                                   getCharger().getTypeCode(),
                                                                                   charging_screen_stylesheet));
    connect(ui->stopChargingButton, &ClickableQWidget::clickedSignal, this, &ChargingScreen::stopChargingButtonClicked);
    connect(this, SIGNAL(authorizeToStopRequestSignal(bool, int)), mainWindow, SLOT(onAuthorizeRequest(bool, int)));
    connect(mainWindow, &MainWindow::meterValueSignal, this, &ChargingScreen::onMeterValueReceived);
    onMeterValueReceived();

    connect(getCharger().getDurationTimer(), SIGNAL(timeout()), this, SLOT(onDurationUpdated()));
    connect(mainWindow, &MainWindow::warningMessageReceivedSignal, this, &ChargingScreen::onWarningMessageReceivedEvent);
    connect(this, SIGNAL(setVisibilityAlternativeAuthorizationSignal(bool)), this, SLOT(setVisibilityAlternativeAuthorization(bool)));
    stateAlternativePaymentMethod = mainWindow->stateAlternativePaymentMethod;
}

void ChargingScreen::onLanguageChanged()
{
    InnerScreen::onLanguageChanged();
    onDurationUpdated();
    ui->stopChargingButtonLabel->setText(AppStrings::stop_charge.getForLocale().c_str());
    ui->powerLabel->setText(AppStrings::power.getForLocale().c_str());
    ui->energyLabel->setText(AppStrings::energy.getForLocale().c_str());
    ui->timeLabel->setText(AppStrings::duration.getForLocale().c_str());
    ui->remainingTimeLabel->setText(AppStrings::remaining_time.getForLocale().c_str());
}

void ChargingScreen::setupBrand(QString brand)
{
    qDebug() << "ChargingScreen:" << brand;
//    TODO brand
}

void ChargingScreen::stopChargingButtonClicked()
{
    string stopChargingActiveItemStylesheet;
    stopChargingActiveItemStylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::STOP_CHARGING_ACTIVE_ITEM);

    UIUtils::setStyleSheetAndUpdate(ui->stopChargingButton, stopChargingActiveItemStylesheet.c_str());
    ui->stopChargingButtonLabel->raise();

    if (authMessageDialog == nullptr)
    {
        authMessageDialog = new AuthorizeMessageDialog(parentWidget());
        authMessageDialog->setAlternativeAuthorizationText(AppStrings::stop_with_mobile);
        authMessageDialog->setAlternativeAuthorizationIcon("background-image: url(:/assets/images/mobile_app.png)");
        emit setVisibilityAlternativeAuthorizationSignal(stateAlternativePaymentMethod);
        authMessageDialog->show();
    }

    connect(authMessageDialog, SIGNAL(dialogClosedSignal()), this, SLOT(onAuthorizationDialogClosed()));
    emit authorizeToStopRequestSignal(true, getCharger().getConnectorId());
}

void ChargingScreen::onAuthorizationDialogClosed()
{
    string stopChargingItemStylesheet;
    stopChargingItemStylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::STOP_CHARGING_ITEM);

    UIUtils::setStyleSheetAndUpdate(ui->stopChargingButton, stopChargingItemStylesheet.c_str());
    ui->stopChargingButtonLabel->raise();
    emit authorizeToStopRequestSignal(false, getCharger().getConnectorId());
    if (authMessageDialog != nullptr)
    {
        authMessageDialog->deleteLater();
        authMessageDialog = nullptr;
    }
}

void ChargingScreen::setEnergy(double energy)
{
    std::stringstream strStream;
    strStream << std::setprecision(1) << std::fixed;
    strStream << energy / TO_KW_AND_KWH_CONVERTOR_RATE << " kWh";
    ui->energyValue->setText(strStream.str().c_str());
}

void ChargingScreen::setPower(double power)
{
    std::stringstream strStream;
    strStream << std::setprecision(1) << std::fixed;
    strStream << power / TO_KW_AND_KWH_CONVERTOR_RATE << " kW";
    ui->powerValue->setText(strStream.str().c_str());
}

void ChargingScreen::setChargePercentage(int percentage)
{
    std::stringstream strStream;
    strStream << percentage << " %";
    ui->percentageLabel->setText(strStream.str().c_str());
    ui->chargeProgressBar->setProgress(percentage);
}

void ChargingScreen::setRemainingTime(int remainingTime)
{
    std::stringstream strStream;
    strStream << remainingTime/60 << " " << AppStrings::minute.getForLocale();
    ui->remainingTimeValue->setText(strStream.str().c_str());
}

void ChargingScreen::onMeterValueReceived()
{
    setEnergy(getCharger().getEnergy());
    setPower(getCharger().getPower());
    if (getCharger().getCurrentType() == Charger::CurrentType::DC) {
        setChargePercentage(getCharger().getChargePercentage());
        setRemainingTime(getCharger().getRemainingTime());
    }
}

void ChargingScreen::onDurationUpdated()
{
    ui->timeValue->setText((to_string(getCharger().getChargeDuration()) + " " + AppStrings::minute.getForLocale()).c_str());
}

void ChargingScreen::onWarningMessageReceivedEvent()
{
    if (authMessageDialog != nullptr)
    {
        authMessageDialog->onCloseButtonClicked();
    }
}

void ChargingScreen::setVisibilityAlternativeAuthorization(bool stateTrial)
{
    authMessageDialog->setVisibilityAlternativeAuthorization(stateTrial);
}
