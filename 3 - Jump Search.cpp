#include <stdio.h>
#include <math.h>
#include <time.h>

int buscaSaltos(int arr[], int n, int alvo) {
    int passo = sqrt(n); 
    int anterior = 0;


    while (arr[passo < n ? passo : n - 1] < alvo) {
        anterior = passo;
        passo += sqrt(n);
        if (anterior >= n) return -1; 
    }

    for (int i = anterior; i < (passo < n ? passo : n); i++) {
        if (arr[i] == alvo) return i; 
    }

    return -1;
}

int buscaBinaria(int arr[], int baixo, int alto, int alvo) {
    if (alto >= baixo) {
        int meio = baixo + (alto - baixo) / 2;

        if (arr[meio] == alvo) return meio;

        if (arr[meio] > alvo) return buscaBinaria(arr, baixo, meio - 1, alvo);

        return buscaBinaria(arr, meio + 1, alto, alvo);
    }

    return -1;
}

double medirTempoBuscaSaltos(int (*funcaoBusca)(int[], int, int), int arr[], int n, int x) {
    clock_t inicio, fim;
    double tempo_cpu_usado;

    inicio = clock();
    funcaoBusca(arr, n, x);
    fim = clock();

    tempo_cpu_usado = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo_cpu_usado;
}


double medirTempoBuscaBinaria(int (*funcaoBusca)(int[], int, int, int), int arr[], int baixo, int alto, int x) {
    clock_t inicio, fim;
    double tempo_cpu_usado;

    inicio = clock();
    funcaoBusca(arr, baixo, alto, x); 
    fim = clock();

    tempo_cpu_usado = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    return tempo_cpu_usado;
}

int main() {

    int tamanhos[] = {100, 1000, 10000, 100000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int s = 0; s < num_tamanhos; s++) {
        int n = tamanhos[s];
        int arr[n];

        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        int x = n - 1; 

        double tempoJump = medirTempoBuscaSaltos(buscaSaltos, arr, n, x);
        printf("Busca por Saltos - Tamanho da lista: %d, Tempo: %f segundos\n", n, tempoJump);

        double tempoBinary = medirTempoBuscaBinaria(buscaBinaria, arr, 0, n - 1, x);
        printf("Busca Binaria - Tamanho da lista: %d, Tempo: %f segundos\n", n, tempoBinary);

        printf("\n");
    }

    return 0;
}
