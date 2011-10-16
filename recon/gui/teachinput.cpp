#include "teachinput.h"
#include "ui_teachinput.h"

TeachInput::TeachInput(QWidget *parent, QString & dir, QString & file
                       , QString caption, QString default_file) :
    QDialog(parent), dir(dir), file(file), 
    caption(caption), default_file(default_file),
    ui(new Ui::TeachInput)
{
    ui->setupUi(this);
    setWindowTitle(caption);
}

TeachInput::~TeachInput()
{
    delete ui;
}

void TeachInput::on_dirButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, 
                                          tr("Enter data directory") 
                                          ); 
    if (!dir.isEmpty()) 
    {
        ui->dirEdit->setText(dir);
        if ((ui->fileEdit->text()).isEmpty()) 
        {
            ui->fileEdit->setText(QDir(dir).filePath(default_file));
        }
    }
}

void TeachInput::on_fileButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, 
                                          tr("Enter file with right positions") 
                                          ); 
    if (!file.isEmpty()) 
    {
        ui->fileEdit->setText(file);
    }
}

void TeachInput::on_buttonBox_accepted()
{
    dir = ui->dirEdit->text();
    file = ui->fileEdit->text();
}

