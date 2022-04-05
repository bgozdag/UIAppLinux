/********************************************************************************
** Form generated from reading UI file 'chargingscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGINGSCREEN_H
#define UI_CHARGINGSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickableqwidget.h>
#include "progressbarwidget.h"

QT_BEGIN_NAMESPACE

class Ui_ChargingScreen
{
public:
    QLabel *percentageLabel;
    ClickableQWidget *stopChargingButton;
    QWidget *stopChargingButtonImage;
    QLabel *stopChargingButtonLabel;
    ProgressBarWidget *chargeProgressBar;
    QWidget *infoLabelWidget;
    QGridLayout *gridLayout;
    QFrame *energyDurationSeparator;
    QVBoxLayout *verticalLayout_4;
    QLabel *remainingTimeLabel;
    QLabel *remainingTimeValue;
    QVBoxLayout *verticalLayout_2;
    QLabel *energyLabel;
    QLabel *energyValue;
    QVBoxLayout *verticalLayout;
    QLabel *powerLabel;
    QLabel *powerValue;
    QVBoxLayout *verticalLayout_3;
    QLabel *timeLabel;
    QLabel *timeValue;
    QFrame *powerEnergySeparator;
    QFrame *durationRemainingSeparator;
    QWidget *carAndStationImage;

    void setupUi(QWidget *ChargingScreen)
    {
        if (ChargingScreen->objectName().isEmpty())
            ChargingScreen->setObjectName(QStringLiteral("ChargingScreen"));
        ChargingScreen->resize(1024, 768);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        ChargingScreen->setFont(font);
        percentageLabel = new QLabel(ChargingScreen);
        percentageLabel->setObjectName(QStringLiteral("percentageLabel"));
        percentageLabel->setGeometry(QRect(330, 445, 101, 51));
        stopChargingButton = new ClickableQWidget(ChargingScreen);
        stopChargingButton->setObjectName(QStringLiteral("stopChargingButton"));
        stopChargingButton->setGeometry(QRect(480, 590, 470, 80));
        stopChargingButtonImage = new QWidget(stopChargingButton);
        stopChargingButtonImage->setObjectName(QStringLiteral("stopChargingButtonImage"));
        stopChargingButtonImage->setGeometry(QRect(0, 0, 466, 74));
        stopChargingButtonLabel = new QLabel(stopChargingButton);
        stopChargingButtonLabel->setObjectName(QStringLiteral("stopChargingButtonLabel"));
        stopChargingButtonLabel->setGeometry(QRect(10, 7, 450, 58));
        chargeProgressBar = new ProgressBarWidget(ChargingScreen);
        chargeProgressBar->setObjectName(QStringLiteral("chargeProgressBar"));
        chargeProgressBar->setGeometry(QRect(440, 450, 541, 40));
        chargeProgressBar->setStyleSheet(QStringLiteral(""));
        infoLabelWidget = new QWidget(ChargingScreen);
        infoLabelWidget->setObjectName(QStringLiteral("infoLabelWidget"));
        infoLabelWidget->setGeometry(QRect(430, 495, 551, 71));
        gridLayout = new QGridLayout(infoLabelWidget);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        energyDurationSeparator = new QFrame(infoLabelWidget);
        energyDurationSeparator->setObjectName(QStringLiteral("energyDurationSeparator"));
        energyDurationSeparator->setFrameShadow(QFrame::Raised);
        energyDurationSeparator->setFrameShape(QFrame::VLine);

        gridLayout->addWidget(energyDurationSeparator, 0, 3, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        remainingTimeLabel = new QLabel(infoLabelWidget);
        remainingTimeLabel->setObjectName(QStringLiteral("remainingTimeLabel"));

        verticalLayout_4->addWidget(remainingTimeLabel);

        remainingTimeValue = new QLabel(infoLabelWidget);
        remainingTimeValue->setObjectName(QStringLiteral("remainingTimeValue"));

        verticalLayout_4->addWidget(remainingTimeValue);


        gridLayout->addLayout(verticalLayout_4, 0, 6, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        energyLabel = new QLabel(infoLabelWidget);
        energyLabel->setObjectName(QStringLiteral("energyLabel"));

        verticalLayout_2->addWidget(energyLabel);

        energyValue = new QLabel(infoLabelWidget);
        energyValue->setObjectName(QStringLiteral("energyValue"));

        verticalLayout_2->addWidget(energyValue);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        powerLabel = new QLabel(infoLabelWidget);
        powerLabel->setObjectName(QStringLiteral("powerLabel"));

        verticalLayout->addWidget(powerLabel);

        powerValue = new QLabel(infoLabelWidget);
        powerValue->setObjectName(QStringLiteral("powerValue"));

        verticalLayout->addWidget(powerValue);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        timeLabel = new QLabel(infoLabelWidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        verticalLayout_3->addWidget(timeLabel);

        timeValue = new QLabel(infoLabelWidget);
        timeValue->setObjectName(QStringLiteral("timeValue"));

        verticalLayout_3->addWidget(timeValue);


        gridLayout->addLayout(verticalLayout_3, 0, 4, 1, 1);

        powerEnergySeparator = new QFrame(infoLabelWidget);
        powerEnergySeparator->setObjectName(QStringLiteral("powerEnergySeparator"));
        powerEnergySeparator->setFrameShadow(QFrame::Raised);
        powerEnergySeparator->setFrameShape(QFrame::VLine);

        gridLayout->addWidget(powerEnergySeparator, 0, 1, 1, 1);

        durationRemainingSeparator = new QFrame(infoLabelWidget);
        durationRemainingSeparator->setObjectName(QStringLiteral("durationRemainingSeparator"));
        durationRemainingSeparator->setFrameShadow(QFrame::Raised);
        durationRemainingSeparator->setFrameShape(QFrame::VLine);

        gridLayout->addWidget(durationRemainingSeparator, 0, 5, 1, 1);

        carAndStationImage = new QWidget(ChargingScreen);
        carAndStationImage->setObjectName(QStringLiteral("carAndStationImage"));
        carAndStationImage->setGeometry(QRect(340, 74, 731, 321));
        carAndStationImage->setStyleSheet(QStringLiteral(""));

        retranslateUi(ChargingScreen);

        QMetaObject::connectSlotsByName(ChargingScreen);
    } // setupUi

    void retranslateUi(QWidget *ChargingScreen)
    {
        ChargingScreen->setWindowTitle(QApplication::translate("ChargingScreen", "Form", Q_NULLPTR));
        percentageLabel->setText(QApplication::translate("ChargingScreen", "%30", Q_NULLPTR));
        stopChargingButtonLabel->setText(QApplication::translate("ChargingScreen", "\305\236arj\304\261 Durdur", Q_NULLPTR));
        remainingTimeLabel->setText(QApplication::translate("ChargingScreen", "Kalan S\303\274re", Q_NULLPTR));
        remainingTimeValue->setText(QApplication::translate("ChargingScreen", "2 dk", Q_NULLPTR));
        energyLabel->setText(QApplication::translate("ChargingScreen", "Enerji", Q_NULLPTR));
        energyValue->setText(QApplication::translate("ChargingScreen", "10 kWh", Q_NULLPTR));
        powerLabel->setText(QApplication::translate("ChargingScreen", "G\303\274\303\247", Q_NULLPTR));
        powerValue->setText(QApplication::translate("ChargingScreen", "68 kW", Q_NULLPTR));
        timeLabel->setText(QApplication::translate("ChargingScreen", "S\303\274re", Q_NULLPTR));
        timeValue->setText(QApplication::translate("ChargingScreen", "10 dk", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChargingScreen: public Ui_ChargingScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGINGSCREEN_H
