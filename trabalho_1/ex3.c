#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void verificar_palindromo(char vet[])
{

    char verificador[999];
    int cont = 0;

    for (int i = 0; vet[i] != '\0'; i++)
    {
        if (isalnum(vet[i]))
        {
            verificador[cont] = tolower(vet[i]);
            cont++;
        }
    }
    verificador[cont] = '\0'; 

    int len = strlen(verificador);
    for (int i = 0; i < len / 2; i++)
    {
        if (verificador[i] != verificador[len - i - 1])
        {   
            printf("False");
            return;
        }
    }
    printf("True");
    return; 
}

int main()
{
    char frase[999];
    printf("Digite uma palavra ou frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0'; 

    verificar_palindromo(frase);

    return 0;
}
