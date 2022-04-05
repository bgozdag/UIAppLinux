/********************************************************************************
** Form generated from reading UI file 'authscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHSCREEN_H
#define UI_AUTHSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <clickableqwidget.h>

QT_BEGIN_NAMESPACE

class Ui_AuthScreen
{
public:
    ClickableQWidget *cancelChargingButton;
    QWidget *cancelChargingButtonImage;
    QLabel *cancelChargingButtonLabel;

    void setupUi(QWidget *AuthScreen)
    {
        if (AuthScreen->objectName().isEmpty())
            AuthScreen->setObjectName(QStringLiteral("AuthScreen"));
        AuthScreen->resize(1024, 770);
        cancelChargingButton = new ClickableQWidget(AuthScreen);
        cancelChargingButton->setObjectName(QStringLiteral("cancelChargingButton"));
        cancelChargingButton->setGeometry(QRect(450, 585, 470, 80));
        cancelChargingButtonImage = new QWidget(cancelChargingButton);
        cancelChargingButtonImage->setObjectName(QStringLiteral("cancelChargingButtonImage"));
        cancelChargingButtonImage->setGeometry(QRect(0, 0, 470, 80));
        cancelChargingButtonLabel = new QLabel(cancelChargingButton);
        cancelChargingButtonLabel->setObjectName(QStringLiteral("cancelChargingButtonLabel"));
        cancelChargingButtonLabel->setGeometry(QRect(0, 0, 470, 80));

        retranslateUi(AuthScreen);

        QMetaObject::connectSlotsByName(AuthScreen);
    } // setupUi

    void retranslateUi(QWidget *AuthScreen)
    {
        AuthScreen->setWindowTitle(QApplication::translate("AuthScreen", "Form", Q_NULLPTR));
        cancelChargingButtonLabel->setText(QApplication::translate("AuthScreen", "Cancel Charging Process", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AuthScreen: public Ui_AuthScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHSCREEN_H
