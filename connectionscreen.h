#ifndef CONNECTIONSCREEN_H
#define CONNECTIONSCREEN_H

#include "innerscreen.h"

#include <model/headers/charger.h>
#include "mainwindow.h"

#include <QWidget>

namespace Ui {
class ConnectionScreen;
}

class ConnectionScreen : public InnerScreen
{
    Q_OBJECT

public:
    ConnectionScreen(QWidget *parent, Charger & charger);
    ~ConnectionScreen() override;
    void setupUi(MainWindow * mainWindow) override;
    void onLanguageChanged() override;
    void setupBrand(QString brand) override;

private:
    Ui::ConnectionScreen *ui;

signals:
    void notSupportedConnectorReadyToStartRequestSignal(int);

public slots:
    void continueChargingButtonClicked();
};

#endif // CONNECTIONSCREEN_H
