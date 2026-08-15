#include "profile.h"
#include <iostream>

using namespace std;

void UserProfile::display(string username) {
    cout << "\n=== USER PROFILE ===" << endl;
    cout << "Username: " << username << endl;
    cout << "Status: Active Member" << endl;
    cout << "====================" << endl;
}
