#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function that returns 1 if number1 is bigger than number2 and zero
 * otherwise. */
int isBigger(int number1, int number2) { return number1 > number2; }

/* Function that switches the elements in the given positions. */
void switchElements(int *a, int position1, int position2) {
  int helper = a[position1];
  a[position1] = a[position2];
  a[position2] = helper;
}

/* Function that returns 1 if the sorting is correct or 0 otherwise. */
int verifiySorting(int *a, int size) {
  int i;
  for (i = 0; i < size - 1; i++) {
    if (a[i] > a[i + 1]) {
      return 0;
    }
  }
  return 1;
}

void printSequence(int *a, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void quickSort(int *a, int left, int right) {
  if (a != NULL && left < right) {
    int pivot = right;

    int i = left - 1;
    int j;
    for (j = left; j < right; j++) {
      if (isBigger(a[pivot], a[j])) {
        i++;
        switchElements(a, i, j);
      }
    }
    i++;
    switchElements(a, i, right);
    pivot = i;

    quickSort(a, left, pivot - 1);
    quickSort(a, pivot + 1, right);
  }
}

void fillArrayAscendingOrder(int *a, int size) {
  int i;
  for (i = 0; i < size; i++) {
    a[i] = i;
  }
}

void fillArrayDescendingOrder(int *a, int size) {
  int i;
  for (i = 0; i < size; i++) {
    a[i] = size - i;
  }
}

void fillArrayRandomOrder(int *a, int size) {
  int i;
  for (i = 0; i < size; i++) {
    a[i] = rand() % (size + 1);
  }
}

void sortAndTime(int *a, int size) {
  clock_t start, end;
  double elapsed_time;
  // printSequence(a, size);
  start = clock();
  quickSort(a, 0, size - 1);
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Tempo de execução (Quick-Sort): %.2f\n", elapsed_time);
  if (!verifiySorting(a, size)) {
    printf("Erro: a ordenação não está correta!\n");
  }
  // printSequence(a, size);
}

/* Main Function. */
int main(int argc, char *argv[]) {
  srand(time(NULL));
  int i;
  int size = 1000000;
  int *a1 = (int *)malloc(size * sizeof(int));
  int *a2 = (int *)malloc(size * sizeof(int));
  int *a3 = (int *)malloc(size * sizeof(int));

  fillArrayRandomOrder(a1, size);
  fillArrayAscendingOrder(a2, size);
  fillArrayDescendingOrder(a3, size);

  printf("Random Order:\n");
  sortAndTime(a1, size);
  printf("\nAscending Order:\n");
  sortAndTime(a2, size);
  printf("\nDescending Order:\n");
  sortAndTime(a3, size);

  free(a1);
  free(a2);
  free(a3);
  return 0;
}

/* Notes:
 * Results when running the code for 10 elements:
 * Random Order:
 * 7 4 3 3 2 7 4 3 8 3
 * Tempo de execução (Quick-Sort): 0.00
 * 2 3 3 3 3 4 4 7 7 8
 *
 * Ascending Order:
 * 0 1 2 3 4 5 6 7 8 9
 * Tempo de execução (Quick-Sort): 0.00
 * 0 1 2 3 4 5 6 7 8 9
 *
 * Descending Order:
 * 10 9 8 7 6 5 4 3 2 1
 * Tempo de execução (Quick-Sort): 0.00
 * 1 2 3 4 5 6 7 8 9 10
 * -----------------------------------------------------------------------------
 * Results when running the code for 100 elements:
 * Random Order:
 * Tempo de execução (Quick-Sort): 0.00
 *
 * Ascending Order:
 * Tempo de execução (Quick-Sort): 0.00
 *
 * Descending Order:
 * Tempo de execução (Quick-Sort): 0.00
 * -----------------------------------------------------------------------------
 * Results when running the code for 1000 elements:
 * Random Order:
 * Tempo de execução (Quick-Sort): 0.00
 *
 * Ascending Order:
 * Tempo de execução (Quick-Sort): 0.00
 *
 * Descending Order:
 * Tempo de execução (Quick-Sort): 0.00
 * -----------------------------------------------------------------------------
 * Results when running the code for 10000 elements:
 * Random Order:
 * Tempo de execução (Quick-Sort): 0.00
 *
 * Ascending Order:
 * Tempo de execução (Quick-Sort): 0.43
 *
 * Descending Order:
 * Tempo de execução (Quick-Sort): 0.32
 * -----------------------------------------------------------------------------
 * Results when running the code for 100000 elements:
 * Random Order:
 * Tempo de execução (Quick-Sort): 0.02
 *
 * Ascending Order:
 * Tempo de execução (Quick-Sort): 42.89
 *
 * Descending Order:
 * Tempo de execução (Quick-Sort): 31.68
 * -----------------------------------------------------------------------------
 * Results when running the code for 1000000 elements:
 * Random Order:
 * Tempo de execução (Quick-Sort): 0.27
 *
 * Ascending Order:
 * segmentation fault: 11
 */
