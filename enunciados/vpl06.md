Durante a pandemia, a utilização de aplicativos para fazer pedidos dos mais variados se tornou muito comum. Neste problema, você terá que simular a compra de lanches do festival ICEx para levantar fundos para o DCE. Para isso, implemente seis classes: Venda, Pedido, Produto, Açaí, Cachorro-quente e Pizza. 

OBS: Os arquivos venda.hpp, pedido.hpp e produto.hpp não devem ser modificados.

A classe Produto armazena as informações e métodos listadas a seguir. Note que seus métodos (em itálico) são virtuais e não implementam comportamento padrão.

Produto

--------------------------------------------------------------------------------------------------------------------------

# _quantidade: int

# _valor_unitario: float

+ descricao() = 0 : string

+ calcPreco() = 0 : float


As classes Açaí, Pizza e Cachorro-Quente herdam de Produto, e possuem as seguintes especificidades:

Açai

--------------------------------------------------------------------------------------------------------------------------

- _tamanho: int

- _complementos: string[1..10]

+ Acai(int tam, vector<string>& comp, int qtd)

+ descricao() : string

+ calcPreco() : float


Cachorro-quente

--------------------------------------------------------------------------------------------------------------------------

- _num_salsichas: int

- _complementos: string[1..10]

- _prensado: bool

+ CachorroQuente(int num_s, vector<string>& comp, bool prens, int qtd)

+ descricao() : string

+ calcPreco() : float


Pizza

--------------------------------------------------------------------------------------------------------------------------

- _sabor: string

- _num_pedacos: int

- _borda_recheada: bool

+ Pizza(string sabor, int pedacos, bool borda, int qtd)

+ descricao() : string

+ calcPreco() : float

A classe Pedido deverá ter uma lista de produtos, o endereco de entrega e os seguintes métodos deverão ser implementados (modifiquem apenas o arquivo pedido.cpp):

Pedido

------------------------------------------------------------------

- produtos: std::list<Produto*>

- endereco: string

+ adicionaProduto(Produto* p): void

+ calculaTotal(): float

+ resumo(): string

+ setEndereco(string endereco): void


Breve descrição:

void adicionaProduto(Produto* p); // adiciona um produto ao pedido

float calculaTotal(); // calcula e retorna o valor total do pedido

string resumo(); // retorna um resumo do pedido (uma descrição de todos os produtos que fazem parte do pedido e o endereço de entrega no final)

setEndereco(string endereco); // atualiza o endereço de entrega do pedido


A classe Venda, terá uma lista de pedidos recebidos e os métodos a seguir (modifiquem apenas o arquivo venda.cpp):

Venda

--------------------------------------------------------------------------------------------------------------------------

- pedidos: std::list<Pedido*>

+ adicionaPedido(Pedido* p): void

+ imprimeRelatorio(): void


Breve descrição:

void adicionaPedido(Pedido* p); // adiciona um pedido à lista de pedidos recebidos

void imprimeRelatorio(); // imprime a lista completa de todos pedidos processados, o total de vendas e a quantidade de pedidos recebidos

Referências

https://www.cplusplus.com/doc/tutorial/classes/

https://www.cplusplus.com/reference/list/list/

https://www.cplusplus.com/reference/string/string/

https://www.cplusplus.com/doc/tutorial/inheritance/

https://www.cplusplus.com/doc/tutorial/polymorphism/

http://www.cplusplus.com/forum/beginner/222475/

Formato de entrada

Os pedidos são compostos por uma lista de produtos e um endereço de entrega. A tag pedido indica o início de um novo pedido e a tag endereço indica o final do pedido. Cada linha de  produto informa o tipo do produto (açaí, cachorro-quente ou pizza) seguido dos respectivos atributos na mesma ordem dos seus construtores.

Formato de saída

Após o processamento de todos os pedidos, o método imprimeRelatorio() da classe Venda é executado. O relatório deverá imprimir uma descrição detalhada de todos os pedidos que foram processados, a quantidade de pedidos e o total de vendas. Assim como no exemplo a seguir.

Exemplo de entrada:
pedido
pizza marguerita especial,4,1,5
cachorro-quente 2,purê de batata,ketchup,0,3
cachorro-quente 2,ketchup,maionese,batata palha,1,5
pizza frango,6,1,6
endereco
Av. do Contorno, 6061 - Sao Pedro, Belo Horizonte
pedido
pizza frango,4,0,3
cachorro-quente 4,purê de batata,mostarda,ketchup,milho,0,9
cachorro-quente 2,ketchup,batata palha,purê de batata,0,4
pizza calabresa,8,1,4
cachorro-quente 4,mostarda,maionese,purê de batata,milho,1,7
endereco
Rua dos Tupis, 337 - Centro, Belo Horizonte

Exemplo de saída:
Pedido 1
5X pizza marguerita especial, 4 pedaços e borda recheada.
3X cachorro-quente com 2 salsicha(s), purê de batata, ketchup.
5X cachorro-quente prensado com 2 salsicha(s), ketchup, maionese, batata palha.
6X pizza frango, 6 pedaços e borda recheada.
Endereço: Av. do Contorno, 6061 - Sao Pedro, Belo Horizonte
Pedido 2
3X pizza frango, 4 pedaços sem borda recheada.
9X cachorro-quente com 4 salsicha(s), purê de batata, mostarda, ketchup, milho.
4X cachorro-quente com 2 salsicha(s), ketchup, batata palha, purê de batata.
4X pizza calabresa, 8 pedaços e borda recheada.
7X cachorro-quente prensado com 4 salsicha(s), mostarda, maionese, purê de batata, milho.
Endereço: Rua dos Tupis, 337 - Centro, Belo Horizonte
Relatorio de Vendas
Total de vendas: R$1065.00
Total de pedidos: 2