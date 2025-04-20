#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    struct Lista minha_lista;
    criar_lista(&minha_lista);

    int op;
    char nome[TAM], cpf[12];

    while (1) {
        printf("\n1 - Inserir pessoa na lista\n");
        printf("2 - Inserir uma pessoa prioritaria na lista\n");
        printf("3 - Retirar alguem da lista\n");
        printf("4 - Imprimir as pessoas presentes na lista\n");
        printf("5 - Verificar se a lista esta vazia\n");
        printf("6 - Sair\n");
        printf("Opcao? ");
        scanf("%d", &op);

        switch (op) {
            case 1: 
                printf("Digite seu nome: ");
                scanf("%s", nome);
                printf("Digite seu CPF: ");
                scanf("%s", cpf);
                inserir_pessoa(&minha_lista, nome, cpf);
                break;

            case 2: // inserir pessoa prioritária
                printf("Digite seu nome: ");
                scanf("%s", nome);
                printf("Digite seu CPF: ");
                scanf("%s", cpf);
                inserir_pessoa_prioritaria(&minha_lista, nome, cpf);
                break;

            case 3:
            {  
                remover_pessoa(&minha_lista);
                break;
            }
            case 4: 
            { 
                mostrar_lista(&minha_lista);
                break;
            }
            case 5:
            { 
                if (esta_vazia(&minha_lista)) 
                {
                    printf("Lista vazia\n");
                } 
                else 
                {
                    printf("A lista nao esta vazia\n");
                }
                break;
            }
            case 6:
            {  
                exit(0);
            }
            default:
            { 
                printf("Opcao invalida!\n");
                break;
            }
        }
    }

    return 0;
}
