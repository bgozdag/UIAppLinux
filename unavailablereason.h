#ifndef UNAVAILABLEREASON_H
#define UNAVAILABLEREASON_H

namespace UnavailableReason {
enum UnavailableReason{
    INTERNAL,
    EXTERNAL,
    FIRMWARE_UPDATE,
    POWERLOSS,
    DC_POWER_NOT_AVAILABLE,
    COUNT
};
}

#endif // UNAVAILABLEREASON_H
