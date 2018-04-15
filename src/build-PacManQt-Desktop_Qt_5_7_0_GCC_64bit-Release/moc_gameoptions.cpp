/****************************************************************************
** Meta object code from reading C++ file 'gameoptions.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../PacManQt/gameoptions.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameoptions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_gameOptions_t {
    QByteArrayData data[6];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gameOptions_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gameOptions_t qt_meta_stringdata_gameOptions = {
    {
QT_MOC_LITERAL(0, 0, 11), // "gameOptions"
QT_MOC_LITERAL(1, 12, 15), // "setActiveWidget"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "activeWidget"
QT_MOC_LITERAL(4, 42, 27), // "on_pushButtonClient_clicked"
QT_MOC_LITERAL(5, 70, 27) // "on_pushButtonServer_clicked"

    },
    "gameOptions\0setActiveWidget\0\0activeWidget\0"
    "on_pushButtonClient_clicked\0"
    "on_pushButtonServer_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gameOptions[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void gameOptions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gameOptions *_t = static_cast<gameOptions *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setActiveWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonClient_clicked(); break;
        case 2: _t->on_pushButtonServer_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (gameOptions::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gameOptions::setActiveWidget)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject gameOptions::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_gameOptions.data,
      qt_meta_data_gameOptions,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *gameOptions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gameOptions::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_gameOptions.stringdata0))
        return static_cast<void*>(const_cast< gameOptions*>(this));
    return QWidget::qt_metacast(_clname);
}

int gameOptions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void gameOptions::setActiveWidget(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
