#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, C, D, i, j, l, x;         
    printf("Digite o numero de linhas da primeira matriz: ");       //A e B numero de linhas e colunas da matriz K
    scanf("%d", &A);                                                //C e D numero de linhas e colunas da matriz L
    printf("Digite o numero de colunas da primeira matriz: ");      
    scanf("%d", &B);
    printf("Digite o numero de linhas da segunda matriz: ");        //matriz 1 = K
    scanf("%d", &C);                                                //matriz 2 = L
    printf("Digite o numero de colunas da segunda matriz: ");       //matriz das multiplicações = R
    scanf("%d", &D);

    int K[A][B], L[C][D], R[A][D];
    if(B==C)
    {
        printf("Digite os valores de cada linha e coluna da primeira matriz:\n");
        for(i=0;i<A;i++)
        {
            for(j=0;j<B;j++)
            {
                printf("Digite o valor [%d][%d] da primeira matriz: ", i+1, j+1);
                scanf("%d", &x);
                K[i][j] = x;
            }
        }
        
        printf("Digite os valores de cada linha e coluna da segunda matriz:\n");
        for(i=0;i<C;i++)
        {
            for(j=0;j<D;j++)
            {
                printf("Digite o valor [%d][%d] da segunda matriz: ", i+1, j+1);
                scanf("%d", &x);
                L[i][j] = x;
                R[i][j] = 0;
            }
        }

        for(i=0;i<A;i++)
        {
            for(j=0;j<D;j++)
            {
                for(l=0;l<C;l++)
                {
                    R[i][j] = R[i][j] + (K[i][l] * L[l][j]);
                }
            }
        }

        printf("Resultado da multiplicaçao das matrizes:\n");
        for(i=0;i<A;i++)
        {
            for(j=0;j<D;j++)
            {
                printf("%d\t", R[i][j]);
            }
            printf("\n\n");
        }
    }

    else
    {
        printf("Nao eh possivel realizar a multiplicaçao");
    }
    
    return 0;
}