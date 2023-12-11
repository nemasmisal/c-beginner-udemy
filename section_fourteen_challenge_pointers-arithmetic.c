#include <stdio.h>

int strLength(const char *charP);

int main(void) {
  printf("%d\n", strLength("Test strLength"));
  return 0;
}

int strLength(const char *charP) {
  const char *begining = charP;
  while (*charP) {
    charP++;
  }
  return charP - begining;
}
