#include "authorizewidget.h"
#include "ui_authorizewidget.h"
#include "languages/generated/appstrings.h"
#include "qpainter.h"
#include "utils/headers/uiutils.h"
#include "dimensions.h"

AuthorizeWidget::AuthorizeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthorizeWidget),
    alternativeAuthorizationText(AppStrings::qr_code)
{
    ui->setupUi(this);
    onLanguageChanged();
}

AuthorizeWidget::~AuthorizeWidget()
{
    delete ui;
}

void AuthorizeWidget::hideAlternativeAuthorization(bool hideAlternativeAuthorization)
{
    ui->orText->setVisible(!hideAlternativeAuthorization);
    ui->qrContainer->setVisible(!hideAlternativeAuthorization);
}

void AuthorizeWidget::onLanguageChanged()
{
    ui->rfidText->setText(AppStrings::membership_card.getForLocale().c_str());
    ui->orText->setText(AppStrings::or_word.getForLocale().c_str());
    ui->qrText->setText(alternativeAuthorizationText.getForLocale().c_str());

    // Since qr code requires the size of the parent container, we need to force layout dimensions to update
    // after changing texts above because they're not immediately updated and added to the event loop instead.
    if (ui->qrContainer->isVisible()) {
        ui->qrContainer->hide();
        ui->qrContainer->show();
        setQrData(this->qrData);
    }
}

void AuthorizeWidget::setAlternativeAuthorizationText(TranslationString alternativeAuthorizationText)
{
    this->alternativeAuthorizationText = alternativeAuthorizationText;
    ui->qrText->setText(alternativeAuthorizationText.getForLocale().c_str());
}

void AuthorizeWidget::setAlternativeAuthorizationIcon(std::string stylesheet)
{
    ui->qrIcon->setStyleSheet(stylesheet.c_str());
}

void AuthorizeWidget::setQrData(std::string qrData)
{
    this->qrData = qrData;
    QPixmap map(ui->qrIcon->width(), ui->qrIcon->height());
    map.fill(QColor("transparent"));
    QPainter painter(&map);
    UIUtils::paintQR(painter, map.size(), QSize(Dimensions::QR_CODE_SIZE, Dimensions::QR_CODE_SIZE), qrData.c_str(), QColor("black"));
    ui->qrIcon->setPixmap(map);
    ui->qrIcon->setStyleSheet("background-image: url(:/assets/images/big_outer_circle.png); background-color: white;");
    ui->qrContainer->show();
}
