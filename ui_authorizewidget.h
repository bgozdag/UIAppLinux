/********************************************************************************
** Form generated from reading UI file 'authorizewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZEWIDGET_H
#define UI_AUTHORIZEWIDGET_H

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

class Ui_AuthorizeWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *rfidContainer;
    QVBoxLayout *verticalLayout;
    QWidget *rfidIcon;
    QLabel *rfidText;
    QLabel *orText;
    QWidget *qrContainer;
    QVBoxLayout *verticalLayout_2;
    QLabel *qrIcon;
    QLabel *qrText;

    void setupUi(QWidget *AuthorizeWidget)
    {
        if (AuthorizeWidget->objectName().isEmpty())
            AuthorizeWidget->setObjectName(QStringLiteral("AuthorizeWidget"));
        AuthorizeWidget->resize(625, 314);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AuthorizeWidget->sizePolicy().hasHeightForWidth());
        AuthorizeWidget->setSizePolicy(sizePolicy);
        AuthorizeWidget->setStyleSheet(QLatin1String("#qrIcon {\n"
"	background-image:url(:/assets/images/qr.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position:center;\n"
"}\n"
"\n"
"#rfidIcon {\n"
"	background-image: url(:/assets/images/handcard.png);\n"
"	background-repeat:no-repeat;\n"
"	background-position:center;\n"
"}\n"
"\n"
"#rfidText, #qrText {\n"
"	qproperty-alignment: AlignCenter;\n"
"	font-family: \"Muli Semibold\";\n"
"	font-size: 24px;\n"
"}\n"
"\n"
"#qrText, #rfidText {\n"
"	qproperty-alignment: 'AlignTop | AlignHCenter';\n"
"}\n"
"\n"
"#orText {\n"
"	font-family: \"Muli Semibold\";\n"
"	font-size: 36px;\n"
"	qproperty-alignment: AlignTop;\n"
"	margin-top: 100px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(AuthorizeWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        rfidContainer = new QWidget(AuthorizeWidget);
        rfidContainer->setObjectName(QStringLiteral("rfidContainer"));
        verticalLayout = new QVBoxLayout(rfidContainer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        rfidIcon = new QWidget(rfidContainer);
        rfidIcon->setObjectName(QStringLiteral("rfidIcon"));
        rfidIcon->setMinimumSize(QSize(242, 243));

        verticalLayout->addWidget(rfidIcon);

        rfidText = new QLabel(rfidContainer);
        rfidText->setObjectName(QStringLiteral("rfidText"));
        rfidText->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(rfidText);


        horizontalLayout->addWidget(rfidContainer);

        orText = new QLabel(AuthorizeWidget);
        orText->setObjectName(QStringLiteral("orText"));
        orText->setAlignment(Qt::AlignTop);

        horizontalLayout->addWidget(orText);

        qrContainer = new QWidget(AuthorizeWidget);
        qrContainer->setObjectName(QStringLiteral("qrContainer"));
        verticalLayout_2 = new QVBoxLayout(qrContainer);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        qrIcon = new QLabel(qrContainer);
        qrIcon->setObjectName(QStringLiteral("qrIcon"));
        qrIcon->setMinimumSize(QSize(242, 243));

        verticalLayout_2->addWidget(qrIcon);

        qrText = new QLabel(qrContainer);
        qrText->setObjectName(QStringLiteral("qrText"));
        qrText->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_2->addWidget(qrText);


        horizontalLayout->addWidget(qrContainer);


        retranslateUi(AuthorizeWidget);

        QMetaObject::connectSlotsByName(AuthorizeWidget);
    } // setupUi

    void retranslateUi(QWidget *AuthorizeWidget)
    {
        AuthorizeWidget->setWindowTitle(QApplication::translate("AuthorizeWidget", "Form", Q_NULLPTR));
        rfidText->setText(QApplication::translate("AuthorizeWidget", "Placeholder", Q_NULLPTR));
        orText->setText(QApplication::translate("AuthorizeWidget", "OR", Q_NULLPTR));
        qrText->setText(QApplication::translate("AuthorizeWidget", "Placeholder", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AuthorizeWidget: public Ui_AuthorizeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZEWIDGET_H
