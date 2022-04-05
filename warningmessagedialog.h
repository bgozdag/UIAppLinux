#ifndef WARNINGMESSAGEDIALOG_H
#define WARNINGMESSAGEDIALOG_H

#include "errorwidget.h"
#include "messagedialog.h"
#include <qtimer.h>

namespace Ui {
class WarningMessageDialog;
}

class WarningMessageDialog : public MessageDialog
{
    Q_OBJECT

public:
    explicit WarningMessageDialog(QWidget *parent = nullptr);
    ~WarningMessageDialog();
    void setMessage(const QString & message);
    void setTimeout(int milliSeconds);
    void show() override;
    void startTimer();
    void stopTimer();

private:
    ErrorWidget * warningWidget = nullptr;
    QTimer * timeoutTimer = nullptr;
    int timeoutMilliSeconds = 15000;

public slots:
    void messageDialogTimeout();
};

#endif // WARNINGMESSAGEDIALOG_H
