#include "grafo.c"

void preencheVertices(Vertice **vertices, int numVertices, char **entrada) {
    for (int i = 0; i < numVertices; i++) {
        char *nomeVertice = (char*) malloc(TAM_PALAVRA * sizeof(char));
        strcpy(nomeVertice, entrada[i]);
        strtok(nomeVertice, ":");
        
        vertices[i]->nomeVertice = nomeVertice;
        vertices[i]->prox = NULL;
        vertices[i]->rotulo = i;
    }
}