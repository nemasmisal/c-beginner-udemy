#include <stdbool.h>
#include <stdio.h>

#define LENGTH 100

int main() {
  int primes[LENGTH] = {2, 3};
  int primeIndex = 1;
  bool isPrime = true;

  for (int i = 5; i < 100; i += 2) {
    isPrime = true;
    for (int j = 1; isPrime && i / primes[j] >= primes[j]; j++) {
      if (i % primes[j] == 0) {
        isPrime = false;
      }
    }
    if (isPrime) {
      primes[primeIndex++] = i;
    }
  }

  for (int i = 0; i < primeIndex; i++) {
    printf("%d,", primes[i]);
  }
  printf("\n");
  return 0;
}
