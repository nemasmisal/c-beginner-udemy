#include <stdio.h>

struct employee {
  char name[30];
  int hireDate;
  float salary;
};

int main(void) {

  struct employee mainEmployee;

  printf("Name:");
  scanf("%s", mainEmployee.name);
  printf("Hire date:");
  scanf("%d", &mainEmployee.hireDate);
  printf("Salary:");
  scanf("%f", &mainEmployee.salary);

  printf("Name: %s, hire date: %d, salary: %.2f\n", mainEmployee.name,
         mainEmployee.hireDate, mainEmployee.salary);
  return 0;
}
