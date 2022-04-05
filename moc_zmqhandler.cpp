/****************************************************************************
** Meta object code from reading C++ file 'zmqhandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "zmqhandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zmqhandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ZmqHandler_t {
    QByteArrayData data[61];
    char stringdata0[1125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZmqHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZmqHandler_t qt_meta_stringdata_ZmqHandler = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ZmqHandler"
QT_MOC_LITERAL(1, 11, 18), // "changeScreenSignal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "screenId"
QT_MOC_LITERAL(4, 40, 11), // "connectorId"
QT_MOC_LITERAL(5, 52, 21), // "showErrorDialogSignal"
QT_MOC_LITERAL(6, 74, 9), // "errorType"
QT_MOC_LITERAL(7, 84, 18), // "stateChangedSignal"
QT_MOC_LITERAL(8, 103, 5), // "inUse"
QT_MOC_LITERAL(9, 109, 8), // "charging"
QT_MOC_LITERAL(10, 118, 8), // "reserved"
QT_MOC_LITERAL(11, 127, 12), // "initializing"
QT_MOC_LITERAL(12, 140, 7), // "faulted"
QT_MOC_LITERAL(13, 148, 11), // "unavailable"
QT_MOC_LITERAL(14, 160, 17), // "chargeProgressing"
QT_MOC_LITERAL(15, 178, 49), // "std::vector<UnavailableReason..."
QT_MOC_LITERAL(16, 228, 23), // "unavailableReasonVector"
QT_MOC_LITERAL(17, 252, 24), // "FaultReason::FaultReason"
QT_MOC_LITERAL(18, 277, 11), // "faultReason"
QT_MOC_LITERAL(19, 289, 16), // "meterValueSignal"
QT_MOC_LITERAL(20, 306, 21), // "clearMeterValueSignal"
QT_MOC_LITERAL(21, 328, 20), // "changeLanguageSignal"
QT_MOC_LITERAL(22, 349, 8), // "Language"
QT_MOC_LITERAL(23, 358, 8), // "language"
QT_MOC_LITERAL(24, 367, 9), // "saveParam"
QT_MOC_LITERAL(25, 377, 27), // "changeDefaultLanguageSignal"
QT_MOC_LITERAL(26, 405, 29), // "projectTypeCodeReceivedSignal"
QT_MOC_LITERAL(27, 435, 11), // "std::string"
QT_MOC_LITERAL(28, 447, 11), // "projectType"
QT_MOC_LITERAL(29, 459, 32), // "serviceContactInfoReceivedSignal"
QT_MOC_LITERAL(30, 492, 18), // "serviceContactInfo"
QT_MOC_LITERAL(31, 511, 25), // "deviceStateReceivedSignal"
QT_MOC_LITERAL(32, 537, 18), // "hmiSoftwareVersion"
QT_MOC_LITERAL(33, 556, 17), // "logoUpdatedSignal"
QT_MOC_LITERAL(34, 574, 28), // "logoVisibilityReceivedSignal"
QT_MOC_LITERAL(35, 603, 14), // "leftLogoStatus"
QT_MOC_LITERAL(36, 618, 15), // "rightLogoStatus"
QT_MOC_LITERAL(37, 634, 27), // "logoVisibilityChangedSignal"
QT_MOC_LITERAL(38, 662, 28), // "connectorConfigurationSignal"
QT_MOC_LITERAL(39, 691, 14), // "connectorTypes"
QT_MOC_LITERAL(40, 706, 18), // "connectorMaxPowers"
QT_MOC_LITERAL(41, 725, 34), // "displayLogoDimensionReceivedS..."
QT_MOC_LITERAL(42, 760, 5), // "width"
QT_MOC_LITERAL(43, 766, 6), // "height"
QT_MOC_LITERAL(44, 773, 19), // "chargePointIdSignal"
QT_MOC_LITERAL(45, 793, 13), // "chargePointId"
QT_MOC_LITERAL(46, 807, 19), // "brandReceivedSignal"
QT_MOC_LITERAL(47, 827, 5), // "brand"
QT_MOC_LITERAL(48, 833, 20), // "firmwareUpdateSignal"
QT_MOC_LITERAL(49, 854, 25), // "firmwareUpdateEndedSignal"
QT_MOC_LITERAL(50, 880, 20), // "lidErrorUpdateSignal"
QT_MOC_LITERAL(51, 901, 25), // "setInitializingStepSignal"
QT_MOC_LITERAL(52, 927, 17), // "completedBootStep"
QT_MOC_LITERAL(53, 945, 13), // "totalBootStep"
QT_MOC_LITERAL(54, 959, 19), // "operationModeSignal"
QT_MOC_LITERAL(55, 979, 13), // "operationMode"
QT_MOC_LITERAL(56, 993, 30), // "alternativePaymentMethodSignal"
QT_MOC_LITERAL(57, 1024, 28), // "firmwareUpdateProgressSignal"
QT_MOC_LITERAL(58, 1053, 31), // "excludedLanguagesReceivedSignal"
QT_MOC_LITERAL(59, 1085, 21), // "std::vector<Language>"
QT_MOC_LITERAL(60, 1107, 17) // "excludedLanguages"

    },
    "ZmqHandler\0changeScreenSignal\0\0screenId\0"
    "connectorId\0showErrorDialogSignal\0"
    "errorType\0stateChangedSignal\0inUse\0"
    "charging\0reserved\0initializing\0faulted\0"
    "unavailable\0chargeProgressing\0"
    "std::vector<UnavailableReason::UnavailableReason>\0"
    "unavailableReasonVector\0"
    "FaultReason::FaultReason\0faultReason\0"
    "meterValueSignal\0clearMeterValueSignal\0"
    "changeLanguageSignal\0Language\0language\0"
    "saveParam\0changeDefaultLanguageSignal\0"
    "projectTypeCodeReceivedSignal\0std::string\0"
    "projectType\0serviceContactInfoReceivedSignal\0"
    "serviceContactInfo\0deviceStateReceivedSignal\0"
    "hmiSoftwareVersion\0logoUpdatedSignal\0"
    "logoVisibilityReceivedSignal\0"
    "leftLogoStatus\0rightLogoStatus\0"
    "logoVisibilityChangedSignal\0"
    "connectorConfigurationSignal\0"
    "connectorTypes\0connectorMaxPowers\0"
    "displayLogoDimensionReceivedSignal\0"
    "width\0height\0chargePointIdSignal\0"
    "chargePointId\0brandReceivedSignal\0"
    "brand\0firmwareUpdateSignal\0"
    "firmwareUpdateEndedSignal\0"
    "lidErrorUpdateSignal\0setInitializingStepSignal\0"
    "completedBootStep\0totalBootStep\0"
    "operationModeSignal\0operationMode\0"
    "alternativePaymentMethodSignal\0"
    "firmwareUpdateProgressSignal\0"
    "excludedLanguagesReceivedSignal\0"
    "std::vector<Language>\0excludedLanguages"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZmqHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      25,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  139,    2, 0x06 /* Public */,
       5,    1,  144,    2, 0x06 /* Public */,
       7,   10,  147,    2, 0x06 /* Public */,
      19,    5,  168,    2, 0x06 /* Public */,
      20,    1,  179,    2, 0x06 /* Public */,
      21,    2,  182,    2, 0x06 /* Public */,
      25,    1,  187,    2, 0x06 /* Public */,
      26,    1,  190,    2, 0x06 /* Public */,
      29,    1,  193,    2, 0x06 /* Public */,
      31,    1,  196,    2, 0x06 /* Public */,
      33,    0,  199,    2, 0x06 /* Public */,
      34,    2,  200,    2, 0x06 /* Public */,
      37,    2,  205,    2, 0x06 /* Public */,
      38,    2,  210,    2, 0x06 /* Public */,
      41,    2,  215,    2, 0x06 /* Public */,
      44,    1,  220,    2, 0x06 /* Public */,
      46,    1,  223,    2, 0x06 /* Public */,
      48,    0,  226,    2, 0x06 /* Public */,
      49,    0,  227,    2, 0x06 /* Public */,
      50,    2,  228,    2, 0x06 /* Public */,
      51,    2,  233,    2, 0x06 /* Public */,
      54,    1,  238,    2, 0x06 /* Public */,
      56,    1,  241,    2, 0x06 /* Public */,
      57,    3,  244,    2, 0x06 /* Public */,
      58,    1,  251,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, 0x80000000 | 15, 0x80000000 | 17,    4,    8,    9,   10,   11,   12,   13,   14,   16,   18,
    QMetaType::Void, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void, 0x80000000 | 22, QMetaType::Bool,   23,   24,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void, 0x80000000 | 27,   30,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   35,   36,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   35,   36,
    QMetaType::Void, 0x80000000 | 27, 0x80000000 | 27,   39,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   42,   43,
    QMetaType::Void, 0x80000000 | 27,   45,
    QMetaType::Void, QMetaType::QString,   47,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   52,   53,
    QMetaType::Void, QMetaType::Int,   55,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 59,   60,

       0        // eod
};

void ZmqHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ZmqHandler *_t = static_cast<ZmqHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeScreenSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->showErrorDialogSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->stateChangedSignal((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< std::vector<UnavailableReason::UnavailableReason>(*)>(_a[9])),(*reinterpret_cast< FaultReason::FaultReason(*)>(_a[10]))); break;
        case 3: _t->meterValueSignal((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 4: _t->clearMeterValueSignal((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 5: _t->changeLanguageSignal((*reinterpret_cast< Language(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->changeDefaultLanguageSignal((*reinterpret_cast< Language(*)>(_a[1]))); break;
        case 7: _t->projectTypeCodeReceivedSignal((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 8: _t->serviceContactInfoReceivedSignal((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 9: _t->deviceStateReceivedSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->logoUpdatedSignal(); break;
        case 11: _t->logoVisibilityReceivedSignal((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 12: _t->logoVisibilityChangedSignal((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 13: _t->connectorConfigurationSignal((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 14: _t->displayLogoDimensionReceivedSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->chargePointIdSignal((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 16: _t->brandReceivedSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->firmwareUpdateSignal(); break;
        case 18: _t->firmwareUpdateEndedSignal(); break;
        case 19: _t->lidErrorUpdateSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 20: _t->setInitializingStepSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 21: _t->operationModeSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->alternativePaymentMethodSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->firmwareUpdateProgressSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 24: _t->excludedLanguagesReceivedSignal((*reinterpret_cast< std::vector<Language>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ZmqHandler::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::changeScreenSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::showErrorDialogSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(unsigned int , bool , bool , bool , bool , bool , bool , bool , std::vector<UnavailableReason::UnavailableReason> , FaultReason::FaultReason );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::stateChangedSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(unsigned int , double , double , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::meterValueSignal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::clearMeterValueSignal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(Language , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::changeLanguageSignal)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(Language );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::changeDefaultLanguageSignal)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::projectTypeCodeReceivedSignal)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::serviceContactInfoReceivedSignal)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::deviceStateReceivedSignal)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::logoUpdatedSignal)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::logoVisibilityReceivedSignal)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::logoVisibilityChangedSignal)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(std::string , std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::connectorConfigurationSignal)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::displayLogoDimensionReceivedSignal)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::chargePointIdSignal)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::brandReceivedSignal)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::firmwareUpdateSignal)) {
                *result = 17;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::firmwareUpdateEndedSignal)) {
                *result = 18;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::lidErrorUpdateSignal)) {
                *result = 19;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::setInitializingStepSignal)) {
                *result = 20;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::operationModeSignal)) {
                *result = 21;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::alternativePaymentMethodSignal)) {
                *result = 22;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::firmwareUpdateProgressSignal)) {
                *result = 23;
                return;
            }
        }
        {
            typedef void (ZmqHandler::*_t)(std::vector<Language> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZmqHandler::excludedLanguagesReceivedSignal)) {
                *result = 24;
                return;
            }
        }
    }
}

