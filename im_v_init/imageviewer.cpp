#include <QtGui>

 #include "imageviewer.h"

 ImageViewer::ImageViewer()
 {
     imageLabel = new QLabel;
     imageLabel->setBackgroundRole(QPalette::Base);
     imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
     imageLabel->setScaledContents(true);

     scrollArea = new QScrollArea;
     scrollArea->setBackgroundRole(QPalette::Dark);
     scrollArea->setWidget(imageLabel);
     setCentralWidget(scrollArea);

     createActions();
     createMenus();

     sigma = 1;
     alpha = 1.5;

     setWindowTitle(tr("Image Viewer"));
     resize(500, 400);
 }

void ImageViewer::createActions()
 {
     openAct = new QAction(tr("&Open..."), this);
     openAct->setShortcut(tr("Ctrl+O"));
     connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

     exitAct = new QAction(tr("E&xit"), this);
     exitAct->setShortcut(tr("Ctrl+Q"));
     connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

     saveAct = new QAction(tr("Save"), this);
     saveAct->setShortcut(tr("Ctrl+S"));
     connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

     saveAsAct = new QAction(tr("saveAs"), this);
     connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

     contAct = new QAction(tr("summed"), this);
     contAct->setShortcut(tr("Ctrl+C"));
     connect(contAct, SIGNAL(triggered()), this, SLOT(contrast()));
     
     per_cAct = new QAction(tr("per channel"), this);
     per_cAct->setShortcut(tr("Ctrl+P"));
     connect(per_cAct, SIGNAL(triggered()), this, SLOT(per_channel()));

     gausAct = new QAction(tr("Gaus"), this);
     gausAct->setShortcut(tr("Ctrl+G"));
     connect(gausAct, SIGNAL(triggered()), this, SLOT(gaus_filter()));

     unsharpAct = new QAction(tr("Unsharp"), this);
     unsharpAct->setShortcut(tr("Ctrl+U"));
     connect(unsharpAct, SIGNAL(triggered()), this, SLOT(unsharp_filter()));
 }

 void ImageViewer::createMenus()
 {
     fileMenu = new QMenu(tr("&File"), this);
     fileMenu->addAction(openAct);
     fileMenu->addAction(saveAct);
     fileMenu->addAction(saveAsAct);
     fileMenu->addAction(exitAct);

     filterMenu = new QMenu(tr("Filter"), this);
     filterMenu->addAction(gausAct);
     filterMenu->addAction(unsharpAct);

     contrastMenu = new QMenu(tr("Contrast"), this);
     contrastMenu->addAction(contAct);
     contrastMenu->addAction(per_cAct);

     QMenuBar *MenuBar = menuBar();
     MenuBar->addMenu(fileMenu);
     MenuBar->addMenu(filterMenu);
     MenuBar->addMenu(contrastMenu);
 }

 void ImageViewer::open()
 {
     QString fileNameNew = QFileDialog::getOpenFileName(this,
                                     tr("Open File"), fileName.isEmpty() ? 
                                     QDir::currentPath() : fileName);
     if (!fileNameNew.isEmpty()) {
         if (!image.load(fileNameNew)) {
             QMessageBox::information(this, tr("Image Viewer"),
                                      tr("Cannot load %1.").arg(fileNameNew));
             return;
         }
         fileName = fileNameNew;
         updateLabel();
     }
 }

 void ImageViewer::saveAs()
 {
     if (SanityCheck()) 
     {
         return;
     }
     if (fileName.isEmpty()) 
     {
             QMessageBox::information(this, tr("Sanity Check"),
                                      tr("Baka, load image at first!!!"));
             return;
     }
     QString fileNameNew = QFileDialog::getSaveFileName(this,
                                     tr("Save File"), fileName, BMP_FILE_FORMAT);
     if (!fileNameNew.isEmpty()) {
         if (!image.save(fileNameNew, BMP)) {
             QMessageBox::information(this, tr("Image Viewer"),
                                      tr("Can't save %1.").arg(fileNameNew));
         }
         else
         {
            fileName = fileNameNew;
         }
     }
 }

 void ImageViewer::save()
 {
     if (SanityCheck()) 
     {
         return;
     }
     if (!image.save(fileName)) {
         QMessageBox::information(this, tr("Image Viewer"),
                                  tr("Can't save %1.").arg(fileName));
     }
 }

 bool ImageViewer::SanityCheck()
{
     if (fileName.isEmpty()) 
     {
             QMessageBox::information(this, tr("Sanity Check"),
                                      tr("Baka, load image at first!!!"));
             return true;
     }
     return false;
}

 void ImageViewer::updateLabel()
{
         imageLabel->setPixmap(QPixmap::fromImage(image));
         imageLabel->adjustSize(); 
}
