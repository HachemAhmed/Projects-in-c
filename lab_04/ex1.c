#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char palavra[70] = "";
    int cont = 0;
    int i;
    int j;
    
    printf("\nDigite uma palavra: ");
    fgets(palavra, 70, stdin);
    palavra[strlen(palavra)-1]='\0';


    for (i = 0; i < 128; i++)   //tabela ascii
    {
        cont = 0;
        for (j = 0; palavra[j] != '\0'; j++)    //para ler todos os caracteres da palavra
        {
            if (palavra[j] == i)        //se o caractere for igual ao valor de i na tabela ascii
            {
                cont++;
            }
        }
        
        if (cont != 0) 
        {
            printf("O caractere '%c' ocorre %d vezes\n", i, cont);
        }
    }

    return 0;
}
