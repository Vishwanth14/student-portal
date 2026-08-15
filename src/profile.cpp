#include "profile.h"
#include <iostream>

using namespace std;

class UserProfile {
private:
    bool isPrivate = false;
    string githubHandle = "";
    string twitterHandle = "";

public:
    void setPrivacy(bool privacySetting) {
        isPrivate = privacySetting;
    }

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
            return;
        }

        cout << "Status: Active Member" << endl;

        if (!githubHandle.empty() || !twitterHandle.empty()) {
            cout << "--- Connections ---" << endl;
            if (!githubHandle.empty()) cout << "GitHub: ://github.com" << githubHandle << endl;
            if (!twitterHandle.empty()) cout << "Twitter: @" << twitterHandle << endl;
        }

        // Calculate profile completion score based on filled fields
        int profileStrength = 40; // Base score for username
        if (!githubHandle.empty()) profileStrength += 30;
        if (!twitterHandle.empty()) profileStrength += 30;

        // Render visual bar metric
        cout << "Profile Completeness: " << profileStrength << "% [";
        for (int i = 0; i < 10; ++i) {
            if (i < (profileStrength / 10)) cout << "■";
            else cout << " ";
        }
        cout << "]" << endl;

        cout << "====================" << endl;
    }
};




