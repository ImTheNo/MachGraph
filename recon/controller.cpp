#include	"controller.h"

Control::Control(ViewBase * i_view)
{
    m_view = i_view;

    //connect events from view to controller
    connect(m_view, SIGNAL(eventTeach(QString, QString)),  this, SLOT(teachSlot(QString, QString)));
    connect(m_view, SIGNAL(eventSave(QString)),  this, SLOT(saveSlot(QString)));
    connect(m_view, SIGNAL(eventLoad(QString)),  this, SLOT(loadSlot(QString)));
    connect(m_view, SIGNAL(eventPredictEstimate(QString, QString)),  this, SLOT(PredictSlot(QString, QString)));
    connect(m_view, SIGNAL(eventEstimate(QString, QString)),  this, SLOT(EstimateSlot(QString, QString)));
    connect(m_view, SIGNAL(eventPredictOne(QString)),  this, SLOT(PredictOneSlot(QString)));
}

void Control::teachSlot(QString dir, QString pos)
{
    m_view->Suspend("Teaching is ongoing");
    int return_code;
    return_code = my_model.teach(dir, pos);
    m_view->Resume();
    switch(return_code)
    {
        case ERROR_TEACH::ENDIR:	
            m_view->tellToUser("dir is not exist");
            break;

        case ERROR_TEACH::EFILE:	
            m_view->tellToUser("can't open file pos");
            break;

        case ERROR_TEACH::EINVAL_DIMEN:	
            m_view->tellToUser("invalid dimensions of patch in file");
            break;

        case ERROR_TEACH::EIMFILE:	
            m_view->tellToUser("can't open .png file");
            break;

        case ERROR_TEACH::ECONV:	
            m_view->tellToUser("file name is not number");
            break;

        default:	
            break;
    }
    m_view->setPrecense(1);
}

void Control::PredictSlot(QString  dir, QString right_positions)
{
    m_view->Suspend("Prediction is ongoing");
    QStringList filters;
    int res;
    //check user path
    QDir path(dir);
    if (!path.exists()) 
    {
        m_view->Resume();
        return;
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
        m_view->Resume();
        return;
    }
    QTextStream out(&result_file);

    res = my_model.predict(path, files, out);
    result_file.close();
    m_view->Resume();//FIXME: race conditions here
    switch (res) 
    {
        case ERROR_PREDICT::ELOAD:	
            m_view->tellToUser("can't load model");
            break;

        case ERROR_PREDICT::EPRES:	
            m_view->tellToUser("model is not loaded");
            break;

        default:	
            break;
    }				
    //here we complete predictio procedure

    // save filenames width results of last prediction
    detected = path.filePath("results.idl");
    //we may estimate results if it needed
    if (right_positions != QString()) 
    {
        return EstimateSlot(detected, right_positions);
    }
}

void Control::EstimateSlot(QString detected, QString right_positions)
{
    m_view->Suspend("Estimation is ongoing");
    double res[2];
    int return_code;
    return_code = my_model.estimate(detected, right_positions, res);
    m_view->Resume();
    switch(return_code)
    {
        case ERROR_ESTIMATE::EFILE:	
            m_view->tellToUser("can't open file with right positions");
            return;
            break;

        case ERROR_ESTIMATE::EINVAL_DIMEN:	
            m_view->tellToUser("invalid dimensions of patch in file");
            return;
            break;

        default:	
            break;
    }
    m_view->setQualityEstimation(res[0], res[1]);
}

void Control::saveSlot(QString model)
{
    m_view->Suspend("Saving is ongoing");
    int return_code;
    return_code = my_model.saveModel(model);
    m_view->Resume();
    switch(return_code)
    {
        case ERROR_LOAD_SAVE::EFILE:	
            m_view->tellToUser("can't save model");
            return;
            break;

        default:	
            break;
    }
}

void Control::loadSlot(QString model)
{
    m_view->Suspend("Loading is ongoing");
    int return_code;
    return_code = my_model.loadModel(model);
    m_view->Resume();
    switch(return_code)
    {
        case ERROR_LOAD_SAVE::EFILE:	
            m_view->tellToUser("can't load model");
            return;
            break;

        default:	
            break;
    }
    m_view->setPrecense(true);
}

void Control::PredictOneSlot(QString  file)
{
    m_view->Suspend("Prediction is ongoing");
    QStringList filters;
    size_t y0, x0, y1, x1;
    QString filename;
    QDir path(QDir::current());
    //prepare list including one file
    QStringList files;
    files << path.relativeFilePath(file);
    QString res;

    //output results to res
    QTextStream out(&res, QIODevice::WriteOnly);

    int return_code = my_model.predict(path, files, out);
    switch(return_code)
    {
        case ERROR_PREDICT::ELOAD:	
            m_view->Resume();
            m_view->tellToUser("can't load model");
            return;
            break;

        case ERROR_PREDICT::EPRES:	
            m_view->Resume();
            m_view->tellToUser("model is not loaded");
            return;
            break;

        default:	
            break;
    }				

    //parse results of prediction
    std::vector<QPoint> results;
    out.setString(&res, QIODevice::ReadOnly);
    out >> filename; 
    while (!out.atEnd()) 
    {
        out >> y0 >> x0 >> y1 >> x1;
        results.push_back(QPoint(x0, y0));
        out >> filename; 
    }
    m_view->Resume();
    m_view->showImage(file, results);
}

