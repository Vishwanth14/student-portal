#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

class Settings {
private:
    std::string themeMode;   // e.g., "Dark", "Light"
    int volumeLevel;         // Range: 0 to 100
    bool notificationsEnabled;

public:
    // Constructor to set default application states
    Settings();

    // Configuration modifiers
    void setTheme(const std::string& newTheme);
    void setVolume(int newVolume);
    void toggleNotifications();

    // Output status summary
    void printConfiguration() const;
};

#endif // SETTINGS_H
