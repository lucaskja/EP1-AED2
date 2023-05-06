#include "lerEntrada.c"


void DfsTransposta(Grafo *GT, int v, int* d, int* f) { 
    d[v] = tempod++; 
    for (Vertice* a = GT->listaAdj[v]; a != NULL; a = a->prox)
        if (d[a->rotulo] == -1) 
            DfsTransposta(GT, a->rotulo, d, f); 
    f[v] = tempof++;
}

void DfsKosarayu(Grafo *G, int v, int *cfc, int k) { 
    cfc[v] = k;
    for (Vertice *a = G->listaAdj[v]; a != NULL; a = a->prox)
        if (cfc[a->rotulo] == -1) 
            DfsKosarayu(G, a->rotulo, cfc, k);
}

int kosarayu1(Grafo* G, int* visitados, int* cfc, int* d, int* f){
    // FASE 1 DO KOSARAYU
    Grafo* GT = transposta(G);
    tempod = tempof = 0;
    int v;

    for (v = 0; v < GT->numVertices; v++) d[v] = -1;

    for (v = 0; v < GT->numVertices; v++) if (d[v] == -1) DfsTransposta(GT, v, d, f);

    for (v = 0; v < GT->numVertices; v++){
       visitados[f[v]] = v;    // visitados[0..V-1] é permutação de GT em pós-ordem 
       cfc[v] = -1;    // FASE 2 COMEÇA AQUI
    }
    
    for (v = 0; v < G->numVertices; v++) cfc[v] = -1;

    int k = 0;

    for (int i = G->numVertices-1; i >= 0; --i) {
       v = visitados[i];
       if (cfc[v] == -1) { // nova etapa
          DfsKosarayu(G, v, cfc, k);
          k++;
       }
    }

    return k;
}

// BASICAMENTE A MSM COISA DO KOSARAYU 1 SÓ QUE A FASE 1 E A FASE 2 ESTÃO INVERTIDAS
int kosarayu2(Grafo* G, int* visitados, int* cfc, int* d, int* f){
    // FASE 2
    tempod = tempof = 0;
    int v;

    for(v = 0 ; v < G->numVertices; v++) d[v] = -1;

    for(v = 0 ; v < G->numVertices; v++) if (d[v] == -1) DfsTransposta(G, v, d, f);

    // FASE 1
    Grafo* GT = transposta(G);
    int k = 0;

    for(v = 0; v < G->numVertices; ++v){
        cfc[v] = -1;
        visitados[f[v]] = v;
    }

    for(int i = GT->numVertices-1; i >= 0; --i) {
        v = visitados[i];
        if (cfc[v] == -1) {
            DfsKosarayu(GT, v, cfc, k);
            k++;
        }
    }

    return k;
}