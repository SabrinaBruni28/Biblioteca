#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
 char titulo[200];
 char autor[100];
 char genero[100];
}Livro;

typedef struct{
    Livro livros[100];
    int qnt;
}Lista_livros;

void Insere(Livro* liv,Lista_livros* list);
int pesquisa_titulo(Lista_livros* list,char*nome);
int pesquisa_autor(Lista_livros* list,char*aut);
int pesquisa_genero(Lista_livros* list,char*gen);
void Imprime(Lista_livros* list);
