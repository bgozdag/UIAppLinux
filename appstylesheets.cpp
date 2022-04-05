#include "appstylesheets.h"

#include <QFile>
#include <QDebug>

const std::string AppStyleSheets::CHARGER_ITEM_REGULAR = "/stylesheets/charger_item_regular.qss";
const std::string AppStyleSheets::CHARGER_ITEM_CHARGING = "/stylesheets/charger_item_charging.qss";
const std::string AppStyleSheets::PREPARING_CHARGING_ITEM = "/stylesheets/preparing_charging_item.qss";
const std::string AppStyleSheets::ERROR_MESSAGE_DIALOG = "/stylesheets/error_message_dialog.qss";
const std::string AppStyleSheets::WARNING_MESSAGE_DIALOG = "/stylesheets/warning_message_dialog.qss";
const std::string AppStyleSheets::STOP_CHARGING_ITEM = "/stylesheets/stop_charging_item.qss";
const std::string AppStyleSheets::STOP_CHARGING_ACTIVE_ITEM = "/stylesheets/stop_charging_active_item.qss";
const std::string AppStyleSheets::VEHICLE_AND_STATION_ITEM = "/stylesheets/vehicle_and_station_widget.qss";
const std::string AppStyleSheets::INNER_SCREEN = "/stylesheets/inner_screen.qss";
const std::string AppStyleSheets::INNER_SCREEN_NOTIFICATION_OUT_OF_ORDER = "/stylesheets/inner_screen_notification_outoforder.qss";
const std::string AppStyleSheets::INNER_SCREEN_NOTIFICATION_RESERVED = "/stylesheets/inner_screen_notification_reserved.qss";
const std::string AppStyleSheets::CHARGING_SCREEN = "/stylesheets/charging_screen.qss";
const std::string AppStyleSheets::CONNECTION_SCREEN = "/stylesheets/connection_screen.qss";
const std::string AppStyleSheets::EVC05_CHARGER_ITEM_REGULAR_LEFT = "/stylesheets/evc05_charger_item_left.qss";
const std::string AppStyleSheets::EVC05_CHARGER_ITEM_REGULAR_RIGHT = "/stylesheets/evc05_charger_item_right.qss";
const std::string AppStyleSheets::EVC05_CHARGER_ITEM_CHARGING_LEFT = "/stylesheets/evc05_charger_item_charging_left.qss";
const std::string AppStyleSheets::EVC05_CHARGER_ITEM_CHARGING_RIGHT = "/stylesheets/evc05_charger_item_charging_right.qss";
const std::string AppStyleSheets::EVC05_OUT_OF_ORDER = "/stylesheets/evc05_out_of_order.qss";
const std::string AppStyleSheets::EVC05_OUT_OF_ORDER_RIGHT = "/stylesheets/evc05_out_of_order_right.qss";
const std::string AppStyleSheets::LANGUAGES = "/stylesheets/languages.qss";
const std::string AppStyleSheets::SPINNER_MESSAGE_WIDGET = "/stylesheets/spinner_message_widget.qss";
const std::string AppStyleSheets::CANCEL_CHARGING_ITEM = "/stylesheets/cancel_charging_item.qss";
const std::string AppStyleSheets::INITIALIZING_PROGRESS_BAR_ITEM = "/stylesheets/initializing_progress_bar.qss";
const std::string AppStyleSheets::EMERGENCY_BUTTON_DIALOG = "/stylesheets/emergency_button_dialog.qss";

AppStyleSheets* AppStyleSheets::instance = new AppStyleSheets();

AppStyleSheets::AppStyleSheets()
{

}

AppStyleSheets* AppStyleSheets::getInstance()
{
    return instance;
}

std::string AppStyleSheets::getStylesheet(std::string stylesheetKey)
{
    return AppStyleSheets::stylesheetMap[stylesheetKey];
}

