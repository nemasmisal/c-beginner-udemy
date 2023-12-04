#include <stdio.h>

#define ROWS 3
#define COLS 3
#define PLAYER_ONE_SIGN 'X'
#define PLAYER_TWO_SIGN 'Y'

struct {
  int x;
  int y;
} Cordinates;

void draw(char board[ROWS][COLS]);
void askForInput(_Bool isPlayerOneTurn, int *position);
void updateBoard(char board[ROWS][COLS], int *position, _Bool isPlayerOneTurn);
void checkForWinner(char board[ROWS][COLS], _Bool isPlayerOneTurn,
                    _Bool *winner);

int main(void) {

  int counter = 0;
  int position;
  _Bool isGameOver = 0;
  _Bool isPlayerOneTurn = 1;
  _Bool winner = 0;
  char board[ROWS][COLS] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

  while (!isGameOver && counter < 9) {
    counter++;
    draw(board);
    askForInput(isPlayerOneTurn, &position);
    updateBoard(board, &position, isPlayerOneTurn);
    checkForWinner(board, isPlayerOneTurn, &winner);
    isPlayerOneTurn = !isPlayerOneTurn;
    isGameOver = winner;
  }
  if (winner) {
    printf("Winner is Player: %d\n", isPlayerOneTurn ? 2 : 1);
  }
  printf("Game is over\n");
  return 0;
}

void checkForWinner(char board[ROWS][COLS], _Bool isPlayerOneTurn,
                    _Bool *winner) {
  char sign = isPlayerOneTurn ? PLAYER_ONE_SIGN : PLAYER_TWO_SIGN;
  // Check up and down
  _Bool isWinning = 1;
  for (int i = 0; i < ROWS; i++) {
    if (board[i][Cordinates.y] != sign)
      isWinning = 0;
  }
  if (isWinning) {
    *winner = 1;
    return;
  }
  // Check left and right
  isWinning = 1;
  for (int i = 0; i < COLS; i++) {
    if (board[Cordinates.x][i] != sign) {
      isWinning = 0;
    }
  }
  if (isWinning) {
    *winner = 1;
    return;
  }
  // Check diagonals
  if (board[0][0] == sign && board[1][1] == sign && board[2][2] == sign) {
    *winner = 1;
    return;
  }
  if (board[0][2] == sign && board[1][1] == sign && board[2][0] == sign) {
    *winner = 1;
    return;
  }
  return;
}

void map1Dto2D(char board[ROWS][COLS], int position) {

  if (position <= 3) {
    Cordinates.x = 0;
    Cordinates.y = position - 1;
  }

  if (position > 3 && position <= 6) {
    Cordinates.x = 1;
    Cordinates.y = (position + 2) % 3;
  }

  if (position > 6) {
    Cordinates.x = 2;
    Cordinates.y = (position + 2) % 3;
  }
  return;
}

_Bool isOccupied(char board[ROWS][COLS], int position) {
  map1Dto2D(board, position);

  return board[Cordinates.x][Cordinates.y] == PLAYER_ONE_SIGN ||
         board[Cordinates.x][Cordinates.y] == PLAYER_TWO_SIGN;
}

void updateBoard(char board[ROWS][COLS], int *position, _Bool isPlayerOneTurn) {
  if (*position < 0 || *position > ROWS * COLS ||
      isOccupied(board, *position)) {
    printf("Choosen position %d is out of the board or already occupied, try "
           "again\n",
           *position);
    askForInput(isPlayerOneTurn, position);
    updateBoard(board, position, isPlayerOneTurn);
  }

  map1Dto2D(board, *position);

  board[Cordinates.x][Cordinates.y] =
      isPlayerOneTurn ? PLAYER_ONE_SIGN : PLAYER_TWO_SIGN;
  return;
}

void askForInput(_Bool isPlayerOneTurn, int *position) {
  printf("Player:%d pick your next turn:", isPlayerOneTurn ? 1 : 2);
  scanf("%d", position);
  return;
}

void draw(char board[ROWS][COLS]) {
  for (int x = 0; x < ROWS; x++) {
    for (int y = 0; y < COLS; y++) {
      printf(" %c", board[x][y]);
    }
    printf("\n");
  }
  return;
}
