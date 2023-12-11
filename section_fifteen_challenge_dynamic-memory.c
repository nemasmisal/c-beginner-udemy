#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  char *text = NULL;
  int size = 0;
  printf("Enter the length of the text:");
  scanf("%d", &size);

  text = (char *)malloc((size + 1) * sizeof(char));
  if (!text) {
    printf("Could not allocate memory\n");
    return -1;
  }

  printf("\nEnter the text:");
  scanf("%s", text);
  printf("\nYou have typed: %s\n", text);

  free(text);
  return 0;
}
