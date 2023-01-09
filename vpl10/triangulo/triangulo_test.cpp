#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "triangulo.hpp"
#include "doctest.h"

//    O subcaso positivo, com checagens que funcionam mesmo com os bugs.
//    O subcaso negativo, com checagens que não funcionam por conta do bug, mas passarão a funcionar após sua correção.

TEST_CASE("Testando a função getPerimeter: ") // o bug é que ele soma o lado 2 duas vezes, ao invés de somar o terceiro.
{
    SUBCASE("Caso positivo: ")
    {
        shapes::Triangle t1(5, 4, 4); // como soma o segundo lado duas vezes, essa função vai funcionar para triângulo equiláteros
        shapes::Triangle t2(4, 4, 4); // e isósceles com os dois últimos lados iguais

        CHECK_EQ(13, t1.getPerimeter());
        CHECK_EQ(12, t2.getPerimeter());
    }

    SUBCASE("Caso Negativo: ")
    {
        shapes::Triangle t1(5, 4, 3);
        shapes::Triangle t2(10, 8, 6);

        CHECK_EQ(12, t1.getPerimeter());
        CHECK_EQ(24, t2.getPerimeter());
    }
}

TEST_CASE("Testando a função getArea: ") // o problema dessa função, é q ela recebe o valor de perimetro errado da primeira,
{                                        // e aí a conta sai errada?
    SUBCASE("Caso positivo: ")
    {
        shapes::Triangle t1(5, 4, 4);
        shapes::Triangle t2(10, 8, 8);
        shapes::Triangle t3(4, 4, 4);

        CHECK_EQ(7.80625, t1.getArea()); // valores verídicos
        CHECK_EQ(31.225, t2.getArea());
        CHECK_EQ(6.9282, t3.getArea());
    }

    SUBCASE("Caso Negativo: ")
    {
        shapes::Triangle t1(5, 4, 3);
        shapes::Triangle t2(10, 8, 6);

        CHECK_EQ(6, t1.getArea());  // se o resultado da função getperimetro tivesse sido retornado corretamente,
        CHECK_EQ(24, t2.getArea()); // esses teriam que ser os valores das áreas
    }
}

TEST_CASE("Testando a função getKind: ") // o bug é qUE todo equilátero, é um isósceles antes
{
    SUBCASE("Caso positivo: ")
    {
        shapes::Triangle t1(5, 4, 3);
        shapes::Triangle t2(10, 8, 8);

        CHECK_EQ(shapes::Triangle::Kind::SCALENE, t1.getKind());
        CHECK_EQ(shapes::Triangle::Kind::ISOSCELES, t2.getKind());
    }

    SUBCASE("Caso Negativo: ")
    {
        shapes::Triangle t1(4, 4, 4);
        CHECK_EQ(shapes::Triangle::Kind::EQUILATERAL, t1.getKind()); // vai retornar que ele é um isósceles
    }
}