#include "lista.h"
#include <limits.h>
#include <stdio.h>

int conta_nos_itr(Lista *lista) {
  int count = 0;
  Lista *helperList = lista;

  while (helperList != NULL) {
    count++;
    helperList = helperList->next;
  }
  return count;
}

int conta_nos_rec(Lista *lista) {
  int count = 1;

  if (lista == NULL) {
    return 0;
  }
  count += conta_nos_rec(lista->next);
  return count;
}

int procura_itr(Lista *lista, int elemento) {
  int index = 0;
  Lista *helperList = lista;

  while (helperList != NULL) {
    if (elemento == helperList->info) {
      return index;
    }
    index++;
    helperList = helperList->next;
  }

  return -1;
}

int procura_rec(Lista *lista, int elemento) {
  int index;

  if (lista == NULL) {
    return -1;
  }

  if (elemento == lista->info) {
    return 0;
  }

  index = procura_rec(lista->next, elemento);

  if (index >= 0) {
    index++;
  }

  return index;
}

int lista_max_itr(Lista *lista) {
  Lista *helperList = lista;
  int maxValue = INT_MIN;

  while (helperList != NULL) {
    if (helperList->info > maxValue) {
      maxValue = helperList->info;
    }
    helperList = helperList->next;
  }
  return maxValue;
}

/*Você pode usar outras funções aqui se achar necessário!*/
int lista_max_rec(Lista *lista) {
  int maxValue;

  if (lista == NULL) {
    return INT_MIN;
  }

  maxValue = lista_max_rec(lista->next);
  return lista->info > maxValue ? lista->info : maxValue;
}

int lista_soma_itr(Lista *lista) {
  int sum = 0;
  Lista *helperList = lista;

  if (helperList == NULL) {
    return sum;
  }

  while (helperList != NULL) {
    sum += helperList->info;
    helperList = helperList->next;
  }
  return sum;
}

int lista_soma_rec(Lista *lista) {
  int sum = 0;

  if (lista == NULL) {
    return sum;
  }
  sum += lista_soma_rec(lista->next);
  return sum + lista->info;
}

/*Você pode usar outras funções aqui se achar necessário!*/
void imprimir_invertida_itr(Lista *lista) {
  Lista *helperList = lista;
  int listLength = conta_nos_itr(lista);
  int infoArray[listLength];
  int i = 0;

  while (helperList != NULL && i <= listLength) {
    infoArray[i] = helperList->info;
    helperList = helperList->next;
    i++;
  }

  for (i = listLength - 1; i >= 0; i--) {
    printf("%d ", infoArray[i]);
  }
}

void imprimir_invertida_rec(Lista *lista) {
  if (lista != NULL) {
    imprimir_invertida_rec(lista->next);
    printf("%d ", lista->info);
  }
}

/*Função para criar uma lista encadeada vazia!*/
Lista *criar_lista(void) { return NULL; }

/*Função para inserir um elemento na cabeça de uma lista encadeada!*/
Lista *inserir(Lista *lista, int elem) {
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->info = elem;
  novo->next = lista;
  return novo;
}

/*Função para imprimir uma lista encadeada!*/
void imprimir_lista(Lista *lista) {
  Lista *v; /*var. para percorrer a lista*/
  printf("Lista: ");
  for (v = lista; v != NULL; v = v->next) {
    printf("%d ", v->info);
  }
  printf("\n");
}

/*Função para desalocar uma lista encadeda!*/
void destruir_lista(Lista *l) {
  Lista *aux;
  while (l != NULL) {
    aux = l->next;
    free(l);
    l = aux;
  }
}
