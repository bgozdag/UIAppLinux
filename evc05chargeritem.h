#ifndef EVC05CHARGERITEM_H
#define EVC05CHARGERITEM_H

#define ELEMENT_NUMBER_IN_LINE 2

#include "chargeritemclicklistener.h"
#include "languages/generated/translationstring.h"

#include <model/headers/charger.h>

#include <QWidget>
#include <qframe.h>

namespace Ui {
class Evc05ChargerItem;
}

class Evc05ChargerItem : public QFrame
{
    Q_OBJECT

public:
    explicit Evc05ChargerItem(QWidget *parent, Charger & charger);
    ~Evc05ChargerItem() override;
    void setOnClickListener(ChargerItemClickListener * clickListener);
    void onLanguageChanged();
    void setupBrand(QString brand);
    void setPower(double power);
    void setEnergy(double energy);
    void setProgress(unsigned int progress);
    void mouseReleaseEvent ( QMouseEvent * event ) override;

private:
    Ui::Evc05ChargerItem *ui;
    Charger& charger;
    unsigned int connectorId;
    ChargerItemClickListener * clickListener = nullptr;
    double lineSpacingOfDanishConnectorTypeLabel = 0.6;

public slots:
    void onMeterValueReceived();
};

#endif // EVC05CHARGERITEM_H
