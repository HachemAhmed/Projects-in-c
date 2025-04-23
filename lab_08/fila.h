#ifndef FILA_H
#define FILA_H

typedef struct 
{
    char nome[50];
    char cpf[12];
    int prioridade;  
} Pessoa;

typedef struct no 
{
    Pessoa *dado;  
    struct no *prox;
} No;

typedef struct fila 
{
    No *inicio;  
    No *fim;     
} Fila;

Fila* criar_fila();
Pessoa* criar_pessoa(char *nome, char *cpf, int prioridade);
void enfileirar(Fila *f, Pessoa *pessoa);
Pessoa* desenfileirar(Fila *f);
void mostrar_fila(Fila *f);
int fila_vazia(Fila *f);
void liberar_fila(Fila *f);

#endif
