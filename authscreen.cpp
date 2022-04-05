#include "appstylesheets.h"
#include "authorizewidget.h"
#include "authscreen.h"
#include "dimensions.h"
#include "ui_authscreen.h"
#include <sstream>
#include <qboxlayout.h>
#include <utils/headers/stringutils.h>
#include <utils/headers/uiutils.h>
#include <errorinfo.h>

AuthScreen::AuthScreen(QWidget * parent, Charger & charger) :
    InnerScreen(parent, charger),
    ui(new Ui::AuthScreen)
{
    ui->setupUi(this);
}

AuthScreen::~AuthScreen()
{
    delete ui;
}

void AuthScreen::setupUi(MainWindow * mainWindow)
{
    InnerScreen::setupUi(mainWindow);
    QWidget * rightContainer = new QWidget(this);
    rightContainer->setGeometry(Dimensions::AUTHORIZE_WIDGET_X_AXIS, Dimensions::AUTHORIZE_WIDGET_Y_AXIS, Dimensions::AUTHORIZE_WIDGET_WIDTH, this->height());
    QBoxLayout * rightContainerLayout = new QBoxLayout(QBoxLayout::LeftToRight, rightContainer);
    authorizeWidget = new AuthorizeWidget();
    handleAlternativeAuthorization(mainWindow);
    rightContainerLayout->addWidget(authorizeWidget);
    rightContainerLayout->setAlignment(Qt::AlignCenter);

    UIUtils::setStyleSheetAndUpdate(ui->cancelChargingButton, QString((AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::CANCEL_CHARGING_ITEM)).c_str()));
    ui->cancelChargingButton->setVisible(getCharger().getType() == Charger::CCS); // TODO: Connection state will be used to set visibility of cancelChargingButton.
    ui->cancelChargingButton->raise();
    connect(ui->cancelChargingButton, &ClickableQWidget::clickedSignal, this, &AuthScreen::cancelChargingButtonClicked);
    connect(this, SIGNAL(unlockConnectorRequestSignal(int)), mainWindow, SLOT(unlockConnectorRequest(int)));
    connect(this, SIGNAL(errorDialogRequestSignal(int)), mainWindow, SLOT(onShowErrorDialogEvent(int)));

    if (getCharger().getLidError())
    {
        emit errorDialogRequestSignal(ErrorInfo::LID_ERROR);
    }
}

void AuthScreen::onLanguageChanged()
{
    InnerScreen::onLanguageChanged();
    if (authorizeWidget != nullptr) {
        authorizeWidget->onLanguageChanged();
    }
    ui->cancelChargingButtonLabel->setText(AppStrings::cancel_charging.getForLocale().c_str());
}

void AuthScreen::setupBrand(QString brand)
{
    qDebug() << "AuthScreen:" << brand;
//    TODO brand
}

void AuthScreen::cancelChargingButtonClicked()
{
    emit unlockConnectorRequestSignal(getCharger().getConnectorId());
}

void AuthScreen::handleAlternativeAuthorization(MainWindow * mainWindow)
{
    if (mainWindow->stateAlternativePaymentMethod) {
        std::stringstream strStream;
        strStream << mainWindow->chargePointId << "," << getCharger().getConnectorId();
        authorizeWidget->setQrData(strStream.str());
    } else {
        authorizeWidget->hideAlternativeAuthorization(true);
    }
}
