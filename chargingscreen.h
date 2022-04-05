#ifndef CHARGINGSCREEN_H
#define CHARGINGSCREEN_H

#include "authorizemessagedialog.h"
#include "innerscreen.h"

#include <model/headers/charger.h>
#include "mainwindow.h"

#include <QWidget>

namespace Ui {
class ChargingScreen;
}

class ChargingScreen : public InnerScreen
{
    Q_OBJECT

public:
    ChargingScreen(QWidget *parent, Charger & charger);
    ~ChargingScreen() override;
    void setupUi(MainWindow * mainWindow) override;   
    void onLanguageChanged() override;
    void setupBrand(QString brand) override;

private:
    Ui::ChargingScreen *ui;
    AuthorizeMessageDialog * authMessageDialog = nullptr;
    void setEnergy(double energy);
    void setPower(double power);
    void setChargePercentage(int percentage);
    void setRemainingTime(int remainingTime);
    bool stateAlternativePaymentMethod;

signals:
    void authorizeToStopRequestSignal(bool, int);
    void setVisibilityAlternativeAuthorizationSignal(bool);

public slots:
    void stopChargingButtonClicked();
    void onAuthorizationDialogClosed();
    void onMeterValueReceived();
    void onDurationUpdated();
    void onWarningMessageReceivedEvent();
    void setVisibilityAlternativeAuthorization(bool stateTrial);
};

#endif // CHARGINGSCREEN_H
