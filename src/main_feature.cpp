#include <iostream>
#include <string>
using namespace std;

int main() {
    string username;

    cout << "Enter username: ";
    getline(cin, username);

    if (username.empty()) {
        cout << "Username cannot be empty.\n";
        return 1;
    }

    cout << "Welcome, " << username << "!\n";
    cout << "Application started successfully.\n";

    return 0;
}