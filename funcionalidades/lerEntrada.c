#include "grafo.c"

char **leituraEntrada(int numVertices) {
    char temp; //variável temporária para não termos problemas com os multíplos scanfs.

    char **entrada = (char**) malloc(numVertices * sizeof(char*));
    for (int i = 0; i < numVertices; i++) {
        entrada[i] = (char*) malloc(TAM_PALAVRA * sizeof(char));
    }
    
    for (int i = 0; i < numVertices; i++) {
        scanf("%[^\n]", entrada[i]);
        scanf("%c", &temp); //logo depois de toda chamda de scanf, teremos que chamar esse outro scanf.
    }

    return entrada;
}