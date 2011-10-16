/********************************************************************************
** Form generated from reading UI file 'suspenddialog.ui'
**
** Created: Sat Oct 15 10:09:00 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUSPENDDIALOG_H
#define UI_SUSPENDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SuspendDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *SuspendDialog)
    {
        if (SuspendDialog->objectName().isEmpty())
            SuspendDialog->setObjectName(QString::fromUtf8("SuspendDialog"));
        SuspendDialog->setWindowModality(Qt::WindowModal);
        SuspendDialog->resize(428, 100);
        verticalLayout = new QVBoxLayout(SuspendDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(SuspendDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        retranslateUi(SuspendDialog);

        QMetaObject::connectSlotsByName(SuspendDialog);
    } // setupUi

    void retranslateUi(QDialog *SuspendDialog)
    {
        SuspendDialog->setWindowTitle(QApplication::translate("SuspendDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SuspendDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SuspendDialog: public Ui_SuspendDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUSPENDDIALOG_H
