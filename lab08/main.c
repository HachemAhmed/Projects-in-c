#include <stdio.h>
#include "fila.h"

int main() 
{
    Fila *f = criar_fila();  
    int opcao;

    do 
    {
        printf("Escolha uma opcao:\n");
        printf("1 - Inserir na fila\n");
        printf("2 - Remover da fila\n");
        printf("3 - Imprimir a fila\n");
        printf("4 - Verificar se a fila esta vazia\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) 
        {
            case 1: 
            { 
                char nome[50], cpf[12];
                int prioridade;
                printf("Digite o nome: ");
                scanf(" %[^\n]s", nome);
                printf("Digite o CPF: ");
                scanf(" %s", cpf);
                printf("Prioridade? (1 para sim, 0 para nao): ");
                scanf("%d", &prioridade);
                Pessoa *nova_pessoa = criar_pessoa(nome, cpf, prioridade);
                enfileirar(f, nova_pessoa);
                break;
            }
            case 2: 
            { 
                Pessoa *pessoa_removida = desenfileirar(f);
                if (pessoa_removida != NULL) {
                    printf("Pessoa removida: Nome: %s, CPF: %s\n", pessoa_removida->nome, pessoa_removida->cpf);
                    free(pessoa_removida);
                }
                break;
            }
            case 3: 
            { 
                mostrar_fila(f);
                break;
            }
            case 4: 
            { 
                if (fila_vazia(f)) 
                {
                    printf("A fila esta vazia.\n");
                } 
                else 
                {
                    printf("A fila nao esta vazia.\n");
                }
                break;
            }
            case 0: 
                break;
            default: 
                printf("Opcao invalida.\n");
                break;
        }
    } 
    while (opcao != 0);

    liberar_fila(f); 
    return 0;
}
