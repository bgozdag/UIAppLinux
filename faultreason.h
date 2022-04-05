#ifndef FAULTREASON_H
#define FAULTREASON_H

namespace FaultReason {
enum FaultReason{
    NO_ERROR,
    OTHER_ERROR,
    EMERGENCY_BUTTON_ERROR,
    COUNT
};

static FaultReason getFaultReasonFromId(int id) {
    if (id < FaultReason::COUNT && id >= FaultReason::NO_ERROR) {
        return static_cast<FaultReason>(id);
    } else {
        return FaultReason::OTHER_ERROR;
    }
}

}


#endif // FAULTREASON_H
