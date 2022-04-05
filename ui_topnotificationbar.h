/********************************************************************************
** Form generated from reading UI file 'topnotificationbar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPNOTIFICATIONBAR_H
#define UI_TOPNOTIFICATIONBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TopNotificationBar
{
public:
    QWidget *topNotification;
    QVBoxLayout *verticalLayout;
    QLabel *topNotificationHeader;
    QLabel *topNotificationDetails;

    void setupUi(QWidget *TopNotificationBar)
    {
        if (TopNotificationBar->objectName().isEmpty())
            TopNotificationBar->setObjectName(QStringLiteral("TopNotificationBar"));
        TopNotificationBar->resize(1024, 90);
        topNotification = new QWidget(TopNotificationBar);
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

        retranslateUi(TopNotificationBar);

        QMetaObject::connectSlotsByName(TopNotificationBar);
    } // setupUi

    void retranslateUi(QWidget *TopNotificationBar)
    {
        TopNotificationBar->setWindowTitle(QApplication::translate("TopNotificationBar", "Form", Q_NULLPTR));
        topNotificationHeader->setText(QApplication::translate("TopNotificationBar", "Top Notification Header", Q_NULLPTR));
        topNotificationDetails->setText(QApplication::translate("TopNotificationBar", "Top Notification Details", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TopNotificationBar: public Ui_TopNotificationBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPNOTIFICATIONBAR_H
