#include "topnotificationbar.h"
#include "ui_topnotificationbar.h"
#include "qdebug.h"

TopNotificationBar::TopNotificationBar(QWidget *parent)
    : ClickableQWidget(parent)
    , ui(new Ui::TopNotificationBar)
{
    ui->setupUi(this);
}

void TopNotificationBar::setCustomStyleSheet(const std::string& styleSheetStr) {
    UIUtils::setStyleSheetAndUpdate(ui->topNotification, styleSheetStr.c_str());
}

void TopNotificationBar::setNotificationHeaderText(const std::string& notificationHeader) {
    ui->topNotificationHeader->setText(notificationHeader.c_str());
}

void TopNotificationBar::setNotificationDetails(const std::string& notificationDetails) {
    ui->topNotificationDetails->setText(notificationDetails.c_str());
}

void TopNotificationBar::mouseReleaseEvent(QMouseEvent *event)
{
    emit onClickedNotificationBarSignal();
}

