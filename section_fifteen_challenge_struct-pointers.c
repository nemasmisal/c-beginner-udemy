#include <stdio.h>
#include <stdlib.h>

struct Item {
  char *name;
  int quantity;
  float price;
  float amount;
};

void readItem(struct Item *item);
void printItem(struct Item *item);

int main(void) {
  struct Item item;
  item.name = (char *)malloc(10 * sizeof(char));
  if (!item.name) {
    return -1;
  }
  readItem(&item);
  item.amount = item.price * item.quantity;
  printItem(&item);
  free(item.name);
  return 0;
}

void printItem(struct Item *item) {
  printf("Product name: %s, quantity: %d, price: %.2f, amount: %.2f\n",
         item->name, item->quantity, item->price, item->amount);
  return;
}

void readItem(struct Item *item) {
  printf("Product name:");
  scanf("%s", item->name);
  printf("Product price:");
  scanf("%f", &item->price);
  printf("Product quantity:");
  scanf("%d", &item->quantity);
  return;
}
