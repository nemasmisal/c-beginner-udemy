#include <stdio.h>

int strLength(char strng[]);
void concatenateChars(char str1[], char str2[], char result[]);
_Bool areEqual(char str1[], char str2[]);
int main(void) {

  printf("Length is: %d, actual is: 5\n", strLength("Hello"));

  char str1[] = "Hello";
  char str2[] = " there!";

  short int firstLength = strLength(str1);
  short int secondLength = strLength(str2);
  char result[firstLength + secondLength + 1];
  concatenateChars(str1, str2, result);
  printf("%s\n", result);
  printf("Array 1: %s and Array 2: %s are equal: %d\n", str1, str2,
         areEqual(str1, str2));

  return 0;
}

_Bool areEqual(char str1[], char str2[]) {
  short int str1Length = strLength(str1);
  short int str2Length = strLength(str2);
  if (str1Length != str2Length)
    return 0;
  for (int i = 0; i < str1Length; i++) {
    if (str1[i] != str2[i]) {
      return 0;
    }
  }
  return 1;
}

void concatenateChars(char str1[], char str2[], char result[]) {
  short int firstLength = strLength(str1);
  short int secondLength = strLength(str2);
  for (int i = 0; i < firstLength; i++) {
    result[i] = str1[i];
  }

  for (int i = 0; i < secondLength; i++) {
    result[i + firstLength] = str2[i];
  }
  result[firstLength + secondLength + 1] = '\0';
  return;
}

int strLength(char strng[]) {
  int index = 0;
  while (strng[index] != '\0') {
    index++;
  }
  return index;
}
