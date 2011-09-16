#ifndef DIALOG_H
#include <QtGui>

 class SetSigmaDialog : public QDialog 
 {
     Q_OBJECT

 public:
     SetSigmaDialog(QWidget * parent = 0);

 private:

     QLabel *EditLabel;
     QLineEdit *lineEdit; 

     QDialogButtonBox okcancel; 
     int sigma;
 };
 #endif
