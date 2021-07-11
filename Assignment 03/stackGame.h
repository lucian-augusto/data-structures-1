/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* =============================================================================
 * Functions
 * ========================================================================== */
void callGameLoop();

void executeRound(Stack *s1, Stack *s2);

void fillStack(Stack *s, int elementAmount);

void moveElementsBetweenStacks(Stack *donor, Stack *recipient,
                               int elementAmount);

int playAgain();

void printWinnerMessage(int winner);

int shouldEndGame(Stack *s1, Stack *s2);
