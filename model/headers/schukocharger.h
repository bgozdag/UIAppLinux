#ifndef SCHUKOCHARGER_H
#define SCHUKOCHARGER_H

#include "charger.h"

class SchukoCharger : public Charger
{
public:
    SchukoCharger(unsigned int connectorId, unsigned int chargingRate);
    ~SchukoCharger();
};

#endif // SCHUKOCHARGER_H
