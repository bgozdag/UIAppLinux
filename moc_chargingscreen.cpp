/****************************************************************************
** Meta object code from reading C++ file 'chargingscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chargingscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chargingscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChargingScreen_t {
    QByteArrayData data[11];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChargingScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChargingScreen_t qt_meta_stringdata_ChargingScreen = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ChargingScreen"
QT_MOC_LITERAL(1, 15, 28), // "authorizeToStopRequestSignal"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 43), // "setVisibilityAlternativeAutho..."
QT_MOC_LITERAL(4, 89, 25), // "stopChargingButtonClicked"
QT_MOC_LITERAL(5, 115, 27), // "onAuthorizationDialogClosed"
QT_MOC_LITERAL(6, 143, 20), // "onMeterValueReceived"
QT_MOC_LITERAL(7, 164, 17), // "onDurationUpdated"
QT_MOC_LITERAL(8, 182, 29), // "onWarningMessageReceivedEvent"
QT_MOC_LITERAL(9, 212, 37), // "setVisibilityAlternativeAutho..."
QT_MOC_LITERAL(10, 250, 10) // "stateTrial"

    },
    "ChargingScreen\0authorizeToStopRequestSignal\0"
    "\0setVisibilityAlternativeAuthorizationSignal\0"
    "stopChargingButtonClicked\0"
    "onAuthorizationDialogClosed\0"
    "onMeterValueReceived\0onDurationUpdated\0"
    "onWarningMessageReceivedEvent\0"
    "setVisibilityAlternativeAuthorization\0"
    "stateTrial"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChargingScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       3,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x0a /* Public */,
       5,    0,   63,    2, 0x0a /* Public */,
       6,    0,   64,    2, 0x0a /* Public */,
       7,    0,   65,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x0a /* Public */,
       9,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,

       0        // eod
};

void ChargingScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChargingScreen *_t = static_cast<ChargingScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->authorizeToStopRequestSignal((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->setVisibilityAlternativeAuthorizationSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->stopChargingButtonClicked(); break;
        case 3: _t->onAuthorizationDialogClosed(); break;
        case 4: _t->onMeterValueReceived(); break;
        case 5: _t->onDurationUpdated(); break;
        case 6: _t->onWarningMessageReceivedEvent(); break;
        case 7: _t->setVisibilityAlternativeAuthorization((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ChargingScreen::*_t)(bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChargingScreen::authorizeToStopRequestSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ChargingScreen::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChargingScreen::setVisibilityAlternativeAuthorizationSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ChargingScreen::staticMetaObject = {
    { &InnerScreen::staticMetaObject, qt_meta_stringdata_ChargingScreen.data,
      qt_meta_data_ChargingScreen,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ChargingScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChargingScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChargingScreen.stringdata0))
        return static_cast<void*>(this);
    return InnerScreen::qt_metacast(_clname);
}

int ChargingScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = InnerScreen::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ChargingScreen::authorizeToStopRequestSignal(bool _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChargingScreen::setVisibilityAlternativeAuthorizationSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
