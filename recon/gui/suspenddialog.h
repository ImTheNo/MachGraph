#ifndef SUSPENDDIALOG_H
#define SUSPENDDIALOG_H

#include <QDialog>

namespace Ui {
    class SuspendDialog;
}

class SuspendDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SuspendDialog(QWidget *parent = 0, QString message = QString(), 
            Qt::WindowFlags f = Qt::Dialog | Qt::CustomizeWindowHint);
    ~SuspendDialog();

private:
    Ui::SuspendDialog *ui;
};

#endif // SUSPENDDIALOG_H
