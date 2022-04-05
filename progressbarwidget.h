#ifndef PROGRESSBARWIDGET_H
#define PROGRESSBARWIDGET_H

#include <QWidget>
#include <qquickwidget.h>

class ProgressBarWidget : public QQuickWidget
{
    Q_OBJECT
public:
    explicit ProgressBarWidget(QWidget *parent = nullptr);
    void setIndeterminate(bool);
    void setProgress(unsigned int);
    void setSize(int, int);
    void setGeometry(const QRect &);

signals:
    void progressSignal(int);
    void setIndeterminateSignal(bool);
    void setSizeSignal(int, int);

public slots:
};

#endif // PROGRESSBARWIDGET_H
