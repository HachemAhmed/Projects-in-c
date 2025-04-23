#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cubo(int num) 
{
    return num * num * num;
}

double exponencial(double x, double decimal) 
{
    double termo = 1.0;
    double soma = termo;
    double expo = exp(x); 
    int n;

    for (n = 1; fabs(soma - expo) >= decimal; n++) 
    {
        termo *= x / n; 
        soma += termo;  
    }

    return n;
}

int main ()
{ 
    int exercicio;
    printf ("Escolha o exercicio: \n");
    scanf("%d",&exercicio);
    switch (exercicio)
    { 

        case 1: 
        { 
            int A, B;
        
            do 
            
            {
                printf("Digite os valores de A e B ou digite 0 para ambos os numeros para encerrar o programa:\n");
                scanf("%d %d", &A, &B);

                if (A != 0 || B != 0) 
                {

                    int primeiro = (A < B) ? A : B;
                    int segundo = (A > B) ? A : B;
                    int soma = 0;

                    for (int i = primeiro + 1; i < segundo; i++) 
                    {
                        if (i % 2 == 0) 
                        {
                            soma += cubo(i);
                        }
                    }
                    
                    printf("Intervalo: (%d, %d)\n", primeiro, segundo); 
                    printf("A soma dos cubos dos numeros pares eh: %d\n", soma);
                }

            } 

            while (A != 0 || B != 0);
            return 0;
        }    

        case 2:
        {
            double x, decimal;
            printf("Digite o valor de x: ");
            scanf("%lf", &x);

            decimal = 0.0001; 
            double elementos = exponencial(x, decimal);

            printf("%g termos sao necessarios para obter a precisao de 4 casas decimais.\n", elementos);

            return 0;
        }
    
        case 3:
        {
            int cpf, somaa, resto, digito1, digito2;
            int d1, d2, d3, d4, d5, d6, d7, d8, d9;

            printf("Digite os 9 primeiros digitos do CPF sem pontos ou hifens: ");
            scanf("%d", &cpf);

            d9 = cpf % 10; 
            cpf /= 10;
            d8 = cpf % 10; 
            cpf /= 10;
            d7 = cpf % 10; 
            cpf /= 10;
            d6 = cpf % 10; 
            cpf /= 10;
            d5 = cpf % 10; 
            cpf /= 10;
            d4 = cpf % 10; 
            cpf /= 10;
            d3 = cpf % 10; 
            cpf /= 10;
            d2 = cpf % 10; 
            cpf /= 10;
            d1 = cpf % 10;

            somaa = d1 * 10 + d2 * 9 + d3 * 8 + d4 * 7 + d5 * 6 + d6 * 5 + d7 * 4 + d8 * 3 + d9 * 2;
            resto = somaa % 11;
            
            if (resto < 2) 
            {
                digito1 = 0;
            } 
            else 
            {
                digito1 = 11 - resto;
            }

            somaa = d1 * 11 + d2 * 10 + d3 * 9 + d4 * 8 + d5 * 7 + d6 * 6 + d7 * 5 + d8 * 4 + d9 * 3 + digito1 * 2;
            resto = somaa % 11;
            
            if (resto < 2) 
            {
                digito2 = 0;
            } 
            else 
            {
                digito2 = 11 - resto;
            }

            printf("O CPF completo eh: %d%d%d.%d%d%d.%d%d%d-%d%d\n", d1, d2, d3, d4, d5, d6, d7, d8, d9, digito1, digito2);

            return 0;
        }   

        case 4:
        {
            int dd1, dd2, dd3, dd4, dd5, dd6, dd7, dd8, dd9, dd10, dd11, dd12;
            long long cnpj;
            int digitoo1, digitoo2;
            int soma1;
            int resto1;
            int soma2;
            int resto2;

            printf("Digite os 12 primeiros digitos do CNPJ sem pontos, barras ou hifens: ");
            scanf("%lld", &cnpj);

            dd12 = cnpj % 10; 
            cnpj /= 10;
            dd11 = cnpj % 10; 
            cnpj /= 10;
            dd10 = cnpj % 10; 
            cnpj /= 10;
            dd9 = cnpj % 10; 
            cnpj /= 10;
            dd8 = cnpj % 10; 
            cnpj /= 10;
            dd7 = cnpj % 10; 
            cnpj /= 10;
            dd6 = cnpj % 10; 
            cnpj /= 10;
            dd5 = cnpj % 10; 
            cnpj /= 10;
            dd4 = cnpj % 10; 
            cnpj /= 10;
            dd3 = cnpj % 10; 
            cnpj /= 10;
            dd2 = cnpj % 10; 
            cnpj /= 10;
            dd1 = cnpj % 10;

            soma1 = dd1*5 + dd2*4 + dd3*3 + dd4*2 + dd5*9 + dd6*8 + dd7*7 + dd8*6 + dd9*5 + dd10*4 + dd11*3 + dd12*2;
            resto1 = soma1 % 11;
            
            if (resto1 < 2) 
            {
                digitoo1 = 0;
            } 
            else 
            {
                digitoo1 = 11 - resto1;
            }

            soma2 = dd1*6 + dd2*5 + dd3*4 + dd4*3 + dd5*2 + dd6*9 + dd7*8 + dd8*7 + dd9*6 + dd10*5 + dd11*4 + dd12*3 + digitoo1*2;
            resto2 = soma2 % 11;
            
            if (resto2 < 2) 
            {
                digitoo2 = 0;
            } 
            else 
            {
                digitoo2 = 11 - resto2;
            }

            printf("O CNPJ completo eh: %d%d.%d%d%d.%d%d%d/%d%d%d%d-%d%d\n", dd1, dd2, dd3, dd4, dd5, dd6, dd7, dd8, dd9, dd10, dd11, dd12, digitoo1, digitoo2);

            return 0;
        }

    }
}
