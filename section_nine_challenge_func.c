#include <stdio.h>

int greatestCommonDivisor(unsigned int x, unsigned int y);
int absValue(int x);
int square(int x);

int main(void) {
  printf("Greatest Common Divisor of 64 and 162 is %d\n",
         greatestCommonDivisor(64, 162));

  printf("Absolute value of -12 is %d\n", absValue(-12));

  printf("Square of 64 is %d\n", square(64));

  return 0;
}

int greatestCommonDivisor(unsigned int x, unsigned int y) {
  if (y == 0) {
    return x;
  }
  return greatestCommonDivisor(y, x % y);
}

int absValue(int x) { return x < 0 ? x * -1 : x; }

int square(int x) {
  if (x <= 0) {
    printf("Square is only valid for positive numbers");
    return -1;
  }

  for (int i = 1; i < x; i++) {
    if (i * i == x) {
      return i;
    }
  }
  return -1;
}
