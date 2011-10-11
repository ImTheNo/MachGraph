
#include	<QtGui>
#include	<iostream>
#include	<vector>

class ViewBase 
{
    Q_OBJECT

public:
    ViewBase();
public signals:
    int eventTeach(QString & dir); 
    int eventPredictEstimate(QString dir = QString(), QString right_positions = QString());
    int eventEstimate(QString detected, QString right_positions);
public slots:
    int virtual Suspend();
    int virtual Resume();
    void virtual tellToUser(QString & message, int num) tell user some information about how model is respond to user input
    void virtual setPrecense(char flag) flag != 0 if program has loaded classificator
    void virtual setQualityEstimation(double recall, double precision) show quality factors to user
};
