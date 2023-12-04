#include <stdio.h>
#include <string.h>

void sortingArr(char str1[], char result[]);
int main(void) {

  char str[50];
  printf("Provide your string that will be reversed:");
  scanf("%s", str);
  char reversed[sizeof(str)];
  int strLength = strlen(str) - 1;
  for (int i = strLength; i >= 0; i--) {
    reversed[strLength - i] = str[i];
  }
  printf("Reversed version of %s is %s\n", str, reversed);

  printf("input number of strings:");
  int totalStrings;
  scanf("%d", &totalStrings);
  printf("input total chars per string:");
  unsigned long totalCharsPerString;
  scanf("%lu", &totalCharsPerString);
  printf("Input %d strings:\n", totalStrings);
  char str2[totalStrings][totalCharsPerString + 1];
  char temp[totalCharsPerString + 1];
  int counter = 0;

  while (counter < totalStrings) {
    scanf("%s", str2[counter]);
    counter++;
  }

  for (int i = 0; i < totalStrings; i++) {
    for (int j = 0; j < totalStrings - i - 1; j++) {
      if (strcmp(str2[j], str2[j + 1]) > 0) {
        strncpy(temp, str2[j], totalCharsPerString + 1);
        strncpy(str2[j], str2[j + 1], totalCharsPerString + 1);
        strncpy(str2[j + 1], temp, totalCharsPerString + 1);
      }
    }
  }

  printf("Sorted:\n");
  for (int i = 0; i < totalStrings; i++) {
    printf("%s\n", str2[i]);
  }
  return 0;
}
