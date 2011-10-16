#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QImage>
#include "../viewbase.h"
#include "suspenddialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public ViewBase
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void virtual Suspend(QString message = QString());
    void virtual Resume();
    void virtual tellToUser(QString  message);
    void virtual setPrecense(char flag);
    void virtual setQualityEstimation(double recall, double precision);
    void virtual showImage(QString file, std::vector<QPoint> results);
    void setAll(char flag);
    ~MainWindow();
public slots:
    void on_actionSave_triggered();
    void on_actionLoad_triggered();
    void on_actionTeach_triggered();
    void on_actionPredict_triggered();
    void on_actionEstimate_triggered();
    void on_actionRecognize_triggered();
    void on_predictButton_clicked();
    void on_estimateButton_clicked();
    void on_teachButton_clicked();
    void on_reconButton_clicked();

private:
    bool precense;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
