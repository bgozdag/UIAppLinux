#ifndef EMERGENCYBUTTONDIALOG_H
#define EMERGENCYBUTTONDIALOG_H

#include "messagedialog.h"
#include "emergencybuttondialogwidget.h"
#include "appstylesheets.h"
#include "languages/generated/appstrings.h"
#include <QTimer>

class EmergencyButtonDialog : public MessageDialog
{
public:
    EmergencyButtonDialog(QWidget *parent);
    ~EmergencyButtonDialog() override;
    void show() override;
    void startTimer();
    void stopTimer();

private:
    QTimer * timeoutTimer = nullptr;
    const int timeoutMilliSeconds = 15000;
};

#endif // EMERGENCYBUTTONDIALOG_H
