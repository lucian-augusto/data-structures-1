/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "stack.h"

/* =============================================================================
 * Stack Creation/Destruction Functions
 * ========================================================================== */
/* Function to create a stack. */
Stack *createStack(int size) {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->top = 0;
  s->size = size;
  s->array = (int *)malloc(size * sizeof(int));
  return s;
}

/*Função para liberar a memória alocada.*/
void destroyStack(Stack *s) {
  free(s->array);
  free(s);
}

/* =============================================================================
 * Stack Manipulation Functions
 * ========================================================================== */
/* Function to insert an element into the stack. */
void push(Stack *s, int element) {
  if (isFullStack(s)) {
    printf("Stack is full! Exiting...\n");
    exit(1);
  }
  s->array[s->top] = element;
  s->top++;
}

/* Function to remove an element from the stack. */
int pop(Stack *s) {
  if (isEmptyStack(s)) {
    printf("Stack is empty! Exiting...\n");
    exit(1);
  }
  s->top--;
  return s->array[s->top];
}

/* =============================================================================
 * Stack Helper Functions
 * ========================================================================== */
/* Function that verifies if the stack is empty. */
int isEmptyStack(Stack *s) { return (s->top == 0); }

/* Function that verifies if the stack is full. */
int isFullStack(Stack *s) { return (s->top == s->size); }
