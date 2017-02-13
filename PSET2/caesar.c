#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ALPHA_NUM 26

int main(int argc, char *argv[]) {

    // check argument number and argument key to be greater than -1
    if (argc != 2 || atoi(argv[1]) < 0) {
        printf("Usage (k >= 0):\n./caesar k \n");
        return 1;
    }

    int key = atoi(argv[1]) % ALPHA_NUM;

    // get plaintext from user
    printf("plaintext: ");
    string plaintext = get_string();
    printf("\n");


    // encode plaintext
    size_t text_len = strlen(plaintext);
    char ciphertext[text_len + 1];

    for (int i = 0; i < text_len; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[i] = (char) (((plaintext[i] + key - 'A') % ALPHA_NUM) + 'A');
            } else {
                ciphertext[i] = (char) (((plaintext[i] + key - 'a') % ALPHA_NUM) + 'a');
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}
