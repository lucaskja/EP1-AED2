#include "../estruturas/structs.c"

Grafo *inicializaGrafo(int numVertices) {
    Grafo *G = (Grafo*) malloc(sizeof(Grafo));

    G->numVertices = numVertices;
    G->nomesVertice = (char**) malloc (numVertices * sizeof(char*));
    G->listaAdj = (Vertice**) malloc(numVertices * sizeof(Vertice*));

    for (int i = 0; i < numVertices; i++) {
        G->listaAdj[i] = (Vertice*) malloc(numVertices * sizeof(Vertice));
        G->listaAdj[i] = NULL;
        G->nomesVertice[i] = (char*) malloc(TAM_PALAVRA * sizeof(char));
    }

    return G;
}

Fila *inicializaFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));

    return fila;
}

int *inicializaVetorInt(int numVertices) {
    int *vetorInt = (int*) malloc(numVertices * sizeof(int));
    
    return vetorInt;
}