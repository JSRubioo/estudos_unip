#include <stdio.h>

int main(void) {
    FILE *banco_dds;
    char nome[20];
    char valor[10];
    char pn[10];
    char linha[100]; // Buffer para leitura do conteúdo do arquivo

    // Abrir o arquivo em modo de append para adicionar o item
    banco_dds = fopen("Banco_de_dados.txt", "a");

    if (banco_dds == NULL) {
        printf("Erro na abertura do arquivo");
        return 1;
    } else {
        // Coletar nome e valor do item
        printf("Escreva o PN do item: ");
        scanf("%s", pn);
        fprintf(banco_dds, "PN: %s", pn);

        printf("Escreva o nome do item: ");
        scanf("%s", nome);
        fprintf(banco_dds, "\nDescricao: %s", nome);

        printf("Escreva o valor do item: ");
        scanf("%s", valor);
        fprintf(banco_dds, "\nPreco: R$ %s\n\n", valor);

        fclose(banco_dds);
        printf("\nItem armazenado no banco de dados com sucesso!\n");
    }

    // Abrir o arquivo em modo de leitura para exibir o conteúdo
    banco_dds = fopen("Banco_de_dados.txt", "r");

    if (banco_dds == NULL) {
        printf("Erro na leitura do arquivo");
        return 1;
    } else {
        printf("\n=======Conteudo do banco de dados=======\n");
        while (fgets(linha, sizeof(linha), banco_dds) != NULL) {
            printf("%s", linha); 
            // Imprime cada linha lida do arquivo
        }
        printf("\n=====Fim do banco de dados======");
        fclose(banco_dds);
    }

    return 0;
}