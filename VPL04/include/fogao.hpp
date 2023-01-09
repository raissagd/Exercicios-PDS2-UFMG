#ifndef FOGAO_HPP
#define FOGAO_HPP

#include <iostream>

class Fogao
{
private:
    // Adicione suas variaveis globais aqui
    int numero_de_queimadores;
    int capacidade_forno;

public:
    // Adicione a assinatura dos seus metodos / construtores aqui
    Fogao(int numero_de_queimadores, int capacidade_forno);

    void set_queimadores(int queimadores);

    int get_queimadores();

    void set_capacidade(int capacidade);

    int get_capacidade();

    void imprimeFogao(Fogao fogao);
};

#endif