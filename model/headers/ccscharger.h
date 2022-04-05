#ifndef CCSCHARGER_H
#define CCSCHARGER_H

#include "charger.h"

class CcsCharger : public Charger
{
public:
    CcsCharger(unsigned int connectorId, unsigned int chargingRate);
    ~CcsCharger();
};

#endif // CCSCHARGER_H
