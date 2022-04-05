#ifndef EMERGENCYBUTTONDIALOGWIDGET_H
#define EMERGENCYBUTTONDIALOGWIDGET_H

#include <QWidget>

namespace Ui {
class EmergencyButtonDialogWidget;
}

class EmergencyButtonDialogWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EmergencyButtonDialogWidget(QWidget * parent = nullptr);
    ~EmergencyButtonDialogWidget();
    void setHeader(const QString& header);
    void setMessage(const QString & message);

private:
    Ui::EmergencyButtonDialogWidget *ui;
};


#endif // EMERGENCYBUTTONDIALOGWIDGET_H
