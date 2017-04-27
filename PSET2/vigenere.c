#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <cs50.h>

#define ALPHA_LEN 26

bool is_alpha_string(string key);

int main(int argc, char *argv[])
{
    if (argc != 2 || is_alpha_string(argv[1]) == false) {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // Normalize ascii alpha key to numerical shifts
    int key_len = (int) strlen(argv[1]);
    int key[key_len];
    for (int i = 0; i < key_len; ++i) {
        key[i] = toupper(argv[1][i]) - 'A';
    }

    printf("plaintext:  ");
    string plaintext = get_string();

    printf("ciphertext: ");
    for (int i = 0, j = 0, text_len = (int) strlen(plaintext), shift; i < text_len; ++i) {

        if (isalpha(plaintext[i])) {

            shift = plaintext[i] + key[j % key_len];

            if (isupper(plaintext[i])) {
                printf("%c", (shift - 'A') % ALPHA_LEN + 'A');
            }
            else {
                printf("%c", (shift - 'a') % ALPHA_LEN + 'a');
            }
            
            ++j;
        }
        else {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");

    return 0;
}

bool is_alpha_string(string key)
{
    for (int i = 0, key_len = (int) strlen(key); i < key_len; ++i) {
        if (isalpha(key[i]) == false) {
            return false;
        }
    }

    return true;
}
