#ifndef UIUTILS_H
#define UIUTILS_H

#include <qwidget.h>
#include <string>
#include <qlabel.h>
#include <fstream>

class UIUtils {
public:
    static void setStyleSheetAndUpdate(QWidget * widget, QString stylesheet);
    static void updateStyleSheet(QWidget * widget, QString stylesheet);
    static void setMarginTop(int top, QWidget * widget);
    static void setMarginLeft(int left, QWidget * widget);
    static QString getStyleSheetForType(const std::string& typeCode, const std::string& styleSheetString);
    static QString getStyleSheetForBootStepWidthOfInitializingProgressBar(const std::string& bootStepWidth,
                                                                          const std::string& borderThicknessOfProgressBar,
                                                                          const std::string& marginBetweenBootSteps,
                                                                          const std::string& styleSheetString);
    static QString getStyleSheetForProjectAndChargerType(const std::string& projectTypeCode, const std::string& chargerTypeCode, const std::string& styleSheetString);
    static void paintQR(QPainter &painter, const QSize containerSize, const QSize sz, const QString &data, QColor fg);
    static void setTextElided(QLabel* label, const std::string& text);
    static void setTextWithLineSpace(QLabel* label, const std::string& text, double lineSpacing);
    static QString getProjectType();

private:
    static void forceWidgetToUseStyleSheet(QWidget * widget);
};

#endif // UIUTILS_H
