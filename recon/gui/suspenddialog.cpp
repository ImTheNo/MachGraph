#include "suspenddialog.h"
#include "ui_suspenddialog.h"

SuspendDialog::SuspendDialog(QWidget *parent, QString message, Qt::WindowFlags f) :
    QDialog(parent, f),
    ui(new Ui::SuspendDialog)
{
    ui->setupUi(this);
    ui->label->setText();
    setModal(false);
}

SuspendDialog::~SuspendDialog()
{
    delete ui;
}
