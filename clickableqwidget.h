#ifndef CLICKABLEQWIDGET_H
#define CLICKABLEQWIDGET_H

#include <qwidget.h>

class ClickableQWidget : public QWidget
{
    Q_OBJECT

public:
    ClickableQWidget(QWidget *parent = nullptr);
    ~ClickableQWidget() override;
    void mousePressEvent (QMouseEvent * event) override;

signals:
    void clickedSignal();
};

#endif // CLICKABLEQWIDGET_H
