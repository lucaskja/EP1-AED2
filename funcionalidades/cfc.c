#include "topologica.c"

char** criaListaDeNomes(Grafo *G, int* cfc, int k){
    char** nomeVertices = (char**) malloc(sizeof(char*)*k);
    int i, j, u;
    for(i = 0 ; i<k ; i++){
        nomeVertices[i] = (char*) malloc(sizeof(char) * 100);
    }
    i = u = 0;
    char aux [100] = "";
    char empty[] = "";
    while (i  < k){
        for(j = 0; j < G->numVertices; j++){
            if(cfc[j] == i){
                strcat(aux, G->nomesVertice[j]);
            }
        }
        strcpy(nomeVertices[i], aux);
        strcpy(aux, empty);
        i++;
    }
    return nomeVertices;
}
char* insereNovaAresta(Grafo *G, int* cfc, int i, Grafo *GCF, char** nomeVertices, Vertice** vertices){
    int j = 0;
    // for(int i = 0; i < G->numVertices; i++) printf("vertices[%i]->nomeVertice = '%s'", i, G->nomesVertice[i]);
    while(j < G->numVertices){
        if(cfc[j] == i){
            Vertice *vertice = G->listaAdj[j];
            while(vertice){
                if(cfc[vertice->rotulo] != i){
                    adicionaAresta(GCF, nomeVertices[i], nomeVertices[cfc[vertice->rotulo]], vertices);
                }
                vertice = vertice->prox;
            }
        }
        j++;
    }
}

Grafo *criaGrafoCFC(int k, Grafo *G, int* cfc, Vertice** vertices){
    char** nomeVertices = criaListaDeNomes(G, cfc, k);
    Grafo *GCF = inicializaGrafo(k);
    criaGrafo(GCF, vertices, nomeVertices);
    int i;
    for (i = 0 ; i < k ; i++){
        insereNovaAresta(G, cfc, i, GCF, nomeVertices, vertices); 
    }
    return GCF;
}