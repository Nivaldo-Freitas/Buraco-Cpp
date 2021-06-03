#pragma once
#include <iostream>
#include <ios>
#include <limits>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

#include "lixo.h"

#define SIZE 52
#define MORTOSIZE 11
#define MAOSIZE 11

using namespace std;

class mao
{

public:

    vector <carta> maoVetor;
    mao();
    encheMao(deckDeCartas *baralho);
    printMao();
    addCard(carta);
    recebeLixo(lixo *lixo);
    selecionaCarta(int selecionador);

private:

};
