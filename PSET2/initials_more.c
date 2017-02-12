#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void) {
    string name = get_string();

    char initials[4] = {};

    int name_len = strlen(name);

    bool inside = false;

    for (int i = 0, j = 0; i < name_len; i++) {
        if (isalpha(name[i]) && !inside) {
            inside = true;
            initials[j] = toupper(name[i]);
            j++;
        } else if (isspace(name[i])) {
            inside = false;
            continue;
        }
    }

    printf("%s\n", initials);

}