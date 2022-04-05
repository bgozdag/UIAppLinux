import json
import os
import shutil
import time

OUTPUT_DIR = "generated"
CODE_TEMPLATE_DIR = "codeTemplates"
APP_STRINGS_CPP = "appstrings.cpp"
APP_STRINGS_H = "appstrings.h"
TRANSLATION_STRING_CPP = "translationstring.cpp"
TRANSLATION_STRING_H = "translationstring.h"

SUPPORTED_LANGUAGES = ['en', 'tr', 'he', 'cs', 'da', 'de', 'es', 'fi', 'fr', 'hu', 'it', 'no', 'pl', 'ro', 'sk', 'sv']
TRANSLATION_FILE = "translations.json"

def generate_translation_string():
    with open(CODE_TEMPLATE_DIR + "/" + TRANSLATION_STRING_CPP, "r") as translation_string_cpp:
        with open(CODE_TEMPLATE_DIR + "/" + TRANSLATION_STRING_H, "r") as translation_string_h:
            translationStringCppSource = translation_string_cpp.read();
            translationStringHeaderSource = translation_string_h.read();
            parameters = ""
            vectorAdditions = "\ttranslations.reserve({0});\n".format(len(SUPPORTED_LANGUAGES))
            for language in SUPPORTED_LANGUAGES:
                parameters += "string&& " + language
                vectorAdditions += "\ttranslations.emplace_back(std::move({0}));".format(language)
                if (language is not SUPPORTED_LANGUAGES[-1]):
                    parameters += ", "
                    vectorAdditions += "\n"

            constructorDefinition = "TranslationString({0}){{\n{1}\n}}\n".format(parameters, vectorAdditions)
            with open(OUTPUT_DIR + "/" + TRANSLATION_STRING_CPP, "w") as generated_translation_string_cpp:
                mark_as_generated(generated_translation_string_cpp)
                generated_translation_string_cpp.write(translationStringCppSource.format("TranslationString::" + constructorDefinition).replace("\t", "    "))
            with open(OUTPUT_DIR + "/" + TRANSLATION_STRING_H, "w") as generated_translation_string_h:
                mark_as_generated(generated_translation_string_h)
                generated_translation_string_h.write(translationStringHeaderSource.format(constructorDefinition.partition("{")[0] + ";"))

def generate_app_strings(languageDict):
    with open(CODE_TEMPLATE_DIR + "/" + APP_STRINGS_CPP, "r") as app_strings_cpp:
        with open(CODE_TEMPLATE_DIR + "/" + APP_STRINGS_H, "r") as app_strings_h:
            appStringCppSource = app_strings_cpp.read();
            appStringHeaderSource = app_strings_h.read();
            declarationTemplate = "static const TranslationString {0}";
            declarations = "";
            definitions = "";

            # Take 'en' translation ids as base and generate everything.
            for id in languageDict['en']:
                declarations += declarationTemplate.format(id) + ";\n\t";
                stringDef = "AppStrings::{0} = TranslationString({1});\n"
                languageParamValues = ""
                for language in SUPPORTED_LANGUAGES:
                    translationString = languageDict[language][id]
                    languageParamValues += "\"" + translationString + "\""
                    if language is not SUPPORTED_LANGUAGES[-1]:
                        languageParamValues += ","

                definitions += declarationTemplate.format(stringDef.format(id, languageParamValues))

            definitions = definitions.replace("static ", "")
            with open(OUTPUT_DIR + "/" + APP_STRINGS_H, "w") as generated_app_strings_h:
                mark_as_generated(generated_app_strings_h)
                generated_app_strings_h.write(appStringHeaderSource.format(declarations).replace("\t", "    "))
            with open(OUTPUT_DIR + "/" + APP_STRINGS_CPP, "w") as generated_app_strings_cpp:
                mark_as_generated(generated_app_strings_cpp)
                generated_app_strings_cpp.write(appStringCppSource.format(definitions).replace("\t", "    "))

def mark_as_generated(generatedFile):
    generatedFile.write("// !! THIS CODE IS AUTOMATICALLY GENERATED AND SHOULD NOT BE COMMITTED !!\n");


if __name__ == '__main__':
    languageDict = {}
    if (os.path.exists(OUTPUT_DIR)):
        shutil.rmtree(OUTPUT_DIR)
        time.sleep(1) # shutil does not block until rmtree is executed, therefore a small delay is needed.
    os.mkdir(OUTPUT_DIR)

    for supportedLanguage in SUPPORTED_LANGUAGES:
        languageDict[supportedLanguage] = {}

    with open(TRANSLATION_FILE, "r") as open_language_file:
        languageStrings = open_language_file.read()
        languageJson = json.loads(languageStrings)
        for translation in languageJson:
            for supportedLanguage in SUPPORTED_LANGUAGES:
                languageDict[supportedLanguage][translation["id"]] = translation[supportedLanguage]

    generate_translation_string()
    generate_app_strings(languageDict)
