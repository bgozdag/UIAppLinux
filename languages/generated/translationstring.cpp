// !! THIS CODE IS AUTOMATICALLY GENERATED AND SHOULD NOT BE COMMITTED !!
#include "languagemanager.h"
#include "translationstring.h"

// TranslationString Constructor Definition
TranslationString::TranslationString(string&& en, string&& tr, string&& he, string&& cs, string&& da, string&& de, string&& es, string&& fi, string&& fr, string&& hu, string&& it, string&& no, string&& pl, string&& ro, string&& sk, string&& sv){
    translations.reserve(16);
    translations.emplace_back(std::move(en));
    translations.emplace_back(std::move(tr));
    translations.emplace_back(std::move(he));
    translations.emplace_back(std::move(cs));
    translations.emplace_back(std::move(da));
    translations.emplace_back(std::move(de));
    translations.emplace_back(std::move(es));
    translations.emplace_back(std::move(fi));
    translations.emplace_back(std::move(fr));
    translations.emplace_back(std::move(hu));
    translations.emplace_back(std::move(it));
    translations.emplace_back(std::move(no));
    translations.emplace_back(std::move(pl));
    translations.emplace_back(std::move(ro));
    translations.emplace_back(std::move(sk));
    translations.emplace_back(std::move(sv));
}


string TranslationString::getForLocale() const
{
    unsigned int languageIndex = LanguageManager::getInstance()->getLanguageIndex();
    return translations[languageIndex];
}
