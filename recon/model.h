#ifndef  model_h_INC
#define  model_h_INC

#include	<QImage>
#include	<QFile>
#include	<QDir>
#include	<QStringList>
#include	<QTextStream>
#include	<vector>
#include    "linear.h"
#include    <cmath>
#include    <cstdlib>
#include    <cstring>

enum CONST
{
    STANDART_X = 0,
    STANDART_HEIGHT = 200, 
    STANDART_WIDTH = 80,
    X_STEP = 10 
};


#define	STANDART_Y STANDART_X			/* yet another stupid convinient */

#define RED_W ((double)0.2125)
#define GREEN_W ((double)0.7154)
#define BLUE_W ((double)0.0721)
#define EPS 1E-4
#define BT709(tmp) ((RED_W * qRed(tmp) + GREEN_W * qGreen(tmp) + BLUE_W * qBlue(tmp)))
#define NORM_WITH(a, border) ((a < 0) ? -a : ((a > border - 1) ? 2 * (border - 1) - a : (a))) 

#define ANGLE_GROUPS 8
#define IMAGE_BLOCS(height, width) ((height / 8 + (height % 8 ? 1 : 0)) * (width / 8 + (width % 8 ? 1 : 0)))
#define IMAGE_FEATURES(height, width) (ANGLE_GROUPS * IMAGE_BLOCS(height, width))

#define PNG ".png"
#define DELIM "/"
#define WILDCARD "*"
class Model 
{
public:
    Model();
    ~Model();
    int teach(QString dir, QString pos);
    int saveModel(QString name);
    int loadModel(QString name);
    int predict(QDir path, QStringList & files, QTextStream & out, QString model = QString());
    int estimate(QString detected, QString right_positions, double *res);
private:
    struct problem prob;
    struct parameter param;
    struct model* predictor;
    void calc_Gradient(QImage & file, char ** grad, int x = STANDART_X, int y = STANDART_Y, int height = STANDART_HEIGHT, int width = STANDART_WIDTH);
    void calc_HOG(struct feature_node * res, char ** grad, int x = STANDART_X, int y = STANDART_Y);
    void destroyPredictor();
};
#endif   /* ----- #ifndef model_h_INC  ----- */
