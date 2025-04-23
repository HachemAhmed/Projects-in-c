#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila* criar_fila() 
{
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (f == NULL) 
    {
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

Pessoa* criar_pessoa(char *nome, char *cpf, int prioridade) 
{
    Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa));
    if (p != NULL) 
    {
        strncpy(p->nome, nome, 50);
        strncpy(p->cpf, cpf, 12);
        p->prioridade = prioridade;
    }
    return p;
}

void enfileirar(Fila *f, Pessoa *pessoa) 
{
    if (f != NULL) 
    {
        No *novo = (No*) malloc(sizeof(No));
        if (novo == NULL) 
        {
            printf("Erro na alocação de memória.\n");
            exit(1);
        }
        novo->dado = pessoa;
        novo->prox = NULL;
        
        if (f->inicio == NULL) 
        {
            f->inicio = novo;
            f->fim = novo;
        } 
        else if (pessoa->prioridade) 
        {
            novo->prox = f->inicio;
            f->inicio = novo;
        } 
        else 
        {
            f->fim->prox = novo;
            f->fim = novo;
        }
    }
}

Pessoa* desenfileirar(Fila *f) 
{
    if (f != NULL && f->inicio != NULL) 
    {
        No *aux = f->inicio;
        Pessoa *pessoa = aux->dado;
        f->inicio = f->inicio->prox;
        free(aux);
        if (f->inicio == NULL) 
        {
            f->fim = NULL;
        }
        return pessoa;
    } 
    else 
    {
        printf("Fila inexistente ou vazia.\n");
        return NULL;
    }
}

void mostrar_fila(Fila *f) 
{
    if (f != NULL && f->inicio != NULL) 
    {
        No *aux = f->inicio;
        printf("Fila:\n");
        while (aux != NULL) 
        {
            printf("Nome: %s, CPF: %s, Prioridade: %d\n", aux->dado->nome, aux->dado->cpf, aux->dado->prioridade);
            aux = aux->prox;
        }
    } 
    else 
    {
        printf("Fila inexistente ou vazia.\n");
    }
}

int fila_vazia(Fila *f) 
{
    return (f == NULL || f->inicio == NULL);
}

void liberar_fila(Fila *f) 
{
    if (f != NULL) 
    {
        No *aux;
        while (f->inicio != NULL) 
        {
            aux = f->inicio;
            f->inicio = f->inicio->prox;
            free(aux->dado);
            free(aux);
        }
        free(f);
    }
}
