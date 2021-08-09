#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function that returns 1 if number1 is bigger than number2 and zero
 * otherwise. */
int isBigger(int number1, int number2) { return number1 > number2; }

/* Function that returns 1 if number1 is smaller than number2 and zero
 * otherwise. */
int isSmaller(int number1, int number2) { return number1 < number2; }

/* Function that switches the elements in the given positions. */
void switchElements(int *a, int position1, int position2) {
  int helper = a[position1];
  a[position1] = a[position2];
  a[position2] = helper;
}

void bubbleSort(int *a, int size) {
  int i, j;
  for (i = 0; i < size; i++) {
    for (j = 1; j < (size - i); j++) {
      if (isBigger(a[j - 1], a[j])) {
        switchElements(a, j - 1, j);
      }
    }
  }
}

void selectionSort(int *a, int size) {
  int currentSmallestNumberPosition;
  int i, j;
  for (i = 0; i < size; i++) {
    currentSmallestNumberPosition = i;
    for (j = i + 1; j < size; j++) {
      if (isSmaller(a[j], a[currentSmallestNumberPosition])) {
        currentSmallestNumberPosition = j;
      }
    }
    switchElements(a, i, currentSmallestNumberPosition);
  }
}

void insertionSort(int *a, int size) {
  int sortingKey;
  int i, j;
  for (i = 1; i < size; i++) {
    sortingKey = a[i];
    for (j = i - 1; j >= 0; j--) {
      if (isBigger(sortingKey, a[j])) {
        break;
      }
      a[j + 1] = a[j];
    }
    a[j + 1] = sortingKey;
  }
}

void imprimir(int *a, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d, ", a[i]);
  }
  printf("\n");
}

/* Function that returns 1 if the order of the elements is correct and zero
 * otherwise. */
int verificaOrdenacao(int *a, int size) {
  int i;
  for (i = 0; i < size - 1; i++) {
    if (a[i] > a[i + 1]) {
      return 0;
    }
  }
  return 1;
}

int main() {

  clock_t start, end;
  double elapsedTime;
  srand(time(NULL));

  int i;

  int size = 250000;

  int *v1 = (int *)malloc(size * sizeof(int));
  int *v2 = (int *)malloc(size * sizeof(int));
  int *v3 = (int *)malloc(size * sizeof(int));

  for (i = 0; i < size; i++) {
    v1[i] = rand() % (size + 1);
    v2[i] = rand() % (size + 1);
    v3[i] = rand() % (size + 1);
  }

  start = clock();
  // imprimir(v1, size);
  bubbleSort(v1, size);
  // imprimir(v1, size);
  end = clock();
  elapsedTime = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Tempo de execução (BubbleSort): %.2f\n", elapsedTime);
  if (!verificaOrdenacao(v1, size)) {
    printf("Erro: a ordenação do BubbleSort não está correta!\n");
  }

  start = clock();
  // imprimir(v2, size);
  selectionSort(v2, size);
  // imprimir(v2, size);
  end = clock();
  elapsedTime = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Tempo de execução (SelectionSort): %.2f\n", elapsedTime);
  if (!verificaOrdenacao(v2, size)) {
    printf("Erro: a ordenação do SelectionSort não está correta!\n");
  }

  start = clock();
  // imprimir(v3, size);
  insertionSort(v3, size);
  // imprimir(v3, size);
  end = clock();
  elapsedTime = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Tempo de execução (InsertionSort): %.2f\n", elapsedTime);
  if (!verificaOrdenacao(v3, size)) {
    printf("Erro: a ordenação do InsertionSort não está correta!\n");
  }

  free(v1);
  free(v2);
  free(v3);

  return 0;
}
/* Notes:
 * Results when running the program for 10 elements:
 * 0, 9, 10, 8, 5, 9, 4, 5, 3, 3,
 * 0, 3, 3, 4, 5, 5, 8, 9, 9, 10,
 * Tempo de execução (BubbleSort): 0.00
 * 0, 3, 2, 1, 2, 5, 6, 2, 4, 9,
 * 0, 1, 2, 2, 2, 3, 4, 5, 6, 9,
 * Tempo de execução (SelectionSort): 0.00
 * 4, 0, 8, 1, 2, 8, 1, 6, 9, 6,
 * 0, 1, 1, 2, 4, 6, 6, 8, 8, 9,
 * Tempo de execução (InsertionSort): 0.00
 * ----------------------------------------------------------------------------
 * Results when running the program for 100 elements (prints commented out):
 * Tempo de execução (BubbleSort): 0.00
 * Tempo de execução (SelectionSort): 0.00
 * Tempo de execução (InsertionSort): 0.00
 * -----------------------------------------------------------------------------
 * Results when running the program for 1000 elements (prints commented out):
 * Tempo de execução (BubbleSort): 0.00
 * Tempo de execução (SelectionSort): 0.00
 * Tempo de execução (InsertionSort): 0.00
 * -----------------------------------------------------------------------------
 * Results when running the program for 10000 elements (prints commented out):
 * Tempo de execução (BubbleSort): 0.48
 * Tempo de execução (SelectionSort): 0.22
 * Tempo de execução (InsertionSort): 0.11
 * -----------------------------------------------------------------------------
 * Results when running the program for 100000 elements (prints commented out):
 * Tempo de execução (BubbleSort): 47.65
 * Tempo de execução (SelectionSort): 20.94
 * Tempo de execução (InsertionSort): 10.88
 * -----------------------------------------------------------------------------
 * Results when running the program for 250000 elements (prints commented out):
 * Tempo de execução (BubbleSort): 296.29
 * Tempo de execução (SelectionSort): 132.27
 * Tempo de execução (InsertionSort): 69.11
 * */
