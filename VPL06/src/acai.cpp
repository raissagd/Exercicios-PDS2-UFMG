// TODO implemente essa classe de acordo com o hpp correspondente
#include "acai.hpp"
#include <iterator>

Acai::Acai(int tamanho, std::vector<std::string> &complementos, int qtd)
{
    _tamanho = tamanho;
    _complementos = complementos;
    _quantidade = qtd;
}

int Acai::getTamanho()
{
    return _tamanho;
}

std::vector<std::string> Acai::getComplemento()
{
    return _complementos;
}

int Acai::getQuantidadeAdicionais()
{
    return _complementos.size();
}

float Acai::calcPreco()
{
    return ((getTamanho() * 0.02) + 2.0 * (getQuantidadeAdicionais()));
}

std::string Acai::descricao() const
{
    // Exemplo: 2X açai 700ml com leite em pó, granola.
    /*
    std::string listaDeComplementos = "";
    std::vector<std::string> vtr = getComplemento();
    std::vector<std::string>::iterator it;
    std::string aux;
    for (it = vtr.begin(); it != vtr.end(); it++)
    {
        listaDeComplementos = it + ", ";
        if (it ==)
    }
    * /

    // std::string _descricao = _quantidade + ("X açai ") + _tamanho + ("ml com ") + listaDeComplementos; //nao sei o por que de isso estar dando errado

    /*
    std::string descricao = "";
    descricao += std::to_string(_quantidade);
    descricao += "X açai ";
    descricao += std::to_string(_tamanho);
    descricao += "ml com ";
    descricao += listaDeComplementos;
    descricao += ".";
    */

    // return descricao;
}
