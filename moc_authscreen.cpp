/****************************************************************************
** Meta object code from reading C++ file 'authscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "authscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'authscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AuthScreen_t {
    QByteArrayData data[6];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AuthScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AuthScreen_t qt_meta_stringdata_AuthScreen = {
    {
QT_MOC_LITERAL(0, 0, 10), // "AuthScreen"
QT_MOC_LITERAL(1, 11, 28), // "unlockConnectorRequestSignal"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 24), // "errorDialogRequestSignal"
QT_MOC_LITERAL(4, 66, 17), // "onLanguageChanged"
QT_MOC_LITERAL(5, 84, 27) // "cancelChargingButtonClicked"

    },
    "AuthScreen\0unlockConnectorRequestSignal\0"
    "\0errorDialogRequestSignal\0onLanguageChanged\0"
    "cancelChargingButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AuthScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   40,    2, 0x0a /* Public */,
       5,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AuthScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AuthScreen *_t = static_cast<AuthScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->unlockConnectorRequestSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->errorDialogRequestSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onLanguageChanged(); break;
        case 3: _t->cancelChargingButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AuthScreen::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AuthScreen::unlockConnectorRequestSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AuthScreen::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AuthScreen::errorDialogRequestSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject AuthScreen::staticMetaObject = {
    { &InnerScreen::staticMetaObject, qt_meta_stringdata_AuthScreen.data,
      qt_meta_data_AuthScreen,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AuthScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AuthScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AuthScreen.stringdata0))
        return static_cast<void*>(this);
    return InnerScreen::qt_metacast(_clname);
}

int AuthScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = InnerScreen::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AuthScreen::unlockConnectorRequestSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AuthScreen::errorDialogRequestSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
