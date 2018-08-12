#include <stdio.h>
#include <cs50.h>

const int ouncesPerMinute = 192;
const int bottleCapacityOunces = 16;

int main(void) {
  printf("Minutes: ");

  int minutes = get_int();

  printf("Bottles: %i\n", minutes * ouncesPerMinute / bottleCapacityOunces);

  return 0;
}
