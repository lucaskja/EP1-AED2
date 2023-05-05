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

int *inicializaVetorInt(int numVertices) {
    int *vetorInt = (int*) malloc(numVertices * sizeof(int));
    
    return vetorInt;
}