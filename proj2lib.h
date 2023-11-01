#ifndef PROJ2LIB_H_INCLUDED
#define PROJ2LIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct item{
    int chave;
    double valor;
} Estrutura;

void trocar(Estrutura *a, Estrutura *b) {
    Estrutura temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(Estrutura *v, int n) {
    int i, j;
    for (i = 1; i < n; i++) {
       for(j = i; j >= 1; j--) {
            if (v[j-1].chave < v[j].chave) { // Comparação invertida para ordem decrescente
                trocar(&v[j-1], &v[j]);
            }
       }
    }
}

void bubbleSort(Estrutura *v, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
       for(j = 1; j < n-i; j++) {
            if (v[j].chave > v[j-1].chave) { // Comparação invertida para ordem decrescente
                trocar(&v[j-1], &v[j]);
            }
       }
    }
}

void shellSort(Estrutura *v, int n) {
    int i, j, h;
    Estrutura aux;

    for (h=1; h < n; h = 3*h+1);

    while (h > 0) {
        h = (h-1)/3;
        for (i = h; i < n; i++) {
            aux = v[i];
            j = i;

            while (j - h >= 0 && v[j - h].chave < aux.chave) { // Comparação invertida para ordem decrescente e adicionado lógica para evitar out of bounds
                v[j] = v[j - h];
                j -= h;
                if (j<h) break;
            }
            v[j] = aux;
        }
    }
}

void merge(Estrutura *v, int *c, int i, int m, int f) {
    int z, iv = i, ic = m + 1;
    for (z = i; z <= f; z++) c[z] = v[z].chave;
    z = i;
    while (iv <= m && ic <= f) {
            if (c[iv] <= c[ic]) {
                v[z++].chave = c[iv++];
            }
            else {
                v[z++].chave = c[ic++];
            }
        while (iv <= m) {
            v[z++].chave = c[iv++];
        }
        while (ic <= f) {
            v[z++].chave = c[ic++];
        }
    }
}

void sort(Estrutura *v, int *c, int i, int f) {
    if (i < f) {
        int m = (i + f) / 2;
        sort(v, c, i, m);
        sort(v, c, m + 1, f);
        if (v[m].chave < v[m + 1].chave) {
            merge(v, c, i, m, f);
        }
    }
}

void mergeSort(Estrutura *v, int n) {
    int *c = malloc(sizeof(int) * n);
    sort(v, c, 0, n-1);
    free(c);
}

int particao(Estrutura *v, int LI, int LS) {
    int aux, pivo, e = LI, d = LS;
    pivo = v[e].chave;  // Escolha do pivô como o valor da chave do primeiro elemento
    while (e < d) {
        while ((v[e].chave >= pivo) && (e < LS)) { e++; } // Condição invertida para elementos menores
        while ((v[d].chave < pivo) && (d > LI)) { d--; }  // Condição invertida para elementos maiores
        if (e < d) {
            aux = v[e].chave;
            v[e].chave = v[d].chave;  // Troca dos elementos de posição
            v[d].chave = aux;
        }
    }
    aux = v[LI].chave;
    v[LI].chave = v[d].chave;  // Troca do pivô com a posição final
    v[d].chave = aux;
    return d;
}

void quickSort(Estrutura *v, int LI, int LS)
{
    if(LI<LS)
    {
        int p;
        p = particao(v,LI,LS);
        quickSort(v,LI,p-1);
        quickSort(v,p+1,LS);
    }
}

// Função para ajustar um heap mínimo com raiz em dado índice (para ordenação decrescente)
void minHeapify(Estrutura *v, int n, int i) {
    int menor = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && v[esquerda].chave < v[menor].chave) {
        menor = esquerda;
    }

    if (direita < n && v[direita].chave < v[menor].chave) {
        menor = direita;
    }

    if (menor != i) {
        trocar(&v[i], &v[menor]);
        minHeapify(v, n, menor);
    }
}

// Função para construir um heap mínimo (para ordenação decrescente)
void buildMinHeap(Estrutura *v, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(v, n, i);
    }
}

// Função principal do Heap Sort para ordenação decrescente
void heapSort(Estrutura *v, int n) {
    buildMinHeap(v, n);

    for (int i = n - 1; i > 0; i--) {
        trocar(&v[0], &v[i]);
        minHeapify(v, i, 0);
    }
}

// A função para calcular o tempo de execução do algoritmo de ordenação
void calcularTempo(Estrutura arr[], int n, int escolha) {
    clock_t inicio;

    switch (escolha){
        case 1:
            inicio = clock();
            insertionSort(arr, n);
            break;
        case 2:
            inicio = clock();
            bubbleSort(arr, n);
            break;
        case 3:
            inicio = clock();
            shellSort(arr, n);
            break;
        case 4:
            inicio = clock();
            mergeSort(arr, n);
            break;
        case 5:
            inicio = clock();
            quickSort(arr, 0, n);
            break;
        case 6:
            inicio = clock();
            heapSort(arr, n);
            break;
    }


    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\t\tTempo de execucao: [%.3fs]!",tempo);
}

// Função para gerar valores aleatórios para as estruturas
void gerar_aleatorio(Estrutura estrutura[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        estrutura[i].chave = rand() % 100000; // Gera valores aleatórios para a chave (0-99999)
        estrutura[i].valor = 100.0 + ((double)rand() / RAND_MAX) * 99899.99;
    }
}

// Função para gerar a chave em ordem crescente e valores aleatórios para as estruturas
void gerar_crescente(Estrutura estrutura[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        estrutura[i].chave = i; // Gera a chave em ordem crescente
        estrutura[i].valor = 100.0 + ((double)rand() / RAND_MAX) * 99899.99; // Gera valores aleatórios para o número real (entre 100 e 99999.99)
    }
}



#endif // PROJ2LIB_H_INCLUDED
