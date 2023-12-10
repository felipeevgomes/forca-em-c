NOME: FELIPE EVANGELISTA GOMES
Jogo da Forca 
Bem-vindo ao Jogo da Forca em C! Este é um jogo clássico em que o jogador tenta adivinhar uma palavra, letra por letra, antes de esgotar todas as tentativas permitidas.

Como Jogar
Compilação:

Certifique-se de ter um compilador C instalado (como o GCC).
Compile o jogo usando o comando gcc main.c -o forca.
Execução:

Execute o jogo com ./forca.
O jogo começará, e você será apresentado com a palavra oculta e um conjunto de underscores representando cada letra não revelada.
Tentativas:

Você tem um número limitado de tentativas para adivinhar a palavra.
Digite uma letra e pressione Enter para fazer uma tentativa.
Feedback:

Se a letra estiver correta, ela será revelada na palavra.
Se a letra estiver incorreta, o número de tentativas restantes será reduzido.
Vitória ou Derrota:

O jogo continua até que você adivinhe corretamente todas as letras ou esgote suas tentativas.
Se adivinhar corretamente, você vence! Uma mensagem de vitória será exibida.
Se esgotar as tentativas, você perde. A palavra correta será revelada.
Jogar Novamente:

Após o término de cada jogo, você será perguntado se deseja jogar novamente.
Digite 'S' para jogar novamente ou 'N' para encerrar o jogo.
Arquivo de Palavras
O jogo carrega palavras de um arquivo chamado "palavras.txt". Certifique-se de ter esse arquivo no mesmo diretório que o executável ou modifique o código para ajustar o caminho do arquivo, se necessário.

Recursos Adicionais
Modularidade:

O código foi dividido em funções para facilitar a compreensão e manutenção.
Arquivo "forca.h" contém as declarações das funções.
Arquivo "forca.c" contém as implementações das funções.
Visualização:

O jogo utiliza mensagens simples no console para interação com o jogador.
Mensagens visuais são exibidas no caso de vitória ou derrota para uma experiência mais envolvente.
Aleatoriedade:

A escolha da palavra é feita de forma aleatória a partir do arquivo de palavras.
Esperamos que você aproveite jogando o Jogo da Forca em C! Se tiver alguma dúvida ou sugestão de melhoria, sinta-se à vontade para contribuir ou entrar em contato. Divirta-se!
