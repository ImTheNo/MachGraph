/****************************************************************************
** Meta object code from reading C++ file 'estimateinput.h'
**
** Created: Sun Oct 16 01:33:21 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "estimateinput.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'estimateinput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EstIn[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      30,    6,    6,    6, 0x0a,
      54,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EstIn[] = {
    "EstIn\0\0on_resButton_clicked()\0"
    "on_fileButton_clicked()\0on_buttonBox_accepted()\0"
};

const QMetaObject EstIn::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EstIn,
      qt_meta_data_EstIn, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EstIn::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EstIn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EstIn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EstIn))
        return static_cast<void*>(const_cast< EstIn*>(this));
    return QDialog::qt_metacast(_clname);
}

int EstIn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_resButton_clicked(); break;
        case 1: on_fileButton_clicked(); break;
        case 2: on_buttonBox_accepted(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
