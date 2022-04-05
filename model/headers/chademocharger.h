#ifndef CHADEMOCHARGER_H
#define CHADEMOCHARGER_H

#include "charger.h"

class ChademoCharger : public Charger
{
public:
    ChademoCharger(unsigned int connectorId, unsigned int chargingRate);
    ~ChademoCharger();
};

#endif // CHADEMOCHARGER_H
