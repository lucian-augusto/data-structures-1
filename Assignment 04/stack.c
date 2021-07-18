/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "stack.h"

/* =============================================================================
 * Stack Creation/Destruction Functions
 * ========================================================================== */
/* Function that creates an empty stack (should not create any node, just return
 * NULL)! */
Stack *createStack() { return NULL; }

/* Function that frees a stack node by node */
void freeStack(Stack *s) {
  Stack *helperStack;

  while (s != NULL) {
    helperStack = s->next;
    free(s);
    s = helperStack;
  }
}

/* =============================================================================
 * Stack Operation Functions
 * ========================================================================== */
/* Function that adds an element to the stack (insert it at the head of the
 * linked list)! */
Stack *push(Stack *s, int element) {
  Stack *newNode = (Stack *)malloc(sizeof(Stack));
  newNode->data = element;
  newNode->next = s;

  return newNode;
}

/* Function that removes an element from the stack (remove it from the head of
 * the linked list)! */
Stack *pop(Stack *s) {
  if (isEmptyStack(s)) {
    printf("Stack is empty! Exiting...");
    exit(1);
  }
  return s->next;
}

/* =============================================================================
 * Helper Functions
 * ========================================================================== */
/* Function that returns the element on the top of the stack (liked list's head)
 * without dequeueing it! */
int getTopElement(Stack *s) {
  return s->data;
  ;
}

/* Function that returns if the stack is empty! */
int isEmptyStack(Stack *s) { return s == NULL; }
