#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionFirst(int arr[], int baixo, int alto) {
    int pivot = arr[baixo];  
    int i = baixo + 1;

    for (int j = baixo + 1; j <= alto; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[baixo], &arr[i - 1]);
    return i - 1;
}


int partitionLast(int arr[], int baixo, int alto) {
    int pivot = arr[alto];
    int i = baixo;

    for (int j = baixo; j < alto; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[alto]);
    return i;
}

int partitionMiddle(int arr[], int baixo, int alto) {
    int meio = baixo + (alto - baixo) / 2;
    swap(&arr[meio], &arr[alto]);  
    return partitionLast(arr, baixo, alto);
}

void quickSort(int arr[], int baixo, int alto, int pivotType) {
    if (baixo < alto) {
        int pi;

        if (pivotType == 1)
            pi = partitionFirst(arr, baixo, alto);     
        else if (pivotType == 2)
            pi = partitionLast(arr, baixo, alto);      
        else
            pi = partitionMiddle(arr, baixo, alto);    
        
        quickSort(arr, baixo, pi - 1, pivotType);
        quickSort(arr, pi + 1, alto, pivotType);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Quick Sort (Pivo: Primeiro Elemento):\n");
    quickSort(arr, 0, n - 1, 1);
    printArray(arr, n);

    int arr2[] = {10, 7, 8, 9, 1, 5};
    printf("\nQuick Sort (Pivo: Último Elemento):\n");
    quickSort(arr2, 0, n - 1, 2);
    printArray(arr2, n);

    int arr3[] = {10, 7, 8, 9, 1, 5};
    printf("\nQuick Sort (Pivo: Elemento do Meio):\n");
    quickSort(arr3, 0, n - 1, 3);
    printArray(arr3, n);

    return 0;
}
