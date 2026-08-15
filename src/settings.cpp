#include "settings.h"
#include <iostream>

using namespace std;

// Updated default setup state to include default language tracking variable
Settings::Settings() : themeMode("Dark"), volumeLevel(70), notificationsEnabled(true), systemLanguage("English") {}

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

void Settings::factoryReset() {
    themeMode = "Dark";
    volumeLevel = 70;
    notificationsEnabled = true;
    systemLanguage = "English"; // Resets language value back to base
    cout << "[System] Factory reset applied. All preferences restored to default state." << endl;
}

// Added Language Selection Feature: Safely updates display language translations
void Settings::setLanguage(const string& newLanguage) {
    if (newLanguage == "English" || newLanguage == "Spanish" || newLanguage == "French" || newLanguage == "German") {
        systemLanguage = newLanguage;
        cout << "[System] Display interface translation loaded: " << systemLanguage << endl;
    } else {
        cout << "[Error] Translation pack for '" << newLanguage << "' is currently unavailable." << endl;
    }
}

void Settings::printConfiguration() const {
    cout << "\n=====================================" << endl;
    cout << "      APPLICATION SETTINGS MANAGER   " << endl;
    cout << "=====================================" << endl;
    cout << "Display Interface Lang: " << systemLanguage << endl; // Added string output line
    cout << "Current Theme:         " << themeMode << endl;
    cout << "Audio Volume Level:    " << volumeLevel << "%" << endl;
    cout << "Push Notifications:    " << (notificationsEnabled ? "Enabled 🔔" : "Disabled 🔕") << endl;
    cout << "=====================================" << endl;
}


