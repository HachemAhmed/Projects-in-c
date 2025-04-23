#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char frase[999] = "", aux[999] = "";
    int i, j;

    printf("\nDigite uma frase: ");
    fgets(frase, 999, stdin);

    frase[strlen(frase) - 1] = '\0';

    for (i = 0; i < strlen(frase); i++) 
    {
        if (frase[i] == 't' && frase[i+1] == 'e' && frase[i+2] == 'c' && frase[i+3] == 'l' && frase[i+4] == 'a' && frase[i+5] == 'd' &&frase[i+6] == 'o') 
        {
            
            for (j = i + 7; j < strlen(frase); j++) 
            {
                aux[j - (i + 7)] = frase[j];    //copia os caracteres do resto da frase
            }
            aux[j - (i + 7)] = '\0';        //copia tudo apos teclado
            frase[i + 7] = '\0';            //copia tudo até teclado

            strcat(frase, " ou mouse");
            strcat(frase, aux);

            i += strlen(" ou mouse"); //feito para recomeçar o loop dps de adicionar ou mouse
        }
    }

    printf("A nova frase eh: %s\n", frase);

    return 0;
}
