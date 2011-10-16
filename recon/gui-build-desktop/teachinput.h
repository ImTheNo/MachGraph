#ifndef TEACHINPUT_H
#define TEACHINPUT_H

#include <QDialog>

namespace Ui {
    class TeachInput;
}

class TeachInput : public QDialog
{
    Q_OBJECT

public:
    explicit TeachInput(QWidget *parent = 0);
    ~TeachInput();

private:
    Ui::TeachInput *ui;
};

#endif // TEACHINPUT_H
