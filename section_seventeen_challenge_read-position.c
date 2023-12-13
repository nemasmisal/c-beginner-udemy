#include <stdio.h>

#define FILENAME "from"

int main(void) {
  FILE *pFile = NULL;
  pFile = fopen("from", "r");
  if (!pFile) {
    printf("Could not open file: %s\n", FILENAME);
    return -1;
  }

  fseek(pFile, 0, SEEK_END);
  int position = ftell(pFile);

  for (int i = 0; i <= position; i++) {
    fseek(pFile, -i, SEEK_END);
    printf("Current char is: %c\n", fgetc(pFile));
  }

  fclose(pFile);
  pFile = NULL;

  return 0;
}
