#include <stdio.h>
#include <string.h>

#define MAX_frases 20
#define MAX_limite 100

int main() 
{
    char nomefile[MAX_limite];
    char frases[MAX_frases][MAX_limite];
    char palavra[MAX_limite];
    FILE *file;
    int count = 0;

    printf("Digite o nome do arquivo: ");
    fgets(nomefile, MAX_limite, stdin);

    nomefile[strlen(nomefile)-1]='\0';
    file = fopen(nomefile, "w");
    
    if (!file) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("Digite ate 20 frases e digite 'FIM' para terminar):\n");
    while (count < MAX_frases) 
    {
        printf("Frase %d: ", count + 1);
        fgets(frases[count], MAX_limite, stdin);
        frases[count][strlen(frases[count])-1]='\0';

        
        if (strcmp(frases[count], "FIM") == 0) 
        {
            break;
        }
        fprintf(file, "%s\n", frases[count]);
        count++;
    }
    fclose(file);

    file = fopen(nomefile, "r");
    if (!file) 
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    count = 0;
    while (fgets(frases[count], MAX_limite, file) && count < MAX_frases) 
    {
        frases[count][strcspn(frases[count], "\n")] = '\0';
        count++;
    }
    fclose(file);

    printf("Digite uma palavra para buscar: ");
    fgets(palavra, MAX_limite, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    printf("Linhas contendo '%s':\n", palavra);
    for (int i = 0; i < count; i++) 
    {
        if (strstr(frases[i], palavra)) 
        {
            printf("Linha %d: %s\n", i + 1, frases[i]);
        }
    }

    return 0;
}
