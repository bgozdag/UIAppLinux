#include <model/headers/charger.h>
#include <qdebug.h>

Charger::Charger(Type type, CurrentType currentType, TranslationString typeName, unsigned int connectorId, unsigned int chargingRate, CableModel cableModel)
    : connectorId(connectorId)
    , chargingRate(chargingRate)
    , type(type)
    , currentType(currentType)
    , cableModel(cableModel)
    , durationTimer(new QTimer())
    , typeName(typeName)
{
    durationTimer->connect(durationTimer, &QTimer::timeout, [this]() {
        updateChargeDuration();
    });
}

// Normally, charger data is not expected to be copied, therefore meter values and charging states are not handled.
Charger::Charger(const Charger& obj)
    : connectorId(obj.connectorId)
    , chargingRate(obj.chargingRate)
    , type(obj.type)
    , currentType(obj.currentType)
    , cableModel(obj.cableModel)
    , durationTimer(new QTimer())
    , typeName(obj.typeName)
{
    this->chargingUnit = obj.chargingUnit;
    this->typeCode = obj.typeCode;
    durationTimer->connect(durationTimer, &QTimer::timeout, [this]() {
        updateChargeDuration();
    });
}

Charger::~Charger()
{
    if (durationTimer != nullptr) {
        durationTimer->deleteLater();
        durationTimer = nullptr;
    }
}

Charger::Type Charger::getTypeFromString(std::string& type) {
    if (type.compare("AC_22") == 0) {
        return Charger::Type::AC_22;
    } else if (type.compare("AC_43") == 0) {
        return Charger::Type::AC_43;
    } else if (type.compare("SCHUKO") == 0) {
        return Charger::Type::SCHUKO;
    } else if (type.compare("CCS") == 0) {
        return Charger::Type::CCS;
    } else if (type.compare("CHADEMO") == 0) {
        return Charger::Type::CHADEMO;
    }

    qDebug() << "Following charger is not found, returning AC_22 instead = " << type.c_str();
    return Charger::Type::AC_22;
}

unsigned int Charger::getConnectorId() const
{
    return connectorId;
}

unsigned int Charger::getChargingRate() const
{
    return chargingRate;
}

Charger::Type Charger::getType() const
{
    return type;
}

string Charger::getTypeCode() const
{
    return typeCode;
}

string Charger::getChargingUnit() const
{
    return chargingUnit;
}

Charger::CurrentType Charger::getCurrentType() const
{
    return currentType;
}

Charger::CableModel Charger::getCableModel() const
{
    return cableModel;
}

bool Charger::isCharging() const
{
    return charging;
}

void Charger::setCharging(bool value)
{
    if (charging && !value) {
        durationTimer->stop();
    } else if (!charging && value) {
        durationTimer->start(60000); // Every minute
    }
    charging = value;
}

bool Charger::isOutOfOrder() const
{
    return outOfOrder;
}

void Charger::setOutOfOrder(bool value)
{
    outOfOrder = value;
}

bool Charger::isReserved() const
{
    return reserved;
}

void Charger::setReserved(bool value)
{
    reserved = value;
}

bool Charger::isInUse() const
{
    return inUse;
}

void Charger::setInUse(bool value)
{
    inUse = value;
}

double Charger::getEnergy() const
{
    return energy;
}

void Charger::setEnergy(double value)
{
    energy = value;
}

double Charger::getPower() const
{
    return power;
}

void Charger::setPower(double value)
{
    power = value;
}

int Charger::getRemainingTime() const
{
    return remainingTime;
}

void Charger::setRemainingTime(int value)
{
    remainingTime = value;
}

int Charger::getChargePercentage() const
{
    return chargePercentage;
}

void Charger::setChargePercentage(int value)
{
    chargePercentage = value;
}

int Charger::getChargeDuration() const
{
    return chargeDuration;
}

void Charger::setChargeDuration(int value)
{
    chargeDuration = value;
}

void Charger::updateChargeDuration()
{
    chargeDuration++;
}

void Charger::clearChargeValues()
{
    energy = 0;
    power = 0;
    remainingTime = 0;
    chargePercentage = 0;
    chargeDuration = 0;
}

QTimer *Charger::getDurationTimer() const
{
    return durationTimer;
}

bool Charger::isChargeProgressing() const
{
    return chargeProgressing;
}

void Charger::setChargeProgressing(bool value)
{
    chargeProgressing = value;
}

bool Charger::isInitializing() const
{
    return initializing;
}

void Charger::setInitializing(bool value)
{
    initializing = value;
}

bool Charger::getLidError() const
{
    return lidError;
}

void Charger::setLidError(bool value)
{
    lidError = value;
}

vector<UnavailableReason::UnavailableReason> Charger::getUnavailableReasons() const
{
    return unavailableReasons;
}

void Charger::setUnavailableReasons(const vector<UnavailableReason::UnavailableReason> &value)
{
    unavailableReasons = value;
}

bool Charger::isHighPower() const
{
    return currentType == CurrentType::DC && chargingRate > HIGH_POWER;
}

FaultReason::FaultReason Charger::getFaultReason() const
{
    return faultReason;
}

void Charger::setFaultReason(const FaultReason::FaultReason &value)
{
    faultReason = value;
}

TranslationString Charger::getTypeName() const
{
    return typeName;
}
