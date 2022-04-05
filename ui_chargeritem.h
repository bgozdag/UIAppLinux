/********************************************************************************
** Form generated from reading UI file 'chargeritem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARGERITEM_H
#define UI_CHARGERITEM_H

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

class Ui_chargeritem
{
public:
    QFrame *chargerItemWidget;
    QLabel *connectorId;
    QLabel *connectorType;
    QLabel *connectorPower;
    QFrame *plugIcon;
    ProgressBarWidget *progressBar;
    QLabel *progressLabel;
    QWidget *chargerItemHoverWidget;
    QWidget *energyAndPowerWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *powerLabel;
    QFrame *socketIcon;
    QLabel *energyLabel;
    QWidget *reservationOrFaultedWidget;
    QWidget *reservationOrFaultedGrayBackgroundWidget;
    QWidget *chargerItemNotificationIconAndLabelWidget;
    QWidget *chargerItemNotificationIconWidget;
    QLabel *reservationOrFaultedLabel;

    void setupUi(QFrame *chargeritem)
    {
        if (chargeritem->objectName().isEmpty())
            chargeritem->setObjectName(QStringLiteral("chargeritem"));
        chargeritem->resize(280, 550);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chargeritem->sizePolicy().hasHeightForWidth());
        chargeritem->setSizePolicy(sizePolicy);
        chargeritem->setMinimumSize(QSize(280, 550));
        chargeritem->setMaximumSize(QSize(280, 550));
        chargeritem->setFrameShape(QFrame::NoFrame);
        chargeritem->setFrameShadow(QFrame::Plain);
        chargerItemWidget = new QFrame(chargeritem);
        chargerItemWidget->setObjectName(QStringLiteral("chargerItemWidget"));
        chargerItemWidget->setGeometry(QRect(0, 0, 280, 550));
        sizePolicy.setHeightForWidth(chargerItemWidget->sizePolicy().hasHeightForWidth());
        chargerItemWidget->setSizePolicy(sizePolicy);
        chargerItemWidget->setMinimumSize(QSize(0, 0));
        chargerItemWidget->setStyleSheet(QStringLiteral(""));
        connectorId = new QLabel(chargerItemWidget);
        connectorId->setObjectName(QStringLiteral("connectorId"));
        connectorId->setGeometry(QRect(0, 35, 280, 82));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(connectorId->sizePolicy().hasHeightForWidth());
        connectorId->setSizePolicy(sizePolicy1);
        connectorId->setMinimumSize(QSize(0, 0));
        connectorId->setStyleSheet(QStringLiteral(""));
        connectorType = new QLabel(chargerItemWidget);
        connectorType->setObjectName(QStringLiteral("connectorType"));
        connectorType->setGeometry(QRect(0, 97, 280, 65));
        sizePolicy1.setHeightForWidth(connectorType->sizePolicy().hasHeightForWidth());
        connectorType->setSizePolicy(sizePolicy1);
        connectorType->setMinimumSize(QSize(0, 0));
        QFont font;
        connectorType->setFont(font);
        connectorType->setAutoFillBackground(false);
        connectorType->setIndent(0);
        connectorPower = new QLabel(chargerItemWidget);
        connectorPower->setObjectName(QStringLiteral("connectorPower"));
        connectorPower->setGeometry(QRect(0, 160, 280, 24));
        sizePolicy1.setHeightForWidth(connectorPower->sizePolicy().hasHeightForWidth());
        connectorPower->setSizePolicy(sizePolicy1);
        connectorPower->setMinimumSize(QSize(0, 0));
        connectorPower->setStyleSheet(QStringLiteral(""));
        plugIcon = new QFrame(chargerItemWidget);
        plugIcon->setObjectName(QStringLiteral("plugIcon"));
        plugIcon->setGeometry(QRect(0, 213, 280, 116));
        progressBar = new ProgressBarWidget(chargerItemWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(65, 385, 151, 15));
        progressLabel = new QLabel(chargerItemWidget);
        progressLabel->setObjectName(QStringLiteral("progressLabel"));
        progressLabel->setGeometry(QRect(0, 414, 280, 29));
        chargerItemHoverWidget = new QWidget(chargerItemWidget);
        chargerItemHoverWidget->setObjectName(QStringLiteral("chargerItemHoverWidget"));
        chargerItemHoverWidget->setGeometry(QRect(0, 0, 280, 550));
        chargerItemHoverWidget->setStyleSheet(QLatin1String("#hoverWidget {\n"
"    background-image: url(:/assets/images/ccs_interface_background_selected.png);\n"
"    background-repeat : no-repeat;\n"
"    background-position : center;\n"
"}"));
        energyAndPowerWidget = new QWidget(chargerItemWidget);
        energyAndPowerWidget->setObjectName(QStringLiteral("energyAndPowerWidget"));
        energyAndPowerWidget->setGeometry(QRect(47, 447, 189, 55));
        layoutWidget = new QWidget(energyAndPowerWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 188, 52));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        powerLabel = new QLabel(layoutWidget);
        powerLabel->setObjectName(QStringLiteral("powerLabel"));
        powerLabel->setMinimumSize(QSize(57, 46));
        powerLabel->setMaximumSize(QSize(16777215, 46));
        powerLabel->setStyleSheet(QStringLiteral(""));
        powerLabel->setText(QLatin1String("Power\n"
"68 kW"));
        powerLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(powerLabel);

        socketIcon = new QFrame(layoutWidget);
        socketIcon->setObjectName(QStringLiteral("socketIcon"));
        socketIcon->setMinimumSize(QSize(50, 50));
        socketIcon->setMaximumSize(QSize(55, 45));

        horizontalLayout->addWidget(socketIcon);

        energyLabel = new QLabel(layoutWidget);
        energyLabel->setObjectName(QStringLiteral("energyLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(energyLabel->sizePolicy().hasHeightForWidth());
        energyLabel->setSizePolicy(sizePolicy2);
        energyLabel->setMinimumSize(QSize(67, 0));
        energyLabel->setText(QLatin1String("Energy\n"
"10 kWh"));
        energyLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(energyLabel);

        chargerItemHoverWidget->raise();
        connectorPower->raise();
        plugIcon->raise();
        connectorType->raise();
        connectorId->raise();
        progressBar->raise();
        progressLabel->raise();
        energyAndPowerWidget->raise();
        reservationOrFaultedWidget = new QWidget(chargeritem);
        reservationOrFaultedWidget->setObjectName(QStringLiteral("reservationOrFaultedWidget"));
        reservationOrFaultedWidget->setGeometry(QRect(17, 35, 230, 510));
        reservationOrFaultedGrayBackgroundWidget = new QWidget(reservationOrFaultedWidget);
        reservationOrFaultedGrayBackgroundWidget->setObjectName(QStringLiteral("reservationOrFaultedGrayBackgroundWidget"));
        reservationOrFaultedGrayBackgroundWidget->setGeometry(QRect(18, 1, 210, 481));
        chargerItemNotificationIconAndLabelWidget = new QWidget(reservationOrFaultedWidget);
        chargerItemNotificationIconAndLabelWidget->setObjectName(QStringLiteral("chargerItemNotificationIconAndLabelWidget"));
        chargerItemNotificationIconAndLabelWidget->setGeometry(QRect(8, 295, 230, 200));
        chargerItemNotificationIconWidget = new QWidget(chargerItemNotificationIconAndLabelWidget);
        chargerItemNotificationIconWidget->setObjectName(QStringLiteral("chargerItemNotificationIconWidget"));
        chargerItemNotificationIconWidget->setGeometry(QRect(0, 14, 230, 80));
        reservationOrFaultedLabel = new QLabel(chargerItemNotificationIconAndLabelWidget);
        reservationOrFaultedLabel->setObjectName(QStringLiteral("reservationOrFaultedLabel"));
        reservationOrFaultedLabel->setGeometry(QRect(0, 100, 230, 60));
        reservationOrFaultedLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(chargeritem);

        QMetaObject::connectSlotsByName(chargeritem);
    } // setupUi

    void retranslateUi(QFrame *chargeritem)
    {
        chargeritem->setWindowTitle(QApplication::translate("chargeritem", "Form", Q_NULLPTR));
        connectorId->setText(QApplication::translate("chargeritem", "1", Q_NULLPTR));
        connectorType->setText(QApplication::translate("chargeritem", "CCS", Q_NULLPTR));
        connectorPower->setText(QApplication::translate("chargeritem", "120 kW", Q_NULLPTR));
        progressLabel->setText(QApplication::translate("chargeritem", "5%", Q_NULLPTR));
        reservationOrFaultedLabel->setText(QApplication::translate("chargeritem", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class chargeritem: public Ui_chargeritem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARGERITEM_H
