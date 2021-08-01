#include "deck.h"
#include <stdlib.h>

Deck *createDeck() { return NULL; }

/* Function that returns the coordinates stored at the linked list's head
 * (assume that Deck *d address points to the head)! */
Point getFront(Deck *d) {
  if (d != NULL) {
    return d->p;
  }
  exit(1);
}

/* Function that returns the coordinates stored at the linked list's rear
 * (Assume that Deck *d addres points to the head)! */
Point getRear(Deck *d) {
  if (d == NULL) {
    exit(1);
  }

  if (d->next == NULL) {
    return d->p;
  }

  return getRear(d->next);
}

/*Função para inserir na cabeça da lista encadeada (assuma que o endereço do
 * Deck *d aponta para a cabeça)!*/
Deck *insertFront(Deck *d, Point p, char field[][SIZE]) {
  Deck *new = (Deck *)malloc(sizeof(Deck));
  new->prev = NULL;
  new->next = d;
  if (d != NULL) {
    d->prev = new;
  }
  field[p.x][p.y] = '*'; /*Ponto inserido faz parte do corpo da Snake!*/
  new->p = p;

  return new;
}

/*Função para inserir na cauda da lista encadeada (assuma que o endereço do Deck
 * *d aponta para a cabeça)!*/
Deck *insertRear(Deck *d, Point p, char field[][SIZE]) {
  Deck *new = (Deck *)malloc(sizeof(Deck));
  new->next = NULL;
  new->p = p;
  if (d == NULL) {
    new->prev = NULL;
    return new;
  }

  Deck *helper = d;
  while (helper->next != NULL) {
    helper = helper->next;
  }
  new->prev = helper;
  new->prev->next = new;
  field[p.x][p.y] = '*'; /*Ponto inserido faz parte do corpo da Snake!*/

  return d;
}

/*Função para remover a cabeça da lista encadeada (assuma que o endereço do Deck
 * *d aponta para a cabeça)!*/
Deck *deleteFront(Deck *d, char field[][SIZE]) {
  if (d == NULL) {
    exit(1);
  }
  Deck *helper = d->next;
  field[d->p.x][d->p.y] = ' '; /*Ponto eliminado agora é marcado como vazio!*/
  free(d);
  helper->prev = NULL;
  return helper;
}

/*Função para remover a cauda da lista encadeada (assuma que o endereço do Deck
 * *d aponta para a cabeça)!*/
Deck *deleteRear(Deck *d, char field[][SIZE]) {
  if (d == NULL) {
    exit(1);
  }

  Deck *helper = d;

  while (helper->next != NULL) {
    helper = helper->next;
  }
  field[helper->p.x][helper->p.y] =
      ' '; /*Ponto eliminado agora é marcado como vazio!*/
  helper->prev->next = NULL;
  free(helper);
  return d;
}
