#include <iostream>
#include <string>

using namespace std;

bool checkLogin() {
    string username, password;

    cout << "Enter Username: ";
    cin >> username;
    if (username.length() < 4) return false;

    cout << "Enter Password: ";
    cin >> password;
    if (password.length() < 6) return false;

    // Save and return the authentication result
    bool isSuccess = (username == "admin" && password == "pass123");
    return isSuccess;
}

int main() {
    // Store the final result
    bool isAuthenticated = checkLogin();

    if (isAuthenticated) {
        cout << "Auth Status: SUCCESS. Access Granted!\n";
    } else {
        cout << "Auth Status: FAILED. Access Denied!\n";
    }
    return 0;
}



