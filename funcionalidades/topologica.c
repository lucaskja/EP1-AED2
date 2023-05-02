#include "kosarayu.c"

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
    Vertice *b = (Vertice*) malloc(sizeof(Vertice));
    b->rotulo = u;
    b->prox = Fila->sentinela->prox;
    Fila->sentinela->prox = b;
}

void DFS(Grafo* G, Fila *Fila, Vertice** vertices){
    Fila->nomesVertice = G->nomesVertice;
    Fila->sentinela = (Vertice*) malloc(sizeof(Vertice));
    Fila->sentinela->prox = NULL;
    Fila->sentinela->rotulo = -1;
    int* cor = inicializaCor(G->numVertices);
    for(int u = 0 ; u < G->numVertices ; u++){
        cor[u] = 0;
    }
    for(int u = 0; u < G->numVertices; u++){
        if(cor[u] == 0){
            DFSVisit(G, u, cor, Fila);
        }
    }
}

void imprimeFila(Fila* Fila, Vertice** vertices){
    Vertice *u = Fila->sentinela->prox;
    while(u){
        printf("%s ", Fila->nomesVertice[u->rotulo]);
        u = u->prox;
    }
}