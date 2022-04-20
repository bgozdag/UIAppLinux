#include <languages/generated/appstrings.h>
#include "evc05chargeritem.h"
#include "chargeritemclicklistener.h"
#include "appstylesheets.h"
#include "ui_evc05chargeritem.h"
#include "dimensions.h"
#include <string>
#include <utils/headers/stringutils.h>
#include <utils/headers/uiutils.h>
#include <languagemanager.h>
#include <QtQuick>
#include <qqmlcontext.h>
#include <qstyle.h>
#include <iomanip>

Evc05ChargerItem::Evc05ChargerItem(QWidget * parent, Charger & charger) :
    QFrame(parent),
    ui(new Ui::Evc05ChargerItem),
    charger(charger)
{
    ui->setupUi(this);
    ui->connectorId->setText(to_string(charger.getConnectorId()).c_str());
    ui->connectorPower->setText((to_string(charger.getChargingRate()) + charger.getChargingUnit()).c_str());

    ui->progressBar->setIndeterminate(charger.getCurrentType() == Charger::CurrentType::AC);
    ui->progressBar->setVisible(charger.isInUse());
    ui->progressLabel->setVisible(charger.isInUse() && charger.getCurrentType() != Charger::CurrentType::AC);

    ui->socketIcon->setMaximumSize(Dimensions::EVC05_SOCKET_ICON_X_AXIS + (Dimensions::EVC05_SOCKET_ICON_X_AXIS * (!charger.isInUse())), Dimensions::EVC05_SOCKET_ICON_Y_AXIS);

    if (!(charger.isReserved()) && !(charger.isOutOfOrder()))
    {
        ui->reservationOrFaultedWidget->setVisible(false);
    }

    // Stop progress bar if AC type connector is not charging
    if (!charger.isChargeProgressing() && charger.getCurrentType() == Charger::CurrentType::AC) {
        ui->progressBar->setIndeterminate(false);
        setProgress(0);
    }

    string leftEvc05ChargerItemStylesheet;
    leftEvc05ChargerItemStylesheet = charger.isInUse() ? AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::EVC05_CHARGER_ITEM_CHARGING_LEFT) :
                                         AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::EVC05_CHARGER_ITEM_REGULAR_LEFT);
    // TODO : Initialize charging parameters such as power/energy/progress based on cached values.

    UIUtils::setStyleSheetAndUpdate(this,
                                    UIUtils::getStyleSheetForProjectAndChargerType("evc05",
                                                                                   charger.getTypeCode(),
                                                                                   leftEvc05ChargerItemStylesheet));

    // Reservation icon is set in the EVC05_CHARGER_ITEM_REGULAR_LEFT.
    if (charger.isOutOfOrder())
    {
        if (charger.isInUse() && charger.isCharging())
        {
            string outOfOrderIconStylesheet;
            outOfOrderIconStylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::EVC05_OUT_OF_ORDER);
            UIUtils::setStyleSheetAndUpdate(ui->chargerItemNotificationIconWidget, UIUtils::getStyleSheetForType(charger.getTypeCode(), outOfOrderIconStylesheet));
        }
        else // regular state
        {
            // All widgets are set again due to inactive background, because there are two main widgets.
            string outOfOrderInRegularCaseStylesheet;
            outOfOrderInRegularCaseStylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::EVC05_OUT_OF_ORDER);
            UIUtils::setStyleSheetAndUpdate(this, UIUtils::getStyleSheetForType(charger.getTypeCode(), outOfOrderInRegularCaseStylesheet));
        }
    }

    if (!(charger.getConnectorId() % ELEMENT_NUMBER_IN_LINE))
    {
        // Except the out of order case, only right sided background image is set by Stylesheet.
        // The other widgets which are created in the leftEvc05ChargerItemStylesheet are mirrored by the setLayoutDirection.
        // In the out of order case, all widgets are set again due to inactive background.
        if (charger.isOutOfOrder() && (!charger.isInUse()) && (!charger.isCharging()))
        {
            string outOfOrderRightStylesheet;
            outOfOrderRightStylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::EVC05_OUT_OF_ORDER_RIGHT);
            UIUtils::setStyleSheetAndUpdate(this, UIUtils::getStyleSheetForType(charger.getTypeCode(), outOfOrderRightStylesheet));
        }
        else
        {
            string rightBackgroundEvc05ChargerItemStylesheet;
            rightBackgroundEvc05ChargerItemStylesheet = charger.isInUse() ? AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::EVC05_CHARGER_ITEM_CHARGING_RIGHT) :
                                                  AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::EVC05_CHARGER_ITEM_REGULAR_RIGHT);
            UIUtils::setStyleSheetAndUpdate(ui->chargerItemWidget, UIUtils::getStyleSheetForType(charger.getTypeCode(), rightBackgroundEvc05ChargerItemStylesheet));
        }
        this->setLayoutDirection(Qt::RightToLeft);
    }
    ui->powerAndEnergyWidget->setVisible(charger.isInUse()); // TODO: setVisible of the widgets will be done after doing setStyleSheet.
}

