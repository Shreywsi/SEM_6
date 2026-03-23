#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateKey(char text[], char key[], char newKey[]) {
    int i, j = 0;
    int textLen = strlen(text);
    int keyLen = strlen(key);

    for (i = 0; i < textLen; i++) {
        if (text[i] == ' ') {
            newKey[i] = ' ';  
        } else {
            newKey[i] = key[j % keyLen];
            j++;
        }
    }
    newKey[i] = '\0';
}

void encrypt(char text[], char key[], char cipher[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            cipher[i] = ' ';
        } else {
            char t = toupper(text[i]) - 'A';
            char k = toupper(key[i]) - 'A';

            cipher[i] = ((t + k) % 26) + 'A';
        }
    }
    cipher[strlen(text)] = '\0';
}

void decrypt(char cipher[], char key[], char original[]) {
    for (int i = 0; cipher[i] != '\0'; i++) {
        if (cipher[i] == ' ') {
            original[i] = ' ';
        } else {
            char c = cipher[i] - 'A';
            char k = toupper(key[i]) - 'A';

            original[i] = ((c - k + 26) % 26) + 'A';
        }
    }
    original[strlen(cipher)] = '\0';
}

int main() {
    char text[100], key[100], newKey[100];
    char cipher[100], original[100];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    text[strcspn(text, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    generateKey(text, key, newKey);

    encrypt(text, newKey, cipher);
    printf("Cipher Text: %s\n", cipher);

    decrypt(cipher, newKey, original);
    printf("Decrypted Text: %s\n", original);

    return 0;
}
