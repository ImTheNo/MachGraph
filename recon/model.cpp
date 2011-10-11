
#include	"model.h"
#include	<QDebug>

Model::Model() 
{
    prob.bias = 0; 

    param.solver_type = L2R_L2LOSS_SVC_DUAL;
    param.C = 1;
    param.eps = 1e-4; 
    param.nr_weight = 0;
    param.weight_label = NULL;
    param.weight = NULL;

    predictor = NULL;
}

Model::~Model()
{
    destroyPredictor(); 
    destroy_param(&param);
}
void Model::destroyPredictor()
{
    if (predictor) 
    {
        free_and_destroy_model(&predictor);
    }
}

int Model::teach(QString dir, QString pos)
{
    QImage tmp_im;
    std::vector< std::vector<QPoint> > main;
    QFile main_pos(pos);
    QStringList filters;
    int num_features = IMAGE_FEATURES(STANDART_HEIGHT, STANDART_WIDTH);
    size_t filename, y0, x0, y1, x1;
    size_t train_exs = 0; // number of training examples of main class
    char ** grad;
    /* train_exs patches from main class and train_exsw patches from background class
     * will be used to train SVM*/
    size_t i, j, k;

    //parse directory
    QDir path(dir);
    if (!path.exists()) 
    {
        return 3;
    }
    //take list of images in directory 
    //DO NOT ACCEPT SYMBOLIC LINKS
    path.setFilter(QDir::Files | QDir::NoSymLinks);
    filters << QString(WILDCARD) + PNG;
    path.setNameFilters(filters);
    //extract list of files in directory
    QStringList files = path.entryList();
    //destroy previous model if it exists
    destroyPredictor(); 
    //open file with information about training sample
    if (!main_pos.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        main_pos.close();
        return 1;
    }
    QTextStream in(&main_pos);
    //collect positions of main class's object's
    in >> filename; 
    while (!in.atEnd()) 
    {
        in >> y0 >> x0 >> y1 >> x1;
        if (y1 - y0 != STANDART_HEIGHT || x1 - x0 != STANDART_WIDTH) 
        {
            main_pos.close();
            return 2;
        }
        //if we add new image, then resize main vector
        if (filename > main.size()) 
        {
            main.resize(filename);
        }
        /*-----------------------------------------------------------------------------
         *  if we have situations when several main class objects we will place 
         *  information about them in main[filename - 1] vector
         *-----------------------------------------------------------------------------*/
        main[filename - 1].push_back(QPoint(x0, y0));
        train_exs++;
        in >> filename; 
    }
    main_pos.close();
    prob.l = train_exs * 2;
    prob.n = num_features + 1;
    prob.y = (int *)malloc(sizeof(int) * prob.l); 
    prob.x = (feature_node **)malloc(sizeof(struct feature_node *) * prob.l); 
    grad = (char **)calloc(STANDART_WIDTH, sizeof(char *));
    for (i = 0; i < STANDART_WIDTH; i++) 
    {
        grad[i] = (char *)calloc(STANDART_HEIGHT, sizeof(char));
    }
    //now open each file and extract hog of each object from it
    for (i = 0, k = 0; i < main.size(); i++) 
    {
        if (main[i].size() == 0) 
        {
            continue;
        }
        tmp_im.load(dir + DELIM + QString::number(i + 1) + PNG);
        if (tmp_im.isNull()) 
        {
            return 3;
        }
        for (j = 0; j < main[i].size(); j++)
        {
            prob.y[k] = 1;
            prob.x[k] = (feature_node *)calloc(num_features + 1, sizeof(struct feature_node));
            calc_Gradient(tmp_im, grad, main[i][j].x(), main[i][j].y());
            calc_HOG(prob.x[k], grad);
            k++;
        }
    }
    k = 0;
    //add objects of background class to the training sample
    while (k < train_exs) 
    {
        //objects will be added randomly from main[i] pictures
        i = rand() % files.size();
        QString tmp(files.at(i)); 
        tmp_im.load(path.filePath(tmp));
        if (tmp_im.isNull()) 
        {
            return 3;
        }
        bool check_conversion;
        i = tmp.remove(PNG, Qt::CaseInsensitive).toInt(&check_conversion);
        if (!check_conversion) 
        {
            return 4;
        }
        i--; // because files' indexes in dir starting from 1
        int x0 = rand() % (tmp_im.width() - STANDART_WIDTH + 1);
        if (i < main.size()) 
        {
        /*-----------------------------------------------------------------------------
         *  FIXME: too slow implementation with random numbers.
         *  to enhance it, try binarry search in images to find a place
         *  where background and human aren't crossed.
         *-----------------------------------------------------------------------------*/
            for (j = 0; j < main[i].size(); j++)
            {
                if (abs(main[i][j].x() - x0) < (STANDART_WIDTH / 2) + EPS) 
                {
                    break;
                }
            }
            if (j < main[i].size()) 
            {
                continue;
            }
        }
        prob.y[k + train_exs] = -1;
        prob.x[k + train_exs] = (feature_node *)calloc(num_features + 1, sizeof(struct feature_node));
        calc_Gradient(tmp_im, grad, x0);
        calc_HOG(prob.x[k + train_exs], grad);
        k++;
    }
    //teach svm
    predictor = train(&prob, &param); 
    //free resources
    free(prob.y);
    for (i = 0; i < prob.l; i++) 
    {
        free(prob.x[i]);
    }
    free(prob.x);
    for (i = 0; i < STANDART_WIDTH; i++) 
    {
        free(grad[i]);
    }
    free(grad);
    return 0;
}

