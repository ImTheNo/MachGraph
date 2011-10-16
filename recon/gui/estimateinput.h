#ifndef EstIn_H
#define EstIn_H

#include <QDialog>
#include <QDir>
#include <QString>
#include <QFileDialog>

namespace Ui {
    class EstIn;
}

class EstIn : public QDialog
{
    Q_OBJECT

public:
    explicit EstIn(QWidget *parent, QString & res, QString & file);
    ~EstIn();

public slots:
    void on_resButton_clicked();
    void on_fileButton_clicked();
    void on_buttonBox_accepted();

private:
    QString & res;
    QString & file;
    QString caption, default_file; 
    Ui::EstIn *ui;
};

#endif // EstIn_H
