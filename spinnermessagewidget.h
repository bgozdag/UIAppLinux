#ifndef SPINNERMESSAGEWIDGET_H
#define SPINNERMESSAGEWIDGET_H

#include <QWidget>
#include <languages/generated/translationstring.h>
#include "spinnerwidget.h"

namespace Ui {
class SpinnerMessageWidget;
}

class SpinnerMessageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SpinnerMessageWidget(QWidget *parent = nullptr);
    ~SpinnerMessageWidget();
    void setMessage(const TranslationString);
    void setMessage(const char* text);
    void addWidgetToSpinnerMessageContainer(QWidget * widget, int stretch, Qt::Alignment alignment);

private:
    Ui::SpinnerMessageWidget *ui;
    const std::string SPINNER_SRC = "qrc:/assets/images/spinner.png";
};

#endif // SPINNERMESSAGEWIDGET_H
