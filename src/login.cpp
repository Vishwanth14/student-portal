#include <iostream>
#include <string>

using namespace std;

bool checkLogin() {
    string username, password;

    cout << "Enter Username: ";
    cin >> username;

    if (username.length() < 4) {
        cout << "Error: Username too short (min 4 chars).\n";
        return false;
    }

    cout << "Enter Password: ";
    cin >> password;

    // Validation: Check if password length is less than 6
    if (password.length() < 6) {
        cout << "Error: Password too short (min 6 chars).\n";
        return false;
    }

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


