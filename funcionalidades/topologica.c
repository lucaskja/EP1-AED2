#include "kosarayu.c"

// USANDO O ALGORITMO MOSTRADO PELA PROFESSORA PARA FAZER A ORDENAÇÃO TOPOLÓGICA DOS COMPONENTES FORTEMENTE CONECTADOS
void DFSVisit(Grafo* G, int u, int* cor, Fila *Fila){
    cor[u] = CINZA;

    Vertice *a = G->listaAdj[u];

    while(a){
        if(cor[a->rotulo] == BRANCO){
            DFSVisit(G, a->rotulo, cor, Fila);  
        }
        a = a->prox;
    }

    cor[u] = PRETO;

    // QUANDO COLORIMOS O VERTICE DE PRETO, ADICIONAMOS ESSE VÉRTICE NA FILA
    Vertice *b = (Vertice*) malloc(sizeof(Vertice));
    b->rotulo = u;
    b->prox = Fila->sentinela->prox;
    Fila->sentinela->prox = b;
}

void DFS(Grafo* G, Fila *Fila){
    Fila->nomesVertice = G->nomesVertice;
    Fila->sentinela = (Vertice*) malloc(sizeof(Vertice));
    Fila->sentinela->prox = NULL;
    Fila->sentinela->rotulo = -1;

    int* cor = inicializaVetorInt(G->numVertices);

    for(int u = 0 ; u < G->numVertices ; u++){
        cor[u] = BRANCO;
    }

    for(int u = 0; u < G->numVertices; u++){
        if(cor[u] == BRANCO){
            DFSVisit(G, u, cor, Fila);
        }
    }
}

void imprimeFila(Fila* Fila){
    Vertice *u = Fila->sentinela->prox;

    while(u){
        printf("%s ", Fila->nomesVertice[u->rotulo]);
        u = u->prox;
    }
}