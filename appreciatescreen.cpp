#include "appreciatescreen.h"
#include "appstylesheets.h"

#include <languages/generated/appstrings.h>

#include <utils/headers/stringutils.h>
#include <utils/headers/uiutils.h>

AppreciateScreen::AppreciateScreen(QWidget *parent, Charger & charger) : DisconnectionScreen(parent, charger)
{

}

AppreciateScreen::~AppreciateScreen()
{

}

void AppreciateScreen::setupUi(MainWindow * mainWindow)
{
    DisconnectionScreen::setupUi(mainWindow);

    string chargerCode = getCharger().getTypeCode();
    if (mainWindow->currentProjectType == MainWindow::Evc05)
    {
        chargerCode = "common";
    }
    setStyleSheetVehicleAndStationWidget(chargerCode, mainWindow->getProjectTypeAsString(mainWindow->currentProjectType));
}

void AppreciateScreen::onLanguageChanged()
{
    DisconnectionScreen::onLanguageChanged();
    setDisconnectionLabel(AppStrings::thanks);
}

void AppreciateScreen::setupBrand(QString brand)
{
    qDebug() << "AppreciateScreen:" << brand;
//    TODO brand
}
