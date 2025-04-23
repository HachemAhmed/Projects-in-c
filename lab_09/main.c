#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main() 
{
    struct Pilha minhaPilha;
    int id, opcao;
    char titulo[100];
    char nomeAutor[100];
    int idAutor;

    criarPilha(&minhaPilha);

    while (1) {
        printf("\nMenu:\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Mostrar topo\n");
        printf("4 - Verificar se esta vazia\n");
        printf("5 - Salvar Pilha\n");
        printf("6 - Ler Pilha\n");
        printf("7 - Sair\n");
        printf("Opcao? ");
        scanf("%d", &opcao);
        getchar();  

        switch (opcao) 
        {
            case 1: 
            {
                printf("Qual o ID de identificacao? ");
                scanf("%d", &id);
                getchar(); 

                printf("Qual o titulo do documento? ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = '\0'; 

                struct Autor *listaAutores = NULL;

                printf("Digite os autores (ID e Nome, digite -1 para encerrar):\n");
                while (1) 
                {
                    printf("ID do autor: ");
                    scanf("%d", &idAutor);
                    getchar();
                    if (idAutor == -1) break;

                    printf("Nome do autor: ");
                    fgets(nomeAutor, sizeof(nomeAutor), stdin);
                    nomeAutor[strcspn(nomeAutor, "\n")] = '\0';  

                    adicionarAutor(&listaAutores, idAutor, nomeAutor);
                }

                empilhar(&minhaPilha, id, titulo, listaAutores);
                break;
            }
            case 2:
                id = desempilhar(&minhaPilha);
                if (id != -1) 
                {
                    printf("Desempilhado: %d\n", id);
                }
                break;
            case 3:
                mostrarTopo(&minhaPilha);
                break;
            case 4:
                if (estaVazia(&minhaPilha)) 
                {
                    printf("Pilha vazia\n");
                } else 
                {
                    printf("Pilha nao esta vazia\n");
                }
                break;
            case 5:
                salvarPilha(&minhaPilha, "pilha.bin");
                printf("Pilha salva em 'pilha.bin'\n");
                break;
            case 6:
                lerPilha(&minhaPilha, "pilha.bin");
                printf("Pilha lida de 'pilha.bin'\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Opção invalida! Tente novamente.\n");
        }
    }

    return 0;
}
