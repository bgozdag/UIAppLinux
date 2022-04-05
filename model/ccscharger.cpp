#include <model/headers/ccscharger.h>
#include <languages/generated/appstrings.h>

CcsCharger::CcsCharger(unsigned int connectorId, unsigned int chargingRate)
    : Charger(Charger::Type(CCS), Charger::CurrentType(DC), AppStrings::ccs, connectorId, chargingRate, Charger::CableModel(OneWay))
{
    typeCode = string("ccs");
}

CcsCharger::~CcsCharger()
{

}
