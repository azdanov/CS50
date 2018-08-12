#include <stdio.h>
#include <cs50.h>

int askHeight();
void printWhitespace(int whitespaces);
void printBlock(int blocks);

int main(void) {
  int height = askHeight();

  int whitespaces = height - 1;
  int blocks = 2;

  for (int i = height; i > 0; i--, whitespaces--, blocks++) {

    printWhitespace(whitespaces);

    printBlock(blocks);

    printf("\n");
  }

  return 0;
}

int askHeight() {
  int height = -1;

  printf("Height: ");

  while (height < 0 || height > 23) {
    height = get_int();
  };

  return height;
}

void printWhitespace(int whitespaces) {
  for (int w = whitespaces; w > 0; w--) {
    printf(" ");
  }
}

void printBlock(int blocks) {
  for (int b = blocks; b > 0; b--) {
    printf("#");
  }
}
