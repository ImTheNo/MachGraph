#ifndef TEACHINPUT_H
#define TEACHINPUT_H

#include <QDialog>
#include <QDir>
#include <QString>
#include <QFileDialog>

namespace Ui {
    class TeachInput;
}

class TeachInput : public QDialog
{
    Q_OBJECT

public:
    explicit TeachInput(QWidget *parent, QString & dir, QString & file, QString caption, QString default_file);
    ~TeachInput();

public slots:
    void on_dirButton_clicked();
    void on_fileButton_clicked();
    void on_buttonBox_accepted();

private:
    QString & dir;
    QString & file;
    QString caption, default_file; 
    Ui::TeachInput *ui;
};

#endif // TEACHINPUT_H
