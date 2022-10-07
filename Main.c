#include "livro.h"

int main(){
    Livro livro[100];
    Lista_livros liv;
    int choice;
    int i=0;
    liv.qnt=0;
    do{
    printf("1-Adicionar livro\n2-Vizualizar livros\n3-Pesquisar por titulo\n4-Pesquisar por autor\n5-Pesquisar por genero\n6-Finalizar\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            Insere(&livro[i],&liv);
            break;
        case 2:
            Imprime(&liv);
            break;
        case 3:
            getchar();
            char ex[200];
            printf("Digite o titulo: ");
            fgets(ex,200,stdin);
            pesquisa_titulo(&liv, ex);
            break;
        case 4:
            getchar();
            char exx[100];
            printf("Digite o autor: ");
            fgets(exx,100,stdin);
            pesquisa_autor(&liv,exx);
            break;
        case 5:
            getchar();
            char exxx[100];
            printf("Digite o genero: ");
            fgets(exxx,100,stdin);
            pesquisa_genero(&liv,exxx);
            break;
        case 6:
            break;
        }
    i++;
    }while(choice!=6);
}