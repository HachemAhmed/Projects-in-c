#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char frase[999] = "", aux[999] = "";
    int i, j;


    printf("\nDigite uma frase: ");
    fgets(frase, 999, stdin);


    frase[strlen(frase) - 1] = '\0';


    for (i = 0; i < strlen(frase); i++) 
    {
        if (frase[i] == 'a' && frase[i+1] == 'l' && frase[i+2] == 'u' && frase[i+3] == 'n' && frase[i+4] == 'o')
        {

            for (j = i + 5; j < strlen(frase); j++) 
            {
                aux[j - (i + 5)] = frase[j];
            }
            aux[j - (i + 5)] = '\0';
            frase[i] = '\0';            //salva tudo antes de aluno

            strcat(frase, "estudante");
            strcat(frase, aux);

            i += strlen("estudante");
        }
    }

    for (i = 0; i < strlen(frase); i++) 
    {
        if (frase[i] == 'e' && frase[i+1] == 's' && frase[i+2] == 'c' && frase[i+3] == 'o' && frase[i+4] == 'l' && frase[i+5] == 'a') 
        {

            for (j = i + 6; j < strlen(frase); j++) 
            {
                aux[j - (i + 6)] = frase[j];
            }
            aux[j - (i + 6)] = '\0';
            frase[i] = '\0';            //nao copia escola

            strcat(frase, "universidade");
            strcat(frase, aux);

            i += strlen("universidade");
        }
    }



    printf("A nova frase eh: %s\n", frase);

    return 0;
}
