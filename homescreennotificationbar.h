#ifndef HOMESCREENNOTIFICATIONBAR_H
#define HOMESCREENNOTIFICATIONBAR_H

#include <QWidget>

namespace Ui {
class HomeScreenNotificationBar;
}

class HomeScreenNotificationBar : public QWidget
{
    Q_OBJECT

public:
    explicit HomeScreenNotificationBar(QWidget *parent = nullptr);
    ~HomeScreenNotificationBar();
    void onLanguageChanged();
    void setupBrand(QString brand);

private:
    Ui::HomeScreenNotificationBar *ui;
};

#endif // HOMESCREENNOTIFICATIONBAR_H
