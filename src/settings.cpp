#include "settings.h"
#include <iostream>

using namespace std;

Settings::Settings() : themeMode("Dark"), volumeLevel(70), notificationsEnabled(true) {}

void Settings::setTheme(const string& newTheme) {
    themeMode = newTheme;
    cout << "[System] Theme preference changed to: " << themeMode << endl;
}

void Settings::setVolume(int newVolume) {
    if (newVolume < 0) volumeLevel = 0;
    else if (newVolume > 100) volumeLevel = 100;
    else volumeLevel = newVolume;
    
    cout << "[System] Audio feedback volume scale set to: " << volumeLevel << "%" << endl;
}

void Settings::toggleNotifications() {
    notificationsEnabled = !notificationsEnabled;
    cout << "[System] Global alert notifications turned " 
         << (notificationsEnabled ? "ON" : "OFF") << endl;
}

// Added Factory Reset Feature: Restores all variables back to factory defaults
void Settings::factoryReset() {
    themeMode = "Dark";
    volumeLevel = 70;
    notificationsEnabled = true;
    cout << "[System] Factory reset applied. All preferences restored to default state." << endl;
}

void Settings::printConfiguration() const {
    cout << "\n=====================================" << endl;
    cout << "      APPLICATION SETTINGS MANAGER   " << endl;
    cout << "=====================================" << endl;
    cout << "Current Theme:         " << themeMode << endl;
    cout << "Audio Volume Level:    " << volumeLevel << "%" << endl;
    cout << "Push Notifications:    " << (notificationsEnabled ? "Enabled 🔔" : "Disabled 🔕") << endl;
    cout << "=====================================" << endl;
}

