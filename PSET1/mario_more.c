#include <stdio.h>
#include "cs50.h"

int main(void) {
    int max_height = 23;
    int height;
    do {
        printf("Height: ");
        height = get_int();

        if (height == 0) {
            return 0;
        }

    } while (height <= 0 || height > max_height);

    int base = height + 2;
    int space = 2;
    int blocks = 1;

    for (int i = 0; i < height; i++, blocks++) {
        for (int j = 0; j < base - blocks - space; j++) {
            printf(" ");
        }
        for (int y = 0; y < blocks; y++) {
            printf("#");
        }
        for (int e = 0; e < space; e++) {
            printf(" ");
        }
        for (int y = 0; y < blocks; y++) {
            printf("#");

        }
        printf("\n");
    }
}