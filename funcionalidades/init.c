#include "../estruturas/structs.c"

Grafo *inicializaGrafo(int numVertices) {
    Grafo *G = (Grafo*) malloc(sizeof(Grafo));

    G->numVertices = numVertices;
    G->nomesVertice = (char**) malloc (sizeof(char*)*numVertices);
    G->listaAdj = (Vertice**) malloc(numVertices * sizeof(Vertice*));

    for (int i = 0; i < numVertices; i++) {
        G->listaAdj[i] = NULL;
        G->nomesVertice[i] = (char*) malloc (sizeof(char)*TAM_PALAVRA);
    }

    return G;
}

Vertice **inicializaVertices(int numVertices) {
    Vertice **vertices = (Vertice**) malloc(numVertices * sizeof(Vertice*));
    
    for (int i = 0; i < numVertices; i++) vertices[i] = (Vertice*) malloc(sizeof(Vertice));

    return vertices;
}

Fila *inicializaFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));

    return fila;
}

int *inicializaCor(int numVertices) {
    int *cor = (int*) malloc(numVertices * sizeof(int));
    
    return cor;
}

int *inicializaDescoberto(int numVertices) {
    int *d = (int*) malloc(numVertices * sizeof(int));
    
    return d;
}

int *inicializaFinalizado(int numVertices) {
    int *f = (int*) malloc(numVertices * sizeof(int));
    
    return f;
}

int *inicializaComponenteFortementeConectado(int numVertices) {
    int *cfc = (int*) malloc(numVertices * sizeof(int));

    return cfc;
}

int *inicializaVisitados(int numVertices) {
    int *visitados = (int*) malloc(numVertices * sizeof(int));

    return visitados;
}