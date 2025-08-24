#include <iostream>
#include <string>
using namespace std;


void concatenateStrings() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    string result = s1; 
    for (int i = 0; i < s2.length(); i++) {
        result += s2[i]; 
    }
    cout << "Concatenated string: " << result << endl;
}


void reverseString() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    cout << "Reversed string: " << s << endl;
}


void deleteVowels() {
    string s, result = "";
    cout << "Enter a string: ";
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        char c = tolower(s[i]);
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            result += s[i];
        }
    }
    cout << "String without vowels: " << result << endl;
}


void sortStrings() {
    int n;
    cout << "How many strings? ";
    cin >> n;
    string arr[100];

    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void upperToLower() {
    char c;
    cout << "Enter an uppercase character: ";
    cin >> c;
    if (c >= 'A' && c <= 'Z') {
        c = c + 32; 
    }
    cout << "Lowercase character: " << c << endl;
}

int main() {
    int choice;
    do {
        cout << "String Operations Menu:\n";
        cout << "1. Concatenate two strings\n";
        cout << "2. Reverse a string\n";
        cout << "3. Delete vowels from string\n";
        cout << "4. Sort strings alphabetically\n";
        cout << "5. Convert uppercase to lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: concatenateStrings(); break;
            case 2: reverseString(); break;
            case 3: deleteVowels(); break;
            case 4: sortStrings(); break;
            case 5: upperToLower(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
