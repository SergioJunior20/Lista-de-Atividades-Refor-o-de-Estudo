#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(char* a, char* b) {
    char* temp = a;
    a = b;
    b = temp;
}

int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void merge(char* arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char* L[n1], * R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
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

void mergeSort(char* arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);
        merge(arr, esquerda, meio, direita);
    }
}

int partition(char* arr[], int baixo, int alto) {
    char* pivot = arr[alto];
    int i = baixo - 1;

    for (int j = baixo; j < alto; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            char* temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    char* temp = arr[i + 1];
    arr[i + 1] = arr[alto];
    arr[alto] = temp;

    return i + 1;
}

void quickSort(char* arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = partition(arr, baixo, alto);
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

int binarySearch(char* arr[], int n, const char* palavra) {
    int esquerda = 0, direito = n - 1;

    while (esquerda <= direito) {
        int meio = esquerda + (direito - esquerda) / 2;

        int res = strcmp(arr[meio], palavra);

        if (res == 0)
            return meio;
        else if (res < 0)
            esquerda = meio + 1;
        else
            direito = meio - 1;
    }

    return -1;
}

void measureSortTime(void (*sortFunc)(char*[], int, int), char* arr[], int n, const char* sortName) {
    clock_t inicio = clock();
    sortFunc(arr, 0, n - 1);
    clock_t fim = clock();
    double time_taken = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("%s: %.6f segundos\n", sortName, time_taken);
}

int main() {
    
    char* palavras[] = {
        "banana", "laranja", "uva", "cereja", "morango", "kiwi", "abacaxi", "mertilo"
    };
    int n = sizeof(palavras) / sizeof(palavras[0]);

    char* palavrasCopy[n];
    for (int i = 0; i < n; i++) {
        palavrasCopy[i] = palavras[i];
    }
    measureSortTime(mergeSort, palavrasCopy, n, "Merge Sort");

    for (int i = 0; i < n; i++) {
            palavrasCopy[i] = palavras[i];
    }
    measureSortTime(quickSort, palavrasCopy, n, "Quick Sort");

    const char* wordToSearch = "uva";
    int resultado = binarySearch(palavras, n, wordToSearch);
    if (resultado != -1) {
        printf("A palavra '%s' foi encontrada na posicao %d.\n", wordToSearch, resultado);
    } else {
        printf("A palavra '%s' nao foi encontrada.\n", wordToSearch);
    }

    return 0;
}
