
#include "../model.h"
#include "../controller.h"
#include "../viewbase.h"
#include "mainwindow.h"
#include <QDebug>
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainWindow view;
    Control controller(&view);
    view.show();
    return app.exec();
}
