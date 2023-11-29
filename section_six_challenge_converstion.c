#include <stdio.h>

int main() {
  int minutes;
  printf("Enter minutes:");
  scanf("%i", &minutes);
  double days = (double)minutes / 60 / 24;
  printf("Days: %.2f, Years: %.2f\n", days, days / 365);
  return 0;
}
