#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

namespace Languages {
    enum Type{
        ENGLISH,
        TURKISH,
        HEBREW,
        CZECH,
        DANISH,
        GERMAN,
        SPANISH,
        FINNISH,
        FRENCH,
        HUNGARIAN,
        ITALIAN,
        NORWEGIAN,
        POLISH,
        ROMANIAN,
        SLOVAKIAN,
        SWEDISH,
        COUNT
    };
};
typedef Languages::Type Language;

class LanguageManager
{
public:
    static LanguageManager * getInstance();
    void changeLanguage(Language language);
    Language getCurrentLanguage();
    unsigned int getLanguageIndex();
    LanguageManager(const LanguageManager& languageManager) = delete;
    LanguageManager& operator=(const LanguageManager& languageManager) = delete;

private:
    LanguageManager();
    static LanguageManager * instance;
    Language currentLanguage;
};

#endif // LANGUAGEMANAGER_H
