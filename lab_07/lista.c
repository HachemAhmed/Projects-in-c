#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void criar_lista(struct Lista *pList) 
{
    pList->prim = NULL;
}

void mostrar_lista(struct Lista *pList) 
{
    struct Pessoa *p;
    int posicao = 0;
    for (p = pList->prim; p != NULL; p = p->prox) 
    {
        printf("Nome: %s, CPF: %s (Posicao: %d)\n", p->nome, p->cpf, posicao);
        posicao++;
    }
    if (posicao == 0) 
    {
        printf("Lista vazia\n");
    }
}

void inserir_pessoa(struct Lista *pList, char nome[], char cpf[]) 
{
    struct Pessoa *nova = (struct Pessoa*)malloc(sizeof(struct Pessoa));
    
    strcpy(nova->nome, nome);
    strcpy(nova->cpf, cpf);
    nova->prox = NULL;

    if (pList->prim == NULL) 
    {
        pList->prim = nova;
    } 
    else 
    {
        struct Pessoa *p = pList->prim;
        int posicao = 1;
        while (p->prox != NULL) 
        {
            p = p->prox;
            posicao++;
        }
        p->prox = nova;
        printf("Pessoa inserida: Nome: %s, CPF: %s (Posicao na fila: %d)\n", nome, cpf, posicao);
    }
}

void inserir_pessoa_prioritaria(struct Lista *pList, char nome[], char cpf[]) 
{
    struct Pessoa *nova = (struct Pessoa*)malloc(sizeof(struct Pessoa));
    
    strcpy(nova->nome, nome);
    strcpy(nova->cpf, cpf);
    nova->prox = pList->prim;
    pList->prim = nova;

    printf("Pessoa com atendimento prioritario inserida: Nome: %s, CPF: %s\n", nome, cpf);
}

void remover_pessoa(struct Lista *pList) 
{
    if (pList->prim == NULL) 
    {
        printf("A lista esta vazia.\n");
    } 
    else 
    {
        struct Pessoa *pAux = pList->prim;
        pList->prim = pAux->prox;
        printf("Pessoa removida: Nome: %s, CPF: %s\n", pAux->nome, pAux->cpf);
        free(pAux);
    }
}

int esta_vazia(struct Lista *pList) 
{
    return (pList->prim == NULL);
}
