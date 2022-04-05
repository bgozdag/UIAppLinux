/********************************************************************************
** Form generated from reading UI file 'stepbasedprogressbar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEPBASEDPROGRESSBAR_H
#define UI_STEPBASEDPROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StepBasedProgressBar
{
public:
    QWidget *initializingProgressBarWidget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *initializingProgressBarGridLayout;
    QProgressBar *initializingProgressBar;

    void setupUi(QWidget *StepBasedProgressBar)
    {
        if (StepBasedProgressBar->objectName().isEmpty())
            StepBasedProgressBar->setObjectName(QStringLiteral("StepBasedProgressBar"));
        StepBasedProgressBar->resize(768, 80);
        initializingProgressBarWidget = new QWidget(StepBasedProgressBar);
        initializingProgressBarWidget->setObjectName(QStringLiteral("initializingProgressBarWidget"));
        initializingProgressBarWidget->setGeometry(QRect(0, 0, 768, 80));
        initializingProgressBarWidget->setMinimumSize(QSize(0, 80));
        initializingProgressBarWidget->setMaximumSize(QSize(800, 80));
        gridLayoutWidget_2 = new QWidget(initializingProgressBarWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 731, 37));
        initializingProgressBarGridLayout = new QGridLayout(gridLayoutWidget_2);
        initializingProgressBarGridLayout->setObjectName(QStringLiteral("initializingProgressBarGridLayout"));
        initializingProgressBarGridLayout->setContentsMargins(0, 0, 0, 0);
        initializingProgressBar = new QProgressBar(gridLayoutWidget_2);
        initializingProgressBar->setObjectName(QStringLiteral("initializingProgressBar"));
        initializingProgressBar->setMinimumSize(QSize(0, 25));
        initializingProgressBar->setMaximumSize(QSize(280, 16777215));
        initializingProgressBar->setStyleSheet(QStringLiteral(""));
        initializingProgressBar->setValue(0);
        initializingProgressBar->setAlignment(Qt::AlignCenter);

        initializingProgressBarGridLayout->addWidget(initializingProgressBar, 0, 0, 1, 1);


        retranslateUi(StepBasedProgressBar);

        QMetaObject::connectSlotsByName(StepBasedProgressBar);
    } // setupUi

    void retranslateUi(QWidget *StepBasedProgressBar)
    {
        StepBasedProgressBar->setWindowTitle(QApplication::translate("StepBasedProgressBar", "Form", Q_NULLPTR));
        initializingProgressBar->setFormat(QString());
    } // retranslateUi

};

namespace Ui {
    class StepBasedProgressBar: public Ui_StepBasedProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEPBASEDPROGRESSBAR_H
