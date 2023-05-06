#include "./funcionalidades/cfc.c"

int main(){
    char temp;
    int numVertices, casoK;
    scanf("%i", &numVertices);
    scanf("%c", &temp);

    // numVertices = 8;
    // casoK = 1;

    char **entradaUsuario = leituraEntrada(numVertices);

    scanf("%i", &casoK);

    // char **entradaUsuario = (char**) malloc(numVertices * sizeof(char*));

    // for (int i = 0; i < numVertices; i++) entradaUsuario[i] = (char*) malloc(TAM_PALAVRA * sizeof(char));

    // entradaUsuario[0] = strdup("a: b");
    // entradaUsuario[1] = strdup("b: c; e; f");
    // entradaUsuario[2] = strdup("c: d; g;");
    // entradaUsuario[3] = strdup("d: c; h;");
    // entradaUsuario[4] = strdup("e: a; f;");
    // entradaUsuario[5] = strdup("f: g;");
    // entradaUsuario[6] = strdup("g: f; h;");
    // entradaUsuario[7] = strdup("h: h;");
    
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