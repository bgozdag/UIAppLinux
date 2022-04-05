#ifndef CHARGER_H
#define CHARGER_H

#define TO_KW_AND_KWH_CONVERTOR_RATE 1000
#define LIMIT_VALUE_TO_HIDE_DIGIT 100

#include <iostream>
#include <qstring.h>
#include <qtimer.h>
#include <languages/generated/translationstring.h>

#include "unavailablereason.h"
#include "faultreason.h"

using namespace std;

#define HIGH_POWER 150

class Charger
{
public:
    enum Type {
        AC_43,
        AC_22,
        CHADEMO,
        CCS,
        SCHUKO
    };

    enum CurrentType {
        AC,
        DC
    };

    enum CableModel {
        OneWay,
        TwoWay
    };

    Charger(Type type, CurrentType currentType, TranslationString typeName, unsigned int connectorId, unsigned int chargingRate, CableModel cableModel);
    Charger(const Charger&);
    ~Charger();
    static Charger::Type getTypeFromString(std::string& type);

    unsigned int getConnectorId() const;
    unsigned int getChargingRate() const;

    TranslationString getTypeName() const;
    Type getType() const;
    string getTypeCode() const;
    string getChargingUnit() const;
    CurrentType getCurrentType() const;
    CableModel getCableModel() const;

    bool isCharging() const;
    void setCharging(bool value);

    bool isOutOfOrder() const;
    void setOutOfOrder(bool value);

    bool isReserved() const;
    void setReserved(bool value);

    bool isInUse() const;
    void setInUse(bool value);

    double getEnergy() const;
    void setEnergy(double value);

    double getPower() const;
    void setPower(double value);

    int getRemainingTime() const;
    void setRemainingTime(int value);

    int getChargePercentage() const;
    void setChargePercentage(int value);

    int getChargeDuration() const;
    void setChargeDuration(int value);

    void clearChargeValues();

    QTimer *getDurationTimer() const;

    bool isChargeProgressing() const;
    void setChargeProgressing(bool value);

    bool isInitializing() const;
    void setInitializing(bool value);

    bool getLidError() const;
    void setLidError(bool value);

    vector<UnavailableReason::UnavailableReason> getUnavailableReasons() const;
    void setUnavailableReasons(const vector<UnavailableReason::UnavailableReason> &value);

    bool isHighPower() const;

    FaultReason::FaultReason getFaultReason() const;
    void setFaultReason(const FaultReason::FaultReason &value);

private:
    unsigned int connectorId;
    unsigned int chargingRate;
    Type type;
    CurrentType currentType;
    CableModel cableModel;
    bool charging = false;
    bool initializing = false;
    bool outOfOrder = false;
    bool reserved = false;
    bool inUse = false;
    bool chargeProgressing = false;
    bool lidError = false;
    vector<UnavailableReason::UnavailableReason> unavailableReasons;
    FaultReason::FaultReason faultReason = FaultReason::FaultReason::NO_ERROR;

    // Meter Values
    double energy = 0;
    double power = 0;
    int remainingTime = 0;
    int chargePercentage = 0;

    int chargeDuration = 0;
    QTimer* durationTimer = nullptr;

protected:
    string typeCode;
    string chargingUnit = " kW";

    // UI Related Data
    TranslationString typeName;

public slots:
    void updateChargeDuration();
};

#endif // CHARGER_H
