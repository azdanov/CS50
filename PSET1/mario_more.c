#include <stdio.h>
#include <cs50.h>

int askHeight();
void printInnerWhitespace();
void printOuterWhitespace(int outerWhitespaces);
void printBlock(int blocks);

int main(void) {
  int height = askHeight();

  int outerWhitespaces = height - 1;
  int blocks = 1;

  for (int i = height; i > 0; i--, outerWhitespaces--, blocks++) {

    printOuterWhitespace(outerWhitespaces);

    printBlock(blocks);

    printInnerWhitespace();

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

void printInnerWhitespace() {
  int innerWhitespaces = 2;

  for (int l = innerWhitespaces; l > 0; l--) {
    printf(" ");
  }
}

void printOuterWhitespace(int outerWhitespaces) {
  for (int j = outerWhitespaces; j > 0; j--) {
    printf(" ");
  }
}

void printBlock(int blocks) {
  for (int k = blocks; k > 0; k--) {
    printf("#");
  }
}
