#include "languagemessagedialog.h"
#include "languagemanager.h"
#include "appstylesheets.h"
#include "languagebuttonwidget.h"
#include "qdebug.h"
#include "dimensions.h"

#include <languages/generated/appstrings.h>

#include <utils/headers/uiutils.h>

LanguageMessageDialog::LanguageMessageDialog(QWidget *parent, vector<Language> excludedLangauges) :
    MessageDialog(parent),
    excludedLanguages(excludedLangauges),
    mainWindow(parent)
{
    resize(getSize().width(), Dimensions::LANGUAGE_MESSAGE_DIALOG_HEIGHT);
    move(getSize().left(), getSize().top() + Dimensions::LANGUAGE_MESSAGE_DIALOG_Y_OFFSET);
    languageWidget = new LanguageWidget();
    getMessageDialogContainer()->addWidget(languageWidget);
    loadLanguages();
    setDeleteOnClose(false);
}

LanguageMessageDialog::~LanguageMessageDialog()
{

}

void LanguageMessageDialog::loadLanguages()
{
    int rowLocationInGridLayout = -1;
    unsigned int columnLocationInGridLayout = 0;
    unsigned int addedLanguageCount = 0;
    for (unsigned int index = Language::ENGLISH; index < Language::COUNT; index++) {
        if (std::find(excludedLanguages.begin(), excludedLanguages.end(), index) != excludedLanguages.end()) {
            qDebug() << "Language index excluded = " << index;
            continue;
        }

        if (addedLanguageCount % LANGUAGE_COUNT_IN_A_LINE == 0)
        {
            rowLocationInGridLayout++;
            columnLocationInGridLayout = 0;
        }

        addedLanguageCount++;
        LanguageButtonWidget * langButton = new LanguageButtonWidget((Language)index);
        connect(langButton, SIGNAL(onClickedLanguageSignal(Language, bool)), mainWindow, SLOT(changeLanguage(Language, bool)));
        languageWidget->getLanguageContainer()->addWidget(langButton->getLanguageButtonContainer(), rowLocationInGridLayout, columnLocationInGridLayout++);
    }

    string languageStylesheet = AppStyleSheets::getInstance()->getStylesheet(AppStyleSheets::LANGUAGES);
    UIUtils::updateStyleSheet(this, languageStylesheet.c_str());
}

void LanguageMessageDialog::setSoftwareVersions(const QString & softwareVersions) {
    languageWidget->setSoftwareVersions(softwareVersions);
}

