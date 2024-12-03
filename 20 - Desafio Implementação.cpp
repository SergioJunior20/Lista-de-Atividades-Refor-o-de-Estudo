#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int baixo, int alto);
int binarySearch(int arr[], int n, int chave);
int interpolationSearch(int arr[], int n, int chave);
int jumpSearch(int arr[], int n, int chave);
int exponentialSearch(int arr[], int n, int chave);
void printArray(int arr[], int size);
void merge(int arr[], int l, int m, int r);
int partition(int arr[], int baixo, int alto);
void swap(int* a, int* b);

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
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

int partition(int arr[], int baixo, int alto) {
    int pivot = arr[alto];
    int i = baixo - 1;

    for (int j = baixo; j < alto; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = partition(arr, baixo, alto);

        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

int binarySearch(int arr[], int n, int chave) {
    int baixo = 0, alto = n - 1;
    while (baixo <= alto) {
        int meio = baixo + (alto - baixo) / 2;
        if (arr[meio] == chave)
            return meio;
        else if (arr[meio] < chave)
            baixo = meio + 1;
        else
            alto = meio - 1;
    }
    return -1;
}

int interpolationSearch(int arr[], int n, int chave) {
    int baixo = 0, alto = n - 1;
    while (baixo <= alto && chave >= arr[baixo] && chave <= arr[alto]) {
        int pos = baixo + ((chave - arr[baixo]) * (alto - baixo)) / (arr[alto] - arr[baixo]);
        if (arr[pos] == chave)
            return pos;
        if (arr[pos] < chave)
            baixo = pos + 1;
        else
            alto = pos - 1;
    }
    return -1;
}

int jumpSearch(int arr[], int n, int chave) {
    int step = (int) sqrt(n);  
    int prev = 0;
    
    while (arr[(step < n) ? step : n - 1] < chave) {
        prev = step;
        step += (int) sqrt(n);
        if (prev >= n)
            return -1;
    }

    for (int i = prev; i < (step < n ? step : n); i++) {
        if (arr[i] == chave)
            return i;
    }

    return -1;
}

int exponentialSearch(int arr[], int n, int chave) {
    if (arr[0] == chave)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= chave)
        i *= 2;

    return binarySearch(arr + i / 2, (i < n ? i : n) - i / 2, chave);
}

void searchMenu(int arr[], int n) {
    int escolha, chave;
    printf("Escolha o algoritmo de busca:\n");
    printf("1. Binary Search\n");
    printf("2. Interpolation Search\n");
    printf("3. Jump Search\n");
    printf("4. Exponential Search\n");
    printf("Escolha (1-4): ");
    scanf("%d", &escolha);
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &chave);

    int result = -1;
    switch (escolha) {
        case 1:
            result = binarySearch(arr, n, chave);
            break;
        case 2:
            result = interpolationSearch(arr, n, chave);
            break;
        case 3:
            result = jumpSearch(arr, n, chave);
            break;
        case 4:
            result = exponentialSearch(arr, n, chave);
            break;
        default:
            printf("Escolha invalida!\n");
            return;
    }

    if (result != -1)
        printf("Elemento encontrado no indice %d.\n", result);
    else
        printf("Elemento nao encontrado.\n");
}

void sortMenu(int arr[], int n) {
    int escolha;
    printf("Escolha o algoritmo de ordenacao:\n");
    printf("1. Quick Sort\n");
    printf("2. Merge Sort\n");
    printf("Escolha (1-2): ");
    scanf("%d", &escolha);

    clock_t inicio, fim;
    inicio = clock();
    switch (escolha) {
        case 1:
            quickSort(arr, 0, n - 1);
            break;
        case 2:
            mergeSort(arr, 0, n - 1);
            break;
        default:
            printf("Escolha invalida!\n");
            return;
    }
    fim = clock();
    printf("Array ordenado: ");
    printArray(arr, n);
    double time_taken = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %.6f segundos.\n", time_taken);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int escolhe;
    printf("Escolha uma operacao:\n");
    printf("1. Algoritmo de Busca\n");
    printf("2. Algoritmo de Ordenacao\n");
    printf("Escolha (1-2): ");
    scanf("%d", &escolhe);

    if (escolhe == 1) {
        searchMenu(arr, n);
    } else if (escolhe == 2) {
        sortMenu(arr, n);
    } else {
        printf("Escolha invalida!\n");
    }

    return 0;
}
