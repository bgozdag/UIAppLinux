#ifndef EVC05DEVICEWIDGET_H
#define EVC05DEVICEWIDGET_H

#include <QWidget>

namespace Ui {
class Evc05DeviceWidget;
}

class Evc05DeviceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit Evc05DeviceWidget(QWidget *parent = nullptr);
    ~Evc05DeviceWidget();

private:
    Ui::Evc05DeviceWidget *ui;
};

#endif // EVC05DEVICEWIDGET_H
