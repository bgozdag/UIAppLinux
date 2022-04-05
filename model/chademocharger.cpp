#include <model/headers/chademocharger.h>
#include <languages/generated/appstrings.h>

ChademoCharger::ChademoCharger(unsigned int connectorId, unsigned int chargingRate)
    : Charger(Charger::Type(CHADEMO), Charger::CurrentType(DC), AppStrings::chademo, connectorId, chargingRate, Charger::CableModel(OneWay))
{
    typeCode = string("chademo");
}

ChademoCharger::~ChademoCharger()
{

}
