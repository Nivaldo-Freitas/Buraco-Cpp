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
#include "mesa.h"

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
    addCard(carta);
    recebeLixo(lixo *lixo);
    carta tiraCarta(int selecionador);
    vector <carta> puxaSequencia(int tamanhoDaSequencia, vector <int> indicesDasCartasSelecionadas);
    verificaNaipe(int tamanhoDaSequencia, vector <int> indicesDasCartasSelecionadas);
    verificaNaipe(int indiceDaSequencia, int indiceDaCarta, mesa *MesaJogador);

private:

};
