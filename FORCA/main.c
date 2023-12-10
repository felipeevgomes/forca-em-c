#include <stdio.h>
#include <stdlib.h>
#include "forca.h"
/*
    FELIPE EVANGELISTA GOMES
Documentação da Função Principal (main) - Jogo da Forca
A seguir, está a documentação para a função principal (main) do jogo da forca em C.

Estrutura Geral
A função main contém a lógica principal do jogo, organizada em um loop principal (do-while). Esse loop permite que o jogador jogue repetidamente, reiniciando o jogo a cada nova iteração.

Inicialização do Jogo
Escolha Aleatória da Palavra:

A função escolher_palavra_aleatoria é chamada para obter uma palavra aleatória do arquivo "palavras.txt".
Se não for possível abrir o arquivo, o programa retorna 1 (indicando erro) e encerra.
Inicialização de Variáveis:

Inicializa o número de tentativas (tentativas) e a palavra adivinhada (palavra_adivinhada) com underscores.
Loop Principal do Jogo
Reinicialização de Variáveis:

A cada iteração do loop, a palavra sorteada é liberada (free) para evitar vazamento de memória.
Uma nova palavra aleatória é escolhida para o próximo jogo.
Loop Interno de Tentativas:

Um loop interno (do-while) processa as tentativas do jogador enquanto houver tentativas restantes e enquanto existirem caracteres não adivinhados na palavra.
Entrada do Jogador:

Solicita que o jogador digite uma letra.
Verificação da Letra:

A função verificar_caractere é chamada para verificar se a letra está presente na palavra sorteada.
Atualiza a palavra adivinhada e o número de tentativas restantes.
Desenho Visual:

A função desenho é chamada para exibir o desenho da forca com base no número de tentativas restantes.
O loop interno continua até que o jogador adivinhe corretamente todas as letras ou esgote suas tentativas.
Verificação do Resultado do Jogo
Vitória:

Se o número de tentativas restantes for maior que 0, o jogador venceu. Uma mensagem de vitória e um desenho correspondente são exibidos.
Derrota:

Se o número de tentativas restantes for igual a 0, o jogador perdeu. Uma mensagem de derrota, a palavra correta e um desenho correspondente são exibidos.
Liberação de Memória
Antes de cada nova iteração do loop principal, a memória alocada dinamicamente para a palavra sorteada é liberada usando a função free.
Jogar Novamente
O loop principal (do-while) continua enquanto a função jogarNovamente retornar verdadeiro. O jogador tem a opção de jogar novamente ou encerrar o programa.*/
int main() {
    do {
        // Escolhe uma palavra aleatória do arquivo
        char* palavra_sorteada = escolher_palavra_aleatoria();
        if (palavra_sorteada == NULL) {
            return 1; // Sai do programa se não for possível abrir o arquivo.
        }

        // Inicializa o número de tentativas e a palavra adivinhada com underscores
        int tentativas = 6;
        char palavra_adivinhada[50];
        for (int i = 0; i < contar_caracteres(palavra_sorteada); i++) {
            palavra_adivinhada[i] = '_';
        }
        palavra_adivinhada[contar_caracteres(palavra_sorteada)] = '\0';

        // Loop principal do jogo
        do {
            char chute;
            printf("Digite uma letra: ");
            scanf(" %c", &chute);
            verificar_caractere(palavra_sorteada, palavra_adivinhada, chute, &tentativas);
        } while (tentativas > 0 && desenho(palavra_adivinhada, tentativas));

        // Verifica o resultado do jogo
        if (tentativas == 0) {
            printf("VOCE PERDEU! A PALAVRA ERA: %s\n", palavra_sorteada);
            printf("    _______________         \n");
            printf("   /               \\       \n"); 
		    printf("  /                 \\      \n");
		    printf("//                   \\/\\  \n");
		    printf("\\|   XXXX     XXXX   | /   \n");
		    printf(" |   XXXX     XXXX   |/     \n");
		    printf(" |   XXX       XXX   |      \n");
		    printf(" |                   |      \n");
		    printf(" \\__      XXX      __/     \n");
		    printf("   |\\     XXX     /|       \n");
		    printf("   | |           | |        \n");
		    printf("   | I I I I I I I |        \n");
		    printf("   |  I I I I I I  |        \n");
		    printf("   \\_             _/       \n");
		    printf("     \\_         _/         \n");
		    printf("       \\_______/           \n");

            // ... (desenho da forca)
        } else {
            printf("VOCE GANHOU! A PALAVRA ERA:  %s\n", palavra_sorteada);
            printf("       ___________      \n");
            printf("      '._==_==_=_.'     \n");
		    printf("      .-\\:      /-.    \n");
		    printf("     | (|:.     |) |    \n");
		    printf("      '-|:.     |-'     \n");
		    printf("        \\::.    /      \n");
		    printf("         '::. .'        \n");
		    printf("           ) (          \n");
		    printf("         _.' '._        \n");
		    printf("        '-------'       \n\n");
            // ... (desenho de comemoração)
        }

        // Libera a memória alocada para a palavra sorteada
        free(palavra_sorteada);

    } while (jogarNovamente()); // Executa enquanto o jogador quiser jogar novamente

    return 0;
}
