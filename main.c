#define TAM 20000
#define SEED 1

#include <stdio.h>
#include <stdlib.h>
#include "proj2lib.h"
#include <time.h>
#include <locale.h>

int main()
{
    printf("TAMANHO: [%d]", TAM);
    printf("\nSEED: [%d]\n\n", SEED);
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    clock_t inicio, fim;
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

    if (array) {
    free(array);
    array = NULL;
    }
    Estrutura *array2 = (Estrutura*) malloc(TAM * sizeof(Estrutura));

    // Shell Sort
    // Tipo 1
    printf("\n\nShell Sort:\n\tTipo 1:\n");
    gerar_aleatorio(array2,TAM);
    calcularTempo(array2,TAM,3);

    // Tipo 2
    printf("\n\tTipo 2:\n");
    gerar_crescente(array2,TAM);
    calcularTempo(array2,TAM,3);

    // Merge Sort
    // Tipo 1
    printf("\n\nMerge Sort:\n\tTipo 1:\n");
    gerar_aleatorio(array2,TAM);
    calcularTempo(array2,TAM,4);
    // Tipo 2
    printf("\n\tTipo 2:\n");
    gerar_crescente(array2,TAM);
    calcularTempo(array2,TAM,4);

    // Quick Sort
    printf("\n\nQuick Sort:\n\tTipo 1:\n");
    // Tipo 1
            // Ordenação com pivô no limite superior
            gerar_aleatorio(array2,TAM);
            inicio = clock();
            quickSort(array2 , 0, TAM, particaoPivoSuperior);
            fim = clock();
            printf("\n\t\tTempo de execucao com pivô no limite superior: [%.3fs]!", (double)(fim - inicio) / CLOCKS_PER_SEC);

            // Ordenação com pivô no limite inferior
            gerar_aleatorio(array2,TAM);
            inicio = clock();
            quickSort(array2, 0, TAM, particaoPivoInferior);
            fim = clock();
            printf("\n\t\tTempo de execucao com pivô no limite inferior: [%.3fs]!", (double)(fim - inicio) / CLOCKS_PER_SEC);

            // Ordenação com pivô no meio do subvetor
            gerar_aleatorio(array2,TAM);
            inicio = clock();
            quickSort(array2, 0, TAM, particaoPivoMeio);
            fim = clock();
            printf("\n\t\tTempo de execucao com pivô no limite meio: [%.3fs]!", (double)(fim - inicio) / CLOCKS_PER_SEC);

    // Tipo 2
    printf("\n\tTipo 2:\n");
            // Ordenação com pivô no limite superior
            gerar_crescente(array2,TAM);
            inicio = clock();
            quickSort(array2, 0, TAM, particaoPivoSuperior);
            fim = clock();
            printf("\n\t\tTempo de execucao com pivô no limite superior: [%.3fs]!", (double)(fim - inicio) / CLOCKS_PER_SEC);

            // Ordenação com pivô no limite inferior
            gerar_crescente(array2,TAM);
            inicio = clock();
            quickSort(array2, 0, TAM, particaoPivoInferior);
            fim = clock();
            printf("\n\t\tTempo de execucao com pivô no limite inferior: [%.3fs]!", (double)(fim - inicio) / CLOCKS_PER_SEC);

            // Ordenação com pivô no meio do subvetor
            gerar_crescente(array2,TAM);
            inicio = clock();
            quickSort(array2, 0, TAM, particaoPivoMeio);
            fim = clock();
            printf("\n\t\tTempo de execucao com pivô no limite meio: [%.3fs]!", (double)(fim - inicio) / CLOCKS_PER_SEC);

    // Heap Sort
    // Tipo 1
    printf("\n\nHeap Sort:\n\tTipo 1:\n");
    gerar_aleatorio(array2,TAM);
    calcularTempo(array2,TAM,5);
    // Tipo 2
    printf("\n\tTipo 2:\n");
    gerar_crescente(array2,TAM);
    calcularTempo(array2,TAM,5);

    if (array2) {
    free(array2);
    array2 = NULL;
    }
    printf("\n\n\n");
    return 0;
}
