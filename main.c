#include "./funcionalidades/cfc.c"

int main(){
    // char temp;
    // int numVertices, casoK;
    // scanf("%i", &numVertices);
    // scanf("%c", &temp);
    int numVertices = 3;

    // char **entradaUsuario = leituraEntrada(numVertices);

    // scanf("%i", &casoK);

    // INICIALIZA AS VARIÁVEIS
    Grafo *G = inicializaGrafo(numVertices);
    // Fila *fila = inicializaFila();
    // int *visitados = inicializaVetorInt(numVertices);
    // int *cfc = inicializaVetorInt(numVertices);
    // int *d = inicializaVetorInt(numVertices);
    // int *f = inicializaVetorInt(numVertices);
    // int k;

    // puts("Criando novos nomes: ");
    // preencheVertices(vertices, numVertices, entradaUsuario);
    // puts("Criando Grafo: ");
    char** entradaUsuario = (char**) malloc(sizeof(char**));

    for (int i = 0; i < 3; i++) {
        entradaUsuario[i] = (char*) malloc(TAM_PALAVRA * sizeof(char));
    }

    strcpy(entradaUsuario[0], "A: B; C;");
    strcpy(entradaUsuario[1], "B: C;");
    strcpy(entradaUsuario[2], "C: A;");

    criaGrafo(G, entradaUsuario);

    for (int i = 0; i < G->numVertices; i++){
        printf("O vértice %s faz conxões com: ", G->nomesVertice[i]);
        for (Vertice *p = G->listaAdj[i]; p != NULL; p = p->prox) {
            printf("%s ", p->nomeVertice);
        }
        printf("\n\n");
    } 
    
    // puts("Iniciando Kosarayu: ");
    // if(casoK == 1){
    //     k = kosarayu1(G, vertices, visitados, cfc, d, f);
    // } else if(casoK == 2){
    //     k = kosarayu2(G, vertices, visitados, cfc, d, f);
    // }

    // if (k==1) puts("Sim");
    // else puts("Não");

    // printf("%d\n", k);

    // // puts("Criando novos nomes: ");
    // char** nomesVertices = criaListaDeNomes(G, cfc, k);
    
    // // puts("Criando Novo Grafo: ");
    // Grafo *GFC = criaGrafoCFC(k, G, cfc, vertices);

    // // puts("DFS: ");
    // DFS(GFC, fila, vertices);
    // // puts("Imprimindo Fila: ");
    // imprimeFila(fila, vertices);

    // printf("\n");

    // //imprime o grafo de componentes fortemente conectadas
    // imprimeGrafo(GFC);
}