void AppStyleSheets::loadStylesheets(QString brand)
{
    AppStyleSheets::stylesheetMap[CHARGER_ITEM_REGULAR] = AppStyleSheets::getStylesheetFromResource(brand, CHARGER_ITEM_REGULAR.c_str());
    AppStyleSheets::stylesheetMap[CHARGER_ITEM_CHARGING] = AppStyleSheets::getStylesheetFromResource(brand, CHARGER_ITEM_CHARGING.c_str());
    AppStyleSheets::stylesheetMap[PREPARING_CHARGING_ITEM] = AppStyleSheets::getStylesheetFromResource(brand, PREPARING_CHARGING_ITEM.c_str());
    AppStyleSheets::stylesheetMap[ERROR_MESSAGE_DIALOG] = AppStyleSheets::getStylesheetFromResource(brand, ERROR_MESSAGE_DIALOG.c_str());
    AppStyleSheets::stylesheetMap[WARNING_MESSAGE_DIALOG] = AppStyleSheets::getStylesheetFromResource(brand, WARNING_MESSAGE_DIALOG.c_str());
    AppStyleSheets::stylesheetMap[STOP_CHARGING_ITEM] = AppStyleSheets::getStylesheetFromResource(brand, STOP_CHARGING_ITEM.c_str());
    AppStyleSheets::stylesheetMap[STOP_CHARGING_ACTIVE_ITEM] = AppStyleSheets::getStylesheetFromResource(brand, STOP_CHARGING_ACTIVE_ITEM.c_str());
    AppStyleSheets::stylesheetMap[VEHICLE_AND_STATION_ITEM] = AppStyleSheets::getStylesheetFromResource(brand, VEHICLE_AND_STATION_ITEM.c_str());
    AppStyleSheets::stylesheetMap[INNER_SCREEN] = AppStyleSheets::getStylesheetFromResource(brand, INNER_SCREEN.c_str());
    AppStyleSheets::stylesheetMap[INNER_SCREEN_NOTIFICATION_OUT_OF_ORDER] = AppStyleSheets::getStylesheetFromResource(brand, INNER_SCREEN_NOTIFICATION_OUT_OF_ORDER.c_str());
    AppStyleSheets::stylesheetMap[INNER_SCREEN_NOTIFICATION_RESERVED] = AppStyleSheets::getStylesheetFromResource(brand, INNER_SCREEN_NOTIFICATION_RESERVED.c_str());
    AppStyleSheets::stylesheetMap[CHARGING_SCREEN] = AppStyleSheets::getStylesheetFromResource(brand, CHARGING_SCREEN.c_str());
    AppStyleSheets::stylesheetMap[CONNECTION_SCREEN] = AppStyleSheets::getStylesheetFromResource(brand, CONNECTION_SCREEN.c_str());
    AppStyleSheets::stylesheetMap[EVC05_CHARGER_ITEM_REGULAR_LEFT] = AppStyleSheets::getStylesheetFromResource(brand, EVC05_CHARGER_ITEM_REGULAR_LEFT.c_str());
    AppStyleSheets::stylesheetMap[EVC05_CHARGER_ITEM_REGULAR_RIGHT] = AppStyleSheets::getStylesheetFromResource(brand, EVC05_CHARGER_ITEM_REGULAR_RIGHT.c_str());
    AppStyleSheets::stylesheetMap[EVC05_CHARGER_ITEM_CHARGING_LEFT] = AppStyleSheets::getStylesheetFromResource(brand, EVC05_CHARGER_ITEM_CHARGING_LEFT.c_str());
    AppStyleSheets::stylesheetMap[EVC05_CHARGER_ITEM_CHARGING_RIGHT] = AppStyleSheets::getStylesheetFromResource(brand, EVC05_CHARGER_ITEM_CHARGING_RIGHT.c_str());
    AppStyleSheets::stylesheetMap[EVC05_OUT_OF_ORDER] = AppStyleSheets::getStylesheetFromResource(brand, EVC05_OUT_OF_ORDER.c_str());
    AppStyleSheets::stylesheetMap[EVC05_OUT_OF_ORDER_RIGHT] = AppStyleSheets::getStylesheetFromResource(brand, EVC05_OUT_OF_ORDER_RIGHT.c_str());
    AppStyleSheets::stylesheetMap[LANGUAGES] = AppStyleSheets::getStylesheetFromResource(brand, LANGUAGES.c_str());
    AppStyleSheets::stylesheetMap[SPINNER_MESSAGE_WIDGET] = AppStyleSheets::getStylesheetFromResource(brand, SPINNER_MESSAGE_WIDGET.c_str());
    AppStyleSheets::stylesheetMap[CANCEL_CHARGING_ITEM] = AppStyleSheets::getStylesheetFromResource(brand, CANCEL_CHARGING_ITEM.c_str());
    AppStyleSheets::stylesheetMap[INITIALIZING_PROGRESS_BAR_ITEM] = AppStyleSheets::getStylesheetFromResource(brand, INITIALIZING_PROGRESS_BAR_ITEM.c_str());
    AppStyleSheets::stylesheetMap[EMERGENCY_BUTTON_DIALOG] = AppStyleSheets::getStylesheetFromResource(brand, EMERGENCY_BUTTON_DIALOG.c_str());
}

std::string AppStyleSheets::getStylesheetFromResource(QString brand, const char * qssFile)
{
    QString file = ":/assets/"+ brand + qssFile;
    qDebug() << "loaded" << file;
    QFile stylesheetFile(file.toStdString().c_str());
    if (!stylesheetFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open the stylesheet resource " << qssFile;
        return std::string();
    }
    QString stylesheetString = QLatin1String(stylesheetFile.readAll());
    stylesheetFile.close();
    return stylesheetString.toStdString();
}
