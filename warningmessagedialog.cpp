#include "warningmessagedialog.h"
#include "appstylesheets.h"
#include "errorwidget.h"
#include <utils/headers/stringutils.h>
#include <utils/headers/uiutils.h>

WarningMessageDialog::WarningMessageDialog(QWidget *parent) :
    MessageDialog(parent),
    timeoutTimer(new QTimer())
{
    warningWidget = new ErrorWidget();
    getMessageDialogContainer()->addWidget(warningWidget);
    warningWidget->setIcon(AppStyleSheets::WARNING_MESSAGE_DIALOG);

    timeoutTimer->connect(timeoutTimer, &QTimer::timeout, [this]() {
        messageDialogTimeout();
    });
}

WarningMessageDialog::~WarningMessageDialog()
{
    if (timeoutTimer != nullptr) {
        timeoutTimer->deleteLater();
        timeoutTimer = nullptr;
    }
}

void WarningMessageDialog::setMessage(const QString & message)
{
    warningWidget->setMessage(message);
}

void WarningMessageDialog::setTimeout(int milliSeconds)
{
    timeoutMilliSeconds = milliSeconds;
}

void WarningMessageDialog::messageDialogTimeout()
{
    stopTimer();
    onCloseButtonClicked();
}

void WarningMessageDialog::startTimer()
{
    timeoutTimer->start(timeoutMilliSeconds);
}

void WarningMessageDialog::stopTimer()
{
    timeoutTimer->stop();
}

void WarningMessageDialog::show()
{
    MessageDialog::show();
    startTimer();
}
