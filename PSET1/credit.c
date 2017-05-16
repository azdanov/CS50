#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Number: ");
    long card_number_input = get_long_long();

    int total_digits = 0;
    long card_number_temp = card_number_input;

    /* Get card number length */
    while (card_number_temp != 0) {
        card_number_temp /= 10;
        total_digits++;
    }

    /* Check card number length */
    if (total_digits < 13 || total_digits > 16) {
        printf("INVALID\n");
        return 0;
    }

    int card_number[total_digits];
    card_number_temp = card_number_input;

    int temp = total_digits;
    /* Create an array with card numbers */
    while (card_number_temp != 0) {
        temp--;
        card_number[temp] = (int) (card_number_temp % 10);
        card_number_temp /= 10;
    }

    /* Check first numbers for validity */
    if ((card_number[0] != 4) &&
        (card_number[0] != 3 && (card_number[1] != 4 || card_number[1] != 7)) &&
        (card_number[0] != 5 && (card_number[1] != 1 || card_number[1] != 2 || card_number[1] != 3 ||
            card_number[1] != 4 || card_number[1] != 5))) {
        printf("INVALID\n");
        return 0;
    }

    int odd_numbers = 0, even_numbers = 0, sum_of_numbers = 0;

    /* Use Luhn’s algorithm to determine if card number is syntactically valid */
    if(total_digits % 2 == 0) {
        for (int i = 0; i < total_digits; ++i) {
            if (i % 2 == 0) {
                temp = card_number[i] * 2;
                if(temp >= 10) {
                    even_numbers += temp % 10;
                    even_numbers += temp / 10;
                }
                else {
                    even_numbers += temp;
                }
            }
            else {
                odd_numbers += card_number[i];
            }
        }
    }
    else {
        for (int i = 0; i < total_digits; ++i) {
            if (i % 2 != 0) {
                temp = card_number[i] * 2;
                if(temp >= 10) {
                    even_numbers += temp % 10;
                    even_numbers += temp / 10;
                }
                else {
                    even_numbers += temp;
                }
            }
            else {
                odd_numbers += card_number[i];
            }
        }
    }

    sum_of_numbers = even_numbers + odd_numbers;

    if (sum_of_numbers % 10 != 0) {
        printf("INVALID\n");
    }
    else {
        switch (card_number[0]) {
            case 3:printf("AMEX\n");
                break;
            case 4:printf("VISA\n");
                break;
            case 5:printf("MASTERCARD\n");
                break;
            default:printf("INVALID\n");
                break;
        }
    }

    return 0;
}