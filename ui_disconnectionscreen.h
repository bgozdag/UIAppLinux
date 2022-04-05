/********************************************************************************
** Form generated from reading UI file 'disconnectionscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISCONNECTIONSCREEN_H
#define UI_DISCONNECTIONSCREEN_H

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

QT_BEGIN_NAMESPACE

class Ui_DisconnectionScreen
{
public:
    QLabel *disconnectionLabel;
    QWidget *VehicleAndStation;
    QWidget *infoLabelWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *durationLabel;
    QLabel *durationValue;
    QFrame *energyDurationSeparator;
    QVBoxLayout *verticalLayout;
    QLabel *energyLabel;
    QLabel *energyValue;
    QVBoxLayout *verticalLayout_3;
    QLabel *batteryLabel;
    QLabel *batteryLevelValue;
    QFrame *durationBatterySeparator;

    void setupUi(QWidget *DisconnectionScreen)
    {
        if (DisconnectionScreen->objectName().isEmpty())
            DisconnectionScreen->setObjectName(QStringLiteral("DisconnectionScreen"));
        DisconnectionScreen->resize(1024, 768);
        disconnectionLabel = new QLabel(DisconnectionScreen);
        disconnectionLabel->setObjectName(QStringLiteral("disconnectionLabel"));
        disconnectionLabel->setGeometry(QRect(400, 530, 611, 71));
        disconnectionLabel->setStyleSheet(QLatin1String("#disconnectionLabel {\n"
"    qproperty-alignment: AlignCenter;\n"
"    font-family: \"Muli SemiBold\";\n"
"    font-size: 28px;\n"
"	color: #58595b;\n"
"	line-height:1px;\n"
"}"));
        VehicleAndStation = new QWidget(DisconnectionScreen);
        VehicleAndStation->setObjectName(QStringLiteral("VehicleAndStation"));
        VehicleAndStation->setGeometry(QRect(385, 104, 637, 294));
        infoLabelWidget = new QWidget(DisconnectionScreen);
        infoLabelWidget->setObjectName(QStringLiteral("infoLabelWidget"));
        infoLabelWidget->setGeometry(QRect(483, 420, 425, 71));
        infoLabelWidget->setStyleSheet(QLatin1String("#energyLabel, #durationLabel, #batteryLabel, #energyValue, #durationValue, #batteryLevelValue {\n"
"    qproperty-alignment: AlignCenter;\n"
"    font-family: \"Muli SemiBold\";\n"
"    font-size: 20px;\n"
"    color: #58595b;\n"
"    line-height:1px;\n"
"}\n"
"\n"
"#energyLabel, #durationLabel, #batteryLabel {\n"
"    font-weight: bold;\n"
"}"));
        gridLayout = new QGridLayout(infoLabelWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        durationLabel = new QLabel(infoLabelWidget);
        durationLabel->setObjectName(QStringLiteral("durationLabel"));

        verticalLayout_2->addWidget(durationLabel);

        durationValue = new QLabel(infoLabelWidget);
        durationValue->setObjectName(QStringLiteral("durationValue"));

        verticalLayout_2->addWidget(durationValue);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);

        energyDurationSeparator = new QFrame(infoLabelWidget);
        energyDurationSeparator->setObjectName(QStringLiteral("energyDurationSeparator"));
        energyDurationSeparator->setFrameShadow(QFrame::Raised);
        energyDurationSeparator->setFrameShape(QFrame::VLine);

        gridLayout->addWidget(energyDurationSeparator, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        energyLabel = new QLabel(infoLabelWidget);
        energyLabel->setObjectName(QStringLiteral("energyLabel"));

        verticalLayout->addWidget(energyLabel);

        energyValue = new QLabel(infoLabelWidget);
        energyValue->setObjectName(QStringLiteral("energyValue"));

        verticalLayout->addWidget(energyValue);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        batteryLabel = new QLabel(infoLabelWidget);
        batteryLabel->setObjectName(QStringLiteral("batteryLabel"));

        verticalLayout_3->addWidget(batteryLabel);

        batteryLevelValue = new QLabel(infoLabelWidget);
        batteryLevelValue->setObjectName(QStringLiteral("batteryLevelValue"));

        verticalLayout_3->addWidget(batteryLevelValue);


        gridLayout->addLayout(verticalLayout_3, 0, 4, 1, 1);

        durationBatterySeparator = new QFrame(infoLabelWidget);
        durationBatterySeparator->setObjectName(QStringLiteral("durationBatterySeparator"));
        durationBatterySeparator->setFrameShadow(QFrame::Raised);
        durationBatterySeparator->setFrameShape(QFrame::VLine);

        gridLayout->addWidget(durationBatterySeparator, 0, 3, 1, 1);


        retranslateUi(DisconnectionScreen);

        QMetaObject::connectSlotsByName(DisconnectionScreen);
    } // setupUi

    void retranslateUi(QWidget *DisconnectionScreen)
    {
        DisconnectionScreen->setWindowTitle(QApplication::translate("DisconnectionScreen", "Form", Q_NULLPTR));
        disconnectionLabel->setText(QApplication::translate("DisconnectionScreen", "\305\236arj kablosunu ara\303\247tan \303\247\304\261kart\304\261p \n"
"cihazdaki yerine yerle\305\237tirin", Q_NULLPTR));
        durationLabel->setText(QApplication::translate("DisconnectionScreen", "Duration", Q_NULLPTR));
        durationValue->setText(QApplication::translate("DisconnectionScreen", "2 h", Q_NULLPTR));
        energyLabel->setText(QApplication::translate("DisconnectionScreen", "Enerji", Q_NULLPTR));
        energyValue->setText(QApplication::translate("DisconnectionScreen", "10 kWh", Q_NULLPTR));
        batteryLabel->setText(QApplication::translate("DisconnectionScreen", "Battery Level", Q_NULLPTR));
        batteryLevelValue->setText(QApplication::translate("DisconnectionScreen", "%70", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DisconnectionScreen: public Ui_DisconnectionScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISCONNECTIONSCREEN_H
