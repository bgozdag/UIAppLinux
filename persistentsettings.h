#ifndef PERSISTENTSETTINGS_H
#define PERSISTENTSETTINGS_H

#include <QSettings>

class PersistentSettings
{
public:
    PersistentSettings(QString pathOfSettingConfFile);

    void setInt(QString key, unsigned int valueToSave);
    int getInt(QString key);
    bool isKeyExist(QString key);

private:
    QSettings settings;
    QString pathOfSettingConfFile;
};

#endif // PERSISTENTSETTINGS_H
