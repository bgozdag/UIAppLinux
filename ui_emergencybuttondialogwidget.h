/********************************************************************************
** Form generated from reading UI file 'emergencybuttondialogwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMERGENCYBUTTONDIALOGWIDGET_H
#define UI_EMERGENCYBUTTONDIALOGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmergencyButtonDialogWidget
{
public:
    QWidget *container;
    QVBoxLayout *errorAndWarningContainer_2;
    QWidget *icon;
    QLabel *header;
    QLabel *message;

    void setupUi(QWidget *EmergencyButtonDialogWidget)
    {
        if (EmergencyButtonDialogWidget->objectName().isEmpty())
            EmergencyButtonDialogWidget->setObjectName(QStringLiteral("EmergencyButtonDialogWidget"));
        EmergencyButtonDialogWidget->resize(750, 400);
        EmergencyButtonDialogWidget->setMinimumSize(QSize(0, 0));
        EmergencyButtonDialogWidget->setStyleSheet(QLatin1String("#icon {\n"
"	background-image: url(:/assets/images/caution_red.png);\n"
"	background-repeat : no-repeat;\n"
"	background-position:center;\n"
"}\n"
"\n"
"\n"
"#header {\n"
"	qproperty-alignment: AlignCenter;\n"
"	font-family: \"Muli Semibold\";\n"
"	font-size: 28px;\n"
"}\n"
"\n"
"#message {\n"
"	qproperty-alignment: AlignCenter;\n"
"	font-family: \"Muli Semibold\";\n"
"	font-size: 20px;\n"
"}"));
        container = new QWidget(EmergencyButtonDialogWidget);
        container->setObjectName(QStringLiteral("container"));
        container->setGeometry(QRect(0, 0, 750, 400));
        errorAndWarningContainer_2 = new QVBoxLayout(container);
        errorAndWarningContainer_2->setSpacing(0);
        errorAndWarningContainer_2->setObjectName(QStringLiteral("errorAndWarningContainer_2"));
        icon = new QWidget(container);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setMinimumSize(QSize(150, 180));

        errorAndWarningContainer_2->addWidget(icon);

        header = new QLabel(container);
        header->setObjectName(QStringLiteral("header"));

        errorAndWarningContainer_2->addWidget(header);

        message = new QLabel(container);
        message->setObjectName(QStringLiteral("message"));
        message->setAlignment(Qt::AlignCenter);
        message->setWordWrap(true);

        errorAndWarningContainer_2->addWidget(message);


        retranslateUi(EmergencyButtonDialogWidget);

        QMetaObject::connectSlotsByName(EmergencyButtonDialogWidget);
    } // setupUi

    void retranslateUi(QWidget *EmergencyButtonDialogWidget)
    {
        EmergencyButtonDialogWidget->setWindowTitle(QApplication::translate("EmergencyButtonDialogWidget", "Form", Q_NULLPTR));
        header->setText(QApplication::translate("EmergencyButtonDialogWidget", "TextLabel", Q_NULLPTR));
        message->setText(QApplication::translate("EmergencyButtonDialogWidget", "PLaceHolder", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EmergencyButtonDialogWidget: public Ui_EmergencyButtonDialogWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMERGENCYBUTTONDIALOGWIDGET_H
