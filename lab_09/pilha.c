#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void criarPilha(struct Pilha *pilha) 
{
    pilha->topo = NULL;
}

void empilhar(struct Pilha *pilha, int id, char titulo[], struct Autor *listaAutores) 
{
    struct Documento *novo = (struct Documento *)malloc(sizeof(struct Documento));
    if (novo == NULL) 
    {
        printf("Memoria insuficiente.\n");
        return;
    }
    novo->ID = id;
    strcpy(novo->TITULO, titulo);
    novo->autores = listaAutores;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int desempilhar(struct Pilha *pilha) 
{
    if (pilha->topo == NULL) 
    {
        printf("Pilha vazia.\n");
        return -1;
    }

    struct Documento *temp = pilha->topo;
    int id = temp->ID;
    pilha->topo = temp->prox;

    struct Autor *autorAtual = temp->autores;
    while (autorAtual != NULL) 
    {
        struct Autor *prox = autorAtual->prox;
        free(autorAtual);
        autorAtual = prox;
    }

    free(temp);
    return id;
}

void mostrarTopo(struct Pilha *pilha) 
{
    if (pilha->topo == NULL) 
    {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Topo: ID=%d, Titulo=%s\n", pilha->topo->ID, pilha->topo->TITULO);

    struct Autor *autor = pilha->topo->autores;
    printf("Autores:\n");
    while (autor != NULL) {
        printf("  ID=%d, Nome=%s\n", autor->id, autor->nome);
        autor = autor->prox;
    }
}

int estaVazia(struct Pilha *pilha) 
{
    return (pilha->topo == NULL);
}

void salvarPilha(struct Pilha *pilha, const char *filename) 
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Falha ao abrir arquivo");
        return;
    }

    struct Documento *atual = pilha->topo;
    while (atual != NULL) 
    {
        fwrite(&atual->ID, sizeof(int), 1, fp);
        fwrite(atual->TITULO, sizeof(char), 100, fp);

        struct Autor *autor = atual->autores;
        while (autor != NULL) 
        {
            fwrite(&autor->id, sizeof(int), 1, fp);
            fwrite(autor->nome, sizeof(char), 100, fp);
            autor = autor->prox;
        }

        int fimAutores = -1;  
        fwrite(&fimAutores, sizeof(int), 1, fp);

        atual = atual->prox;
    }

    fclose(fp);
}

void lerPilha(struct Pilha *pilha, const char *filename) 
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) 
    {
        perror("Falha ao abrir arquivo");
        return;
    }

    criarPilha(pilha);

    int id;
    char titulo[100];

    while (fread(&id, sizeof(int), 1, fp) == 1) 
    {
        fread(titulo, sizeof(char), 100, fp);

        struct Autor *listaAutores = NULL;
        struct Autor *ultimoAutor = NULL;

        while (1) 
        {
            int autorID;
            fread(&autorID, sizeof(int), 1, fp);
            if (autorID == -1) break;

            struct Autor *novoAutor = (struct Autor *)malloc(sizeof(struct Autor));
            novoAutor->id = autorID;
            fread(novoAutor->nome, sizeof(char), 100, fp);
            novoAutor->prox = NULL;

            if (listaAutores == NULL) 
            {
                listaAutores = novoAutor;
            } else 
            {
                ultimoAutor->prox = novoAutor;
            }
            ultimoAutor = novoAutor;
        }

        empilhar(pilha, id, titulo, listaAutores);
    }

    fclose(fp);
}
