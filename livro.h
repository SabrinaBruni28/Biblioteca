#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIVRO "livro.txt"
#define AUTOR "autor.txt"
#define GENERO "genero.txt"

#define MAX 200

typedef struct{
    FILE * livro;
    FILE * genero;
    FILE * autor;
} Arquivos;


int Inicializa(Arquivos* arquivo);
int Adiciona_Livro(Arquivos* arquivo);
void Insere(FILE* arquivo, char* string);
char* Toupper_Vetor(char* string, int tam);
void Elinima_Final(char*  vetor);
void Zera_string(char* string);
int pesquisa_titulo(Arquivos* arquivo);
int pesquisa_autor(Arquivos* arquivo);
int pesquisa_genero(Arquivos* arquivo);
void Imprime_Completo(FILE* arquivo);
void Imprime_Autor(FILE* arquivo, int i);
void Imprime_Livro(FILE* arquivo, int i);
void Imprime_Genero(FILE* arquivo, int i);
int Termina(Arquivos* arquivo);