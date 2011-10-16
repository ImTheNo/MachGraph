/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created: Sun Oct 16 01:11:14 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../controller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Control[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,    9,    8,    8, 0x0a,
      50,   44,    8,    8, 0x0a,
      68,   44,    8,    8, 0x0a,
     106,   86,    8,    8, 0x0a,
     139,  135,    8,    8, 0x2a,
     165,  160,    8,    8, 0x0a,
     214,  189,    8,    8, 0x0a,
     253,  244,    8,    8, 0x2a,
     275,    8,    8,    8, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_Control[] = {
    "Control\0\0dir,pos\0teachSlot(QString,QString)\0"
    "model\0saveSlot(QString)\0loadSlot(QString)\0"
    "dir,right_positions\0PredictSlot(QString,QString)\0"
    "dir\0PredictSlot(QString)\0file\0"
    "PredictOneSlot(QString)\0"
    "detected,right_positions\0"
    "EstimateSlot(QString,QString)\0detected\0"
    "EstimateSlot(QString)\0EstimateSlot()\0"
};

const QMetaObject Control::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Control,
      qt_meta_data_Control, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Control::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Control::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Control::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Control))
        return static_cast<void*>(const_cast< Control*>(this));
    return QObject::qt_metacast(_clname);
}

int Control::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: teachSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: saveSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: loadSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: PredictSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: PredictSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: PredictOneSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: EstimateSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: EstimateSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: EstimateSlot(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
