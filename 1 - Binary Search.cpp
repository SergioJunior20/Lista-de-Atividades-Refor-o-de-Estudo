#include <stdio.h>

int buscaBinaria(int arr[], int tamanho, int alvo) {
    int esquerda = 0, direita = tamanho - 1;
    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        if (arr[meio] == alvo) return meio;
        if (arr[meio] < alvo) esquerda = meio + 1;
        else direita = meio - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int resultado = buscaBinaria(arr, 7, 7);
    if (resultado != -1) 
        printf("Achou no indice %d\n", resultado);
    else 
        printf("Nao achou\n");
    return 0;
}
