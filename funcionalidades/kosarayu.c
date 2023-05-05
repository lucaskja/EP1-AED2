#include "lerEntrada.c"

int tempod, tempof;

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
    // Fase 1 começa aqui
    Grafo* GT = transposta(G);
    tempod = tempof = 0;
    int v; 
    for (v = 0; v < GT->numVertices; v++) d[v] = -1;
    for (v = 0; v < GT->numVertices; v++) 
       if (d[v] == -1)
          DfsTransposta(GT, v, d, f);
    for (v = 0; v < GT->numVertices; v++){
       visitados[f[v]] = v;    // visitados[0..V-1] é permutação de GT em pós-ordem 
       cfc[v] = -1;    // fase 2 começa aqui
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

int kosarayu2(Grafo* G, int* visitados, int* cfc, int* d, int* f){
    // Fase 1
    tempod = tempof = 0;
    int v;
    for(v = 0 ; v < G->numVertices; v++) d[v] = -1;
    for(v = 0 ; v < G->numVertices; v++) if (d[v] == -1) DfsTransposta(G, v, d, f);

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
    };

    return k;
}