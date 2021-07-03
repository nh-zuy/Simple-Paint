/********************************************************************************
** Form generated from reading UI file 'widthdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDTHDIALOG_H
#define UI_WIDTHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WidthDialog
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *WidthDialog)
    {
        if (WidthDialog->objectName().isEmpty())
            WidthDialog->setObjectName(QString::fromUtf8("WidthDialog"));
        WidthDialog->resize(249, 112);
        gridLayout_2 = new QGridLayout(WidthDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(WidthDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSlider = new QSlider(WidthDialog);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(40);
        horizontalSlider->setValue(5);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider);

        spinBox = new QSpinBox(WidthDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(40);
        spinBox->setValue(5);

        horizontalLayout_2->addWidget(spinBox);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(WidthDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(WidthDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), WidthDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WidthDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(WidthDialog);
    } // setupUi

    void retranslateUi(QDialog *WidthDialog)
    {
        WidthDialog->setWindowTitle(QApplication::translate("WidthDialog", "Width Size", nullptr));
        label->setText(QApplication::translate("WidthDialog", "Width", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidthDialog: public Ui_WidthDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDTHDIALOG_H
