#include <stdio.h>
#include <cs50.h>

int main(int argc, char *argv[]) {

    // check entered key
    if (argc != 2 || atoi(argv[1]) < 0) {
        printf("Usage: ./caesar k\nWhere k is a non negative integer.\n");
        return 1;
    }

    int key = atoi(argv[1]);



    return 0;
}
