Uma empresa precisa realizar o pagamento das faturas de seus fornecedores, contudo, a empresa recebe as notas fiscais no dia de seu vencimento, e não consegue realizar todos os pagamentos a tempo, acarretando em multas no próximo dia útil. Nossa tarefa é priorizar o pagamento das faturas de maior valor (visto que todas vencem na mesma data), minimizando o gasto em multas. Para operacionalizar os pagamentos, a empresa acompanha um status de faturas pendentes na forma de uma contagem de faturas por tipo (Pix, Boleto ou Guia).

Vamos implementar dois TADs, Fatura e Colecao para criar uma coleção de faturas, garantindo que a coleção está sempre ordenada de forma crescente em relação ao valor das faturas (valores mais altos nas posições iniciais da coleção).

A TAD Fatura deve possuir o código para pagamento (string), o tipo da fatura (char - ‘p’, ‘b’ ou ‘g’), e seu valor (double). Você deve implementar as operações:

Construtor: recebe os valores de todos os atributos por parâmetro e os inicializa.
void imprimir(): imprime os atributos no formato “tipo valor codigo” seguido de quebra de linha.
double getValor(): retorna o valor da fatura.
char getTipo(): retorna o tipo da fatura.
Crie também a TAD Colecao que tem como atributo a coleção que você julgar relevante para armazenar e gerenciar as faturas (leia até o final antes de escolher a coleção), além de um “map<char, int> status” que guarda uma contagem da quantidade de faturas pendentes separadas por tipo. A Colecao implementa as seguintes operações:

Construtor: Inicializa apenas o map com três elementos correspondendo aos tipos de fatura (chaves) e os valores iniciais da contagem, zero.
void adicionar(Fatura f): 
adiciona uma fatura à coleção garantindo que a coleção fique ordenada de forma crescente de acordo com o valor das faturas. Em outras palavras, encontre a posição na coleção onde a nova fatura deve ser inserida para preservar a ordenação. Atenção: não use funções de ordenação da coleção, insira o novo dado na posição correta.
atualiza também a contagem de faturas no map de acordo com o tipo da fatura.
void proxima(): 
remove a fatura de maior valor, que deve estar no final da sua coleção (nenhuma verificação de valor deve ser feita nesse momento).
Invoca a função imprimir() da fatura que foi removida (se a coleção estiver vazia nada é impresso).
decrementa o map de contagem de acordo com o tipo da fatura removida.
void imprimir(): percorre toda a coleção e invoca a função imprimir() de cada fatura.
void status(): imprime os dados do map de contagem no formato “tipo contagem” seguido de uma quebra de linha, para cada tipo.
É permitido adicionar nos TADs quaisquer outros atributos ou métodos auxiliares quando julgar necessário. 

A função main() deve declarar um objeto de sua TAD Coleção, e implementar um laço infinito que permite ao usuário interagir com o sistema através das seguintes entradas:

- “f tipo valor codigo”: comando para criar um novo objeto do tipo TAD Fatura de acordo com os parâmetros passados e adicioná-lo na coleção.
- 'r': invoca a função proxima() da coleção. Considera-se que o pagamento sempre é realizado após a execução deste comando.
- 'p': comando para imprimir todos os elementos da coleção.
- ‘s’: comando para imprimir o status de faturas pendentes.
- 'e': encerra o programa
Exemplo
Entrada:
f p 1910.89 2022198191089
f g 450.32 2022456745032
p
f b 613.15 2022986061315
s
r
s
r
r
p
e

Saída:
g 450.32 2022456745032
p 1910.89 2022198191089
b 1
g 1
p 1
p 1910.89 2022198191089
b 1
g 1
p 0
b 613.15 2022986061315
g 450.32 2022456745032