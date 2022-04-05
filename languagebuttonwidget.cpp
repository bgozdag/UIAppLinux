#include "dimensions.h"
#include "languagebuttonwidget.h"
#include "languagemanager.h"

#include <qboxlayout.h>
#include <qlabel.h>

#include <languages/generated/appstrings.h>

LanguageButtonWidget::LanguageButtonWidget(Language language, QWidget *parent) :
    ClickableQWidget(parent),
    language(language)
{
    language_button_container = this;
    language_button_container->setObjectName(QStringLiteral("language_button_container"));
    language_button_container->setMinimumSize(QSize(Dimensions::LANGUAGE_WIDGET_WIDTH, Dimensions::LANGUAGE_WIDGET_HEIGHT));
    language_button_container->setMaximumSize(QSize(Dimensions::LANGUAGE_WIDGET_WIDTH, Dimensions::LANGUAGE_WIDGET_HEIGHT));

    QVBoxLayout * verticalLayout = new QVBoxLayout(language_button_container);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

    QWidget * language_button = new QWidget(language_button_container);
    verticalLayout->addWidget(language_button);

    QLabel * language_button_label = new QLabel(language_button_container);
    language_button_label->setAlignment(Qt::AlignCenter);
    verticalLayout->addWidget(language_button_label);

    switch (language) {
        case Language::ENGLISH:
            language_button->setObjectName(QStringLiteral("english_button"));
            language_button_label->setText(AppStrings::language_english.getForLocale().c_str());
            break;
        case Language::TURKISH:
            language_button->setObjectName(QStringLiteral("turkish_button"));
            language_button_label->setText(AppStrings::language_turkish.getForLocale().c_str());
            break;
        case Language::HEBREW:
            language_button->setObjectName(QStringLiteral("hebrew_button"));
            language_button_label->setText(AppStrings::language_hebrew.getForLocale().c_str());
            break;
        case Language::CZECH:
            language_button->setObjectName(QStringLiteral("czech_button"));
            language_button_label->setText(AppStrings::language_czech.getForLocale().c_str());
            break;
        case Language::DANISH:
            language_button->setObjectName(QStringLiteral("danish_button"));
            language_button_label->setText(AppStrings::language_danish.getForLocale().c_str());
            break;
        case Language::GERMAN:
            language_button->setObjectName(QStringLiteral("german_button"));
            language_button_label->setText(AppStrings::language_german.getForLocale().c_str());
            break;
        case Language::SPANISH:
            language_button->setObjectName(QStringLiteral("spanish_button"));
            language_button_label->setText(AppStrings::language_spanish.getForLocale().c_str());
            break;
        case Language::FINNISH:
            language_button->setObjectName(QStringLiteral("finnish_button"));
            language_button_label->setText(AppStrings::language_finnish.getForLocale().c_str());
            break;
        case Language::FRENCH:
            language_button->setObjectName(QStringLiteral("french_button"));
            language_button_label->setText(AppStrings::language_french.getForLocale().c_str());
            break;
        case Language::HUNGARIAN:
            language_button->setObjectName(QStringLiteral("hungarian_button"));
            language_button_label->setText(AppStrings::language_hungarian.getForLocale().c_str());
            break;
        case Language::ITALIAN:
            language_button->setObjectName(QStringLiteral("italian_button"));
            language_button_label->setText(AppStrings::language_italian.getForLocale().c_str());
            break;
        case Language::NORWEGIAN:
            language_button->setObjectName(QStringLiteral("norwegian_button"));
            language_button_label->setText(AppStrings::language_norwegian.getForLocale().c_str());
            break;
        case Language::POLISH:
            language_button->setObjectName(QStringLiteral("polish_button"));
            language_button_label->setText(AppStrings::language_polish.getForLocale().c_str());
            break;
        case Language::ROMANIAN:
            language_button->setObjectName(QStringLiteral("romanian_button"));
            language_button_label->setText(AppStrings::language_romanian.getForLocale().c_str());
            break;
        case Language::SLOVAKIAN:
            language_button->setObjectName(QStringLiteral("slovakian_button"));
            language_button_label->setText(AppStrings::language_slovakian.getForLocale().c_str());
            break;
        case Language::SWEDISH:
            language_button->setObjectName(QStringLiteral("swedish_button"));
            language_button_label->setText(AppStrings::language_swedish.getForLocale().c_str());
            break;
    }
}

LanguageButtonWidget::~LanguageButtonWidget()
{

}

void LanguageButtonWidget::mouseReleaseEvent(QMouseEvent *event)
{
    emit onClickedLanguageSignal(this->language, false);
}

QWidget * LanguageButtonWidget::getLanguageButtonContainer()
{
    return language_button_container;
}
