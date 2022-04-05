#ifndef LANGUAGEMESSAGEDIALOG_H
#define LANGUAGEMESSAGEDIALOG_H

#include <vector>

#include "languagewidget.h"
#include "messagedialog.h"
#include "languagemanager.h"

namespace Ui {
class LanguageMessageDialog;
}

class LanguageMessageDialog : public MessageDialog
{
    Q_OBJECT

public:
    explicit LanguageMessageDialog(QWidget *parent, std::vector<Language> excludedLanguages);
    ~LanguageMessageDialog();
    void loadLanguages();
    void setSoftwareVersions(const QString & softwareVersions);

private:
    LanguageWidget * languageWidget = nullptr;
    const unsigned int LANGUAGE_COUNT_IN_A_LINE = 4;
    std::vector<Language> excludedLanguages;
    QWidget * mainWindow;
};

#endif // LANGUAGEMESSAGEDIALOG_H
