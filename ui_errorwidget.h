/********************************************************************************
** Form generated from reading UI file 'errorwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORWIDGET_H
#define UI_ERRORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrorWidget
{
public:
    QWidget *errorContainer;
    QVBoxLayout *errorAndWarningContainer_2;
    QWidget *errorIcon;
    QLabel *errorText;

    void setupUi(QWidget *ErrorWidget)
    {
        if (ErrorWidget->objectName().isEmpty())
            ErrorWidget->setObjectName(QStringLiteral("ErrorWidget"));
        ErrorWidget->resize(750, 400);
        ErrorWidget->setStyleSheet(QLatin1String("#errorIcon {\n"
"	background-image: url(:/assets/images/caution.png);\n"
"	background-repeat : no-repeat;\n"
"	background-position:center;\n"
"}\n"
"\n"
"#errorText {\n"
"	qproperty-alignment: AlignCenter;\n"
"	font-family: \"Muli Semibold\";\n"
"	font-size: 24px;\n"
"}\n"
""));
        errorContainer = new QWidget(ErrorWidget);
        errorContainer->setObjectName(QStringLiteral("errorContainer"));
        errorContainer->setGeometry(QRect(0, 0, 750, 400));
        errorAndWarningContainer_2 = new QVBoxLayout(errorContainer);
        errorAndWarningContainer_2->setSpacing(0);
        errorAndWarningContainer_2->setObjectName(QStringLiteral("errorAndWarningContainer_2"));
        errorIcon = new QWidget(errorContainer);
        errorIcon->setObjectName(QStringLiteral("errorIcon"));
        errorIcon->setMinimumSize(QSize(242, 243));

        errorAndWarningContainer_2->addWidget(errorIcon);

        errorText = new QLabel(errorContainer);
        errorText->setObjectName(QStringLiteral("errorText"));
        errorText->setAlignment(Qt::AlignCenter);
        errorText->setWordWrap(true);

        errorAndWarningContainer_2->addWidget(errorText);


        retranslateUi(ErrorWidget);

        QMetaObject::connectSlotsByName(ErrorWidget);
    } // setupUi

    void retranslateUi(QWidget *ErrorWidget)
    {
        ErrorWidget->setWindowTitle(QApplication::translate("ErrorWidget", "Form", Q_NULLPTR));
        errorText->setText(QApplication::translate("ErrorWidget", "PLaceHolder", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ErrorWidget: public Ui_ErrorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORWIDGET_H
