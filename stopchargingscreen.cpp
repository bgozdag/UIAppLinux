#include "stopchargingscreen.h"

#include <utils/headers/stringutils.h>
#include <languages/generated/appstrings.h>

StopChargingScreen::StopChargingScreen(QWidget *parent, Charger & charger) : PreparingForChargingScreen(parent, charger)
{

}

StopChargingScreen::~StopChargingScreen()
{

}

void StopChargingScreen::setupUi(MainWindow * mainWindow)
{
    PreparingForChargingScreen::setupUi(mainWindow);
}

void StopChargingScreen::onLanguageChanged()
{
    PreparingForChargingScreen::onLanguageChanged();
    setChargingLabel(AppStrings::stop_charging_in_progress);
}

void StopChargingScreen::setupBrand(QString brand)
{
    qDebug() << "StopChargingScreen:" << brand;
//    TODO brand
}
