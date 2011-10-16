#include "mainwindow.h"
#include "../viewbase.h"
#include "ui_mainwindow.h"
#include "teachinput.h"
#include "ui_teachinput.h"
#include "estimateinput.h"
#include "ui_estimateinput.h"
#include "../model.h"
#include "../controller.h"

MainWindow::MainWindow(QWidget *parent) :
    ViewBase(parent),
    ui(new Ui::MainWindow),
    precense(false)
{
    ui->setupUi(this);
    setPrecense(false);//user can't do some actions until he load or teach some model
    ui->label->setBackgroundRole(QPalette::Dark);//to image viewer

    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));//close action 
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_triggered()
{
    QString model = QFileDialog::getSaveFileName(this, 
                                          tr("Enter model's filename please") 
                                          ); 
    if (model.isEmpty()) 
    {
        QMessageBox::information(this, tr("Can't save"),
                                     tr("Empty input"));
        return;
    }
    emit(eventSave(model));
}

void MainWindow::on_actionLoad_triggered()
{
    QString model = QFileDialog::getOpenFileName(this, 
                                          tr("Enter model's filename please") 
                                          ); 
    if (model.isEmpty()) 
    {
        QMessageBox::information(this, tr("Can't Load"),
                                     tr("Empty input"));
        return;
    }
    emit(eventLoad(model));
}

void MainWindow::on_actionTeach_triggered()
{
    QString dir, file;
    TeachInput dialog(this, dir, file, "Teach Input", "train-processed.idl");
    if (dialog.exec() == QDialog::Accepted) 
    {
        emit(eventTeach(dir, file));
    }
}

void MainWindow::on_actionPredict_triggered()
{
    if (ui->actionSetEstimation->isChecked()) 
    {
        QString dir, file;
        TeachInput dialog(this, dir, file, "Predict Input", "test-processed.idl");
        if (dialog.exec() == QDialog::Accepted) 
        {
            emit(eventPredictEstimate(dir, file));
        }
    }
    else
    {
        QString dir = QFileDialog::getExistingDirectory(this, 
                                          tr("Enter data directory") 
                                          ); 
        if (!dir.isEmpty()) 
        {
            emit(eventPredictEstimate(dir));
        }
    }
}

void MainWindow::on_actionRecognize_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, 
                                          tr("Enter file's name please"), QDir::current().path(), tr("Images (*.png)")); 
    if (file.isEmpty()) 
    {
        QMessageBox::information(this, tr("Can't recognize"),
                                     tr("Empty input"));
        return;
    }
    emit(eventPredictOne(file));
}

void MainWindow::on_actionEstimate_triggered()
{
    QString res, file;
    EstIn dialog(this, res, file);
    if (dialog.exec() == QDialog::Accepted) 
    {
        emit(eventEstimate(res, file));
    }
}

void MainWindow::Suspend(QString message)
{
    ui->statusbar->showMessage(QString("Please wait operation \"%1\" is computing now.").arg(message));
    setAll(false);
}

void MainWindow::Resume()
{
    ui->statusbar->clearMessage();
    setAll(true);
}

void MainWindow::tellToUser(QString  message)
{
        QMessageBox::information(this, QString("Message"),
                                     message);
    
}

void MainWindow::setPrecense(char flag)
{
    precense = flag;
    setAll(true);
}

void MainWindow::setAll(char flag)
{
    if (flag == true) 
    {
        ui->actionSave->setEnabled(precense);
        ui->actionPredict->setEnabled(precense);
        ui->actionRecognize->setEnabled(precense);
        ui->actionSetEstimation->setEnabled(precense);
    }
    else
    {
        ui->actionSave->setEnabled(false);
        ui->actionPredict->setEnabled(false);
        ui->actionRecognize->setEnabled(false);
        ui->actionSetEstimation->setEnabled(false);
        
    }
    ui->actionEstimate->setEnabled(flag);
    ui->actionLoad->setEnabled(flag);
    ui->actionQuit->setEnabled(flag);
    ui->predictButton->setEnabled(flag);
    ui->estimateButton->setEnabled(flag);
    ui->teachButton->setEnabled(flag);
    ui->reconButton->setEnabled(flag);
}

void MainWindow::setQualityEstimation(double recall, double precision)
{
        QMessageBox::information(this, tr("Estimation results"),
                                     tr("recall is %1 and precision is %2").arg(QString::number(recall)).arg(QString::number(precision)));
}

void MainWindow::showImage(QString file, std::vector<QPoint> results)
{
    int i, j;
    int im_w, im_h; //image width and height respectively
    QImage im(file, "PNG");
    if (im.isNull()) 
    {
        tellToUser(QString("can't open image file %1").arg(file));
        return;
    }
    im_w = im.width();
    im_h = im.height();
    for (i = 0; i < results.size(); i++) 
    {
        int x = results[i].x(), y = results[i].y();
        for (j = y; j <= y + STANDART_HEIGHT; j++) 
        {
            if (x < 0 || j < 0|| x >= im_w || j >= im_h) 
            {
                continue;
            }
            im.setPixel(x, j, qRgb(0, 255, 0));
            if (x + STANDART_WIDTH >= im_w) 
            {
                continue;
            }
            im.setPixel(x + STANDART_WIDTH, j, qRgb(0, 255, 0));
        }
        for (j = x + 1; j < x + STANDART_WIDTH; j++) 
        {
            if (j < 0 || y < 0|| j >= im_w || y >= im_h) 
            {
                continue;
            }
            im.setPixel(j, y, qRgb(0, 255, 0));
            if (y + STANDART_HEIGHT >= im_w) 
            {
                continue;
            }
            im.setPixel(j, y + STANDART_HEIGHT, qRgb(0, 255, 0));
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(im));
    ui->label->adjustSize(); 
}

//buttons for convinience
void MainWindow::on_predictButton_clicked()
{
    QString dir = QDir::current().filePath("predict");
    QString model = QDir(dir).filePath("model.idl");
    QString file;
    emit(eventLoad(model));
    if (ui->actionSetEstimation->isChecked()) 
    {
        file = QDir(dir).filePath("test-processed.idl");
    }
    emit(eventPredictEstimate(dir, file));
}

void MainWindow::on_estimateButton_clicked()
{
    QDir dir(QDir::current().filePath("predict"));
    QString res = dir.filePath("results.idl");
    QString file = dir.filePath("test-processed.idl");
    emit(eventEstimate(res, file));
}

void MainWindow::on_teachButton_clicked()
{
    QString dir = QDir::current().filePath("train");
    QString file = QDir(dir).filePath("train-processed.idl");
    emit(eventTeach(dir, file));
    QString model = QDir(QDir::current().filePath("predict")).filePath("model.idl");
    emit(eventSave(model));
}

void MainWindow::on_reconButton_clicked()
{
    QDir path(QDir::current().filePath("predict"));
    if (!path.exists()) 
    {
        return;
    }
    QString model = QDir(path).filePath("model.idl");
    emit(eventLoad(model));
    QStringList filters;

    //take list of images in directory 
    //DO NOT ACCEPT SYMBOLIC LINKS
    path.setFilter(QDir::Files | QDir::NoSymLinks);
    filters << QString(WILDCARD) + PNG;
    path.setNameFilters(filters);
    //extract list of files in directory
    QStringList files = path.entryList();
    int i = rand() % files.size();
    emit(eventPredictOne(path.filePath(files[i])));
}

