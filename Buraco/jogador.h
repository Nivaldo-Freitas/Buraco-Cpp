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
#include "mesa.h"
#include "Baralho.h"
#include "mao.h"

#define SIZE 52
#define MORTOSIZE 11
#define MAOSIZE 11

using namespace std;

class jogador
{

public:
    //objetos dentro de jogador
    mao MaoJogador;
    mesa MesaJogador;

    //funções
    jogador(deckDeCartas *baralho);
    setPlayer(deckDeCartas *baralho);
    sacaMonte(deckDeCartas *baralho);
    carta retornaDescarte();
    pegaLixo(lixo *lixo);
    printMao();
    printMaoVertical();
    carta descarta(int posicao, lixo *lixo);
    novaSequencia();
    printMesa();

private:

};


