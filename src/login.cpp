#include <iostream>
#include <string>

using namespace std;

bool checkLogin() {
    string username, password;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Simple hardcoded check
    if (username == "admin" && password == "pass123") {
        return true;
    }
    
    return false;
}

int main() {
    cout << "=== Welcome ===" << endl;
    
    if (checkLogin()) {
        cout << "Access Granted!" << endl;
    } else {
        cout << "Access Denied!" << endl;
    }

    return 0;
}
