#include "appstylesheets.h"
#include "errorwidget.h"
#include "ui_errorwidget.h"
#include <utils/headers/stringutils.h>

#include <utils/headers/uiutils.h>

ErrorWidget::ErrorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorWidget)
{
    ui->setupUi(this);
}

ErrorWidget::~ErrorWidget()
{
    delete ui;
}

void ErrorWidget::setMessage(const QString & message)
{
    ui->errorText->setText(message);
}

void ErrorWidget::setIcon(const std::string & styleSheetKey)
{
    string messageDialogStylesheet = AppStyleSheets::getInstance()->getStylesheet(styleSheetKey);
    UIUtils::updateStyleSheet(this, messageDialogStylesheet.c_str());
}
