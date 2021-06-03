#pragma once
#include <iostream>
#include <ios>
#include <limits>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

#include "Baralho.h"
#include "mao.h"

#define SIZE 52
#define MORTOSIZE 11
#define MAOSIZE 11

using namespace std;

class jogador
{

public:
    mao MaoJogador;
    jogador();
    setPlayer(deckDeCartas *baralho);
    saca(deckDeCartas *baralho);
    carta retornaDescarte();
    pegaLixo(lixo *lixo);
    printMao();
    carta descarta(int posicao, lixo *lixo);

private:

};


