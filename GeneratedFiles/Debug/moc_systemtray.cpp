/****************************************************************************
** Meta object code from reading C++ file 'systemtray.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../systemtray.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'systemtray.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SystemTray_t {
    QByteArrayData data[12];
    char stringdata[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SystemTray_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SystemTray_t qt_meta_stringdata_SystemTray = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 19),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 16),
QT_MOC_LITERAL(4, 49, 15),
QT_MOC_LITERAL(5, 65, 14),
QT_MOC_LITERAL(6, 80, 15),
QT_MOC_LITERAL(7, 96, 19),
QT_MOC_LITERAL(8, 116, 17),
QT_MOC_LITERAL(9, 134, 21),
QT_MOC_LITERAL(10, 156, 17),
QT_MOC_LITERAL(11, 174, 22)
    },
    "SystemTray\0visitHomeBtnClicked\0\0"
    "updateBtnClicked\0aboutBtnClicked\0"
    "exitBtnClicked\0runOSBTriggered\0"
    "helpOnlineTriggered\0homePageTriggered\0"
    "notificationTriggered\0settingsTriggered\0"
    "restoreWindowTriggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SystemTray[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06,
       3,    0,   65,    2, 0x06,
       4,    0,   66,    2, 0x06,
       5,    0,   67,    2, 0x06,
       6,    0,   68,    2, 0x06,
       7,    0,   69,    2, 0x06,
       8,    0,   70,    2, 0x06,
       9,    0,   71,    2, 0x06,
      10,    0,   72,    2, 0x06,
      11,    0,   73,    2, 0x06,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SystemTray::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SystemTray *_t = static_cast<SystemTray *>(_o);
        switch (_id) {
        case 0: _t->visitHomeBtnClicked(); break;
        case 1: _t->updateBtnClicked(); break;
        case 2: _t->aboutBtnClicked(); break;
        case 3: _t->exitBtnClicked(); break;
        case 4: _t->runOSBTriggered(); break;
        case 5: _t->helpOnlineTriggered(); break;
        case 6: _t->homePageTriggered(); break;
        case 7: _t->notificationTriggered(); break;
        case 8: _t->settingsTriggered(); break;
        case 9: _t->restoreWindowTriggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SystemTray::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemTray::visitHomeBtnClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (SystemTray::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemTray::updateBtnClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (SystemTray::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemTray::aboutBtnClicked)) {
                *result = 2;
            }
        }
        {
            typedef void (SystemTray::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemTray::exitBtnClicked)) {
                *result = 3;
            }
        }
        {
            typedef void (SystemTray::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemTray::runOSBTriggered)) {
                *result = 4;
            }
        }
        {
            typedef void (SystemTray::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemTray::helpOnlineTriggered)) {
                *result = 5;
            }
        }
        {
            typedef void (SystemTray::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemTray::homePageTriggered)) {
                *result = 6;
            }
        }
        {
            typedef void (SystemTray::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemTray::notificationTriggered)) {
                *result = 7;
            }
        }
        {
            typedef void (SystemTray::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemTray::settingsTriggered)) {
                *result = 8;
            }
        }
        {
            typedef void (SystemTray::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SystemTray::restoreWindowTriggered)) {
                *result = 9;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SystemTray::staticMetaObject = {
    { &QSystemTrayIcon::staticMetaObject, qt_meta_stringdata_SystemTray.data,
      qt_meta_data_SystemTray,  qt_static_metacall, 0, 0}
};


const QMetaObject *SystemTray::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SystemTray::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SystemTray.stringdata))
        return static_cast<void*>(const_cast< SystemTray*>(this));
    return QSystemTrayIcon::qt_metacast(_clname);
}

int SystemTray::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSystemTrayIcon::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void SystemTray::visitHomeBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SystemTray::updateBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void SystemTray::aboutBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void SystemTray::exitBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void SystemTray::runOSBTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void SystemTray::helpOnlineTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void SystemTray::homePageTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void SystemTray::notificationTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void SystemTray::settingsTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void SystemTray::restoreWindowTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}
QT_END_MOC_NAMESPACE
