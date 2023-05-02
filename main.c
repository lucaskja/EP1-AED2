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
    Vertice **vertices = inicializaVertices(numVertices);
    Fila *fila = inicializaFila();
    int *visitados = inicializaVisitados(numVertices);
    int *cfc = inicializaComponenteFortementeConectado(numVertices);
    int *d = inicializaDescoberto(numVertices);
    int *f = inicializaFinalizado(numVertices);
    int k;

    // puts("Criando novos nomes: ");
    preencheVertices(vertices, numVertices, entradaUsuario);
    // puts("Criando Grafo: ");
    criaGrafo(G, vertices, entradaUsuario);

    // puts("Iniciando Kosarayu: ");
    if(casoK == 1){
        k = kosarayu1(G, vertices, visitados, cfc, d, f);
    } else if(casoK == 2){
        k = kosarayu2(G, vertices, visitados, cfc, d, f);
    }

    if (k==1) puts("Sim");
    else puts("Não");

    printf("%d\n", k);

    // puts("Criando novos nomes: ");
    char** nomesVertices = criaListaDeNomes(G, cfc, k);
    
    // puts("Criando Novo Grafo: ");
    Grafo *GFC = criaGrafoCFC(k, G, cfc, vertices);

    // puts("DFS: ");
    DFS(GFC, fila, vertices);
    // puts("Imprimindo Fila: ");
    imprimeFila(fila, vertices);

    printf("\n");

    //imprime o grafo de componentes fortemente conectadas
    imprimeGrafo(GFC);
}