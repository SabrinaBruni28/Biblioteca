#include "livro.h"

/*Funcao que printa uma sequencia de asteriscos.*/
void Asterisco(){
    printf("\033[1;33m**********************************************************************************\n\033[m");
}

int Comeco(){
    int i;
    printf("1-Adicionar livro\n2-Vizualizar livros\n3-Pesquisar por titulo\n4-Pesquisar por autor\n5-Pesquisar por genero\n6-Finalizar\n");
    scanf("%d",&i);
    return i;
}

int main(){
    char c[MAX];
    int numero =0;
    Arquivos arquivo;
    /*if(Inicializa(&arquivo));
        Adiciona_Livro(&arquivo);
        numero++;
    Termina(&arquivo);*/
    int choice;
    char ex[MAX];
    int i=0;
    FILE* genero, *autor, *livro;
    Asterisco();
    printf("\t\033[1;35m######### BIBLIOTECA ##########\n\033[m");
    while(choice!=6){
        Inicializa(&arquivo);
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
                printf("**** BIBLIOTECA FECHADA!! ****\n");
                Asterisco();
                break;
            }
        Termina(&arquivo);
    }
}