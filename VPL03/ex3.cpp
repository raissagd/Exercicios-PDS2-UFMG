#include <iostream>
#include <iterator>
#include <map>
#include <set>

class Fatura
{
private:
    std::string _codigo_pagamento;
    char _tipo_fatura;
    double _valor_fatura;

public:
    // construtor
    Fatura(std::string codigo_pagamento, char tipo_fatura, double valor_fatura) : _codigo_pagamento(codigo_pagamento),
                                                                                  _tipo_fatura(tipo_fatura),
                                                                                  _valor_fatura(valor_fatura)
    {
    }
    double getValor()
    {
        return this->_valor_fatura;
    }

    char getTipo()
    {
        return this->_tipo_fatura;
    }

    std::string getCodigo()
    {
        return this->_codigo_pagamento;
    }

    void imprimir()
    {
        std::cout << _valor_fatura << " " << _tipo_fatura << " " << _codigo_pagamento << std::endl;
    }
};

struct compara_faturas
{
    bool operator()(Fatura &f1, Fatura &f2) const
    {
        return f1.getValor() < f2.getValor();
    }
};

class Colecao
{
private:
    std::set<Fatura, compara_faturas> faturas;
    std::map<char, int> status;

public:
    Colecao()
    {
        status.insert(std::pair<char, int>('p', 0));
        status.insert(std::pair<char, int>('b', 0));
        status.insert(std::pair<char, int>('g', 0));
    }

    void adicionar(Fatura F)
    {
        std::map<char, int>::iterator itr;

        faturas.insert(F); // acho que o vpl tbm ta alegando um erro aqui
        if (F.getTipo() == 'p')
        {
            itr = status.find('p');

            if (itr != status.end())
                itr->second++;
        }
        else if (F.getTipo() == 'b')
        {
            itr = status.find('b');

            if (itr != status.end())
                itr->second++;
        }
        else if (F.getTipo() == 'g')
        {
            itr = status.find('g');

            if (itr != status.end())
                itr->second++;
        }
    }

    void retirar(Fatura F)
    {
        std::map<char, int>::iterator itr;

        if (F.getTipo() == 'p')
        {
            itr = status.find('p');

            if (itr != status.end())
                itr->second--;
        }
        else if (F.getTipo() == 'b')
        {
            itr = status.find('b');

            if (itr != status.end())
                itr->second--;
        }
        else if (F.getTipo() == 'g')
        {
            itr = status.find('g');

            if (itr != status.end())
                itr->second--;
        }
    }

    void proxima()
    {
        /*
        1) remove a fatura de maior valor, que deve estar no final da sua coleção (nenhuma verificação de valor deve ser feita nesse momento).
        2) Invoca a função imprimir() da fatura que foi removida (se a coleção estiver vazia nada é impresso).
        3) decrementa o map de contagem de acordo com o tipo da fatura removida
        */

        std::set<Fatura, compara_faturas>::iterator it = faturas.end();

        for (--it; it != faturas.begin(); it--) // isso aqui tambem ta dando errado
        {
            it->imprimir();    // imprimir a fatura
            retirar(it);       // funcao feita para atualizar o map
            faturas.erase(it); // apagar ela do set
        }

        /*
        while (it != status.begin())
        {
            it->imprimir();

            retirar(it);

            faturas.erase(it);
            *it = *it - 1;
        }
        */
    }

    // void imprimir(): percorre toda a coleção e invoca a função imprimir() de cada fatura.
    void imprimir2()
    {
        for (Fatura elem : faturas)
            elem.imprimir();
    }

    // void status(): imprime os dados do map de contagem no formato “tipo contagem” seguido de uma quebra de linha, para cada tipo.
    void status2()
    {
        for (auto const &pair : status)
        {
            std::cout << pair.first << " " << pair.second << " " << std::endl;
        }
    }
};

// A função main() deve declarar um objeto de sua TAD Coleção, e implementar um laço infinito que permite ao usuário interagir com o sistema
int main()
{
    Colecao colecao;
    char test = 0;
    while (std::cin >> test)
    {
        switch (test)
        {
        case 'f':
        {
            std::string codigo;
            char tipo_fatura = 'p';
            double valor = 0;
            std::cin >> tipo_fatura >> valor >> codigo;
            Fatura faturinha_nova(codigo, tipo_fatura, valor);
            colecao.adicionar(faturinha_nova);
        }
        break;

        case 'r':
        {
            // invoca a funcao proxima() da colecao
            // considera-se que o pagamento sempre é realizado apos esse comando
            colecao.proxima();
        }
        break;

        case 'p':
        {
            colecao.imprimir2();
        }
        break;

        case 's':
        {
            colecao.status2(); // nao sei pq isso nao ta funcionando
        }
        break;

        case 'e':
            return 0;
            break;

        default:
            std::cout << "----------" << std::endl;
            break;
        }
    }
    return 0;
}