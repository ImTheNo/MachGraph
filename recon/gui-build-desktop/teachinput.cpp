#include "teachinput.h"
#include "ui_teachinput.h"

TeachInput::TeachInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeachInput)
{
    ui->setupUi(this);
}

TeachInput::~TeachInput()
{
    delete ui;
}
