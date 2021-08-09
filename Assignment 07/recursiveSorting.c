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
  if (size == 1) {
    return;
  }

  int i;
  for (i = 0; i < size - 1; i++) {
    if (isBigger(a[i], a[i + 1])) {
      switchElements(a, i, i + 1);
    }
  }

  bubbleSort(a, size - 1);
}

void selectionSort(int *a, int size) {
  if (size == 0) {
    return;
  }

  int i;
  int currentBiggestNumberPosition = size - 1;
  for (i = 0; i < size; i++) {
    if (isBigger(a[i], a[currentBiggestNumberPosition])) {
      currentBiggestNumberPosition = i;
    }
  }

  if (currentBiggestNumberPosition != size - 1) {
    switchElements(a, size - 1, currentBiggestNumberPosition);
  }

  selectionSort(a, size - 1);
}

void insertionSort(int *a, int size) {
  if (size == 0) {
    return;
  }

  insertionSort(a, size - 1);

  int sortingKey = a[size - 1];

  int i;
  for (i = size - 2; i >= 0; i--) {
    if (isSmaller(a[i], sortingKey)) {
      break;
    }
    a[i + 1] = a[i];
  }
  a[i + 1] = sortingKey;
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
 * 4, 0, 3, 10, 7, 3, 3, 5, 5, 8,
 * 0, 3, 3, 3, 4, 5, 5, 7, 8, 10,
 * Tempo de execução (BubbleSort): 0.00
 * 10, 3, 8, 4, 8, 8, 7, 9, 7, 0,
 * 0, 3, 4, 7, 7, 8, 8, 8, 9, 10,
 * Tempo de execução (SelectionSort): 0.00
 * 6, 6, 3, 7, 4, 5, 10, 8, 1, 9,
 * 1, 3, 4, 5, 6, 6, 7, 8, 9, 10,
 * Tempo de execução (InsertionSort): 0.00
 * -----------------------------------------------------------------------------
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
 * Tempo de execução (InsertionSort): 0.13
 * -----------------------------------------------------------------------------
 * Results when running the program for 100000 elements (prints commented out):
 * Tempo de execução (BubbleSort): 46.81
 * Tempo de execução (SelectionSort): 22.07
 * Tempo de execução (InsertionSort): 12.70
 * -----------------------------------------------------------------------------
 * Results when running the program for 250000 elements (prints commented out):
 * Tempo de execução (BubbleSort): 291.56
 * Tempo de execução (SelectionSort): 135.11
 * Tempo de execução (InsertionSort): 71.52
 * */
