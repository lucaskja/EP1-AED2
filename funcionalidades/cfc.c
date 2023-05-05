#include "topologica.c"

char** criaListaDeNomes(Grafo *G, int* cfc, int k){
    char** nomeVertices = (char**) malloc(sizeof(char*)*k);
    int i, j, u;
    for(i = 0 ; i<k ; i++){
        nomeVertices[i] = (char*) malloc(sizeof(char) * 100);
    }
    i = u = 0;
    char *aux = (char*) malloc(TAM_PALAVRA * sizeof(char));
    char *empty = (char*) malloc(TAM_PALAVRA * sizeof(char));
    while (i  < k){
        for(j = 0; j < G->numVertices; j++){
            if(cfc[j] == i){
                strcat(aux, G->nomesVertice[j]);
            }
        }
        nomeVertices[i] = strdup(aux);
        aux = strdup(empty);
        i++;
    }
    return nomeVertices;
}

void insereNovaAresta(Grafo *G, int* cfc, int i, Grafo *GCF, char** nomeVertices){
    int j = 0;
    while(j < G->numVertices){
        if(cfc[j] == i){
            Vertice *vertice = G->listaAdj[j];
            while(vertice){
                if(cfc[vertice->rotulo] != i){
                    adicionaAresta(GCF, nomeVertices[i], nomeVertices[cfc[vertice->rotulo]]);
                }
                vertice = vertice->prox;
            }
        }
        j++;
    }
}

Grafo *criaGrafoCFC(int k, Grafo *G, int* cfc){
    char** nomeVertices = criaListaDeNomes(G, cfc, k);
    Grafo *GCF = inicializaGrafo(k);
    criaGrafo(GCF, nomeVertices);
    for (int i = 0 ; i < k ; i++) insereNovaAresta(G, cfc, i, GCF, nomeVertices); 
    return GCF;
}