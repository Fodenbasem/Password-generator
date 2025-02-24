#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

string generatePassword(const string& characters, int length) {
    string password;
    for (int i = 0; i < length; ++i) {
        password += characters[generateRandomNumber(0, characters.size() - 1)];
    }
    return password;
}

// Function to get user input (1 for Yes, 0 for No)
bool getInput(const string& prompt) {
    int input;
    cout << prompt;
    cin >> input;
    while (input != 1 && input != 0) {
        cout << "Error: Invalid input! Please enter 1 for Yes or 0 for No.\n";
        cout << prompt;
        cin >> input;
    }
    return input;
}

// Function to generate a custom password
void generateCustomPassword(const string& category) {
    bool includeNumbers = false, includeSymbols = false, includeLower = false, includeUpper = false;

    cout << "Please choose character types for your " << category << " password:\n";
    includeNumbers = getInput("Include numbers? (1: Yes, 0: No): ");
    includeSymbols = getInput("Include symbols? (1: Yes, 0: No): ");
    includeLower = getInput("Include lowercase letters? (1: Yes, 0: No): ");
    includeUpper = getInput("Include uppercase letters? (1: Yes, 0: No): ");

    const string numbers = "0123456789";
    const string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    const string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    const string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string allCharacters;
    int selectedOptions = 0;

    if (includeNumbers) { allCharacters += numbers; selectedOptions++; }
    if (includeSymbols) { allCharacters += symbols; selectedOptions++; }
    if (includeLower) { allCharacters += lowerCase; selectedOptions++; }
    if (includeUpper) { allCharacters += upperCase; selectedOptions++; }

    // Ensure at least three character types are selected
    while (selectedOptions < 3) {
        cout << "Error: You must select at least three character types!\n";
        includeNumbers = getInput("Include numbers? (1: Yes, 0: No): ");
        includeSymbols = getInput("Include symbols? (1: Yes, 0: No): ");
        includeLower = getInput("Include lowercase letters? (1: Yes, 0: No): ");
        includeUpper = getInput("Include uppercase letters? (1: Yes, 0: No): ");

        allCharacters.clear();
        selectedOptions = 0;
        if (includeNumbers) { allCharacters += numbers; selectedOptions++; }
        if (includeSymbols) { allCharacters += symbols; selectedOptions++; }
        if (includeLower) { allCharacters += lowerCase; selectedOptions++; }
        if (includeUpper) { allCharacters += upperCase; selectedOptions++; }
    }

    int length;
    cout << "Enter the desired length of your password (minimum 8): ";
    cin >> length;
    while (length < 8) {
        cout << "Error: Password length must be at least 8 characters.\n";
        cout << "Enter the desired length of your password: ";
        cin >> length;
    }

    cout << "Generated " << category << " Password: ";
    cout << generatePassword(allCharacters, length) << "\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    cout << "Fady, welcome to the Password Generator!\n\n";
    cout << "Please select what you need:\n";
    cout << "1. Lock screen\n2. Visa\n3. Social Media\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice < 1 || choice > 3) {
        cout << "Error: Please select a valid option (1, 2, or 3).\n";
        cout << "Enter your choice: ";
        cin >> choice;
    }

    if (choice == 2) { // Visa Password (4 digits)
        cout << "Generated Visa Password: ";
        cout << generatePassword("0123456789", 4) << "\n";
        return 0;
    }

    if (choice == 1) { // Lock Screen Password
        cout << "Select the device type:\n1. iPhone\n2. Android\n";
        int deviceType;
        cout << "Enter your choice (1-2): ";
        cin >> deviceType;

        while (deviceType < 1 || deviceType > 2) {
            cout << "Error: Please select a valid option (1 or 2).\n";
            cout << "Enter your choice: ";
            cin >> deviceType;
        }

        if (deviceType == 1) {
            cout << "Generated iPhone Lock Screen Password: ";
            cout << generatePassword("0123456789", 6) << "\n";
        } else if (deviceType == 2) { // Android Password Options
            cout << "Select the type of Android password:\n";
            cout << "1. Numbers only (4 digits)\n";
            cout << "2. Numbers only (6 digits)\n";
            cout << "3. Custom (choose character types and length)\n";

            int androidChoice;
            cout << "Enter your choice: ";
            cin >> androidChoice;

            while (androidChoice < 1 || androidChoice > 3) {
                cout << "Error: Please select a valid option (1, 2, or 3).\n";
                cout << "Enter your choice: ";
                cin >> androidChoice;
            }

            if (androidChoice == 1) {
                cout << "Generated Android Password (4 digits): ";
                cout << generatePassword("0123456789", 4) << "\n";
            } else if (androidChoice == 2) {
                cout << "Generated Android Password (6 digits): ";
                cout << generatePassword("0123456789", 6) << "\n";
            } else if (androidChoice == 3) {
                generateCustomPassword("Android");
            }
        }
    }

    if (choice == 3) { // Social Media Password
        generateCustomPassword("Social Media");
    }

    return 0;
}
