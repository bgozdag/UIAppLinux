#include "dimensions.h"
#include "evc05chargeritem.h"
#include "evc05devicewidget.h"
#include "evc05homescreen.h"
#include "mainwindow.h"
#include "screen.h"

#include <QDebug>
#include <qboxlayout.h>
#include <qgridlayout.h>

Evc05HomeScreen::Evc05HomeScreen(QWidget * parent, vector<Charger> & chargers) : Screen(parent), chargers(chargers)
{

}

Evc05HomeScreen::~Evc05HomeScreen()
{

}

void Evc05HomeScreen::setupUi(MainWindow * mainWindow) {
    connect(this, &Evc05HomeScreen::chargerItemClickedSignal, mainWindow, &MainWindow::onChargerSelected);
    initHomeScreen(mainWindow);
    mainWindow->hideHomeCancelButton(true, true);
    onLanguageChanged();
}

void Evc05HomeScreen::onChargerItemClicked(unsigned int connectorId) {
    emit chargerItemClickedSignal(connectorId);
}

void Evc05HomeScreen::initHomeScreen(MainWindow * mainWindow) {
    Evc05DeviceWidget * evc05DeviceItem = new Evc05DeviceWidget(this);
    evc05DeviceItem->move(Dimensions::EVC05_DEVICE_WIDGET_X_AXIS, Dimensions::EVC05_DEVICE_WIDGET_Y_AXIS);

    QWidget *mainWidget = new QWidget(this);

    QWidget *leftWidget = new QWidget(mainWidget);
    QWidget *rightWidget = new QWidget(mainWidget);

    mainWidget->setGeometry(0,
                            Dimensions::EVC05_CHARGER_ITEM_MAIN_WIDGET_Y_AXIS,
                            Dimensions::WINDOW_WIDTH,
                            chargers.size() <= ELEMENT_NUMBER_IN_LINE ? Dimensions::EVC05_2_CHARGER_CASE_WIDGET_HEIGHT : Dimensions::EVC05_4_CHARGER_CASE_WIDGET_HEIGHT);
    leftWidget->setGeometry(0,
                            0,
                            Dimensions::EVC05_CHARGER_ITEM_WIDGET_WIDTH,
                            chargers.size() <= ELEMENT_NUMBER_IN_LINE ? Dimensions::EVC05_2_CHARGER_CASE_WIDGET_HEIGHT : Dimensions::EVC05_4_CHARGER_CASE_WIDGET_HEIGHT);
    rightWidget->setGeometry(Dimensions::EVC05_CHARGER_ITEM_RIGHT_WIDGET_X_AXIS,
                             0,
                             Dimensions::EVC05_CHARGER_ITEM_WIDGET_WIDTH,
                             chargers.size() <= ELEMENT_NUMBER_IN_LINE ? Dimensions::EVC05_2_CHARGER_CASE_WIDGET_HEIGHT :
                                                                         (chargers.size() == (ELEMENT_NUMBER_IN_LINE + 1) ? Dimensions::EVC05_3_CHARGER_CASE_WIDGET_HEIGHT : Dimensions::EVC05_4_CHARGER_CASE_WIDGET_HEIGHT));
    QVBoxLayout *firstColumnChargerItemLayout = new QVBoxLayout();
    QVBoxLayout *secondColumnChargerItemLayout = new QVBoxLayout();

    for (unsigned int i = 0; i < chargers.size(); i++)
    {
        Evc05ChargerItem * firstLineChargerItem = new Evc05ChargerItem(this, chargers[i]);
        connect(mainWindow, SIGNAL(meterValueSignal()), firstLineChargerItem, SLOT(onMeterValueReceived()));

        chargerItems.push_back(firstLineChargerItem);
        firstLineChargerItem->setOnClickListener(this);

        if (!(i % ELEMENT_NUMBER_IN_LINE))
        {
            firstColumnChargerItemLayout->addWidget(firstLineChargerItem);
        }

        else
        {
            secondColumnChargerItemLayout->addWidget(firstLineChargerItem);
        }
    }

    firstColumnChargerItemLayout->setContentsMargins(0,
                                                     chargers.size() <= ELEMENT_NUMBER_IN_LINE ? Dimensions::EVC05_2_CHARGER_CASE_TOP_MARGIN : Dimensions::EVC05_4_CHARGER_CASE_TOP_MARGIN,
                                                     0,
                                                     Dimensions::EVC05_CHARGER_ITEM_BOTTOM_MARGIN);
    secondColumnChargerItemLayout->setContentsMargins(0,
                                                      chargers.size() <= ELEMENT_NUMBER_IN_LINE ? Dimensions::EVC05_2_CHARGER_CASE_TOP_MARGIN : Dimensions::EVC05_4_CHARGER_CASE_TOP_MARGIN,
                                                      0,
                                                      Dimensions::EVC05_CHARGER_ITEM_BOTTOM_MARGIN);

    leftWidget->setLayout(firstColumnChargerItemLayout);
    rightWidget->setLayout(secondColumnChargerItemLayout);

    homeScreenNotificationBar = new HomeScreenNotificationBar(this);
    homeScreenNotificationBar->move(0, Dimensions::EVC05_HOMESCREEN_NOTIFICATION_BAR_Y_AXIS);

    homeScreenNotificationBar->raise();
}

void Evc05HomeScreen::onLanguageChanged()
{
    for (Evc05ChargerItem * chargerItem : chargerItems) {
        chargerItem->onLanguageChanged();
    }

    homeScreenNotificationBar->onLanguageChanged();
}

void Evc05HomeScreen::setupBrand(QString brand)
{
    qDebug() << "HomeScreen:" << brand;
//    TODO brand
}
