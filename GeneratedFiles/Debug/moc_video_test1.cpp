/****************************************************************************
** Meta object code from reading C++ file 'video_test1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../video_test1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'video_test1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_video_test1_t {
    QByteArrayData data[8];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_video_test1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_video_test1_t qt_meta_stringdata_video_test1 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "video_test1"
QT_MOC_LITERAL(1, 12, 11), // "updateImage"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 21), // "on_startCount_clicked"
QT_MOC_LITERAL(4, 47, 20), // "on_stopCount_clicked"
QT_MOC_LITERAL(5, 68, 19), // "on_action_triggered"
QT_MOC_LITERAL(6, 88, 23), // "on_clearPainter_clicked"
QT_MOC_LITERAL(7, 112, 22) // "on_openCalib_triggered"

    },
    "video_test1\0updateImage\0\0on_startCount_clicked\0"
    "on_stopCount_clicked\0on_action_triggered\0"
    "on_clearPainter_clicked\0on_openCalib_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_video_test1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void video_test1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        video_test1 *_t = static_cast<video_test1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateImage(); break;
        case 1: _t->on_startCount_clicked(); break;
        case 2: _t->on_stopCount_clicked(); break;
        case 3: _t->on_action_triggered(); break;
        case 4: _t->on_clearPainter_clicked(); break;
        case 5: _t->on_openCalib_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject video_test1::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_video_test1.data,
      qt_meta_data_video_test1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *video_test1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *video_test1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_video_test1.stringdata0))
        return static_cast<void*>(const_cast< video_test1*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int video_test1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
