#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_FROM "from"
#define FILENAME_TO "to"

int main(void) {
  FILE *pFromFile = NULL, *pToFile = NULL;
  pFromFile = fopen(FILENAME_FROM, "r");
  if (!pFromFile) {
    printf("Can't open file %s\n", FILENAME_FROM);
    return EXIT_FAILURE;
  }
  pToFile = fopen(FILENAME_TO, "w");
  if (!pToFile) {
    printf("Cant create temp file\n");
    return EXIT_FAILURE;
  }

  int ch;
  while ((ch = fgetc(pFromFile)) != EOF) {
    fputc(toupper(ch), pToFile);
  }

  fclose(pFromFile);
  pFromFile = NULL;
  fclose(pToFile);
  pToFile = NULL;

  rename(FILENAME_TO, FILENAME_FROM);

  pFromFile = fopen(FILENAME_FROM, "r");
  if (!pFromFile) {
    printf("Can't open file %s\n", FILENAME_FROM);
    return EXIT_FAILURE;
  }
  while ((ch = fgetc(pFromFile)) != EOF)
    printf("%c", ch);
  fclose(pFromFile);
  pFromFile = NULL;

  return 0;
}
