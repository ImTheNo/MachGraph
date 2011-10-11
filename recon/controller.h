#ifndef  controller_INC
#define  controller_INC
#include	<QWidget>
#include	<iostream>
#include	"viewbase.h"

class Control
{
    Q_OBJECT
public:
    Control(ViewBase * i_view);
public slots:
    int teachSlot(QString dir, QString pos);
    int saveSlot(QString model);
    int loadSlot(QString model);
    int PredictSlot(QString  dir, QString model = QString(), QString right_positions = QString());
    int PredictOneSlot(QString  file, QString model = QString());
    int EstimationSwitch(char val);
    int EstimateSlot(QString detected = QString(), QString right_positions = QString());
private:
    ViewBase * my_view;
    Model my_model;
    QString detected, QString right_positions; 
    bool need_estimation;
    void RefreshState();
};

#endif   /* ----- #ifndef controller_INC  ----- */
