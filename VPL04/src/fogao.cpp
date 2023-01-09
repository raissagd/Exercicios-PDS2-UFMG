#include "fogao.hpp"

Fogao::Fogao(int queimadores, int capacidade)
{
    numero_de_queimadores = queimadores;
    capacidade_forno = capacidade;
}

void Fogao::set_queimadores(int queimadores)
{
    numero_de_queimadores = queimadores;
}

int Fogao::get_queimadores()
{
    return numero_de_queimadores;
}

void Fogao::set_capacidade(int capacidade)
{
    capacidade_forno = capacidade;
}

int Fogao::get_capacidade()
{
    return capacidade_forno;
}

void Fogao::imprimeFogao(Fogao fogao)
{
    std::cout << "F"
              << " " << fogao.numero_de_queimadores << " " << fogao.capacidade_forno << std::endl;
}