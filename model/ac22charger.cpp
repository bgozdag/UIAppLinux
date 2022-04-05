#include <model/headers/ac22charger.h>

#include <languages/generated/appstrings.h>

Ac22Charger::Ac22Charger(unsigned int connectorId, unsigned int chargingRate)
    : Charger(Charger::Type(AC_22), Charger::CurrentType(AC), AppStrings::ac_type_2, connectorId, chargingRate, Charger::CableModel(TwoWay))
{
    typeCode = string("ac22");
}

Ac22Charger::~Ac22Charger()
{

}
