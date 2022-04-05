#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#include <iostream>
#include <regex>

using namespace std;

class StringUtils {
public:
    static string replaceAll(const string& initialString, const string& pattern, const string& replacement);
    static vector<string> split(const string& str, const string& delimiter);
};

#endif // STRINGUTILS_H
