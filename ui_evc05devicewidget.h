/********************************************************************************
** Form generated from reading UI file 'evc05devicewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVC05DEVICEWIDGET_H
#define UI_EVC05DEVICEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Evc05DeviceWidget
{
public:
    QWidget *evc05DeviceImage;

    void setupUi(QWidget *Evc05DeviceWidget)
    {
        if (Evc05DeviceWidget->objectName().isEmpty())
            Evc05DeviceWidget->setObjectName(QStringLiteral("Evc05DeviceWidget"));
        Evc05DeviceWidget->resize(181, 451);
        Evc05DeviceWidget->setStyleSheet(QLatin1String("#evc05DeviceImage {\n"
"    border-image: url(:/assets/images/evc-05-device-1.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}\n"
""));
        evc05DeviceImage = new QWidget(Evc05DeviceWidget);
        evc05DeviceImage->setObjectName(QStringLiteral("evc05DeviceImage"));
        evc05DeviceImage->setGeometry(QRect(0, 0, 181, 451));

        retranslateUi(Evc05DeviceWidget);

        QMetaObject::connectSlotsByName(Evc05DeviceWidget);
    } // setupUi

    void retranslateUi(QWidget *Evc05DeviceWidget)
    {
        Evc05DeviceWidget->setWindowTitle(QApplication::translate("Evc05DeviceWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Evc05DeviceWidget: public Ui_Evc05DeviceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVC05DEVICEWIDGET_H
