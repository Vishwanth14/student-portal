#include "settings.h"
#include <iostream>

using namespace std;

// Constructor initializes system defaults
Settings::Settings() : themeMode("Dark"), volumeLevel(70), notificationsEnabled(true) {}

// Updates the display theme profile choice
void Settings::setTheme(const string& newTheme) {
    themeMode = newTheme;
    cout << "[System] Theme preference changed to: " << themeMode << endl;
}

// Adjusts audio amplitude mixing values safely within range constraints
void Settings::setVolume(int newVolume) {
    if (newVolume < 0) volumeLevel = 0;
    else if (newVolume > 100) volumeLevel = 100;
    else volumeLevel = newVolume;
    
    cout << "[System] Audio feedback volume scale set to: " << volumeLevel << "%" << endl;
}

// Switches notification alerts flag state
void Settings::toggleNotifications() {
    notificationsEnabled = !notificationsEnabled;
    cout << "[System] Global alert notifications turned " 
         << (notificationsEnabled ? "ON" : "OFF") << endl;
}

// Outputs current configurations to the display terminal layout panel
void Settings::printConfiguration() const {
    cout << "\n=====================================" << endl;
    cout << "      APPLICATION SETTINGS MANAGER   " << endl;
    cout << "=====================================" << endl;
    cout << "Current Theme:         " << themeMode << endl;
    cout << "Audio Volume Level:    " << volumeLevel << "%" << endl;
    cout << "Push Notifications:    " << (notificationsEnabled ? "Enabled 🔔" : "Disabled 🔕") << endl;
    cout << "=====================================" << endl;
}
