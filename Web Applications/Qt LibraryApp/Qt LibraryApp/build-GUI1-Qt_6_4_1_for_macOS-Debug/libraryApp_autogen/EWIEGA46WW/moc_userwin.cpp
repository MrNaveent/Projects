/****************************************************************************
** Meta object code from reading C++ file 'userwin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GUI1/userwin.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userwin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_userwin_t {
    uint offsetsAndSizes[8];
    char stringdata0[8];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_userwin_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_userwin_t qt_meta_stringdata_userwin = {
    {
        QT_MOC_LITERAL(0, 7),  // "userwin"
        QT_MOC_LITERAL(8, 20),  // "on_signinbtn_clicked"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 17)   // "on_regbtn_clicked"
    },
    "userwin",
    "on_signinbtn_clicked",
    "",
    "on_regbtn_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_userwin[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x08,    1 /* Private */,
       3,    0,   27,    2, 0x08,    2 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject userwin::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_userwin.offsetsAndSizes,
    qt_meta_data_userwin,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_userwin_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<userwin, std::true_type>,
        // method 'on_signinbtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_regbtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void userwin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<userwin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_signinbtn_clicked(); break;
        case 1: _t->on_regbtn_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *userwin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *userwin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_userwin.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int userwin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
