#include "stdio.h"

void square(int *num);

int main(void) {
  int prime = 5;
  printf("before square: %d\n", prime);
  square(&prime);
  printf("after square: %d\n", prime);
  return 0;
}

void square(int *num) {
  *num = (*num) * (*num);
  return;
}
