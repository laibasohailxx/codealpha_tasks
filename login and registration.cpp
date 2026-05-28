#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to check if username already exists
bool userExists(string username) {
    ifstream file(username + ".txt");

    if (file.is_open()) {
        file.close();
        return true;
    }

    return false;
}

// Registration Function
void registerUser() {

    string username, password;

    cout << "\n===== USER REGISTRATION =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Validation
    if (username.empty() || password.empty()) {
        cout << "Error: Username or Password cannot be empty.\n";
        return;
    }

    // Duplicate Username Check
    if (userExists(username)) {
        cout << "Error: Username already exists.\n";
        return;
    }

    // Store credentials in file
    ofstream file(username + ".txt");

    file << username << endl;
    file << password << endl;

    file.close();

    cout << "Registration Successful!\n";
}

// Login Function
void loginUser() {

    string username, password;
    string storedUsername, storedPassword;

    cout << "\n===== USER LOGIN =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Open user file
    ifstream file(username + ".txt");

    if (!file.is_open()) {
        cout << "Error: User does not exist.\n";
        return;
    }

    // Read stored credentials
    getline(file, storedUsername);
    getline(file, storedPassword);

    file.close();

    // Verify credentials
    if (username == storedUsername && password == storedPassword) {
        cout << "Login Successful! Welcome " << username << endl;
    }
    else {
        cout << "Error: Invalid Username or Password.\n";
    }
}

int main() {

    int choice;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Program Exited.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 3);

    return 0;
}
