/********************************************************************************
** Form generated from reading UI file 'spinnermessagewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPINNERMESSAGEWIDGET_H
#define UI_SPINNERMESSAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "spinnerwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SpinnerMessageWidget
{
public:
    QWidget *spinnerMessageContainer;
    QVBoxLayout *spinnerMessageContainer_2;
    QHBoxLayout *spinnerContainer;
    QSpacerItem *horizontalSpacerLeft;
    SpinnerWidget *progressSpinnerWidget;
    QSpacerItem *horizontalSpacerRight;
    QLabel *informationText;

    void setupUi(QWidget *SpinnerMessageWidget)
    {
        if (SpinnerMessageWidget->objectName().isEmpty())
            SpinnerMessageWidget->setObjectName(QStringLiteral("SpinnerMessageWidget"));
        SpinnerMessageWidget->resize(750, 400);
        SpinnerMessageWidget->setMinimumSize(QSize(750, 400));
        SpinnerMessageWidget->setMaximumSize(QSize(750, 400));
        SpinnerMessageWidget->setStyleSheet(QLatin1String("#progressSpinnerWidget {\n"
"    background-image: url(:/assets/images/spinner.png);\n"
"    background-repeat : no-repeat;\n"
"    background-position:center bottom;\n"
"}\n"
"\n"
"#informationText {\n"
"	qproperty-alignment: AlignCenter;\n"
"	font-family: \"Muli\";\n"
"	font-weight:\"bold\";\n"
"	font-size: 24px;\n"
"}\n"
""));
        spinnerMessageContainer = new QWidget(SpinnerMessageWidget);
        spinnerMessageContainer->setObjectName(QStringLiteral("spinnerMessageContainer"));
        spinnerMessageContainer->setGeometry(QRect(0, 10, 751, 391));
        spinnerMessageContainer_2 = new QVBoxLayout(spinnerMessageContainer);
        spinnerMessageContainer_2->setSpacing(0);
        spinnerMessageContainer_2->setObjectName(QStringLiteral("spinnerMessageContainer_2"));
        spinnerMessageContainer_2->setContentsMargins(9, -1, -1, -1);
        spinnerContainer = new QHBoxLayout();
        spinnerContainer->setSpacing(0);
        spinnerContainer->setObjectName(QStringLiteral("spinnerContainer"));
        horizontalSpacerLeft = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        spinnerContainer->addItem(horizontalSpacerLeft);

        progressSpinnerWidget = new SpinnerWidget(spinnerMessageContainer);
        progressSpinnerWidget->setObjectName(QStringLiteral("progressSpinnerWidget"));

        spinnerContainer->addWidget(progressSpinnerWidget);

        horizontalSpacerRight = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        spinnerContainer->addItem(horizontalSpacerRight);


        spinnerMessageContainer_2->addLayout(spinnerContainer);

        informationText = new QLabel(spinnerMessageContainer);
        informationText->setObjectName(QStringLiteral("informationText"));
        informationText->setAlignment(Qt::AlignCenter);
        informationText->setWordWrap(true);

        spinnerMessageContainer_2->addWidget(informationText);


        retranslateUi(SpinnerMessageWidget);

        QMetaObject::connectSlotsByName(SpinnerMessageWidget);
    } // setupUi

    void retranslateUi(QWidget *SpinnerMessageWidget)
    {
        SpinnerMessageWidget->setWindowTitle(QApplication::translate("SpinnerMessageWidget", "Form", Q_NULLPTR));
        informationText->setText(QApplication::translate("SpinnerMessageWidget", "PLaceHolder", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SpinnerMessageWidget: public Ui_SpinnerMessageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPINNERMESSAGEWIDGET_H
