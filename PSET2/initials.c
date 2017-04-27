#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    string name = get_string();
    int i = 0;

    do {
        if ((isspace(name[i])) || (i - 1 >= 0 && isalpha(name[i - 1]))) {
            /* Empty block */
        }
        else {
            printf("%c", toupper(name[i]));
        }
        ++i;
    }
    while (name[i] != '\0');

    printf("\n");
}
