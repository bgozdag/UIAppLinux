#include "spinnerwidget.h"
#include <QtQuick>

// This is not transparent due to setClearColor problems messing with image glow colors...
SpinnerWidget::SpinnerWidget(QWidget * parent) : QQuickWidget(parent)
{
    setSource(QUrl("qrc:/assets/qml/Spinner.qml"));
    setResizeMode(QQuickWidget::SizeViewToRootObject);
    this->setAttribute(Qt::WA_TranslucentBackground);
    connect(this, SIGNAL(setSourceSignal(QString)), rootObject(), SIGNAL(setSourceSignal(QString)));
}

void SpinnerWidget::setSpinnerSource(QString src)
{
    emit setSourceSignal(src);
}


