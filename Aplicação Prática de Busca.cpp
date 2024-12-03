#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char isbn[14];  
    char titulo[100]; 
    char autor[100]; 
} livro;

int compareBooks(const void* a, const void* b) {
    return strcmp(((livro*)a)->isbn, ((livro*)b)->isbn);
}

int binarySearch(livro livros[], int size, const char* isbn) {
    int esquerda = 0, direita = size - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        int cmp = strcmp(livros[meio].isbn, isbn);

        if (cmp == 0)
            return meio;

        if (cmp < 0)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }

    return -1;
}

void printBook(const livro* livro) {
    if (livro != NULL) {
        printf("ISBN: %s\n", livro->isbn);
        printf("Titulo: %s\n", livro->titulo);
        printf("Autor: %s\n", livro->autor);
    }
}

int main() {
    
    livro livros[] = {
        {"9780131103627", "C Programming Language", "Brian Kernighan & Dennis Ritchie"},
        {"9780131101630", "The Art of Computer Programming", "Donald Knuth"},
        {"9780131103702", "Introduction to Algorithms", "Thomas H. Cormen"},
        {"9780321751041", "Clean Code", "Robert C. Martin"},
        {"9780132350884", "Design Patterns", "Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides"}
    };

    int size = sizeof(livros) / sizeof(livros[0]);

    const char* isbnToFind = "9780321751041";

    int result = binarySearch(livros, size, isbnToFind);

    if (result != -1) {
        printf("Livro encontrado:\n");
        printBook(&livros[result]);
    } else {
        printf("Livro com ISBN %s nao encontrado.\n", isbnToFind);
    }

    return 0;
}
