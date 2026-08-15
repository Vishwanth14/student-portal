#include "settings.h"
#include <iostream>

using namespace std;

// Updated constructor to track internal backup sync timestamps
Settings::Settings() : themeMode("Dark"), volumeLevel(70), notificationsEnabled(true), systemLanguage("English"), powerSaverEnabled(false), lastSyncTime("Never synced") {}

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
    lastSyncTime = "Never synced"; // Clear previous sync logs
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

void Settings::togglePowerSaver() {
    powerSaverEnabled = !powerSaverEnabled;
    cout << "[System] Hardware Power Saving optimization profile turned " 
         << (powerSaverEnabled ? "ENABLED" : "DISABLED") << endl;
         
    if (powerSaverEnabled) {
        themeMode = "Dark";
        if (volumeLevel > 30) {
            volumeLevel = 30;
        }
        cout << "[System] Settings dynamically restricted to conserve battery life." << endl;
    }
}

// Added Cloud Synchronisation Feature: Simulates pushing current configurations to external storage servers
void Settings::syncToCloud() {
    cout << "[System] Establishing connection to backup profile repository database..." << endl;
    cout << "[System] Encrypting structural local preferences configurations..." << endl;
    
    // Simulate real-time server response state updates
    lastSyncTime = "August 2026 (Successful Backup)";
    cout << "[System] Profile syncing completed. All operational settings securely stored online." << endl;
}

void Settings::printConfiguration() const {
    cout << "\n=====================================" << endl;
    cout << "      APPLICATION SETTINGS MANAGER   " << endl;
    cout << "=====================================" << endl;
    cout << "Cloud Profile Sync:    " << lastSyncTime << endl; // Added tracking output block line
    cout << "Power Saving Mode:     " << (powerSaverEnabled ? "ON 🔋" : "OFF 🔌") << endl;
    cout << "Display Interface Lang: " << systemLanguage << endl;
    cout << "Current Theme:         " << themeMode << endl;
    cout << "Audio Volume Level:    " << volumeLevel << "%" << endl;
    cout << "Push Notifications:    " << (notificationsEnabled ? "Enabled 🔔" : "Disabled 🔕") << endl;
    cout << "=====================================" << endl;
}




