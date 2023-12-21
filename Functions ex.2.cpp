#include <stdio.h>
#include <string.h>

// Function to encrypt the text using a simple substitution cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt the text using a simple substitution cipher
void decrypt(char *text, int shift) {
    encrypt(text, 26 - shift); // Decryption is just shifting in the opposite direction
}

int main() {
    char text[100];
    int choice, shift;

    printf("Enter the text: ");
    gets(text); // You can use fgets for safer input handling

    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter the shift value (e.g., 1-25): ");
    scanf("%d", &shift);

    if (choice == 1) {
        encrypt(text, shift);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        decrypt(text, shift);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice. Please choose 1 for encryption or 2 for decryption.\n");
    }

    return 0;
}
