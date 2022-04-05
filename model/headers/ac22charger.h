#ifndef AC22CHARGER_H
#define AC22CHARGER_H

#include "charger.h"

class Ac22Charger : public Charger
{
public:
    Ac22Charger(unsigned int connectorId, unsigned int chargingRate);
    ~Ac22Charger();
};

#endif // AC22CHARGER_H
