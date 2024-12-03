#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mergeStrings(char *arr[], int esquerda, int meio, int direita) {
  int n1 = meio - esquerda + 1;
  int n2 = direita - meio;

  char *L[n1], *R[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[esquerda + i];
  for (int i = 0; i < n2; i++)
    R[i] = arr[meio + 1 + i];

  int i = 0, j = 0, k = esquerda;

  while (i < n1 && j < n2) {
    if (strcmp(L[i], R[j]) <= 0) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSortStrings(char *arr[], int esquerda, int direita) {
  if (esquerda < direita) {
    int meio = esquerda + (direita - esquerda) / 2;

    mergeSortStrings(arr, esquerda, meio);
    mergeSortStrings(arr, meio + 1, direita);

    mergeStrings(arr, esquerda, meio, direita);
  }
}

void printStringArray(char *arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%s ", arr[i]);
  printf("\n");
}

int main() {

  char *arr[] = {"banana", "laranja", "cereja", "mertilo", "damasco"};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("Array original de strings: \n");
  printStringArray(arr, arr_size);

  mergeSortStrings(arr, 0, arr_size - 1);

  printf("\nArray de strings ordenado: \n");
  printStringArray(arr, arr_size);
  return 0;
}
