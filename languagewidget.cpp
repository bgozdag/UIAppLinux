#include "languagewidget.h"
#include "ui_languagewidget.h"

#include <languages/generated/appstrings.h>

LanguageWidget::LanguageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LanguageWidget)
{
    ui->setupUi(this);
    ui->languageTitle->setText(AppStrings::text_choose_your_language.getForLocale().c_str());
    ui->softwareVersions->raise();
}

LanguageWidget::~LanguageWidget()
{
    delete ui;
}

QGridLayout * LanguageWidget::getLanguageContainer()
{
    return ui->languageContainer;
}

void LanguageWidget::setLanguageTitle(const QString & title)
{
    ui->languageTitle->setText(title);
}

void LanguageWidget::setSoftwareVersions(const QString &softwareVersions)
{
    ui->softwareVersions->setText(softwareVersions);
}
