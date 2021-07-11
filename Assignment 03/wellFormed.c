/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "wellFormed.h"

/* =============================================================================
 * Macro Definitions
 * ========================================================================== */
#define NUMBER_OF_SEQUENCES 5
#define MAX_SEQUENCE_LENGTH 20
#define STACK_SIZE 10

/* =============================================================================
 * Main Function
 * ========================================================================== */
int main() {

  char **seq = (char **)malloc(NUMBER_OF_SEQUENCES * sizeof(char *));
  int i;

  seq[0] = "[ ( ) ] [ )";
  seq[1] = "( ( ) [ ( ) ] )";
  seq[2] = "( [ ) ]";
  seq[3] = "( ) [ ]";
  seq[4] = "( [ ]";

  for (i = 0; i < NUMBER_OF_SEQUENCES; i++) {
    printf("Sequence %d:\n", i + 1);
    evaluateBracketSequence(seq[i]);
    printf("\n");
  }

  free(seq);

  return 0;
}

/* =============================================================================
 * Helper Functions
 * ========================================================================== */
int areEqual(char c1, char c2) { return c1 == c2; }

void evaluateBracketSequence(char *seq) {
  Stack *mainStack = createStack(STACK_SIZE);
  Stack *helperStack = createStack(STACK_SIZE);

  int i = 0;

  while (seq[i] != '\0') {
    if (!isSpaceCharacter(seq[i])) {
      printf("%c\n", seq[i]);
      evaluateSequenceElement(mainStack, helperStack, seq[i]);
    }
    i++;
  }

  printf("The Sequence is ");
  if (!isWellFormed(helperStack)) {
    printf("not ");
  }
  printf("well-formed\n");

  destroyStack(mainStack);
  destroyStack(helperStack);
}

void evaluateSequenceElement(Stack *mainStack, Stack *helperStack, char c) {
  if (isOpenBracket(c)) {
    push(mainStack, c);
    push(helperStack, getReverseBracket(c));
  } else {
    char reference = pop(helperStack);
    push(mainStack, c);
    if (!areEqual(c, reference)) {
      push(helperStack, reference);
    }
  }
}

char getReverseBracket(char c) {
  switch (c) {
  case '(':
    return ')';

  case ')':
    return '(';

  case '[':
    return ']';

  case ']':
    return '[';
  default:
    printf("Error! Input is not a round or square bracket. Exiting...");
    exit(1);
  }
}

int isOpenBracket(char c) { return c == '(' || c == '['; }

int isSpaceCharacter(char c) { return c == ' '; }

int isWellFormed(Stack *helperStack) { return isEmptyStack(helperStack); }
