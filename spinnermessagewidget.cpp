#include "appstylesheets.h"
#include "spinnermessagewidget.h"
#include "ui_spinnermessagewidget.h"
#include "progressbarwidget.h"

#include <utils/headers/uiutils.h>

SpinnerMessageWidget::SpinnerMessageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpinnerMessageWidget)
{
    ui->setupUi(this);

    std::string spinnerStylesheet;
    spinnerStylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::SPINNER_MESSAGE_WIDGET);

    UIUtils::setStyleSheetAndUpdate(this, QString::fromStdString(spinnerStylesheet));
    ui->progressSpinnerWidget->setSpinnerSource(SPINNER_SRC.c_str());
}

SpinnerMessageWidget::~SpinnerMessageWidget()
{
    delete ui;
}

void SpinnerMessageWidget::setMessage(const TranslationString inputText)
{
    ui->informationText->setText(inputText.getForLocale().c_str());
}

void SpinnerMessageWidget::setMessage(const char* text)
{
    ui->informationText->setText(text);
}

void SpinnerMessageWidget::addWidgetToSpinnerMessageContainer(QWidget * widget, int stretch, Qt::Alignment alignment)
{
    ui->spinnerMessageContainer_2->addWidget(widget, stretch, alignment);
}
