#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, int a, int b) {
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char ch = toupper(text[i]);
            text[i] = ((a * (ch - 'A') + b) % 26) + 'A';
        }
    }
    return text;
}

string decrypt(string text, int a, int b) {
    int a_inv = 1;

    // Find modular inverse of a
    for (int i = 0; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            a_inv = i;
            break;
        }
    }

    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char ch = text[i];
            text[i] = (a_inv * ((ch - 'A' - b + 26)) % 26) + 'A';
        }
    }
    return text;
}

int main() {
    string text;
    int shift;

    cout << "Enter message: ";
    cin >> text;

    cout << "Enter shift key: ";
    cin >> shift;

    int a = 1;  
    string encrypted = encrypt(text, a, shift);
    cout << "Encrypted Text: " << encrypted << endl;

    string decrypted = decrypt(encrypted, a, shift);
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}