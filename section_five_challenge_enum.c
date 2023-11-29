#include <stdio.h>

int main(void) {
  enum Company { GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT };
  enum Company xerox = XEROX;
  enum Company google = GOOGLE;
  enum Company ebay = EBAY;
  printf("%d\n%d\n%d\n", xerox, google, ebay);
  return 0;
}
