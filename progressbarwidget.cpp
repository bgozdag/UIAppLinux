#include "progressbarwidget.h"
#include <QtQuick>

ProgressBarWidget::ProgressBarWidget(QWidget *parent) : QQuickWidget(parent)
{
    setSource(QUrl("qrc:/assets/qml/ProgressBar.qml"));
    setResizeMode(QQuickWidget::SizeViewToRootObject);
    this->setAttribute(Qt::WA_TranslucentBackground); // Does not seem to work, background is still white.
    connect(this, SIGNAL(progressSignal(int)), rootObject(), SIGNAL(progressSignal(int)));
    connect(this, SIGNAL(setIndeterminateSignal(bool)), rootObject(), SIGNAL(setIndeterminateSignal(bool)));
    connect(this, SIGNAL(setSizeSignal(int, int)), rootObject(), SIGNAL(setSizeSignal(int, int)));
}

void ProgressBarWidget::setIndeterminate(bool indeterminate)
{
    // This hack is needed, since SizeViewToRootObject causes progress bar to flicker when it's indeterminate and big.
    if (indeterminate) {
        setResizeMode(QQuickWidget::SizeRootObjectToView);
    } else {
        setResizeMode(QQuickWidget::SizeViewToRootObject);
    }
    emit setIndeterminateSignal(indeterminate);
}

void ProgressBarWidget::setProgress(unsigned int progress)
{
    emit progressSignal(progress);
}

void ProgressBarWidget::setSize(int height, int width)
{
    emit setSizeSignal(height, width);
}

void ProgressBarWidget::setGeometry(const QRect & rect)
{
    QQuickWidget::setGeometry(rect);
    setSize(height(), width());
}

void ProgressBarWidget::setSourceUrl(QUrl url)
{
    setSource(url);
}
