#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function that switches the elements in the given positions. */
void switchElements(int *a, int position1, int position2) {
  int helper = a[position1];
  a[position1] = a[position2];
  a[position2] = helper;
}

void printSequence(int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int quickFind(int *a, int left, int right, int k) {
  if (a == NULL || k < left || k > right) {
    printf("Null array or index out of bounds");
    exit(1);
  }
  int pivot = right;

  int i = left - 1;
  int j;
  for (j = left; j < right; j++) {
    if (a[pivot] > a[j]) {
      i++;
      switchElements(a, i, j);
    }
  }
  i++;
  switchElements(a, i, right);
  pivot = i;

  if (k < pivot) {
    return quickFind(a, left, pivot - 1, k);
  }

  if (k > pivot) {
    return quickFind(a, pivot + 1, right, k);
  }
  return a[k];
}

/*Função principal.*/
int main(int argc, char *argv[]) {
  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));
  int i;

  // int tamanho = 10;
  // int *vetor = (int *)malloc(tamanho * sizeof(int));
  // for (i = 0; i < tamanho; i++) {
  //   vetor[i] = rand() % (tamanho+1);
  //}

  int tamanho = 8;
  int vetor[] = {7, 1, 3, 10, 17, 2, 21, 9};

  printSequence(vetor, tamanho);
  start = clock();
  int pos = 2;
  printf("O elemento procurado na posição %d é %d\n", pos,
         quickFind(vetor, 0, tamanho - 1, pos));
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  // free(vetor);
  return 0;
}
