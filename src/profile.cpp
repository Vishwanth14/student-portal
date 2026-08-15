#include "profile.h"
#include <iostream>

using namespace std;

void UserProfile::display(string username, string status, bool isPremium) {
    int profileViews = 142; // Added basic view counter variable
    
    cout << "\n=== USER PROFILE ===" << endl;
    cout << "Username: " << username;
    if (isPremium) { cout << " [✔ Verified Premium]"; }
    cout << endl;
    cout << "Status: " << status << endl;
    cout << "Joined: January 2026" << endl;
    cout << "Bio: Coding enthusiast building cool projects." << endl;
    cout << "Profile Views: " << profileViews << endl; // Display views counter
    cout << "====================" << endl;
}


