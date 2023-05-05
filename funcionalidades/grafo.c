#include "init.c"

void copiarNomeVertices(Grafo *GT, Grafo *G) {
    for (int i = 0; i < GT->numVertices; i++) GT->nomesVertice[i] = strdup(G->nomesVertice[i]);
}

char **copiarEntrada(int n, char **entrada) {
    char** cEntrada = (char**) malloc(sizeof(char*));

    for (int i = 0; i < n; i++) cEntrada[i] = (char*) malloc(TAM_PALAVRA * sizeof(char));

    for (int i = 0; i < n; i++) cEntrada[i] = strdup(entrada[i]);
    
    return cEntrada;
}

int buscarVertice(Grafo* G, char* name) {
    for(int i = 0; i < G->numVertices; i++) {
        if(strcmp(G->nomesVertice[i], name) == 0) {
            return i;
        }
    }
    return ERRO;
}

int verticeExiste(Grafo *G, char *verticeOrigem, char *nome) {
  for (Vertice *p = G->listaAdj[buscarVertice(G, verticeOrigem)]; p != NULL; p = p->prox)
      if (strcmp(G->nomesVertice[buscarVertice(G, nome)], p->nomeVertice) == 0)
        return 0;
  return 1;
}

void adicionaArestaCFC(Grafo *G, char *v, char *w) {
    if (verticeExiste(G, v, w) == 0) return;
  
    Vertice *novaConexao = (Vertice*) malloc(sizeof(Vertice));
    novaConexao->nomeVertice = (char*) malloc(TAM_PALAVRA * sizeof(char));
    novaConexao->prox = (Vertice*) malloc(sizeof(char));

    novaConexao->nomeVertice = strdup(G->nomesVertice[buscarVertice(G, w)]);
    novaConexao->rotulo = buscarVertice(G, w);
    novaConexao->prox = G->listaAdj[buscarVertice(G, v)];
    
    G->listaAdj[buscarVertice(G, v)] = novaConexao;
}

void adicionaAresta(Grafo *G, char *v, char *w) {
    Vertice *novaConexao = (Vertice*) malloc(sizeof(Vertice));
    novaConexao->nomeVertice = (char*) malloc(TAM_PALAVRA * sizeof(char));
    novaConexao->prox = (Vertice*) malloc(sizeof(char));

    novaConexao->nomeVertice = strdup(G->nomesVertice[buscarVertice(G, w)]);
    novaConexao->rotulo = buscarVertice(G, w);
    novaConexao->prox = G->listaAdj[buscarVertice(G, v)];
    
    G->listaAdj[buscarVertice(G, v)] = novaConexao;
}

void criaGrafo(Grafo *G, char **entrada) {
    char **copiaEntrada = copiarEntrada(G->numVertices, entrada);

    for(int i = 0; i < G->numVertices; i++) {
        char *nomeVertice = strtok(copiaEntrada[i], ":");
        G->nomesVertice[i] = strdup(nomeVertice);
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

    free(copiaEntrada);
}

Grafo* transposta(Grafo* G) {
    Grafo* GT = inicializaGrafo(G->numVertices);
    copiarNomeVertices(GT, G);
    for (int v = 0; v < G->numVertices; v++) 
        for (Vertice* a = (G->listaAdj[v]); a != NULL; a = a->prox)
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