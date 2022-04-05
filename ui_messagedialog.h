/********************************************************************************
** Form generated from reading UI file 'messagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEDIALOG_H
#define UI_MESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickableqwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MessageDialog
{
public:
    QWidget *messageDialogWidget;
    ClickableQWidget *close_button_container;
    QVBoxLayout *verticalLayout;
    QWidget *close_button;
    QWidget *gridLayoutWidget;
    QGridLayout *messageDialogContainer;

    void setupUi(QFrame *MessageDialog)
    {
        if (MessageDialog->objectName().isEmpty())
            MessageDialog->setObjectName(QStringLiteral("MessageDialog"));
        MessageDialog->resize(1024, 768);
        MessageDialog->setMinimumSize(QSize(1024, 768));
        MessageDialog->setMaximumSize(QSize(1024, 768));
        MessageDialog->setStyleSheet(QLatin1String("#MessageDialog {\n"
"	background-color : rgba(0,0,0,50%);\n"
"}\n"
"\n"
"#messageDialogWidget {\n"
"	background-color : white;\n"
"	border : 1px solid white;	\n"
"	border-radius : 6%;\n"
"}"));
        messageDialogWidget = new QWidget(MessageDialog);
        messageDialogWidget->setObjectName(QStringLiteral("messageDialogWidget"));
        messageDialogWidget->setGeometry(QRect(129, 135, 769, 499));
        messageDialogWidget->setMinimumSize(QSize(769, 499));
        messageDialogWidget->setMaximumSize(QSize(1024, 768));
        close_button_container = new ClickableQWidget(messageDialogWidget);
        close_button_container->setObjectName(QStringLiteral("close_button_container"));
        close_button_container->setGeometry(QRect(700, 0, 71, 71));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(close_button_container->sizePolicy().hasHeightForWidth());
        close_button_container->setSizePolicy(sizePolicy);
        close_button_container->setMinimumSize(QSize(50, 50));
        verticalLayout = new QVBoxLayout(close_button_container);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        close_button = new QWidget(close_button_container);
        close_button->setObjectName(QStringLiteral("close_button"));
        close_button->setMinimumSize(QSize(50, 50));
        close_button->setMaximumSize(QSize(16777215, 16777215));
        close_button->setStyleSheet(QLatin1String("#close_button {\n"
"	background-image: url(:/assets/images/cancel_2.png);\n"
"	background-repeat: no-repeat;\n"
"	background-position: center;\n"
"}"));

        verticalLayout->addWidget(close_button);

        gridLayoutWidget = new QWidget(messageDialogWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, 70, 771, 431));
        messageDialogContainer = new QGridLayout(gridLayoutWidget);
        messageDialogContainer->setObjectName(QStringLiteral("messageDialogContainer"));
        messageDialogContainer->setContentsMargins(0, 0, 0, 0);

        retranslateUi(MessageDialog);

        QMetaObject::connectSlotsByName(MessageDialog);
    } // setupUi

    void retranslateUi(QFrame *MessageDialog)
    {
        MessageDialog->setWindowTitle(QApplication::translate("MessageDialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MessageDialog: public Ui_MessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEDIALOG_H
