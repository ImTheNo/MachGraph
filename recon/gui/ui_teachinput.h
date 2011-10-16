/********************************************************************************
** Form generated from reading UI file 'teachinput.ui'
**
** Created: Sat Oct 15 10:48:49 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHINPUT_H
#define UI_TEACHINPUT_H

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

class Ui_TeachInput
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *dirEdit;
    QPushButton *dirButton;
    QPushButton *fileButton;
    QLineEdit *fileEdit;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TeachInput)
    {
        if (TeachInput->objectName().isEmpty())
            TeachInput->setObjectName(QString::fromUtf8("TeachInput"));
        TeachInput->resize(472, 140);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(TeachInput->sizePolicy().hasHeightForWidth());
        TeachInput->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(TeachInput);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(30, 20, 40, -1);
        gridLayout = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(-1);
        label = new QLabel(TeachInput);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(160, 0));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        dirEdit = new QLineEdit(TeachInput);
        dirEdit->setObjectName(QString::fromUtf8("dirEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dirEdit->sizePolicy().hasHeightForWidth());
        dirEdit->setSizePolicy(sizePolicy2);
        dirEdit->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(dirEdit, 0, 1, 1, 1);

        dirButton = new QPushButton(TeachInput);
        dirButton->setObjectName(QString::fromUtf8("dirButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(dirButton->sizePolicy().hasHeightForWidth());
        dirButton->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(dirButton, 0, 2, 1, 1);

        fileButton = new QPushButton(TeachInput);
        fileButton->setObjectName(QString::fromUtf8("fileButton"));
        sizePolicy3.setHeightForWidth(fileButton->sizePolicy().hasHeightForWidth());
        fileButton->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(fileButton, 3, 2, 1, 1);

        fileEdit = new QLineEdit(TeachInput);
        fileEdit->setObjectName(QString::fromUtf8("fileEdit"));
        fileEdit->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(fileEdit, 3, 1, 1, 1);

        label_2 = new QLabel(TeachInput);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(110, 0));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(TeachInput);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TeachInput);
        QObject::connect(buttonBox, SIGNAL(accepted()), TeachInput, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TeachInput, SLOT(reject()));

        QMetaObject::connectSlotsByName(TeachInput);
    } // setupUi

    void retranslateUi(QDialog *TeachInput)
    {
        TeachInput->setWindowTitle(QApplication::translate("TeachInput", "Train data input", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TeachInput", "File with right positions:", 0, QApplication::UnicodeUTF8));
        dirButton->setText(QApplication::translate("TeachInput", "...", 0, QApplication::UnicodeUTF8));
        fileButton->setText(QApplication::translate("TeachInput", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TeachInput", "Data directory:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TeachInput: public Ui_TeachInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHINPUT_H
