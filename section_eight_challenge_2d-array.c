#include <stdio.h>

#define ROWS 2
#define COLS 12

int main() {
  float rain[ROWS][COLS] = {
      {30, 25.7, 22, 40, 12.5, 22, 31, 22.5, 11, 8.5, 23, 12},
      {8.5, 2, 55, 32.8, 24, 24, 19.8, 17.4, 19, 22.8, 27, 9},
  };

  float subtotal = 0, total = 0;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      subtotal += rain[i][j];
    }
    printf("%f\n", subtotal);
    total += subtotal;
    subtotal = 0;
  }

  printf("Average is %.1f \n", total / ROWS);
  return 0;
}
