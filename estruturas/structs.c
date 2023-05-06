#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ERRO -1
#define TAM_PALAVRA 100
#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define V_RAND 30
#define A_RAND 500

typedef struct vertice {
    char *nomeVertice;
    struct vertice *prox;
    int rotulo;
} Vertice;

typedef struct {
    char **nomesVertice;
    int numVertices;
    Vertice **listaAdj;
} Grafo;

typedef struct fila{
    char** nomesVertice;
    Vertice* sentinela;
} Fila;