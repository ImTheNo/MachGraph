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
     void gaus_filter();
     void unsharp_filter();

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

     QMenu *fileMenu;
     QMenu *filterMenu;
     QMenu *contrastMenu;

     QString fileName;
     QImage image;
     int sigma;
     int alpha;

     bool SanityCheck();
     void updateLabel();
     void convolution(int x0, int y0, int width, int height, std::vector<std::vector<double> > & filter);
 };

 #endif
