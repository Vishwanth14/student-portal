#include "profile.h"
#include <iostream>

using namespace std;

// Added an isPremium boolean check
void UserProfile::display(string username, string status, bool isPremium) {
    cout << "\n=== USER PROFILE ===" << endl;
    cout << "Username: " << username;
    if (isPremium) {
        cout << " [✔ Verified Premium]"; // Added verification badge
    }
    cout << endl;
    cout << "Status: " << status << endl;
    cout << "Joined: January 2026" << endl;
    cout << "Bio: Coding enthusiast building cool projects." << endl;
    cout << "====================" << endl;
}

