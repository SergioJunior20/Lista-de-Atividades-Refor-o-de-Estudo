#include <stdio.h>

int buscaTernaria(int arr[], int baixo, int alto, int chave) {
    if (alto >= baixo) {

        int meio1 = baixo + (alto - baixo) / 3;
        int meio2 = alto - (alto - baixo) / 3;


        if (arr[meio1] == chave) {
            return meio1;
        }

        if (arr[meio2] == chave) {
            return meio2;
        }

        if (chave < arr[meio1]) {
            return buscaTernaria(arr, baixo, meio1 - 1, chave);
        }

        else if (chave > arr[meio2]) {
            return buscaTernaria(arr, meio2 + 1, alto, chave);
        }

        else {
            return buscaTernaria(arr, meio1 + 1, meio2 - 1, chave);
        }
    }

    return -1;
}

void exibirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int chave = 49;

    printf("Array: ");
    exibirArray(arr, n);

    int resultado = buscaTernaria(arr, 0, n - 1, chave);

    if (resultado != -1) {
        printf("Elemento encontrado no indice %d\n", resultado);
    } else {
        printf("Elemento nao encontrado.\n");
    }

    return 0;
}
