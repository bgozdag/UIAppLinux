#include "authorizemessagedialog.h"

AuthorizeMessageDialog::AuthorizeMessageDialog(QWidget *parent) :
    MessageDialog(parent)
{
    authorizeWidget = new AuthorizeWidget();
    getMessageDialogContainer()->addWidget(authorizeWidget);
}

AuthorizeMessageDialog::~AuthorizeMessageDialog()
{

}

void AuthorizeMessageDialog::onCloseButtonClicked()
{
    this->close();
    emit dialogClosedSignal();
}

void AuthorizeMessageDialog::setAlternativeAuthorizationText(TranslationString alternativeAuthorizationText)
{
    authorizeWidget->setAlternativeAuthorizationText(alternativeAuthorizationText);
}

void AuthorizeMessageDialog::setAlternativeAuthorizationIcon(std::string stylesheet)
{
    authorizeWidget->setAlternativeAuthorizationIcon(stylesheet);
}

void AuthorizeMessageDialog::setVisibilityAlternativeAuthorization(bool state)
{
    authorizeWidget->hideAlternativeAuthorization(!state);
}
