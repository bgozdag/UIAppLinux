#ifndef FIRMWAREUPDATEMESSAGEDIALOG_H
#define FIRMWAREUPDATEMESSAGEDIALOG_H

#include "spinnermessagewidget.h"
#include "messagedialog.h"
#include "progressbarwidget.h"

#include "qprogressbar.h"
#include <QWidget>

class FirmwareUpdateMessageDialog : public MessageDialog
{
    Q_OBJECT

public:
    explicit FirmwareUpdateMessageDialog(QWidget *parent = nullptr);
    ~FirmwareUpdateMessageDialog();

private:
    SpinnerMessageWidget * warningWidget = nullptr;
    QProgressBar * progressBar = nullptr;

public slots:
    void onFirmwareUpdateProgress(int deviceType, int progress, int firmwareUpdateState);
};

#endif // FIRMWAREUPDATEMESSAGEDIALOG_H
