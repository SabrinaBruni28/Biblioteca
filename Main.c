#include "livro.h"

/*Funcao que apresenta as opcoes da biblioteca.
  Retorna o numero da opcao escolhida.*/
int Comeco(){
    int i;
    printf("\n\033[1m1-Adicionar livro\n2-Vizualizar livros\n3-Pesquisar por titulo\n4-Pesquisar por autor\n5-Pesquisar por genero\n6-Finalizar\033[m\n");
    scanf("%d",&i);
    return i;
}

/*Funcao principal que conecta tudo.*/
int main(){
    char c[MAX];
    int numero =0;
    Arquivos arquivo;
    int choice;
    char ex[MAX];
    int i=0;
    FILE* genero, *autor, *livro;
    Asterisco(100);
    printf("\t\033[1;35m######### BIBLIOTECA ##########\n\033[m");
    while(choice!=6){
        if(Inicializa(&arquivo)) return 1;
        choice = Comeco();
        switch(choice){
            case 1:
                Adiciona_Livro(&arquivo);
                break;
            case 2:
                Imprime_Completo(arquivo.livro);
                break;
            case 3:
                pesquisa_titulo(&arquivo);
                break;
            case 4:
                pesquisa_autor(&arquivo);
                break;
            case 5:
                pesquisa_genero(&arquivo);
                break;
            case 6:
                printf("\n\033[1;35m**** BIBLIOTECA FECHADA!! ****\033[m\n");
                Asterisco(100);
                break;
            }
        Termina(&arquivo);
    }
    return 0;
}