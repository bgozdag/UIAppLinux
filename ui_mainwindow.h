/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <clickableqwidget.h>
#include <topnotificationbar.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *main_background;
    QWidget *footer;
    QWidget *bottom_buttons;
    QHBoxLayout *horizontalLayout;
    ClickableQWidget *home_button_container;
    QWidget *home_button;
    QLabel *home_button_label;
    QWidget *home_button_clicked;
    ClickableQWidget *cancel_button_container;
    QWidget *cancel_button;
    QLabel *cancel_button_label;
    QWidget *cancel_button_clicked;
    ClickableQWidget *language_button_container;
    QWidget *language_button_background;
    QLabel *language_button_label;
    QWidget *language_button;
    QWidget *language_button_background_clicked;
    QLabel *left_logo;
    QLabel *right_logo;
    TopNotificationBar *topNotificationBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1024, 768));
        MainWindow->setStyleSheet(QLatin1String("#MainWindow {\n"
"	background-color:white;\n"
"}"));
        main_background = new QWidget(MainWindow);
        main_background->setObjectName(QStringLiteral("main_background"));
        main_background->setEnabled(true);
        sizePolicy.setHeightForWidth(main_background->sizePolicy().hasHeightForWidth());
        main_background->setSizePolicy(sizePolicy);
        main_background->setMinimumSize(QSize(1024, 768));
        main_background->setMaximumSize(QSize(1024, 768));
        footer = new QWidget(main_background);
        footer->setObjectName(QStringLiteral("footer"));
        footer->setGeometry(QRect(0, 686, 1024, 84));
        sizePolicy.setHeightForWidth(footer->sizePolicy().hasHeightForWidth());
        footer->setSizePolicy(sizePolicy);
        footer->setMinimumSize(QSize(1024, 77));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        footer->setFont(font);
        footer->setLayoutDirection(Qt::RightToLeft);
        footer->setStyleSheet(QLatin1String("#footer {\n"
"	background-image: url(:/assets/images/footer_background.png);\n"
"}"));
        bottom_buttons = new QWidget(footer);
        bottom_buttons->setObjectName(QStringLiteral("bottom_buttons"));
        bottom_buttons->setGeometry(QRect(679, -3, 321, 91));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bottom_buttons->sizePolicy().hasHeightForWidth());
        bottom_buttons->setSizePolicy(sizePolicy1);
        bottom_buttons->setMinimumSize(QSize(0, 0));
        bottom_buttons->setMaximumSize(QSize(500, 93));
        bottom_buttons->setLayoutDirection(Qt::LeftToRight);
        bottom_buttons->setStyleSheet(QLatin1String("font-size: 14px;\n"
"color: gray;\n"
"font: \"Muli SemiBold\";\n"
""));
        horizontalLayout = new QHBoxLayout(bottom_buttons);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        home_button_container = new ClickableQWidget(bottom_buttons);
        home_button_container->setObjectName(QStringLiteral("home_button_container"));
        home_button_container->setMinimumSize(QSize(130, 80));
        home_button = new QWidget(home_button_container);
        home_button->setObjectName(QStringLiteral("home_button"));
        home_button->setGeometry(QRect(0, 0, 100, 80));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(home_button->sizePolicy().hasHeightForWidth());
        home_button->setSizePolicy(sizePolicy2);
        home_button->setMinimumSize(QSize(80, 80));
        home_button->setMaximumSize(QSize(16777215, 16777215));
        home_button->setStyleSheet(QLatin1String("#home_button {\n"
"	background-image: url(:/assets/images/home.png);\n"
"	background-repeat: no-repeat;\n"
"	background-position: center;\n"
"}"));
        home_button_label = new QLabel(home_button_container);
        home_button_label->setObjectName(QStringLiteral("home_button_label"));
        home_button_label->setGeometry(QRect(0, 52, 100, 21));
        home_button_label->setAlignment(Qt::AlignCenter);
        home_button_clicked = new QWidget(home_button_container);
        home_button_clicked->setObjectName(QStringLiteral("home_button_clicked"));
        home_button_clicked->setEnabled(true);
        home_button_clicked->setGeometry(QRect(0, 0, 100, 80));
        sizePolicy2.setHeightForWidth(home_button_clicked->sizePolicy().hasHeightForWidth());
        home_button_clicked->setSizePolicy(sizePolicy2);
        home_button_clicked->setMinimumSize(QSize(80, 80));
        home_button_clicked->setMaximumSize(QSize(16777215, 16777215));
        home_button_clicked->setStyleSheet(QLatin1String("#home_button_clicked {\n"
"	background-image: url(:/assets/images/home_selected.png);\n"
"	background-repeat: no-repeat;\n"
"	background-position: center;\n"
"}"));

        horizontalLayout->addWidget(home_button_container);

        cancel_button_container = new ClickableQWidget(bottom_buttons);
        cancel_button_container->setObjectName(QStringLiteral("cancel_button_container"));
        sizePolicy2.setHeightForWidth(cancel_button_container->sizePolicy().hasHeightForWidth());
        cancel_button_container->setSizePolicy(sizePolicy2);
        cancel_button_container->setMinimumSize(QSize(130, 80));
        cancel_button = new QWidget(cancel_button_container);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));
        cancel_button->setGeometry(QRect(0, 0, 100, 80));
        cancel_button->setMinimumSize(QSize(80, 80));
        cancel_button->setMaximumSize(QSize(16777215, 16777215));
        cancel_button->setStyleSheet(QLatin1String("#cancel_button {\n"
"	background-image: url(:/assets/images/cancel.png);\n"
"	background-repeat: no-repeat;\n"
"	background-position: center;\n"
"}"));
        cancel_button_label = new QLabel(cancel_button_container);
        cancel_button_label->setObjectName(QStringLiteral("cancel_button_label"));
        cancel_button_label->setGeometry(QRect(0, 52, 100, 21));
        cancel_button_label->setAlignment(Qt::AlignCenter);
        cancel_button_clicked = new QWidget(cancel_button_container);
        cancel_button_clicked->setObjectName(QStringLiteral("cancel_button_clicked"));
        cancel_button_clicked->setGeometry(QRect(0, 0, 100, 80));
        cancel_button_clicked->setMinimumSize(QSize(80, 80));
        cancel_button_clicked->setMaximumSize(QSize(16777215, 16777215));
        cancel_button_clicked->setStyleSheet(QLatin1String("#cancel_button_clicked {\n"
"	background-image: url(:/assets/images/cancel_selected.png);\n"
"	background-repeat: no-repeat;\n"
"	background-position: center;\n"
"}"));

        horizontalLayout->addWidget(cancel_button_container);

        language_button_container = new ClickableQWidget(bottom_buttons);
        language_button_container->setObjectName(QStringLiteral("language_button_container"));
        language_button_container->setMinimumSize(QSize(90, 80));
        language_button_container->setStyleSheet(QStringLiteral(""));
        language_button_background = new QWidget(language_button_container);
        language_button_background->setObjectName(QStringLiteral("language_button_background"));
        language_button_background->setGeometry(QRect(0, 0, 100, 80));
        sizePolicy2.setHeightForWidth(language_button_background->sizePolicy().hasHeightForWidth());
        language_button_background->setSizePolicy(sizePolicy2);
        language_button_background->setMinimumSize(QSize(80, 80));
        language_button_background->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        language_button_background->setFont(font1);
        language_button_background->setStyleSheet(QLatin1String("#language_button_background {\n"
"	background-image: url(:/assets/images/language_inactive.png);\n"
"	background-repeat: no-repeat;\n"
"	background-position: center;\n"
"}"));
        language_button_label = new QLabel(language_button_container);
        language_button_label->setObjectName(QStringLiteral("language_button_label"));
        language_button_label->setGeometry(QRect(0, 52, 100, 21));
        language_button_label->setAlignment(Qt::AlignCenter);
        language_button = new QWidget(language_button_container);
        language_button->setObjectName(QStringLiteral("language_button"));
        language_button->setGeometry(QRect(0, 0, 100, 61));
        language_button->setStyleSheet(QLatin1String("#language_button {\n"
"	background-image: url(:/assets/images/eng_flag_small.png);\n"
"	background-repeat: no-repeat;\n"
"	background-position: center;\n"
"}"));
        language_button_background_clicked = new QWidget(language_button_container);
        language_button_background_clicked->setObjectName(QStringLiteral("language_button_background_clicked"));
        language_button_background_clicked->setGeometry(QRect(0, 0, 100, 80));
        sizePolicy2.setHeightForWidth(language_button_background_clicked->sizePolicy().hasHeightForWidth());
        language_button_background_clicked->setSizePolicy(sizePolicy2);
        language_button_background_clicked->setMinimumSize(QSize(80, 80));
        language_button_background_clicked->setMaximumSize(QSize(16777215, 16777215));
        language_button_background_clicked->setFont(font1);
        language_button_background_clicked->setStyleSheet(QLatin1String("#language_button_background_clicked {\n"
"	background-image: url(:/assets/images/language_selected.png);\n"
"	background-repeat: no-repeat;\n"
"	background-position: center;\n"
"}"));
        language_button_background_clicked->raise();
        language_button_background->raise();
        language_button_label->raise();
        language_button->raise();

        horizontalLayout->addWidget(language_button_container);

        left_logo = new QLabel(main_background);
        left_logo->setObjectName(QStringLiteral("left_logo"));
        left_logo->setGeometry(QRect(25, 25, 163, 63));
        left_logo->setStyleSheet(QStringLiteral(""));
        right_logo = new QLabel(main_background);
        right_logo->setObjectName(QStringLiteral("right_logo"));
        right_logo->setGeometry(QRect(834, 25, 163, 63));
        right_logo->setStyleSheet(QStringLiteral(""));
        topNotificationBar = new TopNotificationBar(main_background);
        topNotificationBar->setObjectName(QStringLiteral("topNotificationBar"));
        topNotificationBar->setGeometry(QRect(0, 0, 1024, 90));
        MainWindow->setCentralWidget(main_background);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        home_button_label->setText(QApplication::translate("MainWindow", "Home", Q_NULLPTR));
        cancel_button_label->setText(QApplication::translate("MainWindow", "Cancel", Q_NULLPTR));
        language_button_label->setText(QApplication::translate("MainWindow", "Language", Q_NULLPTR));
        left_logo->setText(QString());
        right_logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
