#include "dashboard.h"
#include <iostream>

using namespace std;

Dashboard::Dashboard() : totalVisits(0), adminPassword("secure123") {}

bool Dashboard::authenticate(const string& inputPass) {
    if (inputPass == adminPassword) {
        logActivity("Admin successfully authenticated.");
        return true;
    }
    logActivity("CRITICAL: Failed authentication attempt blocked.");
    return false;
}

void Dashboard::logActivity(const string& action) {
    systemLogs.push_back(action);
    totalVisits++;

    if (systemLogs.size() > 5) {
        systemLogs.erase(systemLogs.begin());
    }
}

void Dashboard::displayMetrics(int totalRegisteredUsers) const {
    cout << "\n=====================================" << endl;
    cout << "      SYSTEM METRICS DASHBOARD       " << endl;
    cout << "=====================================" << endl;
    
    int criticalErrors = 0;
    for (const auto& log : systemLogs) {
        if (log.find("CRITICAL:") != string::npos) {
            criticalErrors++;
        }
    }
    cout << "System Status:                   ";
    if (criticalErrors >= 3) cout << "🚨 UNDER ATTACK / SECURE LOCKDOWN" << endl;
    else if (criticalErrors > 0) cout << "⚠️ WARNING (Check Logs)" << endl;
    else cout << "🟢 HEALTHY" << endl;

    // Added Peak Usage Tracker Feature
    cout << "Traffic Load Level:              ";
    if (totalVisits > 50) cout << "🔥 HIGH DEMAND SPIKE (Optimize)" << endl;
    else if (totalVisits > 20) cout << "⚡ MODERATE TRAFFIC" << endl;
    else cout << "🍃 LIGHT LOAD" << endl;

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


