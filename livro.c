#include "livro.h"

int Inicializa(Arquivos* arquivo){
    arquivo->autor = fopen(AUTOR, "a+");
    arquivo->genero = fopen(GENERO, "a+");
    arquivo->livro = fopen(LIVRO, "a+");
    if(arquivo->autor == NULL || arquivo->genero == NULL || arquivo->livro == NULL){
        printf("\n\033[1;31m**** FALHA AO ABRIR ARQUIVO ****\n\033[m");
        return 1;
    }
    fflush(arquivo->autor);
    fflush(arquivo->genero);
    fflush(arquivo->livro);
    return 0;
}

int Termina(Arquivos* arquivo){
    fclose(arquivo->genero);
    fclose(arquivo->autor);
    fclose(arquivo->livro);
}

int Adiciona_Livro(Arquivos* arquivo){
    char liv[MAX];
    char gen[MAX];
    char aut[MAX];
    getchar();
    printf("\033[1mDigite o nome do livro: \033[m");
    fgets(liv, MAX, stdin);
    if(!Existe_Livro(arquivo, liv)){
        Insere(arquivo->livro, liv);
        printf("\033[1mDigite o autor: \033[m");
        fgets(aut, MAX, stdin);
        Insere(arquivo->autor, aut);
        printf("\033[1mDigite o genero: \033[m");
        fgets(gen, MAX, stdin);
        Insere(arquivo->genero, gen);
        printf("\n\033[1;34m**** LIVRO ADICIONADO ****\n\033[m");
        return 1;
    }
    printf("\n\033[1;34m**** LIVRO RECONHECIDO ****\n\033[m");
    return 0;
}

void Insere(FILE* arquivo, char* string){
    fprintf(arquivo, "%s", string); 				  
}


int Existe_Livro(Arquivos* arquivo, char* livro){
    char string[MAX];
    int numero = 0;
    while(!feof(arquivo->livro)){
        numero++;
        fgets(string, MAX, arquivo->livro);
        if(!feof(arquivo->livro) && strcmp(Toupper_Vetor(string, strlen(string)), Toupper_Vetor(livro, strlen(livro))) == 0){
            return 1;
        }
    }
    return 0;
}


char* Toupper_Vetor(char* string, int tam){
    int i;
    char* vetor= (char*)malloc(sizeof(char)*tam);
    strcpy(vetor, string);
    for(i=0;i<tam;i++){
        vetor[i] = toupper(string[i]);
    }
    return vetor;
}

void Elinima_Final(char*  vetor){
    int i;
    for(i=0; vetor[i]; i++) 
        if(vetor[i]=='\n') 
            vetor[i]='\0';
}

int pesquisa_titulo(Arquivos* arquivo){
    char string[MAX];
    char nome[MAX];
    getchar();
    printf("\033[1mDigite o titulo: \033[m");
    fgets(nome, MAX, stdin);
    fflush(arquivo->livro);
    int numero = 0;
    while(!feof(arquivo->livro)){
        numero++;
        fgets(string, MAX, arquivo->livro);
        if(!feof(arquivo->livro) && strcmp(Toupper_Vetor(string, strlen(string)), Toupper_Vetor(nome, strlen(nome))) == 0){
            printf("\n\033[1;32m******* Livro encontrado *******\033[m\n");
            printf("\n");
            Imprime_Autor(arquivo->autor, numero);
            Imprime_Genero(arquivo->genero, numero);
            return 1;
        }
    }
    printf("\n\033[1;31m*** Nao encontrado ***\033[m\n");
    return 0;
}
int pesquisa_autor(Arquivos* arquivo){
    char string[MAX];
    char aut[MAX];
    getchar();
    printf("\033[1mDigite o autor: \033[m");
    fgets(aut, MAX, stdin);
    fflush(arquivo->autor);
    int numero = 0;
    int cont = 0;
    while(!feof(arquivo->autor)){
        numero++;
        fgets(string, MAX, arquivo->autor);
        if(!feof(arquivo->autor) && strcmp(Toupper_Vetor(string, strlen(string)), Toupper_Vetor(aut, strlen(aut))) == 0){
            if(cont==0) printf("\n\033[1;32m******* Autor encontrado *******\033[m\n");
            printf("\n");
            Imprime_Livro(arquivo->livro, numero);
            Imprime_Genero(arquivo->genero, numero);
            numero = 0;
            cont++;
        }
    }
    if(cont != 0) return 1;
    printf("\n\033[1;31m*** Nao encontrado ***\033[m\n");
    return 0;
}
int pesquisa_genero(Arquivos* arquivo){
    char string[MAX];
    char gen[MAX];
    getchar();
    printf("\033[1mDigite o genero: \033[m");
    fgets(gen, MAX, stdin);
    fflush(arquivo->genero);
    int numero = 0;
    int cont = 0;
    while(!feof(arquivo->genero)){
        numero++;
        fgets(string, MAX, arquivo->genero);
        if(!feof(arquivo->genero) && strcmp(Toupper_Vetor(string, strlen(string)), Toupper_Vetor(gen, strlen(gen))) == 0){
            if(cont == 0) printf("\n\033[1;32m******* Genero encontrado *******\033[m\n");
            printf("\n");
            Imprime_Livro(arquivo->livro, numero);
            Imprime_Autor(arquivo->autor, numero);
            numero = 0;
            cont++;
        }
    }
    if(cont != 0) return 1;
    printf("\n\033[1;31m*** Nao encontrado ***\033[m\n");
    return 0;
}

void Imprime_Completo(FILE* arquivo){
    char string[MAX];
    fflush(arquivo);
    int cont = 1;
    Asterisco(50);
    printf("\033[1;34mLIVROS:\033[m\n\n");
    while(!feof(arquivo)){
        fgets(string, MAX, arquivo);
        if(!feof(arquivo))
            printf("%d- %s", cont, string);
        cont++;
    }
    Asterisco(50);

}

void Imprime_Autor(FILE* arquivo, int i){
    char string[MAX];
    fflush(arquivo);
    int numero = 0;
    while(numero<i && !feof(arquivo)){
        numero++;
        fgets(string, MAX, arquivo);
    }
    printf("\033[1;34mAutor:\033[m %s", string);
}

void Imprime_Livro(FILE* arquivo, int i){
    char string[MAX];
    fflush(arquivo);
    int numero = 0;
    while(numero<i && !feof(arquivo)){
        numero++;
        fgets(string, MAX, arquivo);
    }
    printf("\033[1;34mLivro: \033[m%s", string);
}

void Imprime_Genero(FILE* arquivo, int i){
    char string[MAX];
    fflush(arquivo);
    int numero = 0;
    while(numero<i && !feof(arquivo)){
        numero++;
        fgets(string, MAX, arquivo);
    }
    printf("\033[1;34mGenero: \033[m%s", string);
}
void Asterisco(int n){
    int i;
    char a;
    a = '*';
    for(i=0; i<n; i++) printf("\033[1;33m%c\033[m",a);
    printf("\n");
}
