/* =============================================================================
 * Libraries
 * ========================================================================== */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* =============================================================================
 * Struct Definitions
 * ========================================================================== */
typedef struct queue {
  int data;
  struct queue *next;
} Queue;

/* =============================================================================
 * Functions
 * ========================================================================== */
Queue *createQueue();

void freeQueue(Queue *q);

Queue *enqueue(Queue *q, int element);

Queue *dequeue(Queue *q);

int getFirstElement(Queue *q);

int getQueueLength(Queue *q);

int isEmptyQueue(Queue *q);
