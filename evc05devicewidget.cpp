#include "evc05devicewidget.h"
#include "ui_evc05devicewidget.h"

Evc05DeviceWidget::Evc05DeviceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Evc05DeviceWidget)
{
    ui->setupUi(this);
}

Evc05DeviceWidget::~Evc05DeviceWidget()
{
    delete ui;
}
