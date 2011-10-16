/****************************************************************************
** Meta object code from reading C++ file 'viewbase.h'
**
** Created: Sat Oct 15 10:48:54 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../viewbase.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewbase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ViewBase[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   10,    9,    9, 0x05,
      52,   46,    9,    9, 0x05,
      71,   46,    9,    9, 0x05,
     110,   90,    9,    9, 0x05,
     152,  148,    9,    9, 0x25,
     207,  182,    9,    9, 0x05,
     243,  238,    9,    9, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ViewBase[] = {
    "ViewBase\0\0dir,pos\0eventTeach(QString,QString)\0"
    "model\0eventSave(QString)\0eventLoad(QString)\0"
    "dir,right_positions\0"
    "eventPredictEstimate(QString,QString)\0"
    "dir\0eventPredictEstimate(QString)\0"
    "detected,right_positions\0"
    "eventEstimate(QString,QString)\0file\0"
    "eventPredictOne(QString)\0"
};

const QMetaObject ViewBase::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ViewBase,
      qt_meta_data_ViewBase, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ViewBase::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ViewBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ViewBase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViewBase))
        return static_cast<void*>(const_cast< ViewBase*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ViewBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: eventTeach((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: eventSave((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: eventLoad((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: eventPredictEstimate((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: eventPredictEstimate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: eventEstimate((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: eventPredictOne((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ViewBase::eventTeach(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ViewBase::eventSave(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ViewBase::eventLoad(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ViewBase::eventPredictEstimate(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 5
void ViewBase::eventEstimate(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ViewBase::eventPredictOne(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
