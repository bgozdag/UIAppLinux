#ifndef TOPNOTIFICATIONBAR_H
#define TOPNOTIFICATIONBAR_H

#include "clickableqwidget.h"
#include "utils/headers/uiutils.h"
#include "appstylesheets.h"

namespace Ui {
class TopNotificationBar;
}

class TopNotificationBar : public ClickableQWidget
{
    Q_OBJECT

public:
    explicit TopNotificationBar(QWidget *parent = nullptr);
    void setCustomStyleSheet(const std::string&);
    void setNotificationHeaderText(const std::string& notificationHeader);
    void setNotificationDetails(const std::string& notificationDetails);
    void mouseReleaseEvent (QMouseEvent * event) override;

private:
    Ui::TopNotificationBar *ui;

signals:
    void onClickedNotificationBarSignal();
};

#endif // TOPNOTIFICATIONBAR_H
