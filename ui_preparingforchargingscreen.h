/********************************************************************************
** Form generated from reading UI file 'preparingforchargingscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREPARINGFORCHARGINGSCREEN_H
#define UI_PREPARINGFORCHARGINGSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "spinnerwidget.h"

QT_BEGIN_NAMESPACE

class Ui_PreparingForChargingScreen
{
public:
    QLabel *chargingLabel;
    SpinnerWidget *progressSpinnerWidget;
    QWidget *carAndStationImage;

    void setupUi(QWidget *PreparingForChargingScreen)
    {
        if (PreparingForChargingScreen->objectName().isEmpty())
            PreparingForChargingScreen->setObjectName(QStringLiteral("PreparingForChargingScreen"));
        PreparingForChargingScreen->resize(1024, 768);
        chargingLabel = new QLabel(PreparingForChargingScreen);
        chargingLabel->setObjectName(QStringLiteral("chargingLabel"));
        chargingLabel->setGeometry(QRect(390, 435, 631, 91));
        progressSpinnerWidget = new SpinnerWidget(PreparingForChargingScreen);
        progressSpinnerWidget->setObjectName(QStringLiteral("progressSpinnerWidget"));
        progressSpinnerWidget->setGeometry(QRect(625, 540, 161, 131));
        carAndStationImage = new QWidget(PreparingForChargingScreen);
        carAndStationImage->setObjectName(QStringLiteral("carAndStationImage"));
        carAndStationImage->setGeometry(QRect(387, 63, 637, 331));
        carAndStationImage->setStyleSheet(QStringLiteral(""));

        retranslateUi(PreparingForChargingScreen);

        QMetaObject::connectSlotsByName(PreparingForChargingScreen);
    } // setupUi

    void retranslateUi(QWidget *PreparingForChargingScreen)
    {
        PreparingForChargingScreen->setWindowTitle(QApplication::translate("PreparingForChargingScreen", "Form", Q_NULLPTR));
        chargingLabel->setText(QApplication::translate("PreparingForChargingScreen", "\305\236arj ba\305\237lat\304\261l\304\261yor\n"
"L\303\274tfen bekleyiniz...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PreparingForChargingScreen: public Ui_PreparingForChargingScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREPARINGFORCHARGINGSCREEN_H
