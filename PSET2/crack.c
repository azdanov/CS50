#define _XOPEN_SOURCE
#include <stdio.h>
#include <crypt.h>
#include <string.h>
#include <unistd.h>

#define SEED "50"


int main(int argc, char *argv[])
{

    if (argc != 2) {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    char word[5] = {0};

    int alphabet_len = (int) strlen(alphabet);

    for (int i = 0; i < alphabet_len; ++i) {
        for (int j = 0; j < alphabet_len; ++j) {
            for (int k = 0; k < alphabet_len; ++k) {
                for (int l = 0; l < alphabet_len; ++l) {
                    if (strcmp(crypt(word, SEED), argv[1]) == 0) {
                        goto exit_loop;
                    }
                    word[0] = alphabet[l];
                }
                word[1] = alphabet[k];
            }
            word[2] = alphabet[j];
        }
        word[3] = alphabet[i];
    }
    exit_loop:;

    printf("%s\n", word);

    return 0;
}
