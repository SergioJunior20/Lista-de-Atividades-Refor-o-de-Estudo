#include <stdio.h>
#include <math.h>
#include <time.h>

int buscaBinaria(int arr[], int baixo, int alto, int x) {
    if (alto >= baixo) {
        int meio = baixo + (alto - baixo) / 2;

        if (arr[meio] == x)
            return meio;

        if (arr[meio] > x)
            return buscaBinaria(arr, baixo, meio - 1, x);


        return buscaBinaria(arr, meio + 1, alto, x);
    }

    return -1; 
}


int buscaExponencial(int arr[], int n, int x) {

    if (arr[0] == x)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= x)
        i *= 2;

    return buscaBinaria(arr, i / 2, fmin(i, n - 1), x);
}

double medirTempo(int (*funcBusca)(int[], int, int), int arr[], int n, int x) {
    clock_t inicio, fim;
    double tempo_cpu_usado;

    inicio = clock();
    funcBusca(arr, n, x);
    fim = clock();

    tempo_cpu_usado = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo_cpu_usado;
}

int main() {

    int tamanhos[] = {100, 1000, 10000, 100000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int t = 0; t < num_tamanhos; t++) {
        int n = tamanhos[t];
        int arr[n];

        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        int x = n - 1; 

        double tempoExponencial = medirTempo(buscaExponencial, arr, n, x);
        printf("Busca Exponencial - Tamanho da lista: %d, Tempo: %f segundos\n", n, tempoExponencial);

        double tempoBinario = medirTempo((int (*)(int[], int, int))buscaBinaria, arr, n, x);
        printf("Busca Binaria - Tamanho da lista: %d, Tempo: %f segundos\n", n, tempoBinario);

        printf("\n");
    }

    return 0;
}
