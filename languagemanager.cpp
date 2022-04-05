#include "languagemanager.h"

LanguageManager * LanguageManager::instance = nullptr;

LanguageManager::LanguageManager()
{
    currentLanguage = Language::ENGLISH;
}

LanguageManager * LanguageManager::getInstance()
{
    if (!instance) {
        instance = new LanguageManager();
    }
    return instance;
}

void LanguageManager::changeLanguage(Language language) {
    currentLanguage = language;
}

Language LanguageManager::getCurrentLanguage() {
    return currentLanguage;
}

unsigned int LanguageManager::getLanguageIndex()
{
    return currentLanguage;
}

