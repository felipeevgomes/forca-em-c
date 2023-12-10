#include <stdio.h>
#include <stdlib.h>
#include "forca.h"
#include <time.h>
/*
    FELIPE EVANGELISTA GOMES
Documentação do Código - Jogo da Forca
A seguir, está a documentação para o código implementado do Jogo da Forca em C.

escolher_palavra_aleatoria()
Esta função lê palavras de um arquivo chamado "palavras.txt", conta o número de palavras disponíveis, escolhe aleatoriamente uma delas e a retorna como uma string alocada dinamicamente. Utiliza a função strdup para alocar e copiar a palavra escolhida.

Retorno:

Ponteiro para a palavra escolhida.
contar_caracteres(const char* str)
Esta função conta o número de caracteres em uma string.

Parâmetros:

str: Ponteiro para a string a ser contada.
Retorno:

Número de caracteres na string.
verificar_caractere(const char* palavra, char* palavra_adivinhada, char chute, int* tentativa)
Esta função verifica se um caractere (chute) está presente na palavra escolhida. Atualiza a palavra adivinhada e controla o número de tentativas restantes.

Parâmetros:

palavra: Ponteiro para a palavra escolhida.
palavra_adivinhada: Ponteiro para a palavra com as letras adivinhadas.
chute: Caractere a ser verificado.
tentativa: Ponteiro para o número de tentativas restantes.
desenho(const char* str, int tentativas)
Esta função exibe uma representação visual da forca com base no número de tentativas restantes. Retorna 1 se ainda houver underscores na palavra adivinhada e 0 se todos os caracteres foram adivinhados.

Parâmetros:

str: Ponteiro para uma string utilizada no desenho (pode ser uma palavra, mensagem, etc.).
tentativas: Número de tentativas restantes.
Retorno:

1 se ainda houver underscores na palavra adivinhada, 0 se todos os caracteres foram adivinhados.
jogarNovamente()
Esta função pergunta ao jogador se deseja jogar novamente.

Retorno:

1 se o jogador deseja jogar novamente, 0 caso contrário.*/
// Função para escolher uma palavra aleatória de um arquivo
char* escolher_palavra_aleatoria() {
    FILE* arquivo = fopen("palavras.txt", "r");

    if (arquivo == NULL) {
        printf("ERRO AO ABRIR\n");
        return NULL;
    }

    // Conta o número de palavras no arquivo
    int num_palavras = 0;
    char palavra[50];
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        num_palavras++;
    }

    // Gera um índice aleatório para escolher uma palavra
    srand(time(NULL));
    int palavra_escolhida = rand() % num_palavras;

    // Reinicia o ponteiro do arquivo para o início
    rewind(arquivo);
    
    // Move-se pelo arquivo até a palavra selecionada
    for (int i = 0; i < palavra_escolhida; i++) {
        fscanf(arquivo, "%s", palavra);
    }

    fclose(arquivo);

    // Usa strdup para alocar e copiar a palavra escolhida
    return strdup(palavra);
}

// Função para contar o número de caracteres em uma string
int contar_caracteres(const char* str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

// Função para verificar se um caractere está presente na palavra e atualizar a palavra adivinhada
void verificar_caractere(const char* palavra, char* palavra_adivinhada, char chute, int* tentativa) {
    int encontrou = 0;
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (palavra[i] == chute) {
            palavra_adivinhada[i] = chute;
            encontrou = 1;
        }
    }
    printf("%s\n", palavra_adivinhada);

    // Diminui o número de tentativas se o caractere não for encontrado
    if (!encontrou) {
        (*tentativa)--;
        printf("TOTAL DE VIDAS %d\n", *tentativa);
    }
}

// Função para desenhar a figura da forca com base no número de tentativas incorretas
int desenho(const char* str, int tentativas) {
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (tentativas >= 1 ? '(' : ' '), (tentativas >= 1 ? '_' : ' '), (tentativas >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (tentativas >= 3 ? '\\' : ' '), (tentativas >= 2 ? '|' : ' '), (tentativas >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (tentativas >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (tentativas >= 4 ? '/' : ' '), (tentativas >= 4 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    // Verifica se ainda existem underscores na palavra adivinhada
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '_') {
            return 1; // Retorna 1 se ainda houver underscores
        }
    }
    return 0; // Retorna 0 se todos os caracteres forem adivinhados
}

int jogarNovamente() {
    char resposta;
    printf("DESEJA JOGAR DENOVO? (S/N): ");
    scanf(" %c", &resposta);
    return (resposta == 'S' || resposta == 's');
}