#include <stdio.h>
#include <stdlib.h>

#define FILENAME "section_five_challenge_enum.c"

int main(void) {
  FILE *pFile = NULL;
  pFile = fopen(FILENAME, "r");
  if (pFile == NULL) {
    printf("Cant open the file: %s.\n", FILENAME);
    return -1;
  }
  int lines = 0;
  char str[60];
  while (fgets(str, 60, pFile))
    lines++;

  fclose(pFile);
  pFile = NULL;
  printf("%d\n", --lines);
  return 0;
}
