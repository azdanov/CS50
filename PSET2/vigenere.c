#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

#define ALPHA_NUM 26

void key_exit();

int main(int argc, char *argv[]) {

    // check argument number
    if (argc != 2)
        key_exit();

    // get key length
    size_t key_len = strlen(argv[1]);

    // create key copy
    char key[key_len + 1];
    strcpy(key, argv[1]);

    // check if key is alpha
    for (int j = 0; j < key_len; j++)
        if (!isalpha(key[j]))
            key_exit();

    // get plaintext from user
    printf("plaintext: ");
    string plaintext = get_string();

    // encode plaintext
    size_t text_len = strlen(plaintext);
    char ciphertext[text_len + 1];

    for (int i = 0, k = 0; i < text_len; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                // Uppercase shift
                ciphertext[i] = (char) ((((plaintext[i] - 'A') + toupper(key[k % key_len]) % 'A') % ALPHA_NUM) + 'A');
            } else {
                // Lowercase shift
                ciphertext[i] = (char) ((((plaintext[i] - 'a') + tolower(key[k % key_len]) % 'a') % ALPHA_NUM) + 'a');
            }
            k++;
        } else {
            // Skip non alpha
            ciphertext[i] = plaintext[i];
        }
    }
    // insert NUL
    ciphertext[text_len] = '\0';

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

void key_exit() {
    printf("Usage (k is keyword):\n./caesar k \n");
    exit(1);
}