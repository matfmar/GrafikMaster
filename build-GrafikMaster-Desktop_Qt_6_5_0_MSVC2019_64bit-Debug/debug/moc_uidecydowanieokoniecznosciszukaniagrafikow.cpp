/****************************************************************************
** Meta object code from reading C++ file 'uidecydowanieokoniecznosciszukaniagrafikow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GrafikMaster/uidecydowanieokoniecznosciszukaniagrafikow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uidecydowanieokoniecznosciszukaniagrafikow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSUIDecydowanieOKoniecznosciSzukaniaGrafikowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSUIDecydowanieOKoniecznosciSzukaniaGrafikowENDCLASS = QtMocHelpers::stringData(
    "UIDecydowanieOKoniecznosciSzukaniaGrafikow",
    "onButtonSzukajDalejClicked",
    "",
    "onButtonZakonczSzukanieClicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSUIDecydowanieOKoniecznosciSzukaniaGrafikowENDCLASS_t {
    uint offsetsAndSizes[8];
    char stringdata0[43];
    char stringdata1[27];
    char stringdata2[1];
    char stringdata3[31];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSUIDecydowanieOKoniecznosciSzukaniaGrafikowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSUIDecydowanieOKoniecznosciSzukaniaGrafikowENDCLASS_t qt_meta_stringdata_CLASSUIDecydowanieOKoniecznosciSzukaniaGrafikowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 42),  // "UIDecydowanieOKoniecznosciSzu..."
        QT_MOC_LITERAL(43, 26),  // "onButtonSzukajDalejClicked"
        QT_MOC_LITERAL(70, 0),  // ""
        QT_MOC_LITERAL(71, 30)   // "onButtonZakonczSzukanieClicked"
    },
    "UIDecydowanieOKoniecznosciSzukaniaGrafikow",
    "onButtonSzukajDalejClicked",
    "",
    "onButtonZakonczSzukanieClicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUIDecydowanieOKoniecznosciSzukaniaGrafikowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x0a,    1 /* Public */,
       3,    0,   27,    2, 0x0a,    2 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject UIDecydowanieOKoniecznosciSzukaniaGrafikow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSUIDecydowanieOKoniecznosciSzukaniaGrafikowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUIDecydowanieOKoniecznosciSzukaniaGrafikowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUIDecydowanieOKoniecznosciSzukaniaGrafikowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UIDecydowanieOKoniecznosciSzukaniaGrafikow, std::true_type>,
        // method 'onButtonSzukajDalejClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonZakonczSzukanieClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void UIDecydowanieOKoniecznosciSzukaniaGrafikow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UIDecydowanieOKoniecznosciSzukaniaGrafikow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onButtonSzukajDalejClicked(); break;
        case 1: _t->onButtonZakonczSzukanieClicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *UIDecydowanieOKoniecznosciSzukaniaGrafikow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UIDecydowanieOKoniecznosciSzukaniaGrafikow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUIDecydowanieOKoniecznosciSzukaniaGrafikowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int UIDecydowanieOKoniecznosciSzukaniaGrafikow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
