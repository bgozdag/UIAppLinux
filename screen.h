#ifndef SCREEN_H
#define SCREEN_H

class MainWindow;
#include <qwidget.h>

class Screen : public QWidget
{
    Q_OBJECT

public:
    Screen(QWidget *parent);
    virtual ~Screen();
    virtual void setupUi(MainWindow * mainWindow) = 0;
    virtual void setupBrand(QString brand) = 0;

public slots:
    virtual void onLanguageChanged() = 0;
};

#endif // SCREEN_H
