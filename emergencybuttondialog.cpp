#include "emergencybuttondialog.h"

EmergencyButtonDialog::EmergencyButtonDialog(QWidget *parent) : MessageDialog(parent)
{
    EmergencyButtonDialogWidget* errorWidget = new EmergencyButtonDialogWidget();
    getMessageDialogContainer()->addWidget(errorWidget);

    timeoutTimer = new QTimer();
    timeoutTimer->connect(timeoutTimer, &QTimer::timeout, [this]() {
        timeoutTimer->stop();
        onCloseButtonClicked();
    });
}

EmergencyButtonDialog::~EmergencyButtonDialog()
{
    if (timeoutTimer != nullptr) {
        timeoutTimer->stop();
        timeoutTimer->deleteLater();
        timeoutTimer = nullptr;
    }
}

void EmergencyButtonDialog::startTimer()
{
    timeoutTimer->start(timeoutMilliSeconds);
}

void EmergencyButtonDialog::show()
{
    MessageDialog::show();
    timeoutTimer->start(timeoutMilliSeconds);
}
