// !! THIS CODE IS AUTOMATICALLY GENERATED AND SHOULD NOT BE COMMITTED !!
#ifndef TRANSLATIONSTRING_H
#define TRANSLATIONSTRING_H
#include <iostream>
#include <vector>

using namespace std;

class TranslationString
{
public:
    // TranslationString Constructor Declaration
    TranslationString(string&& en, string&& tr, string&& he, string&& cs, string&& da, string&& de, string&& es, string&& fi, string&& fr, string&& hu, string&& it, string&& no, string&& pl, string&& ro, string&& sk, string&& sv);
    string getForLocale() const;
    vector<string> translations;
};

#endif // TRANSLATIONSTRING_H
