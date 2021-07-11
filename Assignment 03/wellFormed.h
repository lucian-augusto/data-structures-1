/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "stack.h"
#include <string.h>

/* =============================================================================
 * Functions
 * ========================================================================== */
int areEqual(char c1, char c2);

void evaluateBracketSequence(char *seq);

void evaluateSequenceElement(Stack *mainStack, Stack *helperStack, char c);

char getReverseBracket(char c);

int isOpenBracket(char c);

int isSpaceCharacter(char c);

int isWellFormed(Stack *helperStack);
