/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "queue.h"

/* =============================================================================
 * Queue Creation/Desctruction Functions
 * ========================================================================== */
/* Function that creates an empty queue (should not create any node, just return
 * NULL)! */
Queue *createQueue() { return NULL; }

/* Function that frees a queue node by node */
void freeQueue(Queue *q) {
  Queue *helperQueue;

  while (q != NULL) {
    helperQueue = q->next;
    free(q);
    q = helperQueue;
  }
}

/* =============================================================================
 * Queue Operation Functions
 * ========================================================================== */
/* Function that enqueues an element (insert it at the end of the linked list)!
 */
Queue *enqueue(Queue *q, int element) {
  Queue *helperQueue = q; // Storing the original memory address.
  Queue *newNode = (Queue *)malloc(sizeof(Queue));
  newNode->data = element;
  newNode->next = NULL;

  if (isEmptyQueue(q)) {
    return newNode;
  }

  /* Looping through all queue's nodes and storing the last node's memory
   * address */
  while (q->next != NULL) {
    q = q->next;
  }

  /* Making the last queue node point to the new node */
  q->next = newNode;

  /* Returning the queue's original memory address */
  return helperQueue;
}

/* Function that dequeues an element (remove it from the head of the linked
 * list)! */
Queue *dequeue(Queue *q) {
  if (isEmptyQueue(q)) {
    printf("Empty Queue! Exiting...");
    exit(1);
  }
  Queue *helperQueue = q->next;
  free(q);
  return helperQueue;
}

/* =============================================================================
 * Helper Functions
 * ========================================================================== */
/* Function that returns the first element of the queue (liked list's head)
 * without dequeueing it! */
int getFirstElement(Queue *q) { return q->data; }

/* Function that returns the length of a queue. */
int getQueueLength(Queue *q) {
  int length = 0;
  Queue *helperQueue = q;
  while (helperQueue != NULL) {
    length++;
    helperQueue = helperQueue->next;
  }

  return length;
}

/* Function that returns if the queue is empty! */
int isEmptyQueue(Queue *q) { return q == NULL; }
