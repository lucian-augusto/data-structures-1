/* =============================================================================
 * Libraries
 * ========================================================================== */
#include <stdio.h>
#include <stdlib.h>

/* =============================================================================
 * Structs Declaration
 * ========================================================================== */
typedef struct _queue {
  int start;
  int end;
  int size;
  int *array;
} Queue;

/* =============================================================================
 * Function Prototype Header
 * ========================================================================== */
Queue *createQueue(int size);
int dequeue(Queue *f);
void destroyQueue(Queue *q);
void enqueue(Queue *f, int element);
int evaluateQueueSize(int size, int queueEnd);
int isEmpty(int queueStart, int queueEnd);

/* =============================================================================
 * Queue Creation/Destruction Functions
 * ========================================================================== */
/* Function that creates the queue, allocating necessary memory and setting
 * variables values. */
Queue *createQueue(int size) {
  // Allocating memory for the struct instance
  Queue *q = (Queue *)malloc(sizeof(Queue));

  // Allocating memory for the vector inside the queue struct
  q->array = (int *)malloc(size * sizeof(int));

  // Setting up the variables values
  q->size = size;
  q->start = 0;
  q->end = 0;

  return q;
}

/* Function that destroys the queue, deallocating the memory previously used.*/
void destroyQueue(Queue *q) {
  // Freeing the memory previously allocated to the queue's array
  free(q->array);

  // Now we can free the memory allocated to the actual queue struct
  free(q);
}

/* =============================================================================
 * Queue Operation Functions
 * ========================================================================== */
/*Funtion to add (enqueue) a new element to the array: */
void enqueue(Queue *q, int element) {
  if (!evaluateQueueSize(q->size, q->end)) {
    printf("Queue is full...");
  } else {
    q->array[q->end] = element;
    (q->end)++;
  }
}

/*Function to remove (dequeue) an element from the array: */
int dequeue(Queue *q) {
  int element = 0;

  if (isEmpty(q->start, q->end)) {
    printf("Queue is empty...");
  } else {
    element = q->array[q->start];
    (q->start)++;
  }

  return element;
}

/* =============================================================================
 * Helper Functions
 * ========================================================================== */
/* Function to evaluate if the queue is at it's maximum capacity. Should be
 * noted that the logic to include elements in the queue when some elements were
 * already removed isn't implemented. */
int evaluateQueueSize(int size, int queueEnd) {
  if (queueEnd >= size) {
    return 0;
  }
  return 1;
}

// Function to evaluate if the queue is empty or not.
int isEmpty(int queueStart, int queueEnd) {
  if (queueStart == queueEnd) {
    return 1;
  }
  return 0;
}

/* =============================================================================
 * Main Function
 * ========================================================================== */
int main() {

  /*Initializing the data structure*/
  Queue *fila = createQueue(10);

  /*Trying to add the element 1 to the queue*/
  int elem = 1;
  enqueue(fila, elem);

  /*Trying to add the element 2 to the queue*/
  elem = 2;
  enqueue(fila, elem);

  /*Trying to add the element 3 to the queue*/
  elem = 3;
  enqueue(fila, elem);

  /*Trying to add the element 4 to the queue*/
  elem = 4;
  enqueue(fila, elem);

  /*Trying to remove the element 1 from the queue*/
  printf("%d\n", dequeue(fila));

  /*Trying to remove the element 2 from the queue*/
  printf("%d\n", dequeue(fila));

  destroyQueue(fila);

  return 0;
}
