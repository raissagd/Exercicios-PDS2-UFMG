#include "fogao.hpp"
#include "geladeira.hpp"
#include "estoque.hpp"
#include <iterator>
#include <vector>
#include <stdlib.h>

Estoque::Estoque() {}

void Estoque::armazena_geladeira(int capacidade, int portas)
{
    Geladeira geladeira = Geladeira(capacidade, portas);
    geladeiras.push_back(geladeira);
}

void Estoque::vende_geladeira(int capacidade, int portas)
{
    int i = 0;
    Geladeira geladeira(capacidade, portas);
    std::vector<Geladeira>::iterator it;
    for (it = geladeiras.begin(); it != geladeiras.end(); it++, i++)
    {
        if (it->get_capacidade() == geladeira.get_capacidade() &&
            it->get_portas() == geladeira.get_portas())
        {
            geladeiras.erase(geladeiras.begin() + i);
            break;
        }
    }
}

void Estoque::armazena_fogao(int queimadores, int capacidade)
{
    Fogao fogao = Fogao(queimadores, capacidade);
    fogoes.push_back(fogao);
}

void Estoque::vende_fogao(int queimadores, int capacidade)
{
    int i = 0;
    Fogao fogao(queimadores, capacidade);
    std::vector<Fogao>::iterator it;
    for (it = fogoes.begin(); it != fogoes.end(); it++, i++)
    {
        if (it->get_queimadores() == fogao.get_queimadores() &&
            it->get_capacidade() == fogao.get_capacidade())
        {
            fogoes.erase(fogoes.begin() + i);
            break;
        }
    }
}

void Estoque::exibe_geladeiras()
{
    for (Geladeira geladeira : geladeiras)
    {
        geladeira.imprimeGeladeira(geladeira);
    }
}

void Estoque::exibe_fogoes()
{
    for (Fogao fogao : fogoes)
    {
        fogao.imprimeFogao(fogao);
    }
}

int Estoque::quantidade_geladeiras()
{
    return geladeiras.size();
}

int Estoque::quantidade_fogoes()
{
    return fogoes.size();
}
