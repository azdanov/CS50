#define _XOPEN_SOURCE

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define LEN 5 // max password length

void increment_guess(char str[], int pos);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    char salt[3];
    strncpy(salt, argv[1], 2); // get salt, first two chars

    char guess[LEN] = {'\0'};

    do {
        if (strcmp(argv[1], crypt(guess, salt)) == 0) { // compare both hashes
            printf("%s", guess);
            return 0;
        }
        increment_guess(guess, 0);
    } while (guess[LEN - 1] == '\0');

}

void increment_guess(char str[], int pos) {
    if (str[pos] == '\0') {       // start with upper 'A'
        str[pos] = 'A';
    } else if (str[pos] == 'Z') { // skip to lower 'a'
        str[pos] = 'a';
    } else if (str[pos] == 'z') { // next position when end is reached
        str[pos] = 'a';
        increment_guess(str, pos + 1);
    } else {                      // else increment char
        str[pos]++;
    }
}