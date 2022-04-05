#include "appstylesheets.h"
#include "disconnectionscreen.h"
#include "ui_disconnectionscreen.h"

#include <utils/headers/stringutils.h>
#include <utils/headers/uiutils.h>

#include <languages/generated/appstrings.h>
#include <iomanip>

DisconnectionScreen::DisconnectionScreen(QWidget *parent, Charger & charger) :
    InnerScreen(parent, charger),
    ui(new Ui::DisconnectionScreen)
{
    ui->setupUi(this);
}

DisconnectionScreen::~DisconnectionScreen()
{
    delete ui;
}

void DisconnectionScreen::setupUi(MainWindow * mainWindow)
{
    InnerScreen::setupUi(mainWindow);
    setEnergy(mainWindow, getCharger().getEnergy());
    setChargeDuration(getCharger().getChargeDuration());
    setChargePercentage(getCharger().getChargePercentage());

    if (getCharger().getCurrentType() == Charger::AC)
    {
        ui->batteryLabel->hide();
        ui->batteryLevelValue->hide();
        ui->durationBatterySeparator->hide();
    }

    setStyleSheetVehicleAndStationWidget(getCharger().getTypeCode(), mainWindow->getProjectTypeAsString(mainWindow->currentProjectType));
}

void DisconnectionScreen::setEnergy(MainWindow * mainWindow, double energy)
{
    std::stringstream strStream;

    if (mainWindow->currentProjectType == MainWindow::Evc03 || mainWindow->currentProjectType == MainWindow::Evc06)
    {
        strStream << std::setprecision(ENERGY_DIGIT_NUMBER_FOR_EVC03) << std::fixed;
    }
    else
    {
        strStream << std::setprecision(ENERGY_DIGIT_NUMBER_FOR_EVC05) << std::fixed;
    }

    strStream << energy / TO_KW_AND_KWH_CONVERTOR_RATE << " kWh";
    ui->energyValue->setText(strStream.str().c_str());
}

void DisconnectionScreen::setChargePercentage(int percentage)
{
    std::stringstream strStream;
    strStream << percentage << " %";
    ui->batteryLevelValue->setText(strStream.str().c_str());
}

void DisconnectionScreen::setChargeDuration(int duration)
{
    std::stringstream strStream;
    strStream << duration << " " << AppStrings::minute.getForLocale().c_str();
    ui->durationValue->setText(strStream.str().c_str());
}

void DisconnectionScreen::onLanguageChanged()
{
    InnerScreen::onLanguageChanged();
    ui->energyLabel->setText(AppStrings::energy.getForLocale().c_str());
    ui->durationLabel->setText(AppStrings::duration.getForLocale().c_str());
    ui->batteryLabel->setText(AppStrings::battery_level.getForLocale().c_str());

    if(getCharger().getCableModel() == Charger::OneWay)
    {
        setDisconnectionLabel(AppStrings::disconnection_text);
    }
    else
    {
        setDisconnectionLabel(AppStrings::disconnection_text_for_two_way_cable);
    }
    setChargeDuration(getCharger().getChargeDuration());
}

void DisconnectionScreen::setupBrand(QString brand)
{
    qDebug() << "DisconnectionScreen:" << brand;
//    TODO brand
}

void DisconnectionScreen::setDisconnectionLabel(const TranslationString inputText)
{
    ui->disconnectionLabel->setText(inputText.getForLocale().c_str());
}

void DisconnectionScreen::setStyleSheetVehicleAndStationWidget(string chargerCode, string projectTypeCode)
{
    string vehicleAndStationItemStylesheet;
    vehicleAndStationItemStylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::VEHICLE_AND_STATION_ITEM);
    UIUtils::setStyleSheetAndUpdate(this,
                                    UIUtils::getStyleSheetForProjectAndChargerType(projectTypeCode,
                                                                                   chargerCode,
                                                                                   vehicleAndStationItemStylesheet));
}
