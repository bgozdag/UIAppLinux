#include "utils/headers/uiutils.h"
#include <qstyle.h>
#include <utils/headers/stringutils.h>
#include "qrcode.hpp"
#include <qpainter.h>

/*
    If the UI element already has a stylesheet, it needs to be manually redrawn
    using unpolish/polish methods. This function guarantees that applied styles
    will be automatically shown on UI.
*/
void UIUtils::setStyleSheetAndUpdate(QWidget * widget, QString stylesheet)
{
    widget->setStyleSheet(stylesheet);
}

void UIUtils::updateStyleSheet(QWidget * widget, QString stylesheet)
{
    QString currentStyleSheet = widget->styleSheet();
    widget->setStyleSheet(currentStyleSheet + stylesheet);
}

void UIUtils::setMarginTop(int top, QWidget *widget)
{
    widget->setGeometry(widget->x(), widget->y() + top, widget->width(), widget->height());
}

void UIUtils::setMarginLeft(int left, QWidget *widget)
{
    widget->setGeometry(widget->x() + left, widget->y(), widget->width(), widget->height());
}

// Recommended way of enforcing a top-level css to all widgets. Might slow things down and should be tested for performance.
// Not used due to poor performance.
void UIUtils::forceWidgetToUseStyleSheet(QWidget *widget)
{
    if (widget == nullptr) {
        return;
    }

    widget->style()->unpolish(widget);
    widget->style()->polish(widget);
    QList<QWidget*> children = widget->findChildren<QWidget *>();
    foreach(QWidget * childWidget, children) {
        forceWidgetToUseStyleSheet(childWidget);
    }
}

// TODO : Might be a good idea to replace the name of this function.
QString UIUtils::getStyleSheetForType(const std::string& typeCode, const std::string& styleSheetString)
{
    return QString(StringUtils::replaceAll(styleSheetString, "<charger_code>", typeCode).c_str());
}

QString UIUtils::getStyleSheetForBootStepWidthOfInitializingProgressBar(const std::string& bootStepWidth,
                                                                        const std::string& borderThicknessOfProgressBar,
                                                                        const std::string& marginBetweenBootSteps,
                                                                        const std::string& styleSheetString)
{
    return QString(StringUtils::replaceAll(
                       StringUtils::replaceAll(StringUtils::replaceAll(styleSheetString, "<boot_step_width>", bootStepWidth), "<border_thickness>", borderThicknessOfProgressBar),
                       "<margin_between_boot_steps>", marginBetweenBootSteps).c_str());
}

QString UIUtils::getStyleSheetForProjectAndChargerType(const std::string& projectTypeCode, const std::string& chargerTypeCode, const std::string& styleSheetString)
{
    return QString(StringUtils::replaceAll(StringUtils::replaceAll(styleSheetString, "<project_type>", projectTypeCode), "<charger_code>", chargerTypeCode).c_str());
}

void UIUtils::paintQR(QPainter &painter, const QSize containerSize, const QSize sz, const QString &data, QColor fg)
{
    qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(data.toUtf8().constData(), qrcodegen::QrCode::Ecc::HIGH);
    const int s = qr.getSize() > 0 ? qr.getSize() : 1;
    const double w = sz.width();
    const double h = sz.height();
    const double aspect = w / h;
    const double size = ((aspect > 1.0) ? h : w);
    const double scale = size / (s + 2);
    painter.setPen(Qt::NoPen);
    painter.setBrush(fg);

    // Calculate start margins to center QR code inside a container.
    const double yStart = (containerSize.height() - h) / (2);
    const double xStart = (containerSize.width() - w) / (2);

    for(int y = 0; y < s; y++) {
        for(int x = 0; x < s; x++) {
            const int color = qr.getModule(x, y);  // 0 for white, 1 for black
            if (color) {
                const double rx1 = (x + 1) * scale + xStart, ry1 = (y + 1) * scale + yStart;
                QRectF r(rx1, ry1, scale, scale);
                painter.drawRect(r);
            }
        }
    }
}

void UIUtils::setTextElided(QLabel* label, const std::string& text)
{
    QFontMetrics metrics(label->font());
    label->setText(metrics.elidedText(text.c_str(), Qt::ElideRight, label->width()));
}

void UIUtils::setTextWithLineSpace(QLabel* label, const std::string& text, double lineSpacing)
{
    label->setText("<p style=\"line-height:" + QString::number(lineSpacing) + "\">" + text.c_str() + "</p>");
}

QString UIUtils::getProjectType()
{
    std::ifstream file("/etc/os-release");
    if (file.is_open())
    {
        std::string line;
        while(std::getline(file,line))
        {
            if (line.find("RELEASE_VERSION") != std::string::npos){
                size_t startIndex = line.find(".") + 1;
                size_t endIndex = line.find(".", startIndex);
                switch (atoi(line.substr(startIndex, endIndex-startIndex).c_str())) {
                    case 0:
                        return QString("EVC05");
                    case 1:
                        return QString("EVC03");
                    case 2:
                        return QString("EVC10");
                }
            }
        }
        file.close();
    }
    return QString("");
}
