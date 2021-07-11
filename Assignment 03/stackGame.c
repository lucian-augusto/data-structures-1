/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "stackGame.h"

/* =============================================================================
 * Macro Definitions
 * ========================================================================== */
#define MAX_STACK_SIZE_POSSIBLE 50
#define MIN_STACK_SIZE_POSSIBLE 10
#define RANDOM_NUMBER_LIMIT 10

/* =============================================================================
 * Main Function
 * ========================================================================== */
int main() {
  srand(time(NULL));
  int keepPlaying = 0;

  do {
    callGameLoop();
    keepPlaying = playAgain();
  } while (keepPlaying);

  return 0;
}

/* =============================================================================
 * Helper Functions
 * ========================================================================== */
void callGameLoop() {
  int winner = 0;
  int startingElementAmount =
      (rand() % (MAX_STACK_SIZE_POSSIBLE - MIN_STACK_SIZE_POSSIBLE)) +
      MIN_STACK_SIZE_POSSIBLE;
  Stack *player1 = createStack(2 * startingElementAmount);
  Stack *player2 = createStack(2 * startingElementAmount);

  fillStack(player1, startingElementAmount);
  fillStack(player2, startingElementAmount);

  do {
    executeRound(player1, player2);
    usleep(300);
    winner = shouldEndGame(player1, player2);
  } while (winner == 0);

  printWinnerMessage(winner);

  destroyStack(player1);
  destroyStack(player2);
}

void executeRound(Stack *s1, Stack *s2) {
  int n1 = pop(s1);
  int n2 = pop(s2);
  int diff, i;

  printf("Player 1: %d\nPlayer 2: %d\n", n1, n2);

  if (n1 > n2) {
    diff = n1 - n2;
    printf("Player 2 gets %d of Player 1's elements!\n", diff);
    moveElementsBetweenStacks(s1, s2, diff);
  }

  if (n2 > n1) {
    diff = n2 - n1;
    printf("Player 1 gets %d of Player 2's elements!\n", diff);
    moveElementsBetweenStacks(s2, s1, diff);
  }
  printf("\n");
}

void fillStack(Stack *s, int elementAmount) {
  int i;
  for (i = 0; i < elementAmount; i++) {
    int randomElement = (rand() % (RANDOM_NUMBER_LIMIT - 1)) + 1;
    push(s, randomElement);
  }
}

void moveElementsBetweenStacks(Stack *donor, Stack *recipient,
                               int elementAmount) {
  int i;
  for (i = 0; i < elementAmount; i++) {
    if (isEmptyStack(donor)) {
      break;
    }
    push(recipient, pop(donor));
  }
}

int playAgain() {
  char input;
  printf("Do you want to play again? (y/n): ");
  scanf(" %c", &input);

  input = tolower(input);

  while (input != 'y' && input != 'n') {
    printf("Invalid Option! Do you want to play again? (y/n): ");
    scanf(" %c", &input);
  }

  getchar();

  if (input == 'y') {
    return 1;
  }

  return 0;
}

void printWinnerMessage(int winner) {
  switch (winner) {
  case 1:
    printf("Player 1 is the Winner!!!\n");
    break;

  case 2:
    printf("Player 2  is the Winner!!!\n");
    break;

  case 3:
    printf("Draw!!!");
    break;
  default:
    printf("Error! Unexpected result. Exiting...");
    exit(1);
  }
  printf("\n");
}

int shouldEndGame(Stack *s1, Stack *s2) {
  int winner = 0;

  if (isEmptyStack(s1)) {
    winner += 1;
  }

  if (isEmptyStack(s2)) {
    winner += 2;
  }

  return winner;
}
