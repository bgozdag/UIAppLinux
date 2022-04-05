#include <model/headers/schukocharger.h>

#include <languages/generated/appstrings.h>

SchukoCharger::SchukoCharger(unsigned int connectorId, unsigned int chargingRate)
    : Charger(Charger::Type(SCHUKO), Charger::CurrentType(AC), AppStrings::schuko, connectorId, chargingRate, Charger::CableModel(TwoWay))
{
    typeCode = string("schuko");
    chargingUnit = string(" A");
}

SchukoCharger::~SchukoCharger()
{

}
