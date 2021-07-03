/* =============================================================================
 * Slot Machine Header File
 * ========================================================================== */

/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "queue.h"

/* =============================================================================
 * Headers
 * ========================================================================== */

int calculatePayout(int accumulatedTries, int multiplier);

Queue **constructSlots();

void fillReel(Queue *reel, int elementAmount);

void gameLoop(Queue **reels);

int isJackpot(Queue **reels);

void playSlots(Queue **reels);

void printJackpot(int payout);

void printReels(Queue **reels);

void rollSingleReel(Queue *reel);

void rollSlotReels(Queue **reels);
