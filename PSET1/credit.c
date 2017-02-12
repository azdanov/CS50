#include <stdio.h>
#include <cs50.h>
#include <math.h>

int calc_even(int even_sum, int temp);

int card_checksum(long card_number, int n_digits);

void validate_card(long start_digits, int checksum);

int main(void) {
    printf("Number: ");

    long card_number = get_long_long();

    // check two most significant digits
    long start_digits = card_number;
    while (start_digits >= 100) start_digits /= 10;

    // check number of digits
    int n_digits = (int) floor(log10(card_number)) + 1;

    if (!((start_digits == 34 || start_digits == 37) ||
          (start_digits >= 51 && start_digits <= 55) ||
          (start_digits >= 40 && start_digits <= 49) ||
          (n_digits >= 13 && n_digits <= 16))) {
        printf("INVALID\n");
        return 0;
    }

    int checksum = card_checksum(card_number, n_digits);

    validate_card(start_digits, checksum);

    return 0;
}

void validate_card(long start_digits, int checksum) {
    if (checksum == 0) {
        printf("INVALID\n");
    } else {
        if (start_digits == 34 || start_digits == 37)
            printf("AMEX\n");
        else if (start_digits >= 51 && start_digits <= 55)
            printf("MASTERCARD\n");
        else if (start_digits >= 40 && start_digits <= 49)
            printf("VISA\n");
    }
}

int card_checksum(long card_number, int n_digits) {
    // Luhn’s algorithm
    // return 0 for false, -1 for true

    long card_copy = card_number;
    int odd_sum = 0;
    int even_sum = 0;

    if (n_digits % 2 == 0) {
        for (int i = 0; i < n_digits; i++) {
            int temp = (int) (card_copy % 10);
            if (i % 2 != 0)
                odd_sum += temp;
            else
                even_sum = calc_even(even_sum, temp);
            card_copy /= 10;
        }
    } else {
        for (int i = 0; i < n_digits; i++) {
            int temp = (int) (card_copy % 10);
            if (i % 2 == 0)
                odd_sum += temp;
            else
                even_sum = calc_even(even_sum, temp);
            card_copy /= 10;
        }
    }
    return (odd_sum + even_sum) % 10 - 1;
}

int calc_even(int even_sum, int temp) {
    temp *= 2;
    // split tens into ones to add
    if (temp > 9)
        for (int j = 0; j < 2; j++) {
            even_sum += temp % 10;
            temp /= 10;
        }
    else
        even_sum += temp;
    return even_sum;
}