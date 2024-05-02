#include <iostream>
#include <string>
using namespace std;

string encrypt(string s, int key) {
    string t = "";
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            t += (char)(((c - base + key) % 26) + base);
        } else {
            t += c; 
        }
    }
    return t;
}

string decrypt(string s, int key) {
    string t = "";
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            t += (char)(((c - base - key + 26) % 26) + base);
        } else {
            t += c; 
        }
    }
    return t;
}

int main() {
    int key = 3;
    char choice;
    string message;
    
    cout << "Enter 'e' to encrypt or 'd' to decrypt: ";
    cin >> choice;
    
    if (choice == 'e') {
        cout << "Enter the message: ";
        cin >> message;
        cout << "Encrypted message is " << encrypt(message, key) << '\n';
    } else if (choice == 'd') {
        cout << "Enter the encrypted message: ";
        cin >> message;
        cout << "Decrypted message is " << decrypt(message, key) << '\n';
    } else {
        cout << "Invalid choice\n";
    }
    
    return 0;
}