Evc05ChargerItem::~Evc05ChargerItem()
{
    delete ui;
}

void Evc05ChargerItem::setOnClickListener(ChargerItemClickListener * clickListener)
{
    this->clickListener = clickListener;
}

void Evc05ChargerItem::onLanguageChanged()
{
    Language currentLanguage = LanguageManager::getInstance()->getCurrentLanguage();
    if (currentLanguage == Language::DANISH || currentLanguage == Language::FINNISH || currentLanguage == Language::FRENCH) {
        ui->connectorType->setStyleSheet("font-size: 16px;");
    } else {
        ui->connectorType->setStyleSheet("");
    }

    if (currentLanguage == Language::GERMAN || currentLanguage == Language::SPANISH || currentLanguage == Language::FRENCH || currentLanguage == Language::ROMANIAN || currentLanguage == Language::SLOVAKIAN) {
        ui->reservationOrFaultedLabel->setStyleSheet("font-size: 16px;");
    } else {
        ui->reservationOrFaultedLabel->setStyleSheet("");
    }

    if (currentLanguage == Languages::DANISH && charger.getType() == charger.AC_22)
    {
        UIUtils::setTextWithLineSpace(ui->connectorType, charger.getTypeName().getForLocale().c_str(), lineSpacingOfDanishConnectorTypeLabel);
    }
    else
    {
        ui->connectorType->setText(charger.getTypeName().getForLocale().c_str());
    }

    if (charger.isInUse())
    {
        onMeterValueReceived();
    }
    if (charger.isOutOfOrder())
    {
        ui->reservationOrFaultedLabel->setText(AppStrings::out_of_order.getForLocale().c_str());
    }
    else if (charger.isReserved())
    {
        ui->reservationOrFaultedLabel->setText(AppStrings::reservation.getForLocale().c_str());
    }
}

void Evc05ChargerItem::mouseReleaseEvent (QMouseEvent * event)
{
    if (this->clickListener != nullptr) {
        this->clickListener->onChargerItemClicked(charger.getConnectorId());
    }
}

// Power/energy values are gotten as W/Wh. Values less than 1000 is shown as W/Wh with 0 precision.
// Values higher than 1000 is shown as kW/kWh with 0 precision for higher than 100 kW/kWh, with 1 precision for less than 100 kW/kWh. (example: 1.4 kW/kWh, 85.3 kW/kWh, 135 kW/kWh, 850 W/Wh)
void Evc05ChargerItem::setPower(double power)
{
    std::stringstream strStream;

    if (power < TO_KW_AND_KWH_CONVERTOR_RATE)
    {
        strStream << power << " W";
    }
    else
    {
        if (power / TO_KW_AND_KWH_CONVERTOR_RATE < LIMIT_VALUE_TO_HIDE_DIGIT)
        {
            strStream << std::setprecision(1) << std::fixed;
        }
        else
        {
            strStream << std::setprecision(0) << std::fixed;
        }
        strStream << power / TO_KW_AND_KWH_CONVERTOR_RATE << " kW";
    }

    UIUtils::setTextElided(ui->powerLabel, AppStrings::power.getForLocale());
    ui->powerValue->setText(strStream.str().c_str());
}

void Evc05ChargerItem::setEnergy(double energy)
{
    std::stringstream strStream;

    if (energy < TO_KW_AND_KWH_CONVERTOR_RATE)
    {
        strStream << energy << " Wh";
    }
    else
    {
        if (energy / TO_KW_AND_KWH_CONVERTOR_RATE < LIMIT_VALUE_TO_HIDE_DIGIT)
        {
            strStream << std::setprecision(1) << std::fixed;
        }
        else
        {
            strStream << std::setprecision(0) << std::fixed;
        }
        strStream << energy / TO_KW_AND_KWH_CONVERTOR_RATE << " kWh";
    }

    UIUtils::setTextElided(ui->energyLabel, AppStrings::energy.getForLocale());
    ui->energyValue->setText(strStream.str().c_str());
}

void Evc05ChargerItem::setProgress(unsigned int progress)
{
    ui->progressBar->setProgress(progress);
    ui->progressLabel->setText((std::to_string(progress) + std::string("%")).c_str());
}

void Evc05ChargerItem::onMeterValueReceived()
{
    setPower(charger.getPower());
    setEnergy(charger.getEnergy());
    if (charger.getCurrentType() == Charger::CurrentType::DC) {
        setProgress(charger.getChargePercentage());
    }
}

void Evc05ChargerItem::setupBrand(QString brand)
{
    qDebug() << "Evc05ChargerItem:" << brand;
    ui->progressBar->setIndeterminate(false);
    ui->progressBar->setVisible(false);
    ui->progressLabel->setVisible(false);
//    TODO brand
}
