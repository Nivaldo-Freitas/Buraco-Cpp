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
#include "morto.h"
#include "Baralho.h"

#define QUANTIDADE_DE_DECKS 2
#define SIZE 52
#define MORTOSIZE 11
#define MAOSIZE 11

using namespace std;

class mesa
{

public:
    // Vetores de vetores de cartas.
    vector <vector <carta>> mesaJogador;
    // Criando morto do jogador
    morto mortoJogador;
    // Construtor padrão da mesa, não uso para nada
    mesa();
    printMesa();
    recebeNovaSequencia(vector <carta> sequenciaRecebida);
    editaSequencia(int indiceDaSequencia, carta carta);
    printSequencia(int indiceDaSequencia);
    setMesa(deckDeCartas *baralho);
    carta recebeCarta(int selecionador, vector <carta> sequenciaRecebida);

private:

};
