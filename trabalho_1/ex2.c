#include <stdio.h>
#include <stdlib.h>

void busca_fibonacci(int n1, int x1)
{
    int vet[n1], inicio = 0, meio;
    vet[0] = 0;
    
    if (n1 > 1) 
    {
        vet[1] = 1;
        for (int i = 2; i < n1; i++) 
        {
            vet[i] = vet[i - 1] + vet[i - 2];
        }
    }
    
    int fim = n1 - 1;
    while(inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if(x1 == vet[meio])
        {   
            printf("Indice: %d", meio);
            return;
        }
        else if(x1 < vet[meio])
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }
    printf("Indice: -1");
    return;
}

int main()
{
    int n, x;

    printf("Digite um enesimo numero de Fibonacci:\n");
    scanf("%d", &n);
    printf("Digite o numero que desejas conferir:\n");
    scanf("%d", &x);
    busca_fibonacci(n, x);
    return 0;
}
