#ifndef IMAGEVIEWER_H
 #define IMAGEVIEWER_H

 #include <QMainWindow>

 #define BMP "BMP" 
 #define BMP_FILE_FORMAT "BMP images (*.bmp)" 

 class QAction;
 class QLabel;
 class QMenu;
 class QScrollArea;
 class QScrollBar;
 class QColor;

 class ImageViewer : public QMainWindow
 {
     Q_OBJECT

 public:
     ImageViewer();

 private slots:
     void open();
     void save();
     void saveAs();
     void contrast();
     void per_channel();
     void from_user_gaus_filter();
     void unsharp_filter();
     void scale();
     void rotate();

 private:
     void createActions();
     void createMenus();

     QLabel *imageLabel;
     QScrollArea *scrollArea;


     QAction *openAct;
     QAction *saveAct;
     QAction *saveAsAct;
     QAction *exitAct;
     QAction *contAct;
     QAction *per_cAct;
     QAction *gausAct;
     QAction *unsharpAct;
     QAction *rotateAct;
     QAction *scaleAct;

     QMenu *fileMenu;
     QMenu *filterMenu;
     QMenu *contrastMenu;
     QMenu *geometryMenu;

     QString fileName;
     QImage image;
     double sigma;
     double alpha;
     double factor;
     double r_factor;

     void updateLabel();

     bool SanityCheck();

     void gaus_filter(double sigma);
     void convolution(std::vector<std::vector<double> > & filter);
 };

 #endif
