/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "slotMachine.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* =============================================================================
 * Constants Definition
 * ========================================================================== */
#define REEL_AMOUNT 3
#define POSITION_AMOUNT 10

/* =============================================================================
 * Main Function
 * ========================================================================== */
int main() {
  srand(time(NULL)); // rand() function's seed.
  Queue **reels = constructSlots();

  gameLoop(reels);

  return 0;
}

/* =============================================================================
 * Slot Machine Function Implementations
 * ========================================================================== */
// Function that calculates the payout
int calculatePayout(int accumulatedTries, int multiplier) {
  return accumulatedTries * 10 * multiplier;
}

Queue **constructSlots() {
  /* Creating an array that contains the slots reels. Each reel is modeled
   * using a Queue. */
  Queue **reels = (Queue **)malloc(REEL_AMOUNT * sizeof(Queue *));

  int i;
  for (i = 0; i < REEL_AMOUNT; i++) {
    reels[i] = createQueue(POSITION_AMOUNT + 1);
    fillReel(reels[i], POSITION_AMOUNT);
  }

  return reels;
}

// Function that add the numbers to the reel (Queue).
void fillReel(Queue *reel, int elementAmount) {
  int i;
  if (elementAmount > getQueueSize(reel)) {
    printf("Error! Number of elements is bigger than the Queue size.");
    exit(1);
  }
  for (i = 0; i < elementAmount; i++) {
    enqueue(reel, i);
  }
}

// Function that "rolls" the reels (Queues) until a Jackpot happens.
void gameLoop(Queue **reels) {
  int loopsAmount = 0;
  do {
    playSlots(reels);
    loopsAmount++;
  } while (!isJackpot(reels));

  int payout = calculatePayout(loopsAmount, 1);

  printJackpot(payout);
}

/* Function that verifies if the elements in the first position in each reel
 * (Queue) is the same. */
int isJackpot(Queue **reels) {
  int isJackpot = 1;
  int i;
  for (i = 1; i < REEL_AMOUNT; i++) {
    if (getFirstQueueElement(reels[i - 1]) != getFirstQueueElement(reels[i])) {
      isJackpot = 0;
    }
  }
  return isJackpot;
}

// Function that runs the slot machine a single time.
void playSlots(Queue **reels) {
  rollSlotReels(reels);
  printReels(reels);
  printf("\n");
}

// Function that prints the Jackpot message and payout amount.
void printJackpot(int payout) {
  printf("JACKPOT!!!\nYour payout is $%02d.00", payout);
}

// Function that prints the first element of each reel (Queue).
void printReels(Queue **reels) {
  int i = 0;
  for (i = 0; i < REEL_AMOUNT; i++) {
    printFirstQueueElement(reels[i]);
    printf(" ");
  }
}

/* Function that generates a random number and "rolls" a reel that many times.
 * Effectively, this function removes and re-adds queue elements according to
 * the random-generated number. */
void rollSingleReel(Queue *reel) {
  int movesAmount = (rand() % 99) + 1;
  int i;

  for (i = 0; i < movesAmount; i++) {
    enqueue(reel, dequeue(reel));
  }
}

/* Function that "rolls" all the reels by looping and "rolling" each of them
 * separetly. */
void rollSlotReels(Queue **reels) {
  int i;
  for (i = 0; i < REEL_AMOUNT; i++) {
    rollSingleReel(reels[i]);
  }
}
