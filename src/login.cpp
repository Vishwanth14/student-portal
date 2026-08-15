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

    // Check specific credentials and print exact error messages
    if (username != "admin") {
        cout << "Login Error: Invalid username.\n";
        return false;
    }
    if (password != "pass123") {
        cout << "Login Error: Invalid password.\n";
        return false;
    }

    return true;
}

int main() {
    if (checkLogin()) {
        cout << "Auth Status: SUCCESS. Access Granted!\n";
    } else {
        cout << "Auth Status: FAILED. Access Denied!\n";
    }
    return 0;
}




