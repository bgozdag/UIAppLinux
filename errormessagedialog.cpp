#include "appstylesheets.h"
#include "errormessagedialog.h"
#include "errorwidget.h"

ErrorMessageDialog::ErrorMessageDialog(QWidget *parent) :
    MessageDialog(parent)
{
    errorWidget = new ErrorWidget();
    errorWidget->setIcon(AppStyleSheets::ERROR_MESSAGE_DIALOG);
    getMessageDialogContainer()->addWidget(errorWidget);
}

ErrorMessageDialog::~ErrorMessageDialog()
{

}

void ErrorMessageDialog::setMessage(const QString & message)
{
    errorWidget->setMessage(message);
}
