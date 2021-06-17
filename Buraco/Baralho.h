#pragma once
#include <iostream>
#include <ios>
#include <limits>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

#define SIZE 52

using namespace std;

class carta
{
public:
        //construtor padr�o de cartas vazias
    carta();
        //Construtor com parametros, para preencher as cartas vazias criadas
    carta(int pesoDaCarta, int naipeDaCarta);
        //Fun��o que retorna o naipe, usado para compara��es e ordena��es.
    retornaNaipe();
        //print function
    string print();
        //Cria duas strings para naipe e pesos da carta
    int peso;
    int naipe;

private:

};


class deckDeCartas
{
public:

    vector <carta> baralho;

    deckDeCartas();
    embaralha();
    printaTudo();
    carta tiraCarta();

private:

};
