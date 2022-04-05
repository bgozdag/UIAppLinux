#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include "chargeritemclicklistener.h"
#include "homescreennotificationbar.h"
#include "mainwindow.h"
#include "screen.h"

#include <qboxlayout.h>
#include <qwidget.h>

class HomeScreen : public Screen, public ChargerItemClickListener
{
    Q_OBJECT

public:
    HomeScreen(QWidget * parent, vector<Charger> & chargers);
    ~HomeScreen() override;
    void setupUi(MainWindow * mainWindow) override;
    void onChargerItemClicked(unsigned int connectorId) override;
    void setupBrand(QString brand) override;

private:
    void initHomeScreen(MainWindow * mainWindow);
    HomeScreenNotificationBar * homeScreenNotificationBar = nullptr;
    vector<ChargerItem *> chargerItems;
    vector<Charger> & chargers;

signals:
    void chargerItemClickedSignal(unsigned int connectorId);

public slots:
    void onLanguageChanged() override;
};

#endif // HOMESCREEN_H
