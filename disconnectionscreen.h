#ifndef DISCONNECTIONSCREEN_H
#define DISCONNECTIONSCREEN_H

#define ENERGY_DIGIT_NUMBER_FOR_EVC03 3
#define ENERGY_DIGIT_NUMBER_FOR_EVC05 1

#include "innerscreen.h"

#include <model/headers/charger.h>
#include "mainwindow.h"

#include <QWidget>

namespace Ui {
class DisconnectionScreen;
}

class DisconnectionScreen : public InnerScreen
{
    Q_OBJECT

public:
    DisconnectionScreen(QWidget *parent, Charger & charger);
    ~DisconnectionScreen() override;
    void setupUi(MainWindow * mainWindow) override;
    void onLanguageChanged() override;
    void setupBrand(QString brand) override;
    void setDisconnectionLabel(const TranslationString inputText);
    void setStyleSheetVehicleAndStationWidget(string styleSheet, string projectTypeCode);

private:
    Ui::DisconnectionScreen *ui;
    void setEnergy(MainWindow * mainWindow, double energy);
    void setChargePercentage(int percentage);
    void setChargeDuration(int duration);
};

#endif // DISCONNECTIONSCREEN_H
