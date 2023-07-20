/****************************************************************************
** Meta object code from reading C++ file 'pprogress.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GrafikMaster/pprogress.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pprogress.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPProgressENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPProgressENDCLASS = QtMocHelpers::stringData(
    "PProgress",
    "setLabelOknoProgress",
    "",
    "ileGrafikow",
    "przymknijOknoProgress",
    "showOknoProgress",
    "killOknoProgress",
    "showAskWindow",
    "int*",
    "result",
    "showEndCommunicate",
    "ile"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPProgressENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[10];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[22];
    char stringdata5[17];
    char stringdata6[17];
    char stringdata7[14];
    char stringdata8[5];
    char stringdata9[7];
    char stringdata10[19];
    char stringdata11[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPProgressENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPProgressENDCLASS_t qt_meta_stringdata_CLASSPProgressENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "PProgress"
        QT_MOC_LITERAL(10, 20),  // "setLabelOknoProgress"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 11),  // "ileGrafikow"
        QT_MOC_LITERAL(44, 21),  // "przymknijOknoProgress"
        QT_MOC_LITERAL(66, 16),  // "showOknoProgress"
        QT_MOC_LITERAL(83, 16),  // "killOknoProgress"
        QT_MOC_LITERAL(100, 13),  // "showAskWindow"
        QT_MOC_LITERAL(114, 4),  // "int*"
        QT_MOC_LITERAL(119, 6),  // "result"
        QT_MOC_LITERAL(126, 18),  // "showEndCommunicate"
        QT_MOC_LITERAL(145, 3)   // "ile"
    },
    "PProgress",
    "setLabelOknoProgress",
    "",
    "ileGrafikow",
    "przymknijOknoProgress",
    "showOknoProgress",
    "killOknoProgress",
    "showAskWindow",
    "int*",
    "result",
    "showEndCommunicate",
    "ile"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPProgressENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x0a,    1 /* Public */,
       4,    0,   53,    2, 0x0a,    3 /* Public */,
       5,    0,   54,    2, 0x0a,    4 /* Public */,
       6,    0,   55,    2, 0x0a,    5 /* Public */,
       7,    1,   56,    2, 0x0a,    6 /* Public */,
      10,    2,   59,    2, 0x0a,    8 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    9,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject PProgress::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSPProgressENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPProgressENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPProgressENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PProgress, std::true_type>,
        // method 'setLabelOknoProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'przymknijOknoProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showOknoProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'killOknoProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showAskWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int *, std::false_type>,
        // method 'showEndCommunicate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void PProgress::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PProgress *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setLabelOknoProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->przymknijOknoProgress(); break;
        case 2: _t->showOknoProgress(); break;
        case 3: _t->killOknoProgress(); break;
        case 4: _t->showAskWindow((*reinterpret_cast< std::add_pointer_t<int*>>(_a[1]))); break;
        case 5: _t->showEndCommunicate((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *PProgress::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PProgress::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPProgressENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PProgress::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
