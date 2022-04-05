#include "utils/headers/stringutils.h"

string StringUtils::replaceAll(const string& initialString, const string& pattern, const string& replacement)
{
    regex expression(pattern);
    return regex_replace(initialString, expression, replacement);
}

vector<string> StringUtils::split(const string& str, const string& delimiter)
{
    vector<string> strList = vector<string>();
    size_t previous_position = 0;
    size_t position = str.find(delimiter);

    while (position != string::npos) {
        strList.emplace_back(str.substr(previous_position, position - previous_position));
        previous_position = position + 1;
        position = str.find(delimiter, previous_position);
    }

    strList.emplace_back(str.substr(previous_position, str.length() - previous_position));

    return strList;
}
