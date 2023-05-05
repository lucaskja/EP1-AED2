#include "init.c"

void copiarNomeVertices(Grafo *GT, Grafo *G) {
    for (int i = 0; i < GT->numVertices; i++) strcpy(GT->nomesVertice[i], G->nomesVertice[i]);
}

char **copiarEntrada(int n, char **entrada) {
    char** copiaEntrada = (char**) malloc(sizeof(char**));

    for (int i = 0; i < n; i++){ 
        copiaEntrada[i] = (char*) malloc(TAM_PALAVRA * sizeof(char));
        strcpy(copiaEntrada[i], entrada[i]);
    }
    
    return copiaEntrada;
}

int buscarVertice(Grafo* G, char* name) {
    for(int i = 0; i < G->numVertices; i++) {
        if(strcmp(G->nomesVertice[i], name) == 0) {
            return i;
        }
    }
    return ERRO;
}

void adicionaAresta(Grafo *G, char *v, char *w) {
    Vertice *novaConexao = (Vertice*) malloc(sizeof(Vertice));
    novaConexao->nomeVertice = (char*) malloc(TAM_PALAVRA * sizeof(char));
    novaConexao->prox = (Vertice*) malloc(sizeof(char));

    strcpy(novaConexao->nomeVertice, G->nomesVertice[buscarVertice(G, w)]);
    novaConexao->rotulo = buscarVertice(G, w);
    
    novaConexao->prox = G->listaAdj[buscarVertice(G, v)];
    G->listaAdj[buscarVertice(G, v)] = novaConexao;
}

void criaGrafo(Grafo *G, char **entrada) {
    char **copiaEntrada = copiarEntrada(G->numVertices, entrada);

    for(int i = 0; i < G->numVertices; i++) {
        char *nomeVertice = strtok(copiaEntrada[i], ":");
        strcpy(G->nomesVertice[i], nomeVertice);
    }

    for(int i = 0; i < G->numVertices; i++) {
        strtok(entrada[i], ":");
        char *conexao = strtok(NULL, ";");
        while (conexao != NULL) {
            if (conexao[0] == ' ') conexao += 1;
            adicionaAresta(G, G->nomesVertice[i], conexao);
            conexao = strtok(NULL, ";");
        }
    }
}

Grafo* transposta(Grafo* G) {
    Grafo* GT = inicializaGrafo(G->numVertices);
    copiarNomeVertices(GT, G);
    for (int v = 0; v < G->numVertices; v++) 
        for (Vertice *a = G->listaAdj[v]; a != NULL; a = a->prox)
            adicionaAresta(GT, a->nomeVertice, G->nomesVertice[v]);
    return GT;
}

void imprimeGrafo(Grafo* G){ 
    for (int i = 0; i < G->numVertices; i++) {
        printf("%s: ", G->nomesVertice[i]);
        for (Vertice *p = G->listaAdj[i]; p != NULL; p = p->prox) {
            printf("%s; ", G->nomesVertice[p->rotulo]);
        }
        printf("\n");
    }
}

Grafo *geradorDeGrafoAleatorio(int numVertices, int numArestas) {
    double prob = (double) numArestas / (numVertices * (numVertices - 1));

    Grafo *G = inicializaGrafo(numVertices);
    Vertice **vertices = inicializaVertices(numVertices);

    for (int i = 0; i < numVertices; i++) {
        char *nomeVertice = (char*) malloc(TAM_PALAVRA * sizeof(char));
        sprintf(nomeVertice, "%d", i);
        vertices[i]->rotulo = i;
        vertices[i]->nomeVertice = nomeVertice;
    }

    for (int v = 0; v < numVertices; v++) {
        for (int w = 0; w < numVertices; w++){
            if(v != w) {
                if(rand() < prob * (RAND_MAX + 1.0)) {
                    adicionaAresta(G, vertices[v]->nomeVertice, vertices[w]->nomeVertice);
                }
            }
        }
    }

    return G;
}