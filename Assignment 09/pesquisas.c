#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function that counts the number of lines in a file. */
int countLines(FILE *file) {
  int numberOfLines = 0;
  if (file == NULL) {
    return numberOfLines;
  }
  while (!feof(file)) {
    char c;
    fscanf(file, "%c", &c);
    if (c == '\n') {
      numberOfLines++;
    }
  }
  rewind(file);
  return (numberOfLines - 1);
}

/* Linear Search. */
int linearSearch(char **dictionary, int numberOfLines, char word[]) {
  int i;
  for (i = 0; i < numberOfLines; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      return i;
    }
  }
  return -1;
}

/* Iteractive Binary Search. */
int iteractiveBinarySearch(char **dictionary, int numberOfLines, char word[]) {
  int currentLine = 0;
  int lowerInterval = 0;
  int higherInterval = numberOfLines - 1;
  int value;

  while (lowerInterval <= higherInterval) {
    currentLine = (lowerInterval + higherInterval) / 2;

    value = strcmp(word, dictionary[currentLine]);

    if (value > 0) {
      lowerInterval = currentLine + 1;
    } else if (value < 0) {
      higherInterval = currentLine - 1;
    } else {
      return currentLine;
    }
  }

  return -1;
}

/* Recursive Binary Search. */
int recursiveBinarySearch(char **dictionary, int left, int right, char word[]) {
  if (left > right) {
    return -1;
  }
  int currentLine = (left + right) / 2;
  int compValue = strcmp(word, dictionary[currentLine]);

  if (compValue > 0) {
    return recursiveBinarySearch(dictionary, currentLine + 1, right, word);
  }

  if (compValue < 0) {
    return recursiveBinarySearch(dictionary, left, currentLine - 1, word);
  }

  return currentLine;
}

/* Main Function. */
int main(int argc, char *argv[]) {

  int nbuscas = 1;

  int p;

  clock_t start, end;

  double elapsed_time;

  /*Abrindo o arquivo:*/
  FILE *file = fopen("palavras.txt", "r");

  /*Contando o número de linhas do arquivo:*/
  int numberOfLines = countLines(file);

  /*Alocando memória para armazenar as palavras:*/
  char **dictionary = (char **)malloc(numberOfLines * sizeof(char *));
  int i;
  for (i = 0; i < numberOfLines; i++) {
    dictionary[i] = (char *)malloc(256 * sizeof(char));
  }

  /*Lendo as dicionario do arquivo:*/
  i = 0;
  while (!feof(file)) {
    fscanf(file, "%s", dictionary[i]);
    i++;
  }

  /*Lendo a palavra a ser pesquisada:*/
  printf("Pesquise a palavra: ");
  char word[256];
  scanf("%s", word);

  /*Executando os algoritmos busca sequêncial:*/
  for (i = 0; i < nbuscas; i++) {
    p = linearSearch(dictionary, numberOfLines, word);
    if (p != -1) {
      printf("Achei a palavra %s no dicionário na posição %d!\n", word, p);
    } else {
      printf("Não achei a palavra %s no dicionário!\n", word);
    }
  }

  /*------------------------------------------------*/
  /*Executando os algoritmo busca binária iterativo:*/
  for (i = 0; i < nbuscas; i++) {
    p = iteractiveBinarySearch(dictionary, numberOfLines, word);
    if (p != -1) {
      printf("Achei a palavra %s no dicionário na posição %d!\n", word, p);
    } else {
      printf("Não achei a palavra %s no dicionário!\n", word);
    }
  }

  /*------------------------------------------------*/
  /*Executando o algoritmo de busca binária recursivo:*/
  for (i = 0; i < nbuscas; i++) {
    p = recursiveBinarySearch(dictionary, 0, numberOfLines - 1, word);
    if (p != -1) {
      printf("Achei a palavra %s no dicionário na posição %d!\n", word, p);
    } else {
      printf("Não achei a palavra %s no dicionário!\n", word);
    }
  }

  /*------------------------------------------------*/
  /*Liberando a memória:*/
  for (i = 0; i < numberOfLines; i++) {
    free(dictionary[i]);
  }
  free(dictionary);
  fclose(file);
  return 0;
}
