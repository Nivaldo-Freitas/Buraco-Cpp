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
    carta(string pesoDaCarta, string naipeDaCarta);
        //print function
    string print();
        //Cria duas strings para naipe e pesos da carta
    string peso;
    string naipe;

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
