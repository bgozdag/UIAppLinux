#include "chargeritem.h"
#include "dimensions.h"
#include "homescreen.h"
#include "homescreennotificationbar.h"
#include "mainwindow.h"
#include "screen.h"

#include <QDebug>
#include <qboxlayout.h>
#include <QtMath>

HomeScreen::HomeScreen(QWidget * parent, vector<Charger> & chargers) : Screen(parent), chargers(chargers)
{

}

HomeScreen::~HomeScreen()
{

}

void HomeScreen::setupUi(MainWindow * mainWindow) {
    connect(this, &HomeScreen::chargerItemClickedSignal, mainWindow, &MainWindow::onChargerSelected);
    initHomeScreen(mainWindow);
    mainWindow->hideHomeCancelButton(true, true);
    onLanguageChanged();
}

void HomeScreen::onChargerItemClicked(unsigned int connectorId) {
    emit chargerItemClickedSignal(connectorId);
}

void HomeScreen::initHomeScreen(MainWindow * mainWindow) {
    QWidget * mainWidget = new QWidget(this);
    mainWidget->setGeometry(0, 0, Dimensions::WINDOW_WIDTH, Dimensions::WINDOW_HEIGHT - Dimensions::FOOTER_HEIGHT);

    QBoxLayout* layoutToCenter = new QBoxLayout(QBoxLayout::LeftToRight, mainWidget);

    if (chargers.size() == MAX_CONNECTOR_NUMBER)
    {
        layoutToCenter->setContentsMargins(0, 0, Dimensions::EVC03_4_CHARGER_CASE_RIGHT_MARGIN, Dimensions::EVC03_ALL_CHARGER_CASE_BOTTOM_MARGIN);
    }
    else
    {
        layoutToCenter->setAlignment( Qt::AlignHCenter);
    }

    for (unsigned int i = 0; i < chargers.size(); i++)
    {
        ChargerItem * chargerItem = new ChargerItem(mainWidget, chargers[i]);
        chargerItems.push_back(chargerItem);
        chargerItem->setOnClickListener(this);
        connect(mainWindow, SIGNAL(meterValueSignal()), chargerItem, SLOT(onMeterValueReceived()));
        layoutToCenter->addWidget(chargerItem);
    }

    homeScreenNotificationBar = new HomeScreenNotificationBar(this);
    homeScreenNotificationBar->move(0, Dimensions::EVC03_HOMESCREEN_NOTIFICATION_BAR_Y_AXIS);
}

void HomeScreen::onLanguageChanged()
{
    for (ChargerItem * chargerItem : chargerItems) {
        chargerItem->onLanguageChanged();
    }

    homeScreenNotificationBar->onLanguageChanged();
}

void HomeScreen::setupBrand(QString brand)
{
    qDebug() << "HomeScreen:" << brand;
//    TODO brand
}
