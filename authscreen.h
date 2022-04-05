#ifndef AUTHSCREEN_H
#define AUTHSCREEN_H

#include "authorizewidget.h"
#include "innerscreen.h"
#include "mainwindow.h"

#include <QWidget>

namespace Ui {
class AuthScreen;
}

class AuthScreen : public InnerScreen
{
    Q_OBJECT

public:
    AuthScreen(QWidget * parent, Charger & charger);
    ~AuthScreen() override;
    void setupUi(MainWindow * mainWindow) override;
    void setupBrand(QString brand) override;

private:
    Ui::AuthScreen *ui;
    AuthorizeWidget * authorizeWidget = nullptr;
    void handleAlternativeAuthorization(MainWindow * mainWindow);

signals:
    void unlockConnectorRequestSignal(int);
    void errorDialogRequestSignal(int);

public slots:
    void onLanguageChanged() override;
    void cancelChargingButtonClicked();
};

#endif // AUTHSCREEN_H
