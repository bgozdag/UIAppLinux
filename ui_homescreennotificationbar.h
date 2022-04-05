/********************************************************************************
** Form generated from reading UI file 'homescreennotificationbar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMESCREENNOTIFICATIONBAR_H
#define UI_HOMESCREENNOTIFICATIONBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeScreenNotificationBar
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *homeScreenNotificationLabel;

    void setupUi(QWidget *HomeScreenNotificationBar)
    {
        if (HomeScreenNotificationBar->objectName().isEmpty())
            HomeScreenNotificationBar->setObjectName(QStringLiteral("HomeScreenNotificationBar"));
        HomeScreenNotificationBar->resize(1024, 85);
        HomeScreenNotificationBar->setMinimumSize(QSize(1024, 85));
        HomeScreenNotificationBar->setMaximumSize(QSize(1280, 85));
        HomeScreenNotificationBar->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(HomeScreenNotificationBar);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        homeScreenNotificationLabel = new QLabel(HomeScreenNotificationBar);
        homeScreenNotificationLabel->setObjectName(QStringLiteral("homeScreenNotificationLabel"));
        homeScreenNotificationLabel->setStyleSheet(QLatin1String("#homeScreenNotificationLabel {\n"
"	qproperty-alignment: AlignCenter;\n"
"	font-size: 24px;\n"
"	color: gray;\n"
"}"));

        verticalLayout->addWidget(homeScreenNotificationLabel);


        retranslateUi(HomeScreenNotificationBar);

        QMetaObject::connectSlotsByName(HomeScreenNotificationBar);
    } // setupUi

    void retranslateUi(QWidget *HomeScreenNotificationBar)
    {
        HomeScreenNotificationBar->setWindowTitle(QApplication::translate("HomeScreenNotificationBar", "Form", Q_NULLPTR));
        homeScreenNotificationLabel->setText(QApplication::translate("HomeScreenNotificationBar", "Choose socket type or connect charging cable to your car", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HomeScreenNotificationBar: public Ui_HomeScreenNotificationBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMESCREENNOTIFICATIONBAR_H
