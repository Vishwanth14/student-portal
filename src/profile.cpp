#include "profile.h"
#include <iostream>

using namespace std;

// Class definition to track internal profile states cleanly
class UserProfile {
private:
    bool isPrivate = false; // Controls visibility of the profile details

public:
    void setPrivacy(bool privacySetting) {
        isPrivate = privacySetting;
    }

    void display(string username) {
        cout << "\n=== USER PROFILE ===" << endl;
        cout << "Username: " << username << endl;
        
        if (isPrivate) {
            cout << "Status: [Hidden - Private Profile]" << endl;
            cout << "====================" << endl;
            return; // Stops rendering early for user privacy
        }

        cout << "Status: Active Member" << endl;
        cout << "====================" << endl;
    }
};


