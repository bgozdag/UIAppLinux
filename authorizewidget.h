#ifndef AUTHORIZEWIDGET_H
#define AUTHORIZEWIDGET_H

#include <QWidget>
#include <languages/generated/appstrings.h>

namespace Ui {
class AuthorizeWidget;
}

class AuthorizeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AuthorizeWidget(QWidget *parent = nullptr);
    ~AuthorizeWidget();
    void hideAlternativeAuthorization(bool);
    void setAlternativeAuthorizationIcon(std::string stylesheet);
    void setAlternativeAuthorizationText(TranslationString alternativeAuthorizationText);
    void setQrData(std::string qrData);
    void onLanguageChanged();
    void setupBrand(QString brand);

private:
    Ui::AuthorizeWidget *ui;
    TranslationString alternativeAuthorizationText;
    std::string qrData;
};

#endif // AUTHORIZEWIDGET_H
