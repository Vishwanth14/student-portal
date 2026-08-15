#include "settings.h"
#include <iostream>

using namespace std;

// Updated constructor tracking state variables
Settings::Settings() : themeMode("Dark"), volumeLevel(70), notificationsEnabled(true), systemLanguage("English"), powerSaverEnabled(false) {}

void Settings::setTheme(const string& newTheme) {
    if (powerSaverEnabled && newTheme != "Dark") {
        cout << "[Warning] Cannot change theme. Dark mode is locked while Power Saver is active." << endl;
        return;
    }
    themeMode = newTheme;
    cout << "[System] Theme preference changed to: " << themeMode << endl;
}

void Settings::setVolume(int newVolume) {
    if (newVolume < 0) volumeLevel = 0;
    else if (newVolume > 100) volumeLevel = 100;
    else volumeLevel = newVolume;
    
    // Limits max volume ceiling while running structural safe power state
    if (powerSaverEnabled && volumeLevel > 30) {
        volumeLevel = 30;
        cout << "[System] Volume restricted to 30% due to active Power Saver profile." << endl;
    } else {
        cout << "[System] Audio feedback volume scale set to: " << volumeLevel << "%" << endl;
    }
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
    systemLanguage = "English";
    powerSaverEnabled = false;
    cout << "[System] Factory reset applied. All preferences restored to default state." << endl;
}

void Settings::setLanguage(const string& newLanguage) {
    if (newLanguage == "English" || newLanguage == "Spanish" || newLanguage == "French" || newLanguage == "German") {
        systemLanguage = newLanguage;
        cout << "[System] Display interface translation loaded: " << systemLanguage << endl;
    } else {
        cout << "[Error] Translation pack for '" << newLanguage << "' is currently unavailable." << endl;
    }
}

// Added Power Saving Mode Toggle Feature: Automatically alters layout bounds to save energy
void Settings::togglePowerSaver() {
    powerSaverEnabled = !powerSaverEnabled;
    cout << "[System] Hardware Power Saving optimization profile turned " 
         << (powerSaverEnabled ? "ENABLED" : "DISABLED") << endl;
         
    if (powerSaverEnabled) {
        themeMode = "Dark"; // Overrides current setup to low power color matrix
        if (volumeLevel > 30) {
            volumeLevel = 30; // Caps audio consumption limits
        }
        cout << "[System] Settings dynamically restricted to conserve battery life." << endl;
    }
}

void Settings::printConfiguration() const {
    cout << "\n=====================================" << endl;
    cout << "      APPLICATION SETTINGS MANAGER   " << endl;
    cout << "=====================================" << endl;
    cout << "Power Saving Mode:     " << (powerSaverEnabled ? "ON 🔋" : "OFF 🔌") << endl; // Added tracking line
    cout << "Display Interface Lang: " << systemLanguage << endl;
    cout << "Current Theme:         " << themeMode << endl;
    cout << "Audio Volume Level:    " << volumeLevel << "%" << endl;
    cout << "Push Notifications:    " << (notificationsEnabled ? "Enabled 🔔" : "Disabled 🔕") << endl;
    cout << "=====================================" << endl;
}



