#ifndef ERRORMESSAGEDIALOG_H
#define ERRORMESSAGEDIALOG_H

#include "errorwidget.h"
#include "messagedialog.h"

namespace Ui {
class ErrorMessageDialog;
}

class ErrorMessageDialog : public MessageDialog
{
    Q_OBJECT

public:
    explicit ErrorMessageDialog(QWidget *parent = nullptr);
    ~ErrorMessageDialog();
    void setMessage(const QString & message);

private:
    ErrorWidget * errorWidget = nullptr;
};

#endif // ERRORMESSAGEDIALOG_H
