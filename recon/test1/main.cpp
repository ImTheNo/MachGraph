
#include "../model.h"
#include "../controller.h"
#include "../viewbase.h"
#include <QDebug>

int main(int argc, char **argv)
{
    Model test;
    QStringList filters;
    QDir path(argv[2]);
    if (!path.exists()) 
    {
        return 1;
    }

    //take list of images in directory 
    //DO NOT ACCEPT SYMBOLIC LINKS
    path.setFilter(QDir::Files | QDir::NoSymLinks);
    filters << QString(WILDCARD) + PNG;
    path.setNameFilters(filters);
    //extract list of files in directory
    QStringList files = path.entryList();

    //output results to
    QFile result_file(path.filePath("results.idl"));
    if (!result_file.open(QIODevice::WriteOnly | QIODevice::Truncate)) 
    {
        return 2;
    }
    QTextStream out(&result_file);
    double res[2];
    if (argc < 2) 
    {
        qDebug() << "enter right args" << endl;
        return 1;
    }
    ViewBase *p = (ViewBase *)NULL;
    Control con(p);
//    qDebug() << test.teach(argv[1], QString(argv[1]) + "/" + QString("train-processed.idl")) << endl;
//    test.saveModel(QString(argv[2]) + "/" + QString("model.idl"));
//    qDebug() << test.predict(path, files, out, path.filePath(QString("model.idl"))) << endl;
//    qDebug() << test.estimate(QString(argv[2]) + "/" + QString("results.idl"), QString(argv[2]) + "/" + QString("test-processed.idl"), res) << endl; 
//    qDebug() << res[0] << " " << res[1] << endl;
    return 0;
}
//"../train""../train/train-processed.idl"
