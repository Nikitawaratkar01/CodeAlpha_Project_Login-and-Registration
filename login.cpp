#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool usernameExists(const string& username) {
    ifstream file(username + ".txt");
    return file.good();
}

void registerUser() {
    string username, password;
    
    cout << "Enter username: ";
    cin >> username;

    if (usernameExists(username)) {
        cout << "Username already exists. Try a different one.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file(username + ".txt");
    file << password;
    file.close();

    cout << "Registration successful!\n";
}

bool loginUser() {
    string username, password, storedPassword;
    
    cout << "Enter username: ";
    cin >> username;

    if (!usernameExists(username)) {
        cout << "Username does not exist.\n";
        return false;
    }

    cout << "Enter password: ";
    cin >> password;

    ifstream file(username + ".txt");
    getline(file, storedPassword);
    file.close();

    if (password == storedPassword) {
        cout << "Login Successful!\n";
        return true;
    } else {
        cout << "Incorrect password.\n";
        return false;
    }
}

int main() {
    int choice;
    
    cout << "1. Register\n2. Login\n";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        default:
            cout << "Invalid choice.\n";
            break;
    }

    return 0;
}
