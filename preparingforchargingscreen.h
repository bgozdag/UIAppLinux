#ifndef PREPARINGFORCHARGINGSCREEN_H
#define PREPARINGFORCHARGINGSCREEN_H

#include "innerscreen.h"

#include <model/headers/charger.h>
#include "mainwindow.h"

#include <QWidget>

namespace Ui {
class PreparingForChargingScreen;
}

class PreparingForChargingScreen : public InnerScreen
{
    Q_OBJECT

public:
    PreparingForChargingScreen(QWidget *parent, Charger & charger);
    ~PreparingForChargingScreen() override;
    void setupUi(MainWindow * mainWindow) override;
    void setupBrand(QString brand) override;
    void setChargingLabel(const TranslationString inputText);
    void onLanguageChanged() override;

private:
    const std::string BASE_SPINNER_SRC = "qrc:/assets/images/<charger_code>_spinner.png";
    Ui::PreparingForChargingScreen *ui;
};

#endif // PREPARINGFORCHARGINGSCREEN_H