const QMetaObject ZmqHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ZmqHandler.data,
      qt_meta_data_ZmqHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ZmqHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZmqHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZmqHandler.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "std::thread"))
        return static_cast< std::thread*>(this);
    return QObject::qt_metacast(_clname);
}

int ZmqHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void ZmqHandler::changeScreenSignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZmqHandler::showErrorDialogSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ZmqHandler::stateChangedSignal(unsigned int _t1, bool _t2, bool _t3, bool _t4, bool _t5, bool _t6, bool _t7, bool _t8, std::vector<UnavailableReason::UnavailableReason> _t9, FaultReason::FaultReason _t10)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ZmqHandler::meterValueSignal(unsigned int _t1, double _t2, double _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ZmqHandler::clearMeterValueSignal(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ZmqHandler::changeLanguageSignal(Language _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ZmqHandler::changeDefaultLanguageSignal(Language _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ZmqHandler::projectTypeCodeReceivedSignal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ZmqHandler::serviceContactInfoReceivedSignal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ZmqHandler::deviceStateReceivedSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ZmqHandler::logoUpdatedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void ZmqHandler::logoVisibilityReceivedSignal(bool _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ZmqHandler::logoVisibilityChangedSignal(bool _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void ZmqHandler::connectorConfigurationSignal(std::string _t1, std::string _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void ZmqHandler::displayLogoDimensionReceivedSignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void ZmqHandler::chargePointIdSignal(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void ZmqHandler::brandReceivedSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void ZmqHandler::firmwareUpdateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void ZmqHandler::firmwareUpdateEndedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void ZmqHandler::lidErrorUpdateSignal(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void ZmqHandler::setInitializingStepSignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void ZmqHandler::operationModeSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void ZmqHandler::alternativePaymentMethodSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void ZmqHandler::firmwareUpdateProgressSignal(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void ZmqHandler::excludedLanguagesReceivedSignal(std::vector<Language> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
