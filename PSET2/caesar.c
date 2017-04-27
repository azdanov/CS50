#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

#define ALPHA_LEN 26

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    int key = atoi(argv[1]) % ALPHA_LEN;

    printf("plaintext:  ");
    string plaintext = get_string();

    printf("ciphertext: ");
    for (int i = 0, shift; plaintext[i] != '\0'; ++i) {

        if (isalpha(plaintext[i])) {

            shift = plaintext[i] + key;

            if (isupper(plaintext[i])) {
                printf("%c", (shift - 'A') % ALPHA_LEN + 'A');
            }
            else {
                printf("%c", (shift - 'a') % ALPHA_LEN + 'a');
            }
        }
        else {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");

    return 0;
}
