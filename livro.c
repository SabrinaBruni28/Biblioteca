#include "livro.h"

void Insere(Livro* liv,Lista_livros* list){
    char nome[200];
    char aut[100];
    char gen[100];
    getchar();
    printf("Digite o nome do livro: ");
    fgets(nome,200,stdin);
    printf("Digite o autor: ");
    fgets(aut,100,stdin);
    printf("Digite o genero do livro: ");
    fgets(gen,100,stdin);
    strcpy(liv->titulo,nome);
    strcpy(liv->autor,aut);
    strcpy(liv->genero,gen);
    list->livros[list->qnt]=*liv;
    list->qnt+=1;
}
int pesquisa_titulo(Lista_livros* list, char*nome){
    int i,c=0;
    for(i=0;i<list->qnt;i++){
        if(!(strcmp(list->livros[i].titulo,nome))){
            c=1;
            printf("Livro encontrado\n");
            printf("Autor: %s\n",list->livros[i].autor);
            printf("Genero: %s\n",list->livros[i].genero);
        }
    }
    if(c==0){
        printf("Nao encontrado\n");
        return 0;
    }
    return 1;
}
int pesquisa_autor(Lista_livros* list,char* aut){
    int i,c=0;
    for(i=0;i<list->qnt;i++){
        if(!(strcmp(list->livros[i].autor,aut))){
            c=1;
            printf("Autor encontrado\n");
            printf("Livro: %s\n",list->livros[i].titulo);
            printf("Genero: %s\n",list->livros[i].genero);
        }
    }
    if(c==0){
        printf("Nao encontrado\n");
        return 0;
    }
    return 1;
}
int pesquisa_genero(Lista_livros* list,char*gen){
    int i,c=0;
    for(i=0;i<list->qnt;i++){
        if(!(strcmp(list->livros[i].genero,gen))){
            c=1;
            printf("Genero encontrado\n");
            printf("Titulo: %s\n",list->livros[i].titulo);
            printf("Autor: %s\n",list->livros[i].autor);
        }
    }
    if(c==0){
        printf("Nao encontrado\n");
        return 0;
    }
    return 1;
}
void Imprime(Lista_livros* list){
    int i;
    for(i=0;i<list->qnt;i++){
        printf("Titulo: %s\n",list->livros[i].titulo);
        printf("Autor: %s\n",list->livros[i].autor);
        printf("Genero: %s\n",list->livros[i].genero);
        printf("\n");
    }
}