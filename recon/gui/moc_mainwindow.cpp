/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Oct 16 02:32:23 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      38,   11,   11,   11, 0x0a,
      64,   11,   11,   11, 0x0a,
      91,   11,   11,   11, 0x0a,
     120,   11,   11,   11, 0x0a,
     150,   11,   11,   11, 0x0a,
     181,   11,   11,   11, 0x0a,
     208,   11,   11,   11, 0x0a,
     236,   11,   11,   11, 0x0a,
     261,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionSave_triggered()\0"
    "on_actionLoad_triggered()\0"
    "on_actionTeach_triggered()\0"
    "on_actionPredict_triggered()\0"
    "on_actionEstimate_triggered()\0"
    "on_actionRecognize_triggered()\0"
    "on_predictButton_clicked()\0"
    "on_estimateButton_clicked()\0"
    "on_teachButton_clicked()\0"
    "on_reconButton_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &ViewBase::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return ViewBase::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ViewBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionSave_triggered(); break;
        case 1: on_actionLoad_triggered(); break;
        case 2: on_actionTeach_triggered(); break;
        case 3: on_actionPredict_triggered(); break;
        case 4: on_actionEstimate_triggered(); break;
        case 5: on_actionRecognize_triggered(); break;
        case 6: on_predictButton_clicked(); break;
        case 7: on_estimateButton_clicked(); break;
        case 8: on_teachButton_clicked(); break;
        case 9: on_reconButton_clicked(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
