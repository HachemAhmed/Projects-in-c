#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 999

int main() 
{
    char nomenormal[MAX];
    char nomemaiusculo[MAX];
    FILE *file, *file_novo;

    printf("Digite o nome do arquivo para salvar os dados: ");
    scanf("%s", nomenormal);

    file = fopen(nomenormal, "w");
    if (!file) 
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    printf("Digite os nomes dos estudantes ou digite 'SAIR' para terminar):\n");
    
    while (1) 
    {
        scanf("%s", nomemaiusculo);
        if (strcmp(nomemaiusculo, "SAIR") == 0) 
        {
            break;
        }
        fprintf(file, "%s\n", nomemaiusculo);
    }
    fclose(file);

    file = fopen(nomenormal, "r");
    if (!file) 
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    strcpy(nomemaiusculo, nomenormal);
    strcat(nomemaiusculo, "_MAIUSCULO.txt");
    file_novo = fopen(nomemaiusculo, "w");
    
    if (!file_novo) 
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }
    
    printf("Nomes digitados:\n");
    while (fgets(nomemaiusculo, MAX, file)) 
    {
        for (int i = 0; nomemaiusculo[i]; i++) 
        {
            nomemaiusculo[i] = toupper(nomemaiusculo[i]);
        }
        fprintf(file_novo, "%s", nomemaiusculo);
        printf("%s", nomemaiusculo);
    }

    fclose(file);
    fclose(file_novo);
    return 0;
}
