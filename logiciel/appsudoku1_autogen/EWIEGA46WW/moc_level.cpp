/****************************************************************************
** Meta object code from reading C++ file 'level.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../level.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'level.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN5levelE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN5levelE = QtMocHelpers::stringData(
    "level",
    "levelChanged",
    "",
    "boardChanged",
    "loadlevel",
    "getcurrentlevel",
    "setCurrentlevel",
    "getBoard",
    "QList<int>",
    "currentlevel",
    "board"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN5levelE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       2,   60, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    3 /* Public */,
       3,    0,   51,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   52,    2, 0x0a,    5 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   55,    2, 0x102,    7 /* Public | MethodIsConst  */,
       6,    1,   56,    2, 0x02,    8 /* Public */,
       7,    0,   59,    2, 0x102,   10 /* Public | MethodIsConst  */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    0,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    0,
    0x80000000 | 8,

 // properties: name, type, flags, notifyId, revision
       9, QMetaType::Int, 0x00015903, uint(0), 0,
      10, 0x80000000 | 8, 0x00015009, uint(1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject level::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN5levelE.offsetsAndSizes,
    qt_meta_data_ZN5levelE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN5levelE_t,
        // property 'currentlevel'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'board'
        QtPrivate::TypeAndForceComplete<QList<int>, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<level, std::true_type>,
        // method 'levelChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'boardChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadlevel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getcurrentlevel'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setCurrentlevel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getBoard'
        QtPrivate::TypeAndForceComplete<QVector<int>, std::false_type>
    >,
    nullptr
} };

void level::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<level *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->levelChanged(); break;
        case 1: _t->boardChanged(); break;
        case 2: _t->loadlevel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: { int _r = _t->getcurrentlevel();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->setCurrentlevel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: { QList<int> _r = _t->getBoard();
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _q_method_type = void (level::*)();
            if (_q_method_type _q_method = &level::levelChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _q_method_type = void (level::*)();
            if (_q_method_type _q_method = &level::boardChanged; *reinterpret_cast<_q_method_type *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getcurrentlevel(); break;
        case 1: *reinterpret_cast< QList<int>*>(_v) = _t->getBoard(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentlevel(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *level::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *level::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN5levelE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int level::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void level::levelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void level::boardChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
