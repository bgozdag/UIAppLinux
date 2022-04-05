/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[57];
    char stringdata0[1161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "languageChangedSignal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16), // "meterValueSignal"
QT_MOC_LITERAL(4, 51, 28), // "warningMessageReceivedSignal"
QT_MOC_LITERAL(5, 80, 17), // "onChargerSelected"
QT_MOC_LITERAL(6, 98, 11), // "connectorId"
QT_MOC_LITERAL(7, 110, 19), // "onScreenChangeEvent"
QT_MOC_LITERAL(8, 130, 8), // "screenId"
QT_MOC_LITERAL(9, 139, 39), // "setInitializingProgressBarBoo..."
QT_MOC_LITERAL(10, 179, 17), // "completedBootStep"
QT_MOC_LITERAL(11, 197, 13), // "totalBootStep"
QT_MOC_LITERAL(12, 211, 22), // "onShowErrorDialogEvent"
QT_MOC_LITERAL(13, 234, 19), // "onHomeButtonClicked"
QT_MOC_LITERAL(14, 254, 23), // "onLanguageButtonClicked"
QT_MOC_LITERAL(15, 278, 14), // "changeLanguage"
QT_MOC_LITERAL(16, 293, 8), // "Language"
QT_MOC_LITERAL(17, 302, 8), // "language"
QT_MOC_LITERAL(18, 311, 9), // "saveParam"
QT_MOC_LITERAL(19, 321, 21), // "changeDefaultLanguage"
QT_MOC_LITERAL(20, 343, 24), // "onDefaultLanguageTimeout"
QT_MOC_LITERAL(21, 368, 23), // "onLanguageDialogTimeout"
QT_MOC_LITERAL(22, 392, 23), // "projectTypeCodeReceived"
QT_MOC_LITERAL(23, 416, 11), // "std::string"
QT_MOC_LITERAL(24, 428, 26), // "serviceContactInfoReceived"
QT_MOC_LITERAL(25, 455, 18), // "serviceContactInfo"
QT_MOC_LITERAL(26, 474, 18), // "onAuthorizeRequest"
QT_MOC_LITERAL(27, 493, 19), // "onStateChangedEvent"
QT_MOC_LITERAL(28, 513, 49), // "std::vector<UnavailableReason..."
QT_MOC_LITERAL(29, 563, 24), // "FaultReason::FaultReason"
QT_MOC_LITERAL(30, 588, 17), // "onMeterValueEvent"
QT_MOC_LITERAL(31, 606, 22), // "onClearMeterValueEvent"
QT_MOC_LITERAL(32, 629, 21), // "onDeviceStateReceived"
QT_MOC_LITERAL(33, 651, 15), // "softwareVersion"
QT_MOC_LITERAL(34, 667, 13), // "onLogoUpdated"
QT_MOC_LITERAL(35, 681, 27), // "onChangeLogoVisibilityEvent"
QT_MOC_LITERAL(36, 709, 14), // "leftLogoStatus"
QT_MOC_LITERAL(37, 724, 15), // "rightLogoStatus"
QT_MOC_LITERAL(38, 740, 32), // "onConnectorConfigurationReceived"
QT_MOC_LITERAL(39, 773, 30), // "onDisplayLogoDimensionReceived"
QT_MOC_LITERAL(40, 804, 5), // "width"
QT_MOC_LITERAL(41, 810, 6), // "height"
QT_MOC_LITERAL(42, 817, 23), // "onChargePointIdReceived"
QT_MOC_LITERAL(43, 841, 13), // "chargePointId"
QT_MOC_LITERAL(44, 855, 21), // "onFirmwareUpdateEvent"
QT_MOC_LITERAL(45, 877, 26), // "onFirmwareUpdateEndedEvent"
QT_MOC_LITERAL(46, 904, 40), // "notSupportedConnectorReadyToS..."
QT_MOC_LITERAL(47, 945, 22), // "unlockConnectorRequest"
QT_MOC_LITERAL(48, 968, 17), // "onLidErrorUpdated"
QT_MOC_LITERAL(49, 986, 23), // "onOperationModeReceived"
QT_MOC_LITERAL(50, 1010, 37), // "setVisibilityAlternativePayme..."
QT_MOC_LITERAL(51, 1048, 27), // "onExcludedLanguagesReceived"
QT_MOC_LITERAL(52, 1076, 21), // "std::vector<Language>"
QT_MOC_LITERAL(53, 1098, 17), // "excludedLanguages"
QT_MOC_LITERAL(54, 1116, 22), // "notificationBarClicked"
QT_MOC_LITERAL(55, 1139, 15), // "onBrandReceived"
QT_MOC_LITERAL(56, 1155, 5) // "brand"

    },
    "MainWindow\0languageChangedSignal\0\0"
    "meterValueSignal\0warningMessageReceivedSignal\0"
    "onChargerSelected\0connectorId\0"
    "onScreenChangeEvent\0screenId\0"
    "setInitializingProgressBarBootStepWidth\0"
    "completedBootStep\0totalBootStep\0"
    "onShowErrorDialogEvent\0onHomeButtonClicked\0"
    "onLanguageButtonClicked\0changeLanguage\0"
    "Language\0language\0saveParam\0"
    "changeDefaultLanguage\0onDefaultLanguageTimeout\0"
    "onLanguageDialogTimeout\0projectTypeCodeReceived\0"
    "std::string\0serviceContactInfoReceived\0"
    "serviceContactInfo\0onAuthorizeRequest\0"
    "onStateChangedEvent\0"
    "std::vector<UnavailableReason::UnavailableReason>\0"
    "FaultReason::FaultReason\0onMeterValueEvent\0"
    "onClearMeterValueEvent\0onDeviceStateReceived\0"
    "softwareVersion\0onLogoUpdated\0"
    "onChangeLogoVisibilityEvent\0leftLogoStatus\0"
    "rightLogoStatus\0onConnectorConfigurationReceived\0"
    "onDisplayLogoDimensionReceived\0width\0"
    "height\0onChargePointIdReceived\0"
    "chargePointId\0onFirmwareUpdateEvent\0"
    "onFirmwareUpdateEndedEvent\0"
    "notSupportedConnectorReadyToStartRequest\0"
    "unlockConnectorRequest\0onLidErrorUpdated\0"
    "onOperationModeReceived\0"
    "setVisibilityAlternativePaymentMethod\0"
    "onExcludedLanguagesReceived\0"
    "std::vector<Language>\0excludedLanguages\0"
    "notificationBarClicked\0onBrandReceived\0"
    "brand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  189,    2, 0x06 /* Public */,
       3,    0,  190,    2, 0x06 /* Public */,
       4,    0,  191,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,  192,    2, 0x0a /* Public */,
       7,    2,  195,    2, 0x0a /* Public */,
       9,    2,  200,    2, 0x0a /* Public */,
      12,    1,  205,    2, 0x0a /* Public */,
      13,    0,  208,    2, 0x0a /* Public */,
      14,    0,  209,    2, 0x0a /* Public */,
      15,    2,  210,    2, 0x0a /* Public */,
      19,    1,  215,    2, 0x0a /* Public */,
      20,    0,  218,    2, 0x0a /* Public */,
      21,    0,  219,    2, 0x0a /* Public */,
      22,    1,  220,    2, 0x0a /* Public */,
      24,    1,  223,    2, 0x0a /* Public */,
      26,    2,  226,    2, 0x0a /* Public */,
      27,   10,  231,    2, 0x0a /* Public */,
      30,    5,  252,    2, 0x0a /* Public */,
      31,    1,  263,    2, 0x0a /* Public */,
      32,    1,  266,    2, 0x0a /* Public */,
      34,    0,  269,    2, 0x0a /* Public */,
      35,    2,  270,    2, 0x0a /* Public */,
      38,    2,  275,    2, 0x0a /* Public */,
      39,    2,  280,    2, 0x0a /* Public */,
      42,    1,  285,    2, 0x0a /* Public */,
      44,    0,  288,    2, 0x0a /* Public */,
      45,    0,  289,    2, 0x0a /* Public */,
      46,    1,  290,    2, 0x0a /* Public */,
      47,    1,  293,    2, 0x0a /* Public */,
      48,    2,  296,    2, 0x0a /* Public */,
      49,    1,  301,    2, 0x0a /* Public */,
      50,    1,  304,    2, 0x0a /* Public */,
      51,    1,  307,    2, 0x0a /* Public */,
      54,    0,  310,    2, 0x0a /* Public */,
      55,    1,  311,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16, QMetaType::Bool,   17,   18,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, 0x80000000 | 23,   25,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, 0x80000000 | 28, 0x80000000 | 29,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void, QMetaType::QString,   33,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   36,   37,
    QMetaType::Void, 0x80000000 | 23, 0x80000000 | 23,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   40,   41,
    QMetaType::Void, 0x80000000 | 23,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 52,   53,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   56,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->languageChangedSignal(); break;
        case 1: _t->meterValueSignal(); break;
        case 2: _t->warningMessageReceivedSignal(); break;
        case 3: _t->onChargerSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onScreenChangeEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->setInitializingProgressBarBootStepWidth((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->onShowErrorDialogEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onHomeButtonClicked(); break;
        case 8: _t->onLanguageButtonClicked(); break;
        case 9: _t->changeLanguage((*reinterpret_cast< Language(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->changeDefaultLanguage((*reinterpret_cast< Language(*)>(_a[1]))); break;
        case 11: _t->onDefaultLanguageTimeout(); break;
        case 12: _t->onLanguageDialogTimeout(); break;
        case 13: _t->projectTypeCodeReceived((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 14: _t->serviceContactInfoReceived((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 15: _t->onAuthorizeRequest((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->onStateChangedEvent((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< std::vector<UnavailableReason::UnavailableReason>(*)>(_a[9])),(*reinterpret_cast< FaultReason::FaultReason(*)>(_a[10]))); break;
        case 17: _t->onMeterValueEvent((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 18: _t->onClearMeterValueEvent((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 19: _t->onDeviceStateReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->onLogoUpdated(); break;
        case 21: _t->onChangeLogoVisibilityEvent((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 22: _t->onConnectorConfigurationReceived((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 23: _t->onDisplayLogoDimensionReceived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 24: _t->onChargePointIdReceived((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 25: _t->onFirmwareUpdateEvent(); break;
        case 26: _t->onFirmwareUpdateEndedEvent(); break;
        case 27: _t->notSupportedConnectorReadyToStartRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->unlockConnectorRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->onLidErrorUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 30: _t->onOperationModeReceived((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->setVisibilityAlternativePaymentMethod((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->onExcludedLanguagesReceived((*reinterpret_cast< std::vector<Language>(*)>(_a[1]))); break;
        case 33: _t->notificationBarClicked(); break;
        case 34: _t->onBrandReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::languageChangedSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::meterValueSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::warningMessageReceivedSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::languageChangedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::meterValueSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::warningMessageReceivedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
