
#include	<dialog.h>
 SetSigmaDialog::SetSigmaDialog(QWidget * parent = 0): QDialog(parent)
 {
     EditLabel = new QLabel(tr("Sigma: "));
     lineEdit = new QLineEdit;
     EditLabel->setBuddy(lineEdit);

     okcancel = new QDialogButtonBox(QDialogButtonBox::Ok
                                      | QDialogButtonBox::Cancel, Qt::Horizontal, this);
     connect(okcancel, SIGNAL(accepted()), this, accept());
     connect(okcancel, SIGNAL(rejected()), this, reject());
 }

 SetSigmaDialog::accept()
