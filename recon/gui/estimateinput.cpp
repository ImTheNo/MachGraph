#include "estimateinput.h"
#include "ui_estimateinput.h"

EstIn::EstIn(QWidget *parent, QString & res, QString & file) :
    QDialog(parent), res(res), file(file), 
    ui(new Ui::EstIn)
{
    ui->setupUi(this);
}

EstIn::~EstIn()
{
    delete ui;
}

void EstIn::on_resButton_clicked()
{
    QString res = QFileDialog::getOpenFileName(this, 
                                          tr("Enter file with results of prediction") 
                                          ); 
    if (!res.isEmpty()) 
    {
        ui->resEdit->setText(res);
    }
}

void EstIn::on_fileButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, 
                                          tr("Enter file with right positions") 
                                          ); 
    if (!file.isEmpty()) 
    {
        ui->fileEdit->setText(file);
    }
}

void EstIn::on_buttonBox_accepted()
{
    res = ui->resEdit->text();
    file = ui->fileEdit->text();
}

