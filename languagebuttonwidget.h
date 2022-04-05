#ifndef LANGWIDGET_H
#define LANGWIDGET_H

#include "clickableqwidget.h"
#include "languagemanager.h"

class LanguageButtonWidget : public ClickableQWidget
{
    Q_OBJECT

public:
    explicit LanguageButtonWidget(Language language, QWidget * parent = nullptr);
    ~LanguageButtonWidget();
    QWidget * getLanguageButtonContainer();
    void mouseReleaseEvent (QMouseEvent * event) override;

private:
    QWidget * language_button_container;
    Language language;

signals:
    void onClickedLanguageSignal(Language, bool);
};

#endif // LANGWIDGET_H
