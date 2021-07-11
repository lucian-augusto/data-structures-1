/* =============================================================================
 * Libraries
 * ========================================================================== */
#include <stdio.h>
#include <stdlib.h>

/* =============================================================================
 * Struct Definition
 * ========================================================================== */
typedef struct stack {
  int top;
  int size;
  int *array;
} Stack;

/* =============================================================================
 * Functions
 * ========================================================================== */
Stack *createStack(int size);

void destroyStack(Stack *s);

void push(Stack *s, int element);

int pop(Stack *s);

int isEmptyStack(Stack *s);

int isFullStack(Stack *s);
