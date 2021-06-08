#pragma once

#include <iostream>
#include <ios>
#include <limits>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

#include "designfunctions.h"
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
    setMao(deckDeCartas *baralho);
    printMao();
    printMaoVertical();
    addCard(carta);
    recebeLixo(lixo *lixo);
    carta selecionaCarta(int selecionador);

private:

};
