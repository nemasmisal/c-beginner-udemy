// %c - char
// %i %u - bool (0 , 1)
// %hi %hx %ho - short integers
// %hu %hx %ho unsigned short integers
// %i %x %o - integers
// %u %x %o - unsigned integers
// %f %.2f %.5f %e %g %a - float/double
#include <stdio.h>

int main() {
  double width = 5.3;
  double height = 3.5;
  double perimeter = 2.0 * (height + width);
  double area = width * height;

  printf("Perimeter is: %f\nArea is: %f\n", perimeter,area);
  return 0;
}
