#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void shellSort(int arr[], int n, int seq[], int seq_size) {
    for (int s = 0; s < seq_size; s++) {
        int gap = seq[s];
        
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void shellSequence(int n, int seq[], int *size) {
    int h = n / 2;
    int i = 0;
    while (h > 0) {
        seq[i++] = h;
        h /= 2;
    }
    *size = i;
}

void knuthSequence(int n, int seq[], int *size) {
    int h = 1;
    int i = 0;
    while (h < n) {
        seq[i++] = h;
        h = 3 * h + 1;
    }
    *size = i;
}

void hibbardSequence(int n, int seq[], int *size) {
    int k = 1;
    int i = 0;
    int h = 1;
    while (h < n) {
        seq[i++] = h;
        k++;
        h = pow(2, k) - 1;
    }
    *size = i;
}

double measureTime(void (*sortFunc)(int[], int, int[], int), int arr[], int n, int seq[], int seq_size) {
    clock_t inicio, fim;
    double cpu_time_used;

    inicio = clock();
    sortFunc(arr, n, seq, seq_size);
    fim = clock();

    cpu_time_used = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
	
    int sizes[] = {1000, 5000, 10000, 50000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
 

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        int arr[n], arr_copia[n];

        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100000;
        }

        int shell_seq[50], shell_size;
        int knuth_seq[50], knuth_size;
        int hibbard_seq[50], hibbard_size;

        shellSequence(n, shell_seq, &shell_size);
        knuthSequence(n, knuth_seq, &knuth_size);
        hibbardSequence(n, hibbard_seq, &hibbard_size);

        copyArray(arr, arr_copia, n);
        double shellTime = measureTime(shellSort, arr_copia, n, shell_seq, shell_size);
        printf("Shell Sort (sequencia original) - Tamanho da lista: %d, Tempo: %f segundos\n", n, shellTime);

        copyArray(arr, arr_copia, n);
        double knuthTime = measureTime(shellSort, arr_copia, n, knuth_seq, knuth_size);
        printf("Shell Sort (sequencia de Knuth) - Tamanho da lista: %d, Tempo: %f segundos\n", n, knuthTime);

        copyArray(arr, arr_copia, n);
        double hibbardTime = measureTime(shellSort, arr_copia, n, hibbard_seq, hibbard_size);
        printf("Shell Sort (sequencia de Hibbard) - Tamanho da lista: %d, Tempo: %f segundos\n", n, hibbardTime);

        printf("\n");
    }

    return 0;
}
