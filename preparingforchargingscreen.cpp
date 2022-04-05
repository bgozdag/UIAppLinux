#include "appstylesheets.h"
#include "dimensions.h"
#include "preparingforchargingscreen.h"
#include "spinnerwidget.h"
#include "ui_preparingforchargingscreen.h"

#include <utils/headers/stringutils.h>
#include <utils/headers/uiutils.h>

#include <languages/generated/appstrings.h>

PreparingForChargingScreen::PreparingForChargingScreen(QWidget *parent, Charger & charger) :
    InnerScreen(parent, charger),
    ui(new Ui::PreparingForChargingScreen)
{
    ui->setupUi(this);
}

PreparingForChargingScreen::~PreparingForChargingScreen()
{
    delete ui;
}

void PreparingForChargingScreen::setupUi(MainWindow * mainWindow)
{
    InnerScreen::setupUi(mainWindow);

    string preparingChargingItemStylesheet;
    string chargerCode = getCharger().getTypeCode();

    if (mainWindow->currentProjectType == MainWindow::Evc05)
    {
        chargerCode = "common";
    }

    preparingChargingItemStylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::PREPARING_CHARGING_ITEM);
    UIUtils::setStyleSheetAndUpdate(this,
                                    UIUtils::getStyleSheetForProjectAndChargerType(mainWindow->getProjectTypeAsString(mainWindow->currentProjectType),
                                                                                   chargerCode,
                                                                                   preparingChargingItemStylesheet));

    ui->progressSpinnerWidget->setSpinnerSource(UIUtils::getStyleSheetForType(getCharger().getTypeCode(), BASE_SPINNER_SRC));
}

void PreparingForChargingScreen::setChargingLabel(const TranslationString inputText)
{
    ui->chargingLabel->setText(inputText.getForLocale().c_str());
}

void PreparingForChargingScreen::onLanguageChanged()
{
    InnerScreen::onLanguageChanged();
    ui->chargingLabel->setText(AppStrings::preparing_for_charging.getForLocale().c_str());
}


void PreparingForChargingScreen::setupBrand(QString brand)
{
    qDebug() << "PreparingForChargingScreen:" << brand;
//    TODO brand
}
