#ifndef  viewbase_INC
#define  viewbase_INC

#include <QMainWindow>
#include	<QImage>
#include	<QDir>
#include	<QTextStream>
#include	<iostream>
#include	<vector>
#include <QDebug>

class ViewBase: public QMainWindow
{
    Q_OBJECT

public:
    ViewBase(QWidget *parent = 0);
    void virtual Suspend(QString message = QString()) = 0;
    void virtual Resume() = 0;
    void virtual tellToUser(QString  message) = 0;
    void virtual setPrecense(char flag) = 0;
    void virtual setQualityEstimation(double recall, double precision) = 0;
    void virtual showImage(QString file, std::vector<QPoint> results) = 0;
signals:
    void eventTeach(QString dir, QString pos); 
    void eventSave(QString model);
    void eventLoad(QString model);
    void eventPredictEstimate(QString dir, QString right_positions = QString());
    void eventEstimate(QString detected, QString right_positions);
    void eventPredictOne(QString  file);
};
#endif   /* ----- #ifndef viewbase_INC  ----- */
