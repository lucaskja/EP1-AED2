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
    int *visitados = inicializaVisitados(numVertices);
    int *cfc = inicializaComponenteFortementeConectado(numVertices);
    int *d = inicializaDescoberto(numVertices);
    int *f = inicializaFinalizado(numVertices);
    int k;

    preencheVertices(vertices, numVertices, entradaUsuario);
    criaGrafo(G, vertices, entradaUsuario);
    imprimeGrafo(G, vertices);

    if(casoK == 1){
        k = kosarayu1(G, vertices, visitados, cfc, d, f);
    } else if(casoK == 2){
        k = kosarayu2(G, vertices, visitados, cfc, d, f);
    }

    if (k==1) printf("Sim\n");
    else printf("Nao\n");

    printf("%d\n", k);
}