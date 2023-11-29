#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HIGHEST 21
#define MAX_TRIES 5

int main() {

  time_t t;
  int currentTry = 0;
  int guessNumber, randomNumber;
  srand((unsigned)time(&t));
  randomNumber = rand() % HIGHEST;

  while (currentTry < MAX_TRIES) {
    printf("You have %d tries left\n", MAX_TRIES - currentTry++);
    printf("Enter a guess:");
    scanf("%d", &guessNumber);
    if (guessNumber == randomNumber) {
      printf("Contratulations. You guessed it!\n");
      break;
    }
    if (guessNumber > randomNumber)
      printf("Sorry, %d is wrong, My number is less than that.\n", guessNumber);
    else
      printf("Sorry %d is wrong. My Number is great than that.\n", guessNumber);
  }
  return 0;
}
