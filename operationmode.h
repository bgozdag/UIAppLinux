#ifndef OPERATIONMODE_H
#define OPERATIONMODE_H

enum OperationMode{
    TRADITIONAL_OCPP,
    FREE_AUTHORIZE_NO_OCPP,
    FREE_AUTHORIZE_OCPP,
    WHITE_LISTED_OCPP,
    WHITE_LISTED_NOOCPP,
    FIXED_IDTAG_OCPP,
    COUNT
};

#endif // OPERATIONMODE_H