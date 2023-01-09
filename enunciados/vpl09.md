Você vai trabalhar com o "Jogo da Vida" desenvolvido por John Horton Conway, embora não seja um "jogo" tradicional. O programa expressa as regras da Vida em uma matriz de células que segue a modelagem Toro. Nesse modelo, cada célula da matriz (sem exceção) tem exatamente 8 vizinhas, ou seja, após a última coluna, vem a primeira coluna e após a última linha vem a primeira linha (e vice versa). Por exemplo, numa matriz de 4x5 (4 linhas e 5 colunas) a esquerda da célula [0, 0] está a célula [0, 4] e abaixo da célula [3, 4] está a célula [0, 4].

Cada célula da matriz pode estar viva ou morta, e a cada iteração, células mortas podem reviver ou células vivas podem morrer, obedecendo às seguintes regras:

Cada célula possui oito células vizinhas: 4 diretamente acima, abaixo, à direita, à esquerda, e as 4 diagonais adjacentes.
Se uma célula viva possui 0 ou 1 vizinhas, morre de solidão.
Se uma célula viva possui mais de 3 vizinhas, morre de superpopulação.
Se uma célula morta possui exatamente 3 células vizinhas ocupadas, ela revive
Nascimentos e mortes são ocorrem simultaneamente no início de cada iteração. Uma célula que morre pode provocar um nascimento, mas uma célula recém-nascida não pode ressuscitar uma célula morrendo, nem a morte de uma célula impede a morte de outra, digamos, por meio da redução da população local.

Exemplos em: https://www.youtube.com/watch?v=23MBR2pZoDQ

Você já vai receber o jogo da vida PRONTO (uhuul 🥳). Ele está preparado para receber o seguinte conjunto de entradas:

<número de iterações do jogo da vida>
<número de linhas da matriz> <número de colunas da matriz>
<linha da primeira célula viva> <coluna da primeira célula viva>
<linha da segunda célula viva> <coluna da segunda célula viva>
...
<linha da n-ésima célula viva> <coluna da n-ésima célula viva>

Exemplo de entrada para o código atual:

5
25 60
1 2
2 3
3 1
3 2
3 3
21 22
22 23
23 21
23 22
23 23
19 8
18 6
18 8
17 7
17 8 

Seu trabalho primeiramente é baixar o código, abrir na sua IDE de preferência (VSCode né galera :D) e entender o funcionamento do código.

Agora que você entende o código é hora de torná-lo mais robusto para que ele não encerre abruptamente sem explicação. Vamos fazer um tratamento de exceções referente às coordenadas de células vivas alimentadas pelo usuário, de modo que entradas inválidas disparem uma verificação se o usuário deseja continuar o jogo ignorando aquela entrada.

Note no exemplo a seguir que das n entradas referentes às células vivas, entradas inválidas são acompanhadas por um caracter (s ou n) se deseja continuar sem aquela célula. Qualquer caracter diferente do esperado dispara novamente a mensagem de erro (como especificado mais a frente).

Entrada:
1
5 5
-1 0 s
1 2
2 3
3 1
0 27 y s
3 2
3 3

Saída:
Célula (-1, 0) não é válida. Deseja continuar e ignorá-la? (s/n)?
Célula (0, 27) não é válida. Deseja continuar e ignorá-la? (s/n)?
Célula (0, 27) não é válida. Deseja continuar e ignorá-la? (s/n)?
  X X X X X
X           X
X     o     X
X       o   X
X   o o o   X
X           X
  X X X X X

  X X X X X
X           X
X           X
X   o   o   X
X     o o   X
X     o     X
  X X X X X

O tratamento de exceção consiste em:

Criar no jogo_da_vida.hpp um TAD ExcecaoCelulaInvalida que herda de std::exception. Sua exceção deve possuir três atributos referente a linha e coluna responsáveis pelo erro, além de uma string para a mensagem de erro. Seus métodos são:
um construtor que recebe e inicializa os valores de linha e coluna, e no corpo da função monta a mensagem de erro como apresentado no exemplo acima (note que a linha e coluna fazem parte da mensagem de erro)
uma sobrescrita da função what() que retorna a mensagem de erro, que deve ser convertida para c_str para respeitar o tipo de retorno da função.
Encontre na main.cpp o trecho do código que deve ser protegido no escopo try-catch, ou seja, onde são utilizadas as entradas do usuário referente às células que devem estar vivas no início do jogo. O escopo do catch deve:
Receber uma referência a um objeto do tipo ExcecaoCelulaInvalida 
Tratar o erro criando um laço do-while que imprime a descrição do erro (método what()) e lê do usuário um caracter referente ao seu desejo de continuar sem aquela célula (opções: s ou n). A condição de parada do laço deve garantir que o laço só encerra se o usuário escolher uma opção válida. Se o usuário entrar 'n' o main encerra com return 1, se entrar 's' basta seguir o fluxo do jogo ignorando aquela entrada.
No jogo_da_vida.cpp você deve lançar o erro no momento adequado. Encontre o método equivalente à sua escolha de try-catch do ponto anterior, e verifique a validade dos parâmetros recebidos. Parâmetros invalidos devem lançar um erro do tipo ExcecaoCelulaInvalida.