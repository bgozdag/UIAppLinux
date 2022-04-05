#ifndef AUTHORIZEMESSAGEDIALOG_H
#define AUTHORIZEMESSAGEDIALOG_H

#include "authorizewidget.h"
#include "messagedialog.h"

namespace Ui {
class AuthorizeMessageDialog;
}

class AuthorizeMessageDialog : public MessageDialog
{
    Q_OBJECT

public:
    explicit AuthorizeMessageDialog(QWidget *parent = nullptr);
    ~AuthorizeMessageDialog() override;
    void onCloseButtonClicked() override;
    void setAlternativeAuthorizationIcon(std::string stylesheet);
    void setAlternativeAuthorizationText(TranslationString alternativeAuthorizationText);
    void setVisibilityAlternativeAuthorization(bool state);

private:
    AuthorizeWidget * authorizeWidget = nullptr;
};

#endif // AUTHORIZEMESSAGEDIALOG_H
