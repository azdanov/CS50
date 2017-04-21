#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);

    int padding = height - 1, padding_middle = 2, row = 1;

    for (int i = height; i > 0; i--, padding--, row++) {

        for (int j = padding; j > 0; j--) {
            printf(" ");
        }

        for (int k = row; k > 0; k--) {
            printf("#");
        }

        for (int l = padding_middle; l > 0; l--) {
            printf(" ");
        }

        for (int m = row; m > 0; m--) {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
