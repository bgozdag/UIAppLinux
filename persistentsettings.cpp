#include "persistentsettings.h"

PersistentSettings::PersistentSettings(QString pathOfSettingConfFile)
{
    this->pathOfSettingConfFile = pathOfSettingConfFile;
}

void PersistentSettings::setInt(QString key, unsigned int valueToSave)
{
    QSettings settings(pathOfSettingConfFile, QSettings::NativeFormat, Q_NULLPTR);
    settings.setValue(key, valueToSave);
}

int PersistentSettings::getInt(QString key)
{
    QSettings settings(pathOfSettingConfFile, QSettings::NativeFormat, Q_NULLPTR);
    return settings.value(key).toInt();
}

bool PersistentSettings::isKeyExist(QString key)
{
    QSettings settings(pathOfSettingConfFile, QSettings::NativeFormat, Q_NULLPTR);
    if (settings.contains(key))
    {
        return true;
    }
    return false;
}
