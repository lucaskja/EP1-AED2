#include "./funcionalidades/cfc.c"

int main(){
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
    
    if(casoK == 1){
        k = kosarayu1(G, visitados, cfc, d, f);
    } else if(casoK == 2){
        k = kosarayu2(G, visitados, cfc, d, f);
    }

    if (k==1) puts("Sim");
    else puts("Não");

    printf("%d\n", k);
    
    // puts("Criando Novo Grafo: ");
    Grafo *GFC = criaGrafoCFC(k, G, cfc);

    // puts("DFS: ");
    DFS(GFC, fila);
    // puts("Imprimindo Fila: ");
    imprimeFila(fila);

    printf("\n");

    //imprime o grafo de componentes fortemente conectadas
    imprimeGrafo(GFC);
}