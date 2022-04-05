#include "clickableqwidget.h"

ClickableQWidget::ClickableQWidget(QWidget *parent) : QWidget(parent)
{

}

ClickableQWidget::~ClickableQWidget()
{

}

void ClickableQWidget::mousePressEvent(QMouseEvent *event)
{
    emit clickedSignal();
}
