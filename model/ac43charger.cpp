#include <model/headers/ac43charger.h>

#include <qcoreapplication.h>
#include <languages/generated/appstrings.h>

Ac43Charger::Ac43Charger(unsigned int connectorId, unsigned int chargingRate)
    : Charger(Charger::Type(AC_43), Charger::CurrentType(AC), AppStrings::ac_type_2, connectorId, chargingRate, Charger::CableModel(OneWay))
{
    typeCode = string("ac43");
}

Ac43Charger::~Ac43Charger()
{

}
