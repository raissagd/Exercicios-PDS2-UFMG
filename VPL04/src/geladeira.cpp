#include "geladeira.hpp"

// Adicione seus metodos / construtores aqui

Geladeira::Geladeira(int capacidade, int portas)
{
    capacidade_em_litros = capacidade;
    numero_de_portas = portas;
}

void Geladeira::set_capacidade(int capacidade)
{
    capacidade_em_litros = capacidade;
}

int Geladeira::get_capacidade()
{
    return capacidade_em_litros;
}

void Geladeira::set_portas(int portas)
{
    numero_de_portas = portas;
}

int Geladeira::get_portas()
{
    return numero_de_portas;
}

void Geladeira::imprimeGeladeira(Geladeira geladeira)
{
    std::cout << "G"
              << " " << geladeira.capacidade_em_litros << " " << geladeira.numero_de_portas << std::endl;
}
