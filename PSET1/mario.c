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

    int padding = height - 1;
    int row = 2;
    
    for (int i = height; i > 0; i--, padding--, row++) {

        for (int j = padding; j > 0; j--) {
            printf(" ");
        }

        for (int k = row; k > 0; k--) {
            printf("#");
        }
        
        printf("\n");
    }

    return 0;
}
