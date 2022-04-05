/********************************************************************************
** Form generated from reading UI file 'evc05chargeritem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVC05CHARGERITEM_H
#define UI_EVC05CHARGERITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "progressbarwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Evc05ChargerItem
{
public:
    QFrame *chargerItemWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *connectorInfoWidget;
    QLabel *connectorId;
    QLabel *connectorPower;
    QLabel *connectorType;
    QWidget *powerEnergyProgressBarWidget;
    QWidget *powerAndEnergyWidget;
    QLabel *energyLabel;
    QLabel *powerLabel;
    QWidget *lineWidget;
    QLabel *energyValue;
    QLabel *powerValue;
    QLabel *progressLabel;
    ProgressBarWidget *progressBar;
    QWidget *socketIcon;
    QWidget *reservationOrFaultedWidget;
    QWidget *layoutWidget1;
    QHBoxLayout *iconLabelEmptyWidgetLayout;
    QWidget *emptyWidget;
    QWidget *chargerItemNotificationIconAndLabelWidget;
    QWidget *layoutWidget2;
    QHBoxLayout *chargerItemNotificationIconAndLabelLayout;
    QLabel *reservationOrFaultedLabel;
    QWidget *chargerItemNotificationIconWidget;

    void setupUi(QWidget *Evc05ChargerItem)
    {
        if (Evc05ChargerItem->objectName().isEmpty())
            Evc05ChargerItem->setObjectName(QStringLiteral("Evc05ChargerItem"));
        Evc05ChargerItem->resize(440, 230);
        chargerItemWidget = new QFrame(Evc05ChargerItem);
        chargerItemWidget->setObjectName(QStringLiteral("chargerItemWidget"));
        chargerItemWidget->setGeometry(QRect(-5, 0, 440, 230));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chargerItemWidget->sizePolicy().hasHeightForWidth());
        chargerItemWidget->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(chargerItemWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(33, 23, 371, 171));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        connectorInfoWidget = new QWidget(layoutWidget);
        connectorInfoWidget->setObjectName(QStringLiteral("connectorInfoWidget"));
        connectorInfoWidget->setMinimumSize(QSize(0, 0));
        connectorInfoWidget->setMaximumSize(QSize(107, 16777215));
        connectorId = new QLabel(connectorInfoWidget);
        connectorId->setObjectName(QStringLiteral("connectorId"));
        connectorId->setGeometry(QRect(1, 23, 105, 71));
        connectorId->setMinimumSize(QSize(0, 0));
        connectorId->setMaximumSize(QSize(16777215, 16777215));
        connectorId->setLayoutDirection(Qt::RightToLeft);
        connectorPower = new QLabel(connectorInfoWidget);
        connectorPower->setObjectName(QStringLiteral("connectorPower"));
        connectorPower->setGeometry(QRect(1, 130, 105, 51));
        connectorPower->setMaximumSize(QSize(16777215, 16777215));
        connectorType = new QLabel(connectorInfoWidget);
        connectorType->setObjectName(QStringLiteral("connectorType"));
        connectorType->setGeometry(QRect(1, 95, 105, 40));
        connectorType->setMinimumSize(QSize(0, 0));
        connectorType->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(connectorInfoWidget);

        powerEnergyProgressBarWidget = new QWidget(layoutWidget);
        powerEnergyProgressBarWidget->setObjectName(QStringLiteral("powerEnergyProgressBarWidget"));
        powerEnergyProgressBarWidget->setMinimumSize(QSize(0, 0));
        powerAndEnergyWidget = new QWidget(powerEnergyProgressBarWidget);
        powerAndEnergyWidget->setObjectName(QStringLiteral("powerAndEnergyWidget"));
        powerAndEnergyWidget->setGeometry(QRect(0, 90, 181, 61));
        powerAndEnergyWidget->setStyleSheet(QLatin1String("#lineWidget {\n"
"    background-image: url(:/assets/images/rectangle.png);\n"
"    background-repeat : no-repeat;\n"
"    background-position: center;\n"
"}"));
        energyLabel = new QLabel(powerAndEnergyWidget);
        energyLabel->setObjectName(QStringLiteral("energyLabel"));
        energyLabel->setGeometry(QRect(90, 10, 81, 23));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(energyLabel->sizePolicy().hasHeightForWidth());
        energyLabel->setSizePolicy(sizePolicy1);
        energyLabel->setMinimumSize(QSize(70, 23));
        energyLabel->setText(QStringLiteral("Energy"));
        energyLabel->setAlignment(Qt::AlignCenter);
        powerLabel = new QLabel(powerAndEnergyWidget);
        powerLabel->setObjectName(QStringLiteral("powerLabel"));
        powerLabel->setGeometry(QRect(0, 10, 81, 23));
        powerLabel->setMinimumSize(QSize(0, 23));
        powerLabel->setText(QStringLiteral("Power"));
        powerLabel->setAlignment(Qt::AlignCenter);
        lineWidget = new QWidget(powerAndEnergyWidget);
        lineWidget->setObjectName(QStringLiteral("lineWidget"));
        lineWidget->setGeometry(QRect(73, 10, 21, 46));
        lineWidget->setMinimumSize(QSize(0, 46));
        energyValue = new QLabel(powerAndEnergyWidget);
        energyValue->setObjectName(QStringLiteral("energyValue"));
        energyValue->setGeometry(QRect(90, 33, 81, 23));
        powerValue = new QLabel(powerAndEnergyWidget);
        powerValue->setObjectName(QStringLiteral("powerValue"));
        powerValue->setGeometry(QRect(0, 33, 81, 23));
        progressLabel = new QLabel(powerEnergyProgressBarWidget);
        progressLabel->setObjectName(QStringLiteral("progressLabel"));
        progressLabel->setGeometry(QRect(0, 60, 181, 31));
        progressLabel->setMinimumSize(QSize(0, 0));
        progressBar = new ProgressBarWidget(powerEnergyProgressBarWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 65, 160, 16));
        progressBar->setMinimumSize(QSize(160, 16));
        progressBar->setMaximumSize(QSize(160, 16));

        horizontalLayout->addWidget(powerEnergyProgressBarWidget);

        socketIcon = new QWidget(layoutWidget);
        socketIcon->setObjectName(QStringLiteral("socketIcon"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(socketIcon->sizePolicy().hasHeightForWidth());
        socketIcon->setSizePolicy(sizePolicy2);
        socketIcon->setMinimumSize(QSize(0, 0));
        socketIcon->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(socketIcon);

        reservationOrFaultedWidget = new QWidget(Evc05ChargerItem);
        reservationOrFaultedWidget->setObjectName(QStringLiteral("reservationOrFaultedWidget"));
        reservationOrFaultedWidget->setGeometry(QRect(19, 32, 391, 167));
        reservationOrFaultedWidget->setMinimumSize(QSize(0, 0));
        reservationOrFaultedWidget->setMaximumSize(QSize(16777215, 185));
        layoutWidget1 = new QWidget(reservationOrFaultedWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(1, 0, 391, 171));
        iconLabelEmptyWidgetLayout = new QHBoxLayout(layoutWidget1);
        iconLabelEmptyWidgetLayout->setObjectName(QStringLiteral("iconLabelEmptyWidgetLayout"));
        iconLabelEmptyWidgetLayout->setContentsMargins(0, 0, 0, 3);
        emptyWidget = new QWidget(layoutWidget1);
        emptyWidget->setObjectName(QStringLiteral("emptyWidget"));
        emptyWidget->setMinimumSize(QSize(0, 0));
        emptyWidget->setMaximumSize(QSize(125, 168));

        iconLabelEmptyWidgetLayout->addWidget(emptyWidget);

        chargerItemNotificationIconAndLabelWidget = new QWidget(layoutWidget1);
        chargerItemNotificationIconAndLabelWidget->setObjectName(QStringLiteral("chargerItemNotificationIconAndLabelWidget"));
        chargerItemNotificationIconAndLabelWidget->setMinimumSize(QSize(0, 0));
        chargerItemNotificationIconAndLabelWidget->setMaximumSize(QSize(16777215, 168));
        chargerItemNotificationIconAndLabelWidget->setStyleSheet(QStringLiteral(""));
        layoutWidget2 = new QWidget(chargerItemNotificationIconAndLabelWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 35, 221, 111));
        chargerItemNotificationIconAndLabelLayout = new QHBoxLayout(layoutWidget2);
        chargerItemNotificationIconAndLabelLayout->setObjectName(QStringLiteral("chargerItemNotificationIconAndLabelLayout"));
        chargerItemNotificationIconAndLabelLayout->setContentsMargins(0, 0, 0, 0);
        reservationOrFaultedLabel = new QLabel(layoutWidget2);
        reservationOrFaultedLabel->setObjectName(QStringLiteral("reservationOrFaultedLabel"));
        reservationOrFaultedLabel->setMinimumSize(QSize(133, 0));
        reservationOrFaultedLabel->setLayoutDirection(Qt::LeftToRight);
        reservationOrFaultedLabel->setAlignment(Qt::AlignCenter);

        chargerItemNotificationIconAndLabelLayout->addWidget(reservationOrFaultedLabel);

        chargerItemNotificationIconWidget = new QWidget(layoutWidget2);
        chargerItemNotificationIconWidget->setObjectName(QStringLiteral("chargerItemNotificationIconWidget"));
        chargerItemNotificationIconWidget->setMaximumSize(QSize(85, 16777215));

        chargerItemNotificationIconAndLabelLayout->addWidget(chargerItemNotificationIconWidget);


        iconLabelEmptyWidgetLayout->addWidget(chargerItemNotificationIconAndLabelWidget);


        retranslateUi(Evc05ChargerItem);

        QMetaObject::connectSlotsByName(Evc05ChargerItem);
    } // setupUi

    void retranslateUi(QWidget *Evc05ChargerItem)
    {
        Evc05ChargerItem->setWindowTitle(QApplication::translate("Evc05ChargerItem", "Form", Q_NULLPTR));
        connectorId->setText(QApplication::translate("Evc05ChargerItem", "1", Q_NULLPTR));
        connectorPower->setText(QApplication::translate("Evc05ChargerItem", "220 V", Q_NULLPTR));
        connectorType->setText(QApplication::translate("Evc05ChargerItem", "Schuko", Q_NULLPTR));
        energyValue->setText(QApplication::translate("Evc05ChargerItem", "TextLabel", Q_NULLPTR));
        powerValue->setText(QApplication::translate("Evc05ChargerItem", "TextLabel", Q_NULLPTR));
        progressLabel->setText(QApplication::translate("Evc05ChargerItem", "%5", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Evc05ChargerItem: public Ui_Evc05ChargerItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVC05CHARGERITEM_H
