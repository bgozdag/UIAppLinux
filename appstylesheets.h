#ifndef APPSTYLESHEETS_H
#define APPSTYLESHEETS_H
#include <iostream>
#include <unordered_map>
#include <QFile>

class AppStyleSheets
{
public:
    static AppStyleSheets* getInstance();
    AppStyleSheets(const AppStyleSheets& languageManager) = delete;
    AppStyleSheets& operator=(const AppStyleSheets& languageManager) = delete;
    std::string getStylesheet(std::string stylesheetKey);
    void loadStylesheets(QString brand="");

    static const std::string CHARGER_ITEM_REGULAR;
    static const std::string CHARGER_ITEM_CHARGING;
    static const std::string PREPARING_CHARGING_ITEM;
    static const std::string ERROR_MESSAGE_DIALOG;
    static const std::string WARNING_MESSAGE_DIALOG;
    static const std::string STOP_CHARGING_ITEM;
    static const std::string STOP_CHARGING_ACTIVE_ITEM;
    static const std::string VEHICLE_AND_STATION_ITEM;
    static const std::string INNER_SCREEN;
    static const std::string INNER_SCREEN_NOTIFICATION_OUT_OF_ORDER;
    static const std::string INNER_SCREEN_NOTIFICATION_RESERVED;
    static const std::string CHARGING_SCREEN;
    static const std::string CONNECTION_SCREEN;
    static const std::string EVC05_CHARGER_ITEM_REGULAR_LEFT;
    static const std::string EVC05_CHARGER_ITEM_REGULAR_RIGHT;
    static const std::string EVC05_CHARGER_ITEM_CHARGING_LEFT;
    static const std::string EVC05_CHARGER_ITEM_CHARGING_RIGHT;
    static const std::string EVC05_OUT_OF_ORDER;
    static const std::string EVC05_OUT_OF_ORDER_RIGHT;
    static const std::string LANGUAGES;
    static const std::string SPINNER_MESSAGE_WIDGET;
    static const std::string CANCEL_CHARGING_ITEM;
    static const std::string INITIALIZING_PROGRESS_BAR_ITEM;
    static const std::string EMERGENCY_BUTTON_DIALOG;

private:
    AppStyleSheets();
    static AppStyleSheets * instance;
    std::unordered_map<std::string, std::string> stylesheetMap;
    std::string getStylesheetFromResource(QString brand, const char * qssFile);
};

#endif // APPSTYLESHEETS_H
