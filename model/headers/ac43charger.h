#ifndef AC43CHARGER_H
#define AC43CHARGER_H

#include "charger.h"

class Ac43Charger : public Charger
{
public:
    Ac43Charger(unsigned int connectorId, unsigned int chargingRate);
    ~Ac43Charger();
};

#endif // AC43CHARGER_H
