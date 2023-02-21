#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Nomes dos arquivos de texto.*/
#define LIVRO "Biblioteca/livro.txt"
#define AUTOR "Biblioteca/autor.txt"
#define GENERO "Biblioteca/genero.txt"
/*Tamanho maximo das strings no geral.*/
#define MAX 200

/*TAD que guarda os arquivos de texto com as caracteristicas dos livros.*/
typedef struct{
    FILE * livro;
    FILE * genero;
    FILE * autor;
} Arquivos;

/*Funcao que inicializa os arquivos, conferindo se da erro ao abrir o arquivo.
  Se nao houver erro ele limpa o buffer e retorna 0.
  Se houver erro ele avisa com um print e retorna 1.*/
int Inicializa(Arquivos* arquivo);
/*Funcao que pega do teclado o nome do livro, o autor e o genero do livro.
  Escrevendo em seus respectivos arquivos de texto.
  Se o livro ja existir na lista, ele nao pega os outros itens e avisa reconhecer o livro.
  Retorn 0 se o livro for reconhecido e 1 se nao for e pegar as outras informacoes.*/
int Adiciona_Livro(Arquivos* arquivo);
/*Funcao que escreve uma string no arquivo escolhido.*/
void Insere(FILE* arquivo, char* string);
/*Funcao que confere se ja existe o livro na biblioteca.
  Retorna 1 se o livro existir e 0 caso contrario.*/
int Existe_Livro(Arquivos* arquivo, char* livro);
/*Funcao que deixa um vetor todo em maiusculo.
  Retornando a nova string maiuscula.*/
char* Toupper_Vetor(char* string, int tam);
/*Funcao que elimina o \n do final das strings e substitui por \0.*/
void Elinima_Final(char*  vetor);
/*Funcao que procura livro pelo titulo.
  Printando o autor e o genero.
  Retorna 1 se achar o livro e 0 caso nao encontrar.*/
int pesquisa_titulo(Arquivos* arquivo);
/*Funcao que procura livro pelo autor.
  Printando o titulo e o genero de cada livro daquele autor.
  Retorna 1 se achar o autor e 0 caso nao encontrar.*/
int pesquisa_autor(Arquivos* arquivo);
/*Funcao que procura livro pelo genero.
  Printando o autor e o titulo de cada livro daquele genero.
  Retorna 1 se achar o genero e 0 caso nao encontrar.*/
int pesquisa_genero(Arquivos* arquivo);
/*Funcao que imprime todos os livros da biblioteca, somente o titulo.*/
void Imprime_Completo(FILE* arquivo);
/*Funcao que imprime o autor em determinada linha do arquivo.*/
void Imprime_Autor(FILE* arquivo, int i);
/*Funcao que imprime o titulo em determinada linha do arquivo.*/
void Imprime_Livro(FILE* arquivo, int i);
/*Funcao que imprime o genero em determinada linha do arquivo*/
void Imprime_Genero(FILE* arquivo, int i);
/*Funcao que fecha os arquivos.*/
int Termina(Arquivos* arquivo);
/*Funcao que printa uma sequencia de asteriscos.*/
void Asterisco(int n);