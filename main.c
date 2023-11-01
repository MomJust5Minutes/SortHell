#define TAM 40000
#define SEED 1

#include <stdio.h>
#include <stdlib.h>
#include "proj2lib.h"
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(SEED);

    Estrutura *array = (Estrutura*) malloc(TAM * sizeof(Estrutura));

    // Selection Sort
    // Tipo 1
    printf("Selection Sort:\n\tTipo 1:\n");
    gerar_aleatorio(array,TAM);
    calcularTempo(array,TAM,1);
    // Tipo 2
    printf("\n\tTipo 2:\n");
    gerar_crescente(array,TAM);
    calcularTempo(array,TAM,1);

    // Bubble Sort
    // Tipo 1
    printf("\n\nBubble Sort:\n\tTipo 1:\n");
    gerar_aleatorio(array,TAM);
    calcularTempo(array,TAM,2);
    // Tipo 2
    printf("\n\tTipo 2:\n");
    gerar_crescente(array,TAM);
    calcularTempo(array,TAM,2);

    // Shell Sort
    // Tipo 1
    printf("\n\nShell Sort:\n\tTipo 1:\n");
    gerar_aleatorio(array,TAM);
    calcularTempo(array,TAM,3);
    // Tipo 2
    printf("\n\tTipo 2:\n");
    gerar_crescente(array,TAM);
    calcularTempo(array,TAM,3);

    // Merge Sort
    // Tipo 1
    printf("\n\nMerge Sort:\n\tTipo 1:\n");
    gerar_aleatorio(array,TAM);
    calcularTempo(array,TAM,4);
    // Tipo 2
    printf("\n\tTipo 2:\n");
    gerar_crescente(array,TAM);
    calcularTempo(array,TAM,4);

    // Quick Sort
    // Tipo 1
    printf("\n\nQuick Sort:\n\tTipo 1:\n");
    gerar_aleatorio(array,TAM);
    calcularTempo(array,TAM,5);
    // Tipo 2
    printf("\n\tTipo 2:\n");
    gerar_crescente(array,TAM);
    calcularTempo(array,TAM,5);

    // Heap Sort
    // Tipo 1
    printf("\n\nHeap Sort:\n\tTipo 1:\n");
    gerar_aleatorio(array,TAM);
    calcularTempo(array,TAM,6);
    // Tipo 2
    printf("\n\tTipo 2:\n");
    gerar_crescente(array,TAM);
    calcularTempo(array,TAM,6);

    free(array);
    printf("\n\n\n");
    return 0;
}
