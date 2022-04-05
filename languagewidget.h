#ifndef LANGUAGEWIDGET_H
#define LANGUAGEWIDGET_H

#include <QWidget>
#include <qgridlayout.h>

namespace Ui {
class LanguageWidget;
}

class LanguageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LanguageWidget(QWidget *parent = nullptr);
    ~LanguageWidget();
    QGridLayout * getLanguageContainer();
    void setLanguageTitle(const QString & title);
    void setSoftwareVersions(const QString & softwareVersions);

private:
    Ui::LanguageWidget *ui;
};

#endif // LANGUAGEWIDGET_H
