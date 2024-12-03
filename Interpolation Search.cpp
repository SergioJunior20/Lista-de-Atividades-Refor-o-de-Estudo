#include <stdio.h>

int interpolationSearch(int arr[], int n, int x) {
    int baixo = 0, alto = n - 1;

    while (baixo <= alto && x >= arr[baixo] && x <= arr[alto]) {
        if (baixo == alto) {
            if (arr[baixo] == x) return baixo;
            return -1;
        }
        int pos = baixo + ((double)(alto - baixo) / (arr[alto] - arr[baixo]) * (x - arr[baixo]));

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            baixo = pos + 1;

        else
            alto = pos - 1;
    }
    return -1; 
}

int binarySearch(int arr[], int baixo, int alto, int x) {
    if (alto >= baixo) {
        int meio = baixo + (alto - baixo) / 2;

        if (arr[meio] == x)
            return meio;

        if (arr[meio] > x)
            return binarySearch(arr, baixo, meio - 1, x);

        return binarySearch(arr, meio + 1, alto, x);
    }

    return -1; 
}


void testSearches(int arr[], int n, int x) {
    printf("Buscando valor %d...\n", x);

  
    int resultInterpolation = interpolationSearch(arr, n, x);
    if (resultInterpolation != -1)
        printf("Interpolation Search encontrou o valor no indice %d\n", resultInterpolation);
    else
        printf("Interpolation Search nao encontrou o valor\n");


    int resultBinary = binarySearch(arr, 0, n - 1, x);
    if (resultBinary != -1)
        printf("Binary Search encontrou o valor no indice %d\n", resultBinary);
    else
        printf("Binary Search nao encontrou o valor\n");

    printf("\n");
}

int main() {

    int arr_uniforme[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n_uniforme = sizeof(arr_uniforme) / sizeof(arr_uniforme[0]);

    int arr_nao_uniforme[] = {10, 22, 35, 47, 53, 68, 72, 81, 93, 101};
    int n_nao_uniforme = sizeof(arr_nao_uniforme) / sizeof(arr_nao_uniforme[0]);

    printf("Testando com lista de intervalos uniformes:\n");
    testSearches(arr_uniforme, n_uniforme, 70);
    testSearches(arr_uniforme, n_uniforme, 25);

    printf("Testando com lista de intervalos nao uniformes:\n");
    testSearches(arr_nao_uniforme, n_nao_uniforme, 68);
    testSearches(arr_nao_uniforme, n_nao_uniforme, 50);

    return 0;
}
