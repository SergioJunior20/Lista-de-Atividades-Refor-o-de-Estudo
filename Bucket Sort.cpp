#include <stdio.h>
#include <stdlib.h>

#define BALDES 10 


void ordenacaoInsercao(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float chave = arr[i];
        int j = i - 1;



        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}


void ordenacaoBaldes(float arr[], int n) {

    float baldes[BALDES][n];
    int contagemBaldes[BALDES];


    for (int i = 0; i < BALDES; i++)
        contagemBaldes[i] = 0;

    for (int i = 0; i < n; i++) {
        int indiceBalde = n * arr[i];  
        baldes[indiceBalde][contagemBaldes[indiceBalde]++] = arr[i];
    }

    for (int i = 0; i < BALDES; i++) {
        if (contagemBaldes[i] > 0) {
            ordenacaoInsercao(baldes[i], contagemBaldes[i]);
        }
    }

    int indice = 0;
    for (int i = 0; i < BALDES; i++) {
        for (int j = 0; j < contagemBaldes[i]; j++) {
            arr[indice++] = baldes[i][j];
        }
    }
}

void exibirArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    exibirArray(arr, n);

    ordenacaoBaldes(arr, n);

    printf("\nArray ordenado:\n");
    exibirArray(arr, n);

    return 0;
}
