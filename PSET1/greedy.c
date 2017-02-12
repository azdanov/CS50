#include <stdio.h>
#include <cs50.h>

int main(void) {
    float change_owned = 0;
    int number_of_coins = 0;

    float quarter = 0.25;
    float dime = 0.1;
    float nickel = 0.05;
    float pennie = 0.01;

    float epsilon = 0.01;

    printf("O hai! ");

    do {
        printf("How much change is owed?\n");
        change_owned = get_float();
    } while (change_owned <= 0);

    change_owned += 0.00001; // fix potential float error

    while (change_owned >= epsilon) {
        if ((change_owned / quarter) >= 1) {
            change_owned -= quarter;
            number_of_coins++;
        } else if ((change_owned / dime) >= 1) {
            change_owned -= dime;
            number_of_coins++;
        } else if ((change_owned / nickel) >= 1) {
            change_owned -= nickel;
            number_of_coins++;
        } else {
            change_owned -= pennie;
            number_of_coins++;
        }
    }
    printf("%d\n", number_of_coins);
}