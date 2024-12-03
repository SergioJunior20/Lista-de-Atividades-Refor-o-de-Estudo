#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[100];  
    int grade;       
} estudante;

void insertionSort(estudante arr[], int n) {
    int i, j;
    estudante chave;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].grade > chave.grade) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

void bucketSort(estudante estudantes[], int n) {
    int numBuckets = 10;
    estudante* buckets[numBuckets];
    int bucketCounts[numBuckets];

    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = (estudante*)malloc(sizeof(estudante) * n);  
        bucketCounts[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = estudantes[i].grade / 10;  
        buckets[bucketIndex][bucketCounts[bucketIndex]++] = estudantes[i];
    }

    for (int i = 0; i < numBuckets; i++) {
        if (bucketCounts[i] > 0) {
            insertionSort(buckets[i], bucketCounts[i]);
        }
    }

    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < bucketCounts[i]; j++) {
            estudantes[index++] = buckets[i][j];
        }
    }

    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i]);
    }
}

int interpolationSearch(estudante estudantes[], int n, int grade) {
    int baixo = 0, alto = n - 1;

    while (baixo <= alto && grade >= estudantes[baixo].grade && grade <= estudantes[alto].grade) {
        if (baixo == alto) {
            if (estudantes[baixo].grade == grade) {
                return baixo;
            }
            return -1;
        }

        int pos = baixo + ((double)(alto - baixo) / (estudantes[alto].grade - estudantes[baixo].grade)) * (grade - estudantes[baixo].grade);

        if (estudantes[pos].grade == grade) {
            return pos;
        }

        if (estudantes[pos].grade < grade) {
            baixo = pos + 1;
        } else {
            alto = pos - 1;
        }
    }

    return -1;  
}

void printStudent(const estudante* estudantes) {
    printf("Nome: %s, Nota: %d\n", estudantes->nome, estudantes->grade);
}

int main() {
    
    estudante estudantes[] = {
        {"João", 75},
        {"Maria", 85},
        {"Pedro", 65},
        {"Ana", 92},
        {"Lucas", 55},
        {"Fernanda", 89},
        {"Carlos", 80},
        {"Juliana", 90}
    };

    int n = sizeof(estudantes) / sizeof(estudantes[0]);

    bucketSort(estudantes, n);

    printf("Alunos ordenados por nota:\n");
    for (int i = 0; i < n; i++) {
        printStudent(&estudantes[i]);
    }

    int gradeToFind = 85;
    int result = interpolationSearch(estudantes, n, gradeToFind);

    if (result != -1) {
        printf("\nAluno com nota %d encontrado:\n", gradeToFind);
        printStudent(&estudantes[result]);
    } else {
        printf("\nAluno com nota %d nao encontrado.\n", gradeToFind);
    }

    return 0;
}
