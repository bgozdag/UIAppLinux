#ifndef SPINNERWIDGET_H
#define SPINNERWIDGET_H

#include <qquickwidget.h>
#include <QWidget>

class SpinnerWidget : public QQuickWidget
{
    Q_OBJECT
public:
    explicit SpinnerWidget(QWidget *parent = nullptr);
    void setSpinnerSource(QString);

signals:
    void setSourceSignal(QString);
};

#endif // SPINNERWIDGET_H
