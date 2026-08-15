#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <string>
#include <vector>
#include "profile.h" // Includes your existing UserProfile class

class Dashboard {
private:
    std::vector<std::string> systemLogs;
    int totalVisits;

public:
    // Constructor initializes metrics
    Dashboard();

    // Adds system audit actions
    void logActivity(const std::string& action);

    // Prints out administrative analytics
    void displayMetrics(int totalRegisteredUsers) const;
};

#endif // DASHBOARD_H
