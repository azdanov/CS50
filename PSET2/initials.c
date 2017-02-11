#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

int main(void)
{
    // Get a name to initialise
    string name = get_string();

    // Append first letter, initials[4] is '/0'
    char initials[4] = {toupper(name[0])};

    // Get full name length
    int name_len = strlen(name);

    for (int i = 0, j = 1; i < name_len; i++)
    {
        // If there is a space then next letter is of a new word
        if (name[i] == ' ')
        {
            initials[j] = toupper(name[i + 1]);
            j++;
        }
    }

    printf("%s\n", initials);
    
    return 0;
}