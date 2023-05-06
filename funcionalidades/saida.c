#include "cfc.c"

void saidaEntradaPadrao(){
    char temp;
    int numVertices, casoK;
    scanf("%i", &numVertices);
    scanf("%c", &temp);

    char **entradaUsuario = leituraEntrada(numVertices);

    scanf("%i", &casoK);
    
    // INICIALIZA AS VARIÁVEIS
    Grafo *G = inicializaGrafo(numVertices);
    Fila *fila = inicializaFila();
    int *visitados = inicializaVetorInt(numVertices);
    int *cfc = inicializaVetorInt(numVertices);
    int *d = inicializaVetorInt(numVertices);
    int *f = inicializaVetorInt(numVertices);
    int k;

    criaGrafo(G, entradaUsuario);
    imprimeGrafo(G);
    free(entradaUsuario);
    
    if(casoK == 1){
        k = kosarayu1(G, visitados, cfc, d, f);
    } else if(casoK == 2){
        k = kosarayu2(G, visitados, cfc, d, f);
    }

    if (k==1) puts("Sim");
    else puts("Não");

    printf("%d\n", k);
    
    Grafo *GFC = criaGrafoCFC(k, G, cfc);

    DFS(GFC, fila);

    imprimeFila(fila);

    printf("\n");

    imprimeGrafo(GFC);
}

void saidaEntradaAleatoria(){
    Fila *fila = inicializaFila();
    int *visitados = inicializaVetorInt(V_RAND);
    int *cfc = inicializaVetorInt(V_RAND);
    int *d = inicializaVetorInt(V_RAND);
    int *f = inicializaVetorInt(V_RAND);
    int k;

    Grafo *G = geradorDeGrafoAleatorio(V_RAND, A_RAND);
    imprimeGrafo(G);
    
    k = kosarayu1(G, visitados, cfc, d, f);

    if (k==1) puts("Sim");
    else puts("Não");

    printf("%d\n", k);
    
    Grafo *GFC = criaGrafoCFC(k, G, cfc);

    DFS(GFC, fila);

    imprimeFila(fila);

    printf("\n");

    imprimeGrafo(GFC);
}