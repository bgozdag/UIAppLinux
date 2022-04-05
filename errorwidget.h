#ifndef ERRORWIDGET_H
#define ERRORWIDGET_H

#include <QWidget>

namespace Ui {
class ErrorWidget;
}

class ErrorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ErrorWidget(QWidget * parent = nullptr);
    ~ErrorWidget();
    void setMessage(const QString & message);
    void setIcon(const std::string & styleSheetKey);

private:
    Ui::ErrorWidget *ui;
};

#endif // ERRORWIDGET_H
