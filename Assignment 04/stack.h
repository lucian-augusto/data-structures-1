/* =============================================================================
 * Libraries
 * ========================================================================== */
#include <stdio.h>
#include <stdlib.h>

/* =============================================================================
 * Struct Definitions
 * ========================================================================== */
typedef struct stack {
  int data;
  struct stack *next;
} Stack;

/* =============================================================================
 * Functions
 * ========================================================================== */
Stack *createStack();

void freeStack(Stack *s);

Stack *push(Stack *s, int element);

Stack *pop(Stack *s);

int getTopElement(Stack *s);

int isEmptyStack(Stack *s);
