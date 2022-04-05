#ifndef APPRECIATESCREEN_H
#define APPRECIATESCREEN_H

#include "disconnectionscreen.h"

#include <QWidget>

namespace Ui {
class AppreciateScreen;
}

class AppreciateScreen : public DisconnectionScreen
{
    Q_OBJECT

public:
    AppreciateScreen(QWidget *parent, Charger & charger);
    ~AppreciateScreen() override;
    void setupUi(MainWindow * mainWindow) override;
    void setupBrand(QString brand) override;
    void onLanguageChanged() override;

};

#endif // APPRECIATESCREEN_H
