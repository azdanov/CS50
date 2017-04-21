#include <stdio.h>
#include <cs50.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1
#define CORRECT_IMPRECISION 0.0001

int main(void)
{
    float change_input;

    do {
        printf("O hai! How much change is owed?\n");
        change_input = get_float();
    }
    while (change_input < 0);

    int change_owned = (int) ((change_input + CORRECT_IMPRECISION) * 100); // Normalise floats (e.g '0.409995' ==> '41')

    int total_coins = 0;

    while (change_owned > 0) {

        if (change_owned - QUARTER >= 0) {
            change_owned -= QUARTER;
        }
        else if (change_owned - DIME >= 0) {
            change_owned -= DIME;
        }
        else if (change_owned - NICKEL >= 0) {
            change_owned -= NICKEL;
        }
        else {
            change_owned -= PENNY;
        }
        
        total_coins++;
    }

    printf("%d\n", total_coins);

    return 0;
}
