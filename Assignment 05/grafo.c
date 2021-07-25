#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

/* Função para criar um grafo representado como uma lista de adjacências com {V}
 * vértices de tamanho.*/
Grafo *criar_grafo(int V) {
  Grafo *g = (Grafo *)malloc(sizeof(Grafo));
  g->list = (No **)malloc(V * sizeof(No *));

  int i;
  for (i = 0; i < V; i++) {
    (g->list)[i] = NULL;
  }

  g->V = V;

  return g;
}

/* Função para destruir um grafo construído através de uma representação por
 * lista de adjacências.*/
void destruir_grafo(Grafo *G) {
  int i;
  for (i = 0; i < G->V; i++) {
    while (G->list[i] != NULL) {
      No *helper = G->list[i]->next;
      free(G->list[i]);
      G->list[i] = helper;
    }
  }
  free(G->list);

  free(G);
}

/* Função para imprimir um grafo construído através de uma representação por
 * lista de adjacências.*/
void imprimir_grafo(Grafo *G) {
  int i;
  for (i = 0; i < G->V; i++) {
    printf("%d -> ", i);
    No *helper = (G->list)[i];
    while (helper != NULL) {
      printf("%d ", helper->id);
      helper = helper->next;
    }
    printf("\n");
  }
}

/* Função para adicionar a aresta (ligação) entre os vértices {u,v} e {v,u} no
 * grafo {G}.
 * Adicione um novo vértice sempre no início da lista encadeada do respectivo
 * vértice.
 * Você pode dividir essa função em duas se achar necessário!*/
void adicionar_aresta(int u, int v, Grafo *G) {
  createNewNodeEdge(u, v, G);
  createNewNodeEdge(v, u, G);

  (G->E)++;
}

void createNewNodeEdge(int u, int v, Grafo *G) {
  No *n = (No *)malloc(sizeof(No));
  n->id = v;
  n->next = G->list[u];
  G->list[u] = n;
}
