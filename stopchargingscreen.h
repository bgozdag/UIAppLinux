#ifndef STOPCHARGINGSCREEN_H
#define STOPCHARGINGSCREEN_H

#include "preparingforchargingscreen.h"

#include <QWidget>

namespace Ui {
class StopChargingScreen;
}

class StopChargingScreen : public PreparingForChargingScreen
{
    Q_OBJECT

public:
    StopChargingScreen(QWidget *parent, Charger & charger);
    ~StopChargingScreen() override;
    void setupUi(MainWindow * mainWindow) override;
    void setupBrand(QString brand) override;
    void onLanguageChanged() override;

};

#endif // STOPCHARGINGSCREEN_H
