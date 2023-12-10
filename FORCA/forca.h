/*
    FELIPE EVANGELISTA GOMES
Documentação do Header (forca.h)
O arquivo de cabeçalho "forca.h" contém as declarações de funções utilizadas no jogo da forca em C. Essas funções encapsulam diferentes aspectos do jogo, desde a escolha aleatória de palavras até a verificação de letras e o controle de tentativas. A seguir, é apresentada a documentação para cada função.

char* escolher_palavra_aleatoria()
Esta função é responsável por escolher aleatoriamente uma palavra do arquivo "palavras.txt". Retorna um ponteiro para a palavra escolhida.

Retorno:

Ponteiro para a palavra escolhida.
int contar_caracteres(const char* str)
Esta função conta o número de caracteres em uma string.

Parâmetros:

str: Ponteiro para a string a ser contada.
Retorno:

Número de caracteres na string.
void verificar_caractere(const char* palavra, char* palavra_adivinhada, char chute, int* tentativa)
Esta função verifica se um caractere (chute) está presente na palavra escolhida. Atualiza a palavra adivinhada e controla o número de tentativas.

Parâmetros:

palavra: Ponteiro para a palavra escolhida.
palavra_adivinhada: Ponteiro para a palavra com as letras adivinhadas.
chute: Caractere a ser verificado.
tentativa: Ponteiro para o número de tentativas restantes.
int desenho(const char* str, int tentativas)
Esta função exibe um desenho visual correspondente ao número de tentativas restantes. O desenho depende do número de tentativas e pode representar, por exemplo, a forca.

Parâmetros:

str: Ponteiro para uma string utilizada no desenho (pode ser uma palavra, mensagem, etc.).
tentativas: Número de tentativas restantes.
Retorno:

Valor indicando se o jogo deve continuar ou não.
int jogarNovamente()
Esta função pergunta ao jogador se deseja jogar novamente.

Retorno:

1 se o jogador deseja jogar novamente, 0 caso contrário.*/



#ifndef FORCA_H
#define FORCA_H

char* escolher_palavra_aleatoria(); 
int contar_caracteres(const char* str);
void verificar_caractere(const char* palavra, char* palavra_adivinhada, char chute, int* tentativa) ;
int desenho(const char* str, int tentativas);
int jogarNovamente();

#endif