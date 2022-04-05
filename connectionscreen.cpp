#include "appstylesheets.h"
#include "connectionscreen.h"
#include "dimensions.h"
#include "ui_connectionscreen.h"
#include "languages/generated/appstrings.h"
#include "utils/headers/stringutils.h"

#include <utils/headers/uiutils.h>

ConnectionScreen::ConnectionScreen(QWidget *parent, Charger & charger) :
    InnerScreen(parent, charger),
    ui(new Ui::ConnectionScreen)
{
    ui->setupUi(this);
}

ConnectionScreen::~ConnectionScreen()
{
    delete ui;
}

void ConnectionScreen::onLanguageChanged()
{
    InnerScreen::onLanguageChanged();
    if (getCharger().getType() == Charger::CHADEMO)
    {
        ui->connectionLabel->setText((StringUtils::replaceAll(AppStrings::connect_cable_to_car_and_continue_charging.getForLocale().c_str(), "<charger_type>", getCharger().getTypeName().getForLocale())).c_str());
    }
    else
    {
        ui->connectionLabel->setText(StringUtils::replaceAll(AppStrings::connect_cable_to_car.getForLocale().c_str(), "<charger_type>", getCharger().getTypeName().getForLocale()).c_str());
    }
    ui->schukoCableConnection1Label->setText(AppStrings::schuko_slide_up.getForLocale().c_str());
    ui->schukoCableConnection2Label->setText(AppStrings::schuko_connect.getForLocale().c_str());
    ui->schukoCableConnection3Label->setText(AppStrings::schuko_make_sure_closing.getForLocale().c_str());
    ui->continueChargingButtonLabel->setText(AppStrings::continue_charging.getForLocale().c_str());
}

void ConnectionScreen::setupUi(MainWindow * mainWindow)
{
    InnerScreen::setupUi(mainWindow);
    string connection_screen_stylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::CONNECTION_SCREEN);

    UIUtils::setStyleSheetAndUpdate(this,
                                    UIUtils::getStyleSheetForProjectAndChargerType(mainWindow->getProjectTypeAsString(mainWindow->currentProjectType),
                                                                                   getCharger().getTypeCode(),
                                                                                   connection_screen_stylesheet));

    ui->continueChargingButton->setVisible(getCharger().getType() == Charger::CHADEMO); // TODO: Plug connection type will be used to set visibility of continueChargingButton.
    connect(ui->continueChargingButton, &ClickableQWidget::clickedSignal, this, &ConnectionScreen::continueChargingButtonClicked);
    connect(this, SIGNAL(notSupportedConnectorReadyToStartRequestSignal(int)), mainWindow, SLOT(notSupportedConnectorReadyToStartRequest(int)));
    if (getCharger().getType() == Charger::SCHUKO)
    {
        hideSocketObject();
        ui->carAndStationImage->hide();
        ui->connectionLabel->hide();
    }
    else
    {
        ui->schukoCableConnectionWidget->hide();
    }
}

void ConnectionScreen::continueChargingButtonClicked()
{
    emit notSupportedConnectorReadyToStartRequestSignal(getCharger().getConnectorId());
}

void ConnectionScreen::setupBrand(QString brand)
{
    qDebug() << "ConnectionScreen:" << brand;
//    TODO brand
}
