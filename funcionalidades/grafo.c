#include "init.c"

void adicionaAresta(Grafo *G, char *v, char *w, Vertice **vertices) {
    int lugarInsercao;
    Vertice *novaConexao = (Vertice*) malloc(sizeof(Vertice));
    
    for (int i = 0; i < G->numVertices; i++) {
        if (strcmp(vertices[i]->nomeVertice, v) == 0) {
            lugarInsercao = vertices[i]->rotulo;
        }
        
        if (strcmp(vertices[i]->nomeVertice, w) == 0) {
            novaConexao->nomeVertice = vertices[i]->nomeVertice;
            novaConexao->rotulo = vertices[i]->rotulo;
            novaConexao->prox = vertices[i]->prox;
        }
    }
    
    novaConexao->prox = G->listaAdj[lugarInsercao];
    G->listaAdj[lugarInsercao] = novaConexao;
}

void criaGrafo(Grafo *G, Vertice **vertices, char **entrada) {
    for(int i = 0; i < G->numVertices; i++) {
        char *nomeVertice = (char*) malloc(TAM_PALAVRA * sizeof(char));
        char *conexao = (char*) malloc(TAM_PALAVRA * sizeof(char));
        strcpy(nomeVertice, entrada[i]);
        strtok(nomeVertice, ":");
        strcpy(G->nomesVertice[i], nomeVertice);

        while ((conexao = strtok(NULL, ";")) != NULL) {
            if(conexao[0] == ' ') conexao +=1;
            adicionaAresta(G, nomeVertice, conexao, vertices);
        }
    }
}

Grafo* transposta(Grafo* G, Vertice** vertices) {
    Grafo* GR = inicializaGrafo(G->numVertices);
    for (int v = 0; v < G->numVertices; v++) 
        for (Vertice* a = (G->listaAdj[v]); a != NULL; a = a->prox)
        adicionaAresta(GR, a->nomeVertice, vertices[v]->nomeVertice, vertices);
    return GR;
}

void imprimeGrafo(Grafo* G){ 
    for (int i = 0; i < G->numVertices; i++) {
        printf("%s:", G->nomesVertice[i]);
        for (Vertice *p = G->listaAdj[i]; p != NULL; p = p->prox) {
            printf("%s;", G->nomesVertice[p->rotulo]);
        }
        printf("\n");
    }
}

int buscaVertice(Grafo* G, Vertice** vertices, char* name) {
    int i;
    for(i = 0; i < G->numVertices; i++) {
        if(strcmp(vertices[i]->nomeVertice, name) == 0) {
            return i;
        }
    }
    return ERRO;
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
                    adicionaAresta(G, vertices[v]->nomeVertice, vertices[w]->nomeVertice, vertices);
                }
            }
        }
        
    }

    return G;
}