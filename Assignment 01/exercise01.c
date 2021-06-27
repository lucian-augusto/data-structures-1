/* =============================================================================
 * Libraries
 * ========================================================================== */
#include <stdio.h>
#include <stdlib.h>

/* =============================================================================
 * Function Prototype Header
 * ========================================================================== */
int dequeue(int *array, int size, int *queueStart, int *queueEnd);
void enqueue(int *array, int element, int size, int *queueStart, int *queueEnd);
int evaluateQueueSize(int size, int queueEnd);
int isEmpty(int queueStart, int queueEnd);

/* =============================================================================
 * Queue Operation Functions
 * ========================================================================== */
/*Funtion to add (enqueue) a new element to the array: */
void enqueue(int *array, int element, int size, int *queueStart,
             int *queueEnd) {
  /*Besides the parameters that were initially included, we need to add the
   *parameters that control the queue's intial and final positions.
   *Also, as we're passing the parameters by themselves (not using a struct)
   *and the variables were declared on the block inside the main function, we
   *need to pass the addres so that they're actually modified. Otherwise, we'll
   *be only modifying a copy of the variable created when the function is
   *called. For this reason, we need to use a pointer to the quereStart and
   *queueEnd variables. However, since we don't have to update the size and
   *element variables outside this function, it's not necessary to pass a
   *pointer, we can use just their copies.*/

  if (!evaluateQueueSize(size, *queueEnd)) {
    printf("Queue full...");
    exit(1);
  }

  array[*queueEnd] = element;
  (*queueEnd)++;
}

/*Function to remove (dequeue) an element from the array: */
int dequeue(int *array, int size, int *queueStart, int *queueEnd) {
  /*Besides the parameters that were initially included, we need to add the
   *parameters that control the queue's intial and final positions.
   *Also, as we're passing the parameters by themselves (not using a struct)
   *and the variables were declared on the block inside the main function, we
   *need to pass the addres so that they're actually modified. Otherwise, we'll
   *be only modifying a copy of the variable created when the function is
   *called. For this reason, we need to use a pointer to the quereStart and
   *queueEnd variables. However, since we don't have to update the size and
   *element variables outside this function, it's not necessary to pass a
   *pointer, we can use just their copies?*/

  int element;

  if (isEmpty(*queueStart, *queueEnd)) {
    printf("Queue is empty...");
    return 1;
  }

  element = array[*queueStart];
  (*queueStart)++;
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

  int elem;

  /*Queue size*/
  int queueSize = 10;

  /* Adding variables to control the queue's initial and final position. Both
   * Start at zero, indicating that the queue is initially empty. */
  int queueStart = 0;
  int queueEnd = 0;

  /*allocating memoty for the queue array*/
  int *queue = (int *)malloc(queueSize * sizeof(int));

  /*Trying to add the element 1 to the queue*/
  elem = 1;
  enqueue(queue, elem, queueSize, &queueStart, &queueEnd);

  /*Trying to add the element 2 to the queue*/
  elem = 2;
  enqueue(queue, elem, queueSize, &queueStart, &queueEnd);

  /*Trying to add the element 3 to the queue*/
  elem = 3;
  enqueue(queue, elem, queueSize, &queueStart, &queueEnd);

  /*Trying to add the element 4 to the queue*/
  elem = 4;
  enqueue(queue, elem, queueSize, &queueStart, &queueEnd);

  /*Trying to remove the element 1 from the queue*/
  printf("%d\n", dequeue(queue, queueSize, &queueStart, &queueEnd));

  /*Trying to remove the element 2 from the queue*/
  printf("%d\n", dequeue(queue, queueSize, &queueStart, &queueEnd));

  // Freeing the memoty allocated to the queue array
  free(queue);

  return 0;
}
