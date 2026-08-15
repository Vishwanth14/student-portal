#include "dashboard.h"
#include <iostream>

using namespace std;

Dashboard::Dashboard() : totalVisits(0), adminPassword("secure123") {}

bool Dashboard::authenticate(const string& inputPass) {
    if (inputPass == adminPassword) {
        logActivity("Admin successfully authenticated.");
        return true;
    }
    logActivity("Failed authentication attempt blocked.");
    return false;
}

void Dashboard::logActivity(const string& action) {
    systemLogs.push_back(action);
    totalVisits++;

    // Added Auto-Archive Feature: Keeps system logs from eating up memory
    if (systemLogs.size() > 5) {
        systemLogs.erase(systemLogs.begin()); // Removes oldest entry
    }
}

void Dashboard::displayMetrics(int totalRegisteredUsers) const {
    cout << "\n=====================================" << endl;
    cout << "      SYSTEM METRICS DASHBOARD       " << endl;
    cout << "=====================================" << endl;
    cout << "Total Platform Registered Users: " << totalRegisteredUsers << endl;
    cout << "Total Dashboard Active Hits:     " << totalVisits << endl;
    cout << "Recent System Logs Block:        " << endl;

    if (systemLogs.empty()) {
        cout << "  [No recent activity logs recorded]" << endl;
    } else {
        for (const auto& log : systemLogs) {
            cout << "  - " << log << endl;
        }
    }
    cout << "=====================================" << endl;
}

