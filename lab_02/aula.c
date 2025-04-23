#include <stdio.h>
#include <stdlib.h>

int main()
{
    int exercicio;
    do 
    { 
        printf ("\nEscolha algum exercicio ou digite 0 para encerrar o programa:\n");
        scanf("%d", &exercicio);
        switch (exercicio)
        {
            case 1: 
            {

                int cont, N, resultado;
                printf ("Digite um numero: \n");
                scanf("%d", &N); 
                for (cont=1; cont<=10; cont++) 
                {
                    resultado = cont*N;
                    printf ("%d x %d = %d \n", N, cont, resultado);
                }
                break;
            }

            case 2:
            {
                int num, fat = 1, i = 1;
                printf ("Digite um numero inteiro positivo: \n");
                scanf ("%d", &num);
                do
                {
                    fat *= i;
                    i++;
                }
                while (i <= num);
                printf ("O fatorial de %d eh: %d\n", num, fat);
                break;
            }

            case 3:
            {
                int num4;
                printf("Coloque um numero:");
                scanf("%d",&num4);

                printf("O numero escolhido apos ser invertido: %d", inverternumero(num4));
                break;
                return 0;
            }
        
            case 4:
            {
                int num3,cont1,resto;
                printf("Digite um numero: \n");
                scanf("%d",&num3);
      
                for ( cont1=2; cont1<=num3; cont1++)
                {
                    resto=num3%cont1;
                    if(resto==0)
                    break;
                }
                
                if(num3==cont1)
                printf("\nO numero %d e primo. \n",num3);
                
                else    
                printf ("\nO numero %d nao e primo. \n",num3);
                
                break;
                return 0;
            }
        }
    }

    while(exercicio!=0);
}

int inverternumero(int x)
{
    int inv = 0;
    while (x > 0)
    {
        inv = 10 * inv + x % 10;
        x/=10;    
    }
    return inv;
}


