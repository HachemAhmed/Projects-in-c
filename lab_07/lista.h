#ifndef LISTA_H
#define LISTA_H

#define TAM 999

struct Pessoa 
{
    char nome[TAM];
    char cpf[12];
    struct Pessoa *prox;
};

struct Lista 
{
    struct Pessoa *prim;
};

void criar_lista(struct Lista *pList);
void mostrar_lista(struct Lista *pList);
void inserir_pessoa(struct Lista *pList, char nome[], char cpf[]);
void inserir_pessoa_prioritaria(struct Lista *pList, char nome[], char cpf[]);
void remover_pessoa(struct Lista *pList);
int esta_vazia(struct Lista *pList);

#endif
