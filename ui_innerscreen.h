/********************************************************************************
** Form generated from reading UI file 'innerscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INNERSCREEN_H
#define UI_INNERSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InnerScreen
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *innerScreenBackground;
    QLabel *connectorId;
    QLabel *type;
    QLabel *power;
    QWidget *socketObject;
    QWidget *topNotification;
    QVBoxLayout *verticalLayout;
    QLabel *topNotificationHeader;
    QLabel *topNotificationDetails;

    void setupUi(QWidget *InnerScreen)
    {
        if (InnerScreen->objectName().isEmpty())
            InnerScreen->setObjectName(QStringLiteral("InnerScreen"));
        InnerScreen->resize(1024, 768);
        InnerScreen->setMinimumSize(QSize(1024, 768));
        InnerScreen->setAutoFillBackground(true);
        InnerScreen->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(InnerScreen);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        innerScreenBackground = new QWidget(InnerScreen);
        innerScreenBackground->setObjectName(QStringLiteral("innerScreenBackground"));
        innerScreenBackground->setMinimumSize(QSize(1024, 768));
        connectorId = new QLabel(innerScreenBackground);
        connectorId->setObjectName(QStringLiteral("connectorId"));
        connectorId->setGeometry(QRect(-60, 215, 301, 421));
        type = new QLabel(innerScreenBackground);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(80, 440, 301, 100));
        type->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        power = new QLabel(innerScreenBackground);
        power->setObjectName(QStringLiteral("power"));
        power->setGeometry(QRect(80, 535, 301, 61));
        power->setMinimumSize(QSize(0, 0));
        power->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        socketObject = new QWidget(innerScreenBackground);
        socketObject->setObjectName(QStringLiteral("socketObject"));
        socketObject->setGeometry(QRect(670, 10, 361, 768));
        topNotification = new QWidget(innerScreenBackground);
        topNotification->setObjectName(QStringLiteral("topNotification"));
        topNotification->setGeometry(QRect(0, 0, 1024, 90));
        verticalLayout = new QVBoxLayout(topNotification);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topNotificationHeader = new QLabel(topNotification);
        topNotificationHeader->setObjectName(QStringLiteral("topNotificationHeader"));
        topNotificationHeader->setLineWidth(1);
        topNotificationHeader->setScaledContents(false);
        topNotificationHeader->setMargin(0);
        topNotificationHeader->setIndent(-1);

        verticalLayout->addWidget(topNotificationHeader);

        topNotificationDetails = new QLabel(topNotification);
        topNotificationDetails->setObjectName(QStringLiteral("topNotificationDetails"));
        topNotificationDetails->setMargin(0);

        verticalLayout->addWidget(topNotificationDetails);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        horizontalLayout->addWidget(innerScreenBackground);


        retranslateUi(InnerScreen);

        QMetaObject::connectSlotsByName(InnerScreen);
    } // setupUi

    void retranslateUi(QWidget *InnerScreen)
    {
        InnerScreen->setWindowTitle(QApplication::translate("InnerScreen", "Form", Q_NULLPTR));
        connectorId->setText(QApplication::translate("InnerScreen", "4", Q_NULLPTR));
        type->setText(QApplication::translate("InnerScreen", "CCS", Q_NULLPTR));
        power->setText(QApplication::translate("InnerScreen", "100 kW", Q_NULLPTR));
        topNotificationHeader->setText(QApplication::translate("InnerScreen", "Top Notification Header", Q_NULLPTR));
        topNotificationDetails->setText(QApplication::translate("InnerScreen", "Top Notification Details", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InnerScreen: public Ui_InnerScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INNERSCREEN_H
