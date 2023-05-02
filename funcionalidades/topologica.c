#include "kosarayu.c"

void DFSVisit(Grafo* G, int u, int* cor, Fila *OTopo){
    cor[u] = CINZA;
    Vertice *a = G->listaAdj[u];
    while(a){
        if(cor[a->rotulo] == BRANCO){
            DFSVisit(G, a->rotulo, cor, OTopo);  
        }
        a = a->prox;
    }
    cor[u] = 3;
    Vertice *w = (Vertice*) malloc(sizeof(Vertice));
    w->rotulo = u;
    w->prox = OTopo->sentinela->prox;
    OTopo->sentinela->prox = w;
}

void DFS(Grafo* G, Fila *OTopo, Vertice** vertices){
    OTopo->sentinela = (Vertice*) malloc(sizeof(Vertice));
    OTopo->sentinela->prox = NULL;
    OTopo->sentinela->rotulo = -1;
    int* cor = inicializaCor(G->numVertices);
    for(int u = 0 ; u < G->numVertices ; u++){
        cor[u] = 0;
    }
    for(int u = 0; u < G->numVertices; u++){
        if(cor[u] == 0){
            DFSVisit(G, u, cor, OTopo);
        }
    }
}

void printList(Fila* OTopo){
    Vertice *u = OTopo->sentinela->prox;
    while(u!=NULL){
        printf("%s ", u->nomeVertice);
        u = u->prox;
    }
}