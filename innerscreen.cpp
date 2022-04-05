#include "appstylesheets.h"
#include "innerscreen.h"
#include "ui_innerscreen.h"

#include <utils/headers/uiutils.h>
#include <mainwindow.h>
#include <languages/generated/appstrings.h>

InnerScreen::InnerScreen(QWidget * parent, Charger & currentCharger)
    : Screen(parent)
    , ui(new Ui::InnerScreen)
    , charger(currentCharger)
{
    ui->setupUi(this);
}

InnerScreen::~InnerScreen()
{
    delete ui;
}

void InnerScreen::setupUi(MainWindow * mainWindow)
{
    this->layout()->setAlignment(Qt::AlignCenter);

    string innerScreenStylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::INNER_SCREEN);
    UIUtils::setStyleSheetAndUpdate(ui->innerScreenBackground, UIUtils::getStyleSheetForType(charger.getTypeCode(), innerScreenStylesheet));

    ui->topNotification->setVisible(!mainWindow->isThereStationWideFault() && (charger.isOutOfOrder() || charger.isReserved()));
    ui->topNotification->setParent(this); // Setting style sheet is required due to using setParent!
    mainWindow->showVestelLogo(ui->topNotification->isHidden());
    mainWindow->showCustomerLogo(ui->topNotification->isHidden());

    if (charger.isInitializing()) {
        // Use Reservation style top bar, replace the text in onLanguageChanged.
        UIUtils::setStyleSheetAndUpdate(ui->topNotification, AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::INNER_SCREEN_NOTIFICATION_RESERVED).c_str());
    } else if (charger.isOutOfOrder()) {
        UIUtils::setStyleSheetAndUpdate(ui->topNotification, AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::INNER_SCREEN_NOTIFICATION_OUT_OF_ORDER).c_str());
    } else if (charger.isReserved()) {
        UIUtils::setStyleSheetAndUpdate(ui->topNotification, AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::INNER_SCREEN_NOTIFICATION_RESERVED).c_str());
    }
    serviceContact = mainWindow->serviceContact;
}

void InnerScreen::onLanguageChanged()
{
    ui->connectorId->setText(to_string(charger.getConnectorId()).c_str());
    ui->power->setText((to_string(charger.getChargingRate()) + charger.getChargingUnit() + (charger.isHighPower() ? " HP" : "")).c_str());
    if (LanguageManager::getInstance()->getLanguageIndex() == Languages::DANISH && (charger.getType() == charger.AC_22 || charger.getType() == charger.AC_43))
    {
        ui->type->setAlignment(Qt::AlignTop);
        UIUtils::setTextWithLineSpace(ui->type, charger.getTypeName().getForLocale().c_str(), lineSpacingOfDanishConnectorTypeLabel);
    }
    else
    {
        ui->type->setAlignment(Qt::AlignBottom);
        ui->type->setText(charger.getTypeName().getForLocale().c_str());
    }

    if (charger.isInitializing()) {
        ui->topNotificationHeader->setText(AppStrings::connector_initialization_header.getForLocale().c_str());
        ui->topNotificationDetails->setText(AppStrings::connector_initialization_details.getForLocale().c_str());
    } else if (charger.isOutOfOrder()) {
        ui->topNotificationHeader->setText(AppStrings::out_of_order_notification_header.getForLocale().c_str());
        if (serviceContact != "")
        {
            std::stringstream strStream;
            strStream << AppStrings::service_contact_info_in_out_ouf_order.getForLocale() <<std::endl << serviceContact;
            ui->topNotificationDetails->setText(strStream.str().c_str());
        }
        else
        {
            ui->topNotificationDetails->setText(AppStrings::out_of_order_notification_details.getForLocale().c_str());
        }

        std::vector<UnavailableReason::UnavailableReason> unavailableReasons = charger.getUnavailableReasons();
        if (std::find(unavailableReasons.begin(), unavailableReasons.end(), UnavailableReason::DC_POWER_NOT_AVAILABLE) != unavailableReasons.end()) {
            ui->topNotificationDetails->setText(AppStrings::out_of_order_dc_power_not_available.getForLocale().c_str());
        }
    } else if (charger.isReserved()) {
        ui->topNotificationHeader->setText(AppStrings::reserved_notification_header.getForLocale().c_str());
        ui->topNotificationDetails->setVisible(false);
    }
}

void InnerScreen::hideSocketObject()
{
    ui->socketObject->hide();
}

Charger &InnerScreen::getCharger() const
{
    return charger;
}

void InnerScreen::setupBrand(QString brand)
{
    qDebug() << "InnerScreen:" << brand;
//    TODO brand
}
