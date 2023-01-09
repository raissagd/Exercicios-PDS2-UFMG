#ifndef GELADEIRA_HPP
#define GELADEIRA_HPP

#include <iostream>

class Geladeira
{
private:
    // Adicione suas variaveis globais aqui
    int capacidade_em_litros;
    int numero_de_portas;

public:
    // Adicione a assinatura dos seus metodos / construtores aqui
    Geladeira(int capacidade_em_litros, int numero_de_portas);

    void set_capacidade(int capacidade);

    int get_capacidade();

    void set_portas(int portas);

    int get_portas();

    void imprimeGeladeira(Geladeira geladeira);
};

#endif