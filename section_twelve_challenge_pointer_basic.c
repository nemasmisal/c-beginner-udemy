#include <stdio.h>

int main(void) {
  int numFive = 5;
  int *pNumFive = NULL;
  pNumFive = &numFive;

  printf("Pointer is pointing to: %p\n", pNumFive);
  printf("Adress of pointer is: %p\n", &pNumFive);
  printf("Value at the location in memroy where pointer is pointing is: %d\n",
         *pNumFive);
  return 0;
}