int Model::loadModel(QString name)
{
    QByteArray tmp = name.toAscii();
    if((predictor = load_model(tmp.data())) == 0)
    {
        return 1;
    }
    return 0;
}

int Model::saveModel(QString name)
{
    QByteArray tmp = name.toAscii();
    if (save_model(tmp.data(), predictor))
    {
        return 1;
    }
    return 0;
}

//this function is for optimisation purposes
void Model::calc_Gradient(QImage & file, char ** grad, int x, int y, int height, int width)
{
    int i, j;
    //i suggest that IMAGE_FEATURES is integer
    //prepare kernels for convolution
    double Gx[3][3] = {{-1.0, -2.0, -1.0}, {0.0, 0.0, 0.0}, {1.0, 2.0, 1.0}};
    double Gy[3][3] = {{-1.0, 0.0, 1.0}, {-2.0, 0.0, 2.0}, {-1.0, 0.0, 1.0}};
    //calculate brightness in each poing of image
    //it is for optimization purposes
    double **bright = (double **)calloc(width, sizeof(double *));
    for (i = 0; i < width; i++) 
    {
        bright[i] = (double *)calloc(height, sizeof(double));
        for (j = 0; j < height; j++) 
        {
            QRgb tmp = file.pixel(x + i, y + j);
            bright[i][j] = BT709(tmp);
        }
    }
    //compute Gradient 
    for (i = 0; i < width; i++) 
    {
        for (j = 0; j < height; j++) 
        {
            int k, l, filter_i, filter_j; 
            double gr_x = 0.0, gr_y = 0.0; //gradient will be (gr_x, gr_y)
            //compute gradient
            for (k = i -1, filter_i = 0; k <= i + 1; k++, filter_i++) 
            {
                for (l = j -1, filter_j = 0; l <= j + 1; l++, filter_j++) 
                {
                    //use convolution, edges are mirrored
                    gr_x += bright[NORM_WITH(k, width)][NORM_WITH(l, height)] * Gx[filter_i][filter_j];
                    gr_y += bright[NORM_WITH(k, width)][NORM_WITH(l, height)] * Gy[filter_i][filter_j];
                }
            }
            //compute gradient angle than its angle block
            if (abs(gr_x) < EPS) 
            {
                grad[i][j] = ANGLE_GROUPS - 1;
                continue;
            }
            grad[i][j] = int((atan(gr_y / gr_x) + M_PI / 2) / M_PI * ANGLE_GROUPS);
        }
    }
    for (i = 0; i < width; i++) 
    {
        free(bright[i]);
    }
    free(bright);
}

//calc HOG to res based on grad array
void Model::calc_HOG(struct feature_node * res, char ** grad, int x, int y)
{
    int i, j;
    int num_features = IMAGE_FEATURES(STANDART_HEIGHT, STANDART_WIDTH);

    //prepare feature_node array
    res[num_features].index = -1;
    for (i = 0; i < num_features; i++) 
    {
        res[i].index = i + 1;
        res[i].value = 0;
    }
    //calculate HOG
    for (i = 0; i < STANDART_WIDTH; i++) 
    {
        for (j = 0; j < STANDART_HEIGHT; j++) 
        {
            res[(i / 8 * (STANDART_HEIGHT / 8) + j / 8) * ANGLE_GROUPS + grad[x + i][y + j]].value++;
        }
    }
    
}

