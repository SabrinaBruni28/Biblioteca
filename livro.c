#include "livro.h"

int Inicializa(Arquivos* arquivo){
    arquivo->autor = fopen(AUTOR, "a+");
    arquivo->genero = fopen(GENERO, "a+");
    arquivo->livro = fopen(LIVRO, "a+");
    if(arquivo->autor == NULL || arquivo->genero == NULL || arquivo->livro == NULL){
        printf("\033[1;31m**** FALHA AO ABRIR ARQUIVO ****\n\033[m");
        return 0;
    }
    fflush(arquivo->autor);
    fflush(arquivo->genero);
    fflush(arquivo->livro);
    return 1;
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
    printf("Digite o nome do livro: ");
    fgets(liv, MAX, stdin);
    Insere(arquivo->livro, liv);
    printf("Digite o autor: ");
    fgets(aut, MAX, stdin);
    Insere(arquivo->autor, aut);
    printf("Digite o genero: ");
    fgets(gen, MAX, stdin);
    Insere(arquivo->genero, gen);
}

void Insere(FILE* arquivo, char* string){
    fprintf(arquivo, "%s", string); 				  
}

char* Toupper_Vetor(char* string, int tam){
    int i;
    char* vetor= (char*)malloc(sizeof(int)*tam);
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

void Zera_string(char* string){
    int i;
    for(i=0; i<MAX; i++)
        string[i] = '\0';
}

int pesquisa_titulo(Arquivos* arquivo){
    char string[MAX];
    char nome[MAX];
    getchar();
    printf("Digite o titulo: ");
    fgets(nome, MAX, stdin);
    fflush(arquivo->livro);
    int numero = 0;
    while(feof(arquivo->livro) == 0){
        numero++;
        fgets(string, MAX, arquivo->livro);
        if(!feof(arquivo->livro) && strcmp(Toupper_Vetor(string, strlen(string)), Toupper_Vetor(nome, strlen(nome))) == 0){
            printf("Livro encontrado\n");
            Imprime_Autor(arquivo->autor, numero);
            Imprime_Genero(arquivo->genero, numero);
            return 1;
        }
    }
    printf("Nao encontrado\n");
    return 0;
}
int pesquisa_autor(Arquivos* arquivo){
    char string[MAX];
    char aut[MAX];
    getchar();
    printf("Digite o autor: ");
    fgets(aut, MAX, stdin);
    fflush(arquivo->autor);
    int numero = 0;
    while(feof(arquivo->autor) == 0){
        numero++;
        fgets(string, MAX, arquivo->autor);
        if(!feof(arquivo->autor) && strcmp(Toupper_Vetor(string, strlen(string)), Toupper_Vetor(aut, strlen(aut))) == 0){
            printf("Autor encontrado\n");
            Imprime_Livro(arquivo->livro, numero);
            Imprime_Genero(arquivo->genero, numero);
        }
    }
    if(numero != 0) return 1;
    printf("Nao encontrado\n");
    return 0;
}
int pesquisa_genero(Arquivos* arquivo){
    char string[MAX];
    char gen[MAX];
    getchar();
    printf("Digite o genero: ");
    fgets(gen, MAX, stdin);
    fflush(arquivo->genero);
    int numero = 0;
    while(feof(arquivo->genero) == 0){
        numero++;
        fgets(string, MAX, arquivo->genero);
        if(!feof(arquivo->genero) && strcmp(Toupper_Vetor(string, strlen(string)), Toupper_Vetor(gen, strlen(gen))) == 0){
            printf("******* Genero encontrado ******\n");
            Imprime_Livro(arquivo->livro, numero);
            Imprime_Autor(arquivo->autor, numero);
        }
    }
    if(numero != 0) return 1;
    printf("*** Nao encontrado ***\n");
    return 0;
}

void Imprime_Completo(FILE* arquivo){
    char string[MAX];
    fflush(arquivo);
    while(feof(arquivo) == 0){
        fgets(string, MAX, arquivo);
        if(!feof(arquivo))
            printf("%s\n", string);
    }
}


void Imprime_Autor(FILE* arquivo, int i){
    char string[MAX];
    fflush(arquivo);
    int numero = 0;
    while(numero<i && feof(arquivo) != EOF){
        fgets(string, MAX, arquivo);
        numero+=1;
    }
    printf("Autor: %s\n", string);
}

void Imprime_Livro(FILE* arquivo, int i){
    char string[MAX];
    fflush(arquivo);
    int numero = 0;
    while(numero<i && feof(arquivo) != EOF){
        fgets(string, MAX, arquivo);
        numero++;
    }
    printf("Livro: %s\n", string);
}

void Imprime_Genero(FILE* arquivo, int i){
    char string[MAX];
    fflush(arquivo);
    int numero = 0;
    while(numero<i && feof(arquivo) != EOF){
        fgets(string, MAX, arquivo);
        numero++;
    }
    printf("Genero: %s\n", string);
}