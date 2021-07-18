/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "queue.h"
#include <stdio.h>

/* =============================================================================
 * Functions
 * ========================================================================== */
void captureInput(int *m, int *n);

Queue *fillQueue(Queue *q, int numberOfParticipants);

Queue *executeRound(Queue *q, int numberOfSteps);

Queue *killParticipant(Queue *q);
