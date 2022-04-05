#include <languages/generated/appstrings.h>
#include "chargeritem.h"
#include "chargeritemclicklistener.h"
#include "appstylesheets.h"
#include "ui_chargeritem.h"
#include "dimensions.h"
#include <string>
#include <utils/headers/stringutils.h>
#include <utils/headers/uiutils.h>
#include <QtQuick>
#include <qqmlcontext.h>
#include <qstyle.h>
#include <iomanip>
#include "languagemanager.h"

ChargerItem::ChargerItem(QWidget * parent, Charger & charger) :
    QFrame(parent),
    ui(new Ui::chargeritem),
    charger(charger)
{
    ui->setupUi(this);
    ui->connectorId->setText(to_string(charger.getConnectorId()).c_str());
    ui->connectorPower->setText((to_string(charger.getChargingRate()) + charger.getChargingUnit() + (charger.isHighPower() ? " HP" : "")).c_str());
    ui->progressBar->setIndeterminate(charger.getCurrentType() == Charger::CurrentType::AC);
    if (charger.getCurrentType() == Charger::CurrentType::AC) {
        ui->progressBar->setVisible(charger.isChargeProgressing());
    } else {
        ui->progressBar->setVisible(true);
    }

    if (!(charger.isReserved()) && !(charger.isOutOfOrder()) && !(charger.isInitializing()))
    {
        ui->reservationOrFaultedWidget->setVisible(false);
    }

    string chargerItemStylesheet;
    if (charger.isInUse()) {
        chargerItemStylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::CHARGER_ITEM_CHARGING);
        // TODO : Initialize charging parameters such as power/energy/progress based on cached values.
    } else {
        chargerItemStylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::CHARGER_ITEM_REGULAR);
    }

    UIUtils::setStyleSheetAndUpdate(this,
                                    UIUtils::getStyleSheetForProjectAndChargerType("evc03",
                                                                                   charger.getTypeCode(),
                                                                                   chargerItemStylesheet));

    // Reservation icon is set in the CHARGER_ITEM_REGULAR.
    if (charger.isOutOfOrder() || charger.isInitializing())
    {
        // In the case of requiring changes for the more than one widgets in the out of order state, a new style sheet should be created.
        ui->chargerItemNotificationIconWidget->setStyleSheet("background-image: url(:/assets/images/outof-order.png)");
    }
    ui->progressLabel->setVisible(charger.isInUse() && charger.getCurrentType() != Charger::CurrentType::AC);
    ui->powerLabel->setVisible(charger.isInUse());
    ui->energyLabel->setVisible(charger.isInUse());
    ui->chargerItemHoverWidget->setVisible(false);
}

ChargerItem::~ChargerItem()
{
    delete ui;
}

void ChargerItem::setOnClickListener(ChargerItemClickListener * clickListener)
{
    this->clickListener = clickListener;
}

void ChargerItem::onLanguageChanged()
{
    if (LanguageManager::getInstance()->getLanguageIndex() == Languages::DANISH && (charger.getType() == charger.AC_22 || charger.getType() == charger.AC_43))
    {
        ui->connectorType->setContentsMargins(0, 0, 0, 8);
        UIUtils::setTextWithLineSpace(ui->connectorType, charger.getTypeName().getForLocale().c_str(), lineSpacingOfDanishConnectorTypeLabel);
    }
    else
    {
        ui->connectorType->setContentsMargins(0, 0, 0, 0);
        ui->connectorType->setText(charger.getTypeName().getForLocale().c_str());
    }

    onMeterValueReceived();

    if (charger.isInitializing())
    {
        ui->reservationOrFaultedLabel->setText(AppStrings::connector_is_initializing.getForLocale().c_str());
    }
    else if (charger.isOutOfOrder())
    {
        ui->reservationOrFaultedLabel->setText(AppStrings::out_of_order.getForLocale().c_str());
    }
    else if (charger.isReserved())
    {
        ui->reservationOrFaultedLabel->setText(AppStrings::reservation.getForLocale().c_str());
    }
}

void ChargerItem::mousePressEvent (QMouseEvent *event)
{
    ui->chargerItemHoverWidget->setVisible(true);

    if (this->clickListener != nullptr) {
        this->clickListener->onChargerItemClicked(charger.getConnectorId());
    }
}

void ChargerItem::setPower(unsigned int power)
{
    std::stringstream strStream;
    strStream << std::setprecision(0) << std::fixed;
    strStream << AppStrings::power.getForLocale() << std::endl << power / TO_KW_AND_KWH_CONVERTOR_RATE << " kW";
    ui->powerLabel->setText(strStream.str().c_str());
}

void ChargerItem::setEnergy(double energy)
{
    std::stringstream strStream;
    strStream << std::setprecision(0) << std::fixed;
    strStream << AppStrings::energy.getForLocale() << std::endl << energy / TO_KW_AND_KWH_CONVERTOR_RATE << " kWh";
    ui->energyLabel->setText(strStream.str().c_str());
}

void ChargerItem::setProgress(unsigned int progress) {
    ui->progressBar->setProgress(progress);
    ui->progressLabel->setText((std::to_string(progress) + std::string("%")).c_str());
}

void ChargerItem::onMeterValueReceived()
{
    setPower(charger.getPower());
    setEnergy(charger.getEnergy());
    if (charger.getCurrentType() == Charger::CurrentType::DC) {
        setProgress(charger.getChargePercentage());
    }
}
