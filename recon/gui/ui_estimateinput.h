/********************************************************************************
** Form generated from reading UI file 'estimateinput.ui'
**
** Created: Sun Oct 16 01:16:02 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESTIMATEINPUT_H
#define UI_ESTIMATEINPUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EstIn
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *resEdit;
    QPushButton *resButton;
    QPushButton *fileButton;
    QLineEdit *fileEdit;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EstIn)
    {
        if (EstIn->objectName().isEmpty())
            EstIn->setObjectName(QString::fromUtf8("EstIn"));
        EstIn->resize(470, 136);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(EstIn->sizePolicy().hasHeightForWidth());
        EstIn->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(EstIn);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(30, 20, 40, -1);
        gridLayout = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(-1);
        label = new QLabel(EstIn);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(160, 0));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        resEdit = new QLineEdit(EstIn);
        resEdit->setObjectName(QString::fromUtf8("resEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(resEdit->sizePolicy().hasHeightForWidth());
        resEdit->setSizePolicy(sizePolicy2);
        resEdit->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(resEdit, 0, 1, 1, 1);

        resButton = new QPushButton(EstIn);
        resButton->setObjectName(QString::fromUtf8("resButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(resButton->sizePolicy().hasHeightForWidth());
        resButton->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(resButton, 0, 2, 1, 1);

        fileButton = new QPushButton(EstIn);
        fileButton->setObjectName(QString::fromUtf8("fileButton"));
        sizePolicy3.setHeightForWidth(fileButton->sizePolicy().hasHeightForWidth());
        fileButton->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(fileButton, 3, 2, 1, 1);

        fileEdit = new QLineEdit(EstIn);
        fileEdit->setObjectName(QString::fromUtf8("fileEdit"));
        fileEdit->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(fileEdit, 3, 1, 1, 1);

        label_2 = new QLabel(EstIn);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(110, 0));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(EstIn);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(EstIn);
        QObject::connect(buttonBox, SIGNAL(accepted()), EstIn, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EstIn, SLOT(reject()));

        QMetaObject::connectSlotsByName(EstIn);
    } // setupUi

    void retranslateUi(QDialog *EstIn)
    {
        EstIn->setWindowTitle(QApplication::translate("EstIn", "Train data input", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EstIn", "File with right positions:", 0, QApplication::UnicodeUTF8));
        resButton->setText(QApplication::translate("EstIn", "...", 0, QApplication::UnicodeUTF8));
        fileButton->setText(QApplication::translate("EstIn", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EstIn", "File with results:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EstIn: public Ui_EstIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESTIMATEINPUT_H
