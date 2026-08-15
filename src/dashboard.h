#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <string>
#include <vector>

class Dashboard {
private:
    std::vector<std::string> systemLogs;
    int totalVisits;
    std::string adminPassword; // Secure authentication credential storage

public:
    Dashboard();
    
    // Verifies administrator portal login credentials
    bool authenticate(const std::string& inputPass);
    
    void logActivity(const std::string& action);
    void displayMetrics(int totalRegisteredUsers) const;
};

#endif // DASHBOARD_H
