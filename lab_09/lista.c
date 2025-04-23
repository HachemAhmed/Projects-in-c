#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct Autor *criarAutor(int id, char nome[]) 
{
    struct Autor *novo = (struct Autor *)malloc(sizeof(struct Autor));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    return novo;
}

void adicionarAutor(struct Autor **listaAutores, int id, char nome[]) 
{
    struct Autor *novo = criarAutor(id, nome);
    novo->prox = *listaAutores;
    *listaAutores = novo;
}