int Model::estimate(QString detected, QString right_positions, double *res)
{
    QFile pos(detected);
    size_t filename, y0, x0, y1, x1;
    size_t i;
    std::vector< std::vector<QPoint> > main; //FIXME: Don't have to store y component. Optimize it!
    double det = 0.0, tp = 0.0, gt = 0.0;
    if (!pos.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        qDebug() << detected << endl;
        pos.close();
        return 1;
    }
    QTextStream in(&pos);
    in >> filename; 
    while (!in.atEnd()) 
    {
        in >> y0 >> x0 >> y1 >> x1;
        if (y1 - y0 != STANDART_HEIGHT || x1 - x0 != STANDART_WIDTH) 
        {
            pos.close();
            return 2;
        }
        //if we add new image, then resize main vector
        if (filename > main.size()) 
        {
            main.resize(filename);
        }
        main[filename - 1].push_back(QPoint(x0, y0));
        det++;
        in >> filename; 
    }
    pos.close();
    pos.setFileName(right_positions);
    if (!pos.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        pos.close();
        return 1;
    }
    in >> filename; 
    while (!in.atEnd()) 
    {
        in >> y0 >> x0 >> y1 >> x1;
        if (y1 - y0 != STANDART_HEIGHT || x1 - x0 != STANDART_WIDTH) 
        {
            pos.close();
            return 2;
        }
        if (filename <= main.size()) 
        {
            for (i = 0; i < main[filename -1].size(); i++) 
            {
                if (abs(x0 - main[filename - 1][i].x()) < STANDART_WIDTH / 2 + EPS) 
                {
                    tp++;
                    break;
                }
            }
        }
        gt++;
        in >> filename; 
    }
    res[0] = tp / gt;
    res[1] = tp / det;
    return 0;
}

int Model::predict(QDir path, QStringList & files, QTextStream & out, QString model)
{
    int i, k;
    QImage tmp_im;
    char ** grad;
    //check if user wants to use new model (not current one)
    if (model != QString()) 
    {
        destroyPredictor();
        if (loadModel(model))
        {
            return 1;
        }
    }
    //check if model is loaded
    if (!predictor) 
    {
        return 2;
    }
    //allocate space for future predictions
    struct feature_node *example = (feature_node *)calloc(IMAGE_FEATURES(STANDART_HEIGHT, STANDART_WIDTH) + 1, sizeof(struct feature_node));

    //open result file in the same directory
    //iterate though files
    for (k = 0; k < files.size(); k++) 
    {
        tmp_im.load(path.filePath(files.at(k)));
        if (tmp_im.isNull()) 
        {
            continue;
        }
        grad = (char **)calloc(tmp_im.width(), sizeof(char *));
        for (i = 0; i < tmp_im.width(); i++) 
        {
            grad[i] = (char *)calloc(tmp_im.height(), sizeof(char));
        }
        std::vector<double> func((tmp_im.width() - STANDART_WIDTH + 1) / X_STEP + 1);

        calc_Gradient(tmp_im, grad, STANDART_X, STANDART_Y, tmp_im.height(), tmp_im.width());
        //search appropriate patch with "window"
        for (i = 0; i < tmp_im.width() - STANDART_WIDTH + 1; i += X_STEP) 
        {
            calc_HOG(example, grad, i, STANDART_Y);
            predict_values(predictor, example, &func[i / X_STEP]);
        }

        //output results
        QString tmp(files.at(k)); 
        QString & name = tmp.remove(PNG, Qt::CaseInsensitive);
        double last_max;
        //greed algoritm to erase bad dots
        do
        {
            last_max = 0.0;
            int new_positive = 0;
            for (i = 0; i < (tmp_im.width() - STANDART_WIDTH + 1) / X_STEP; i++) 
            {
                if (func[i] - last_max > EPS) 
                {
                    new_positive = i;
                    last_max = func[i];
                }
            }
            if (last_max > EPS) 
            {
                out << name << " " << STANDART_Y << " " << new_positive * X_STEP << " " << STANDART_Y + STANDART_HEIGHT << " " << new_positive * X_STEP + STANDART_WIDTH << endl;
                for (i = new_positive - (STANDART_WIDTH / 2 / X_STEP + 1); i < new_positive + (STANDART_WIDTH / 2 / X_STEP + 1); i++) 
                {
                    //to erase some bad behaviour of comparison signed and unsigned ints i add (long) 
                    if (i >= 0 && i < (long)func.size())
                    {
                        func[i] = -1.0;
                    }
                }
            }
        }
        while (last_max > EPS);
        for (i = 0; i < tmp_im.width(); i++) 
        {
            free(grad[i]);
        }
        free(grad);
    }
    free(example);
    return 0;
}
