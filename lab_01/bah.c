#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main ()
{ 
    int exercicio;
    printf ("Escolha o exercicio: \n");
    scanf("%d",&exercicio);
    switch (exercicio)
    { 

        case 1: 
        
        { 

            float n1, n2, n3, media;
            float desvio_padrao;
            printf ("Digite tres numeros: \n");
            scanf("%f %f %f", &n1, &n2, &n3);
            media=(n1+n2+n3)/3;
            desvio_padrao = sqrt(((n1 - media) * (n1 - media) + (n2 - media) * (n2 - media) + (n3 - media) * (n3 - media)) / 3);
            printf ("Media: %.2f", media);
            printf ("\nDesvio padrao: %.2f", desvio_padrao);
            break;

        }

        case 2: 
        
        { 

            float x;
            printf ("Digite um numero x:\n ");
            scanf ("%f", &x);
            if (-2 * x + 3 == 0) 
            {
                printf ("O numero %.2f iguala o denominador a zero, escolha outro numero", x);
            }
            else 
            {
                float resultado = (x + 1) / (-2 * x + 3);
            
                if (resultado <= 0) 
                {
                    printf ("O numero %.2f satisfaz a inequacao ", x);
                }
                else 
                {
                    printf ("O numero %.2f nao satisfaz a inequacao", x);
                }
            }
            break;
        }

        case 3:
    
        {
            int media;
            printf ("Digite 1 para escolher a media aritmetica, digite 2 para escolher a media ponderada ou digite 3 para escolher a media harmonica: ");
            scanf("%d",&media); 
            switch (media)
            { 
                case 1:
                { 
                    float n1, n2, n3, media;
                    printf ("\nVoce escolheu a media aritmetica, cite tres numeros: \n");
                    scanf ("%f %f %f", &n1, &n2, &n3);
                    media=(n1+n2+n3)/3;
                    printf ("Media: %.2f", media);
                    break; 
                }
                case 2:
                { 
                    float n01, n02, n03, mediap;
                    printf ("\nVoce escolheu a media ponderada, cite tres numeros: \n");
                    scanf ("%f %f %f", &n01, &n02, &n03);
                    mediap=(n01*3+n02*3+n03*4)/10;
                    printf ("Media: %.2f", mediap);
                    break;
                }
                case 3:
                { 
                    float n001, n002, n003, mediah;
                    printf ("\nVoce escolheu a media harmonica, cite tres numeros: \n");
                    scanf ("%f %f %f", &n001, &n002, &n003);
                    mediah=3/((1/n001)+(1/n002)+(1/n003));
                    printf ("Media: %.2f", mediah);
                    break;
                } 
                default:
                    printf("Opcao invalida");
                    break;
            }   
            break;
        }

        case 4: 
        
        {   
            char sexo;
            int tempo_casa;
            float salario, bonus;

            printf("Digite o sexo do funcionario (M para masculino, F para feminino): ");
            scanf(" %c", &sexo);
            printf("Digite o tempo de trabalho (em anos): ");
            scanf("%d", &tempo_casa);
            printf("Digite o salario do funcionario: ");
            scanf("%f", &salario);

            if (sexo == 'M' && tempo_casa > 15)
            {
                bonus = salario * 0.2;
            } 
            else if (sexo == 'F' && tempo_casa > 10)
            {
                bonus = salario * 0.25;
            } 
            else
            {
                bonus = 100.00;
            }

            printf("O bonus do funcionario e: R$ %.2f\n", bonus);
            break;
        }

        default:
            printf ("Opcao invalida");
            break;
    }

    return 0;
}
    
