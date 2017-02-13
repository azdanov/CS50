#include <stdio.h>
#include <cs50.h>
#include <string.h>
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

    string ciphertext = "";

    // encode plaintext
    size_t text_len = strlen(plaintext);
    for (int i = 0; i < text_len; ++i) {
        
    }



    return 0;
}
