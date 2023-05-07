#include "cfc.c"

void saidaEntradaPadrao(){
    // LEITURA DE ENTRADA
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
    // imprimeGrafo(G);
    free(entradaUsuario);
    
    // CASO DOS 2 KOSARAYUS DIFERENTES
    if(casoK == 1){
        k = kosarayu1(G, visitados, cfc, d, f);
    } else if(casoK == 2){
        k = kosarayu2(G, visitados, cfc, d, f);
    }

    // SE K = 1 ENTÃO TEMOS SOMENTE UM CONJUNTO DE COMPONENTES FORTEMENTE CONECTADOS, FAZENDO ASSIM O GRAFO SER UM GRAFO DE COMPONENTES FORTEMENTE CONECTADOS
    if (k==1) puts("Sim");
    else puts("Não");

    printf("%d\n", k);
    
    // CRIAMOS O GRAFO DE COMPONENTES FORTEMENTE CONECTADOS PARA PODER IMPRIMIR SUA ORDEM TOPOLÓGICA E IMPRIMIR OS VÉRTICES
    Grafo *GFC = criaGrafoCFC(k, G, cfc);

    DFS(GFC, fila);

    imprimeFila(fila);

    printf("\n");

    imprimeGrafo(GFC);
}

void saidaEntradaAleatoria(){
    // INICIALIZA AS VARIÁVEIS
    Fila *fila = inicializaFila();
    int *visitados = inicializaVetorInt(V_RAND);
    int *cfc = inicializaVetorInt(V_RAND);
    int *d = inicializaVetorInt(V_RAND);
    int *f = inicializaVetorInt(V_RAND);
    int k;

    // INICIALIZA O GRAFO ALEATÓRIO
    Grafo *G = geradorDeGrafoAleatorio(V_RAND, A_RAND);
    imprimeGrafo(G);
    
    // FAZEMOS UM KOSARAYU ARBITRÁRIO NESSE CASO USAMOS O 1
    k = kosarayu1(G, visitados, cfc, d, f);

    // SE K = 1 ENTÃO TEMOS SOMENTE UM CONJUNTO DE COMPONENTES FORTEMENTE CONECTADOS, FAZENDO ASSIM O GRAFO SER UM GRAFO DE COMPONENTES FORTEMENTE CONECTADOS
    if (k==1) puts("Sim");
    else puts("Não");

    printf("%d\n", k);
    
    // CRIAMOS O GRAFO DE COMPONENTES FORTEMENTE CONECTADOS PARA PODER IMPRIMIR SUA ORDEM TOPOLÓGICA E IMPRIMIR OS VÉRTICES
    Grafo *GFC = criaGrafoCFC(k, G, cfc);

    DFS(GFC, fila);

    imprimeFila(fila);

    printf("\n");

    imprimeGrafo(GFC);
}