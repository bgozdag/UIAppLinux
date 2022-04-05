/********************************************************************************
** Form generated from reading UI file 'connectionscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONSCREEN_H
#define UI_CONNECTIONSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <clickableqwidget.h>

QT_BEGIN_NAMESPACE

class Ui_ConnectionScreen
{
public:
    QLabel *connectionLabel;
    QWidget *carAndStationImage;
    QWidget *schukoCableConnectionWidget;
    QWidget *schukoCableConnection1Widget;
    QLabel *schukoCableConnection1Label;
    QWidget *schukoCableConnection3Widget;
    QLabel *schukoCableConnection3Label;
    QWidget *schukoCableConnection2Widget;
    QLabel *schukoCableConnection2Label;
    ClickableQWidget *continueChargingButton;
    QWidget *continueChargingButtonImage;
    QLabel *continueChargingButtonLabel;

    void setupUi(QWidget *ConnectionScreen)
    {
        if (ConnectionScreen->objectName().isEmpty())
            ConnectionScreen->setObjectName(QStringLiteral("ConnectionScreen"));
        ConnectionScreen->resize(1024, 768);
        connectionLabel = new QLabel(ConnectionScreen);
        connectionLabel->setObjectName(QStringLiteral("connectionLabel"));
        connectionLabel->setGeometry(QRect(390, 445, 631, 105));
        connectionLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        carAndStationImage = new QWidget(ConnectionScreen);
        carAndStationImage->setObjectName(QStringLiteral("carAndStationImage"));
        carAndStationImage->setGeometry(QRect(340, 80, 681, 319));
        carAndStationImage->setStyleSheet(QStringLiteral(""));
        schukoCableConnectionWidget = new QWidget(ConnectionScreen);
        schukoCableConnectionWidget->setObjectName(QStringLiteral("schukoCableConnectionWidget"));
        schukoCableConnectionWidget->setGeometry(QRect(435, 85, 589, 620));
        schukoCableConnection1Widget = new QWidget(schukoCableConnectionWidget);
        schukoCableConnection1Widget->setObjectName(QStringLiteral("schukoCableConnection1Widget"));
        schukoCableConnection1Widget->setGeometry(QRect(0, 0, 589, 200));
        schukoCableConnection1Label = new QLabel(schukoCableConnection1Widget);
        schukoCableConnection1Label->setObjectName(QStringLiteral("schukoCableConnection1Label"));
        schukoCableConnection1Label->setGeometry(QRect(230, 0, 325, 200));
        schukoCableConnection3Widget = new QWidget(schukoCableConnectionWidget);
        schukoCableConnection3Widget->setObjectName(QStringLiteral("schukoCableConnection3Widget"));
        schukoCableConnection3Widget->setGeometry(QRect(0, 400, 589, 200));
        schukoCableConnection3Label = new QLabel(schukoCableConnection3Widget);
        schukoCableConnection3Label->setObjectName(QStringLiteral("schukoCableConnection3Label"));
        schukoCableConnection3Label->setGeometry(QRect(230, 0, 325, 200));
        schukoCableConnection2Widget = new QWidget(schukoCableConnectionWidget);
        schukoCableConnection2Widget->setObjectName(QStringLiteral("schukoCableConnection2Widget"));
        schukoCableConnection2Widget->setGeometry(QRect(0, 200, 589, 200));
        schukoCableConnection2Label = new QLabel(schukoCableConnection2Widget);
        schukoCableConnection2Label->setObjectName(QStringLiteral("schukoCableConnection2Label"));
        schukoCableConnection2Label->setGeometry(QRect(230, 0, 325, 200));
        continueChargingButton = new ClickableQWidget(ConnectionScreen);
        continueChargingButton->setObjectName(QStringLiteral("continueChargingButton"));
        continueChargingButton->setGeometry(QRect(530, 575, 355, 85));
        continueChargingButtonImage = new QWidget(continueChargingButton);
        continueChargingButtonImage->setObjectName(QStringLiteral("continueChargingButtonImage"));
        continueChargingButtonImage->setGeometry(QRect(0, 0, 355, 85));
        continueChargingButtonLabel = new QLabel(continueChargingButton);
        continueChargingButtonLabel->setObjectName(QStringLiteral("continueChargingButtonLabel"));
        continueChargingButtonLabel->setGeometry(QRect(0, 0, 355, 85));

        retranslateUi(ConnectionScreen);

        QMetaObject::connectSlotsByName(ConnectionScreen);
    } // setupUi

    void retranslateUi(QWidget *ConnectionScreen)
    {
        ConnectionScreen->setWindowTitle(QApplication::translate("ConnectionScreen", "Form", Q_NULLPTR));
        connectionLabel->setText(QApplication::translate("ConnectionScreen", "Connect the CCS \n"
"charging cable to your car", Q_NULLPTR));
        schukoCableConnection1Label->setText(QApplication::translate("ConnectionScreen", "TextLabel", Q_NULLPTR));
        schukoCableConnection3Label->setText(QString());
        schukoCableConnection2Label->setText(QString());
        continueChargingButtonLabel->setText(QApplication::translate("ConnectionScreen", "Continue", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConnectionScreen: public Ui_ConnectionScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONSCREEN_H
