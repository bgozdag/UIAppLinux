/********************************************************************************
** Form generated from reading UI file 'languagewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANGUAGEWIDGET_H
#define UI_LANGUAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LanguageWidget
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *languageContainer;
    QLabel *languageTitle;
    QLabel *softwareVersions;

    void setupUi(QWidget *LanguageWidget)
    {
        if (LanguageWidget->objectName().isEmpty())
            LanguageWidget->setObjectName(QStringLiteral("LanguageWidget"));
        LanguageWidget->resize(769, 478);
        LanguageWidget->setStyleSheet(QLatin1String("#languageTitle {\n"
"	qproperty-alignment: AlignCenter;\n"
"	font-size: 24px;\n"
"	color: #58595b;\n"
"}"));
        gridLayoutWidget = new QWidget(LanguageWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 40, 771, 461));
        languageContainer = new QGridLayout(gridLayoutWidget);
        languageContainer->setObjectName(QStringLiteral("languageContainer"));
        languageContainer->setContentsMargins(0, 0, 0, 0);
        languageTitle = new QLabel(LanguageWidget);
        languageTitle->setObjectName(QStringLiteral("languageTitle"));
        languageTitle->setGeometry(QRect(0, 0, 771, 31));
        languageTitle->setStyleSheet(QLatin1String("#language_message_dialog_title {\n"
"	qproperty-alignment: AlignCenter;\n"
"	font-size: 24px;\n"
"	color: #58595b;\n"
"}"));
        softwareVersions = new QLabel(LanguageWidget);
        softwareVersions->setObjectName(QStringLiteral("softwareVersions"));
        softwareVersions->setGeometry(QRect(18, 500, 731, 20));
        softwareVersions->setStyleSheet(QLatin1String("#softwareVersions {\n"
"	color: #50666666;\n"
"	font-family: Muli-SemiBold;\n"
"	font-size: 16px;\n"
"}"));

        retranslateUi(LanguageWidget);

        QMetaObject::connectSlotsByName(LanguageWidget);
    } // setupUi

    void retranslateUi(QWidget *LanguageWidget)
    {
        LanguageWidget->setWindowTitle(QApplication::translate("LanguageWidget", "Form", Q_NULLPTR));
        languageTitle->setText(QApplication::translate("LanguageWidget", "Choose your language", Q_NULLPTR));
        softwareVersions->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LanguageWidget: public Ui_LanguageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANGUAGEWIDGET_H
