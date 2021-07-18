/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "josephus.h"
#include <stdio.h>
#include <unistd.h>

/* =============================================================================
 * Main Function
 * ========================================================================== */
int main() {
  int i, m, n;
  printf("Josephus - Enter the death step and the number of participants: ");
  captureInput(&m, &n);
  Queue *q = createQueue();

  q = fillQueue(q, n);

  while (getQueueLength(q) > 1) {
    q = executeRound(q, m);
    usleep(300);
  }

  printf("Participant %d is the winner!!!", getQueueLength(q));

  freeQueue(q);
  return 0;
}

/* =============================================================================
 * Helper Functions
 * ========================================================================== */
void captureInput(int *m, int *n) {
  scanf("%d %d", m, n);
  while (*m < 1 || *n < 1) {
    printf("Both the death step and number of participants must be higher than "
           "1. Please, try again: ");
    scanf("%d %d", m, n);
  }
}

Queue *fillQueue(Queue *q, int numberOfParticipants) {
  int i;
  for (i = 1; i <= numberOfParticipants; i++) {
    q = enqueue(q, i);
  }
  printf("There are %d participants.\n", getQueueLength(q));
  return q;
}

Queue *executeRound(Queue *q, int numberOfSteps) {
  int i;
  int helper;
  for (i = 0; i < numberOfSteps; i++) {
    helper = getFirstElement(q);
    q = dequeue(q);
    q = enqueue(q, helper);
  }
  q = killParticipant(q);
  return q;
}

Queue *killParticipant(Queue *q) {
  int participantKilled = getFirstElement(q);
  q = dequeue(q);
  printf("Participant %d was killed!\n", participantKilled);
  return q;
}
