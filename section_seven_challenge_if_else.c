#include <stdio.h>

#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define WORKING_HOURS 40
#define OVERTIME_RATE 18.00

int main() {

  int actualHours, overtime;
  float gross, taxes;

  printf("Enter working hours for this week: ");
  scanf("%d", &actualHours);

  overtime = actualHours - WORKING_HOURS;

  if (overtime > 0) {
    gross = overtime * OVERTIME_RATE + WORKING_HOURS * PAYRATE;
  } else {
    gross += actualHours * PAYRATE;
  }

  taxes = gross <= 300 ? gross * TAXRATE_300 : (float)300 * TAXRATE_300;

  if (gross > 300 && gross <= 450) {
    taxes += (gross - 300) * TAXRATE_150;
  }

  if (gross > 450) {
    taxes += 150 * TAXRATE_150;
    taxes += (gross - 450) * TAXRATE_REST;
  }

  printf("Gross: %.2f. Net: %.2f. Taxes: %.2f\n", gross, gross - taxes, taxes);
  return 0;
}
