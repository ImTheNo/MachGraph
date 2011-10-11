#include	<controller.h>

Control::Control(ViewBase * i_view)
{
    my_view = i_view;
}

int Control::teachSlot(QString name)
{
    return 0;
}

int Control::PredictSlot(QString  dir, QString model = QString(), QString right_positions = QString())
{
    QStringList filters;
    //check user path
    QDir path(dir);
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
    return 0;
}

int Control::EstimateSlot(QString detected, QString right_positions)
{
    return 0;
}
void Control::RefreshState()
{
    
}
