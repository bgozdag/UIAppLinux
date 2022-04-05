#include "homescreennotificationbar.h"
#include "ui_homescreennotificationbar.h"
#include <QDebug>
#include <qfontdatabase.h>
#include <languages/generated/appstrings.h>

HomeScreenNotificationBar::HomeScreenNotificationBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeScreenNotificationBar)
{
    ui->setupUi(this);
}

HomeScreenNotificationBar::~HomeScreenNotificationBar()
{
    delete ui;
}

void HomeScreenNotificationBar::onLanguageChanged()
{
    ui->homeScreenNotificationLabel->setText(AppStrings::choose_socket_or_connect.getForLocale().c_str());
}

