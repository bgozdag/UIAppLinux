#ifndef INNERSCREEN_H
#define INNERSCREEN_H

#include "screen.h"

#include <QWidget>

#include <model/headers/charger.h>
#include <utils/headers/stringutils.h>

namespace Ui {
class InnerScreen;
}

class InnerScreen : public Screen
{
    Q_OBJECT

public:
    explicit InnerScreen(QWidget * parent, Charger & currentCharger);
    ~InnerScreen() override;
    void setupUi(MainWindow * mainWindow) override;
    void hideSocketObject();
    void setupBrand(QString brand) override;

    Charger &getCharger() const;

private:
    Ui::InnerScreen *ui;
    Charger & charger;
    double lineSpacingOfDanishConnectorTypeLabel = 0.65;
    string serviceContact;

public slots:
    void onLanguageChanged() override;
};

#endif // INNERSCREEN_H
