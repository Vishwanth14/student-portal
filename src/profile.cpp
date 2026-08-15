#include "profile.h"
#include <iostream>

using namespace std;

class UserProfile {
private:
    bool isPrivate = false; // Controls visibility of the profile details
    string githubHandle = ""; // Added fields to store social connections
    string twitterHandle = "";

public:
    void setPrivacy(bool privacySetting) {
        isPrivate = privacySetting;
    }

    // Method to store user social media handles
    void setSocials(string github, string twitter) {
        githubHandle = github;
        twitterHandle = twitter;
    }

    void display(string username) {
        cout << "\n=== USER PROFILE ===" << endl;
        cout << "Username: " << username << endl;
        
        if (isPrivate) {
            cout << "Status: [Hidden - Private Profile]" << endl;
            cout << "====================" << endl;
            return; // Stops rendering early to keep social links secure
        }

        cout << "Status: Active Member" << endl;

        // Displays connections section only if handles are provided
        if (!githubHandle.empty() || !twitterHandle.empty()) {
            cout << "--- Connections ---" << endl;
            if (!githubHandle.empty()) cout << "GitHub: ://github.com" << githubHandle << endl;
            if (!twitterHandle.empty()) cout << "Twitter: @" << twitterHandle << endl;
        }

        cout << "====================" << endl;
    }
};



