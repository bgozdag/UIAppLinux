#include "appstylesheets.h"
#include "emergencybuttondialogwidget.h"
#include "ui_emergencybuttondialogwidget.h"
#include "ui_errorwidget.h"
#include "languages/generated/appstrings.h"
#include <utils/headers/stringutils.h>

#include <utils/headers/uiutils.h>

EmergencyButtonDialogWidget::EmergencyButtonDialogWidget(QWidget *parent) : QWidget(parent),
    ui(new Ui::EmergencyButtonDialogWidget)
{
    ui->setupUi(this);
    UIUtils::updateStyleSheet(this, AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::EMERGENCY_BUTTON_DIALOG).c_str());
    setHeader(AppStrings::emergency_button_error_notification_header.getForLocale().c_str());
    setMessage(AppStrings::emergency_button_instructions.getForLocale().c_str());
}

EmergencyButtonDialogWidget::~EmergencyButtonDialogWidget()
{
    delete ui;
}

void EmergencyButtonDialogWidget::setHeader(const QString& header)
{
    ui->header->setText(header);
}

void EmergencyButtonDialogWidget::setMessage(const QString & message)
{
    ui->message->setText(message);
}
