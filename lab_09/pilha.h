#ifndef PILHA_H
#define PILHA_H

struct Autor 
{
    int id;
    char nome[100];
    struct Autor *prox;
};

struct Documento 
{
    int ID;
    char TITULO[100];
    struct Autor *autores; 
    struct Documento *prox;
};

struct Pilha 
{
    struct Documento *topo;
};

void criarPilha(struct Pilha *pilha);
void empilhar(struct Pilha *pilha, int id, char titulo[], struct Autor *listaAutores);
int desempilhar(struct Pilha *pilha);
void mostrarTopo(struct Pilha *pilha);
int estaVazia(struct Pilha *pilha);
void salvarPilha(struct Pilha *pilha, const char *filename);
void lerPilha(struct Pilha *pilha, const char *filename);

struct Autor *criarAutor(int id, char nome[]);
void adicionarAutor(struct Autor **listaAutores, int id, char nome[]);

#endif

