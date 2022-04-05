#ifndef CHARGERITEM_H
#define CHARGERITEM_H

#define MAX_CONNECTOR_NUMBER 4

#include "chargeritemclicklistener.h"
#include "languages/generated/translationstring.h"

#include <model/headers/charger.h>

#include <QWidget>
#include <qframe.h>

namespace Ui {
class chargeritem;
}

class ChargerItem : public QFrame
{
    Q_OBJECT

public:
    explicit ChargerItem(QWidget *parent, Charger & charger);
    ~ChargerItem() override;
    void setOnClickListener(ChargerItemClickListener * clickListener);
    void onLanguageChanged();
    void setupBrand(QString brand);
    void setPower(unsigned int power);
    void setEnergy(double energy);
    void setProgress(unsigned int progress);
    void mousePressEvent ( QMouseEvent * event ) override;

private:
    Ui::chargeritem *ui;
    Charger& charger;
    unsigned int connectorId;
    ChargerItemClickListener * clickListener = nullptr;
    double lineSpacingOfDanishConnectorTypeLabel = 0.65;

public slots:
    void onMeterValueReceived();
};

#endif // CHARGERITEM_H


