#ifndef  controller_INC
#define  controller_INC
#include	<QObject>
#include	<QImage>
#include	<QDir>
#include	<QTextStream>
#include	<vector>
#include <QDebug>
#include	"viewbase.h"
#include	"model.h"

class Control: public QObject
{
    Q_OBJECT
public:
    Control(ViewBase * i_view);
public slots:
    void teachSlot(QString dir, QString pos);
    void saveSlot(QString model);
    void loadSlot(QString model);
    void PredictSlot(QString  dir, QString right_positions = QString());
    void PredictOneSlot(QString  file);
    void EstimateSlot(QString detected = QString(), QString right_positions = QString());
private:
    ViewBase * m_view;
    Model my_model;
    QString detected; 
};

#endif   /* ----- #ifndef controller_INC  ----- */
