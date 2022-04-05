#ifndef EVC05HOMESCREEN_H
#define EVC05HOMESCREEN_H

#include "chargeritemclicklistener.h"
#include "evc05chargeritem.h"
#include "homescreennotificationbar.h"
#include "mainwindow.h"
#include "screen.h"

#include <qboxlayout.h>
#include <qwidget.h>

class Evc05HomeScreen : public Screen, public ChargerItemClickListener
{
    Q_OBJECT

public:
    Evc05HomeScreen(QWidget * parent, vector<Charger> & chargers);
    ~Evc05HomeScreen() override;
    void setupUi(MainWindow * mainWindow) override;
    void setupBrand(QString brand) override;
    void onChargerItemClicked(unsigned int connectorId) override;

private:
    void initHomeScreen(MainWindow * mainWindow);
    HomeScreenNotificationBar * homeScreenNotificationBar = nullptr;
    HomeScreenNotificationBar * homeScreenNotificationBarx = nullptr;
    vector<Evc05ChargerItem *> chargerItems;
    vector<Charger> & chargers;

signals:
    void chargerItemClickedSignal(unsigned int connectorId);

public slots:
    void onLanguageChanged() override;
};

#endif // EVC05HOMESCREEN_H
