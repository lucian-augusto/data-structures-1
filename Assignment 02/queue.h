#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
  int start;  /*guarda o inicio da fila*/
  int end;    /*guarda o fim da fila*/
  int size;   /*tamanho da fila*/
  int *array; /*vetor de elementos inteiros*/
} Queue;

Queue *createQueue(int size);

void enqueue(Queue *q, int e);

int dequeue(Queue *q);

int empty(Queue *q);

int full(Queue *q);

void free_queue(Queue *q);

int getFirstQueueElement(Queue *q);

int getQueueSize(Queue *q);

void printFirstQueueElement(Queue *q);
