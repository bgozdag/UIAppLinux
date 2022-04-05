#include "languagemanager.h"
#include "translationstring.h"

// TranslationString Constructor Definition
{0}

string TranslationString::getForLocale() const
{{
    unsigned int languageIndex = LanguageManager::getInstance()->getLanguageIndex();
    return translations[languageIndex];
}}
