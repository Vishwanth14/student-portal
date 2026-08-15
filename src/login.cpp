#include <iostream>
#include <string>

using namespace std;

bool checkLogin() {
    string username, password;

    cout << "Enter Username: ";
    cin >> username;

    // Validation: Check if length is less than 4
    if (username.length() < 4) {
        cout << "Error: Username must be at least 4 characters long.\n";
        return false;
    }

    cout << "Enter Password: ";
    cin >> password;

    return (username == "admin" && password == "pass123");
}

int main() {
    if (checkLogin()) {
        cout << "Access Granted!\n";
    } else {
        cout << "Access Denied!\n";
    }
    return 0;
}

