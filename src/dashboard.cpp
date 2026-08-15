#include "dashboard.h"
#include <iostream>

using namespace std;

// Constructor sets starting metric totals
Dashboard::Dashboard() : totalVisits(0) {}

// Tracks system activity inside memory vectors
void Dashboard::logActivity(const string& action) {
    systemLogs.push_back(action);
    totalVisits++; // Increments visit hit count every time action logs
}

// Renders full system stats panel dashboard analytics
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
        // Prints recent logged actions
        for (const auto& log : systemLogs) {
            cout << "  - " << log << endl;
        }
    }
    cout << "=====================================" << endl;
}
