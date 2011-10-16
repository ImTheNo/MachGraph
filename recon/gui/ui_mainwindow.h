/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Oct 15 12:51:03 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionQuit;
    QAction *actionTeach;
    QAction *actionPredict;
    QAction *actionEstimate;
    QAction *actionRecognize;
    QAction *actionSetEstimation;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *teachButton;
    QPushButton *predictButton;
    QPushButton *estimateButton;
    QPushButton *reconButton;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuSVM;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(557, 384);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionTeach = new QAction(MainWindow);
        actionTeach->setObjectName(QString::fromUtf8("actionTeach"));
        actionPredict = new QAction(MainWindow);
        actionPredict->setObjectName(QString::fromUtf8("actionPredict"));
        actionEstimate = new QAction(MainWindow);
        actionEstimate->setObjectName(QString::fromUtf8("actionEstimate"));
        actionRecognize = new QAction(MainWindow);
        actionRecognize->setObjectName(QString::fromUtf8("actionRecognize"));
        actionSetEstimation = new QAction(MainWindow);
        actionSetEstimation->setObjectName(QString::fromUtf8("actionSetEstimation"));
        actionSetEstimation->setCheckable(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(6, 6, 6, 6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        teachButton = new QPushButton(centralwidget);
        teachButton->setObjectName(QString::fromUtf8("teachButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(teachButton->sizePolicy().hasHeightForWidth());
        teachButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(teachButton);

        predictButton = new QPushButton(centralwidget);
        predictButton->setObjectName(QString::fromUtf8("predictButton"));
        sizePolicy.setHeightForWidth(predictButton->sizePolicy().hasHeightForWidth());
        predictButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(predictButton);

        estimateButton = new QPushButton(centralwidget);
        estimateButton->setObjectName(QString::fromUtf8("estimateButton"));
        sizePolicy.setHeightForWidth(estimateButton->sizePolicy().hasHeightForWidth());
        estimateButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(estimateButton);

        reconButton = new QPushButton(centralwidget);
        reconButton->setObjectName(QString::fromUtf8("reconButton"));
        sizePolicy.setHeightForWidth(reconButton->sizePolicy().hasHeightForWidth());
        reconButton->setSizePolicy(sizePolicy);
        reconButton->setSizeIncrement(QSize(0, 0));

        verticalLayout->addWidget(reconButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout->addWidget(label);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 557, 21));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuSVM = new QMenu(menubar);
        menuSVM->setObjectName(QString::fromUtf8("menuSVM"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuSVM->menuAction());
        menuMenu->addAction(actionSave);
        menuMenu->addAction(actionLoad);
        menuMenu->addSeparator();
        menuMenu->addSeparator();
        menuMenu->addAction(actionQuit);
        menuSVM->addAction(actionTeach);
        menuSVM->addAction(actionPredict);
        menuSVM->addAction(actionSetEstimation);
        menuSVM->addAction(actionEstimate);
        menuSVM->addAction(actionRecognize);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save prediction model to ifle", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionLoad->setToolTip(QApplication::translate("MainWindow", "Load model from file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionLoad->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionTeach->setText(QApplication::translate("MainWindow", "Teach", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionTeach->setToolTip(QApplication::translate("MainWindow", "Create Model", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionTeach->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", 0, QApplication::UnicodeUTF8));
        actionPredict->setText(QApplication::translate("MainWindow", "Predict", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPredict->setToolTip(QApplication::translate("MainWindow", "Predict group of files", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPredict->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionEstimate->setText(QApplication::translate("MainWindow", "Estimate", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionEstimate->setToolTip(QApplication::translate("MainWindow", "Estimate result of prediction", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionEstimate->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        actionRecognize->setText(QApplication::translate("MainWindow", "Recognize", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRecognize->setToolTip(QApplication::translate("MainWindow", "Dedect objects on image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRecognize->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        actionSetEstimation->setText(QApplication::translate("MainWindow", "SetEstimation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSetEstimation->setToolTip(QApplication::translate("MainWindow", "set estimation to do with prediction", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        teachButton->setText(QApplication::translate("MainWindow", "Teach", 0, QApplication::UnicodeUTF8));
        predictButton->setText(QApplication::translate("MainWindow", "Predict", 0, QApplication::UnicodeUTF8));
        estimateButton->setText(QApplication::translate("MainWindow", "Estimate", 0, QApplication::UnicodeUTF8));
        reconButton->setText(QApplication::translate("MainWindow", "Recognize", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        menuMenu->setTitle(QApplication::translate("MainWindow", "Model", 0, QApplication::UnicodeUTF8));
        menuSVM->setTitle(QApplication::translate("MainWindow", "SVM", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
