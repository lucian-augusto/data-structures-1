/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "queue.h"
#include <stdio.h>

/* =============================================================================
 * Queue Creation/Destruction Functions
 * ========================================================================== */
Queue *createQueue(int size) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->start = 0;
  q->end = 0;
  q->size = size;
  q->array = (int *)malloc(size * sizeof(int));
  return q;
}

void free_queue(Queue *q) {
  free(q->array);
  free(q);
}

/* =============================================================================
 * Queue Operations Functions (Exercise 01)
 * ========================================================================== */
/* Function that enqueues an element into a Circular Queue implemented using an
 * array.
 * Part of Exercise 01*/
void enqueue(Queue *q, int e) {
  if (full(q)) {
    printf("Queue Full!");
    exit(1); // Aborting execution
  }

  q->array[q->end] = e; // Storing new element into the current end position
  q->end = (q->end + 1) % q->size; /* Incrementing the end of the queue
                                    * parameter */
}

/* Function that dequeues an element from a Circular Queue implemented using an
 * array.
 * Part of Exercise 01 */
int dequeue(Queue *q) {
  if (empty(q)) {
    printf("Queue Empty!");
    exit(1); // Aborting execution
  }

  int e = q->array[q->start]; /* Storing the first element of the queue into a
                               * variable */
  q->start = (q->start + 1) % q->size; /* Incrementing the end of the queue
                                        * parameter, essentially removing from
                                        * the queue */

  return e; // Returning the removed element
}

/* =============================================================================
 * Queue Helper Functions
 * ========================================================================== */
int empty(Queue *q) { return (q->start == q->end); }

int full(Queue *q) { return (q->start == ((q->end + 1) % q->size)); }

/* =============================================================================
 * Slot Machine Helper Functions
 * ========================================================================== */
int getFirstQueueElement(Queue *q) { return q->array[0]; }

int getQueueSize(Queue *q) { return q->size; }

void printFirstQueueElement(Queue *q) { printf("%d", getFirstQueueElement(q)); }
