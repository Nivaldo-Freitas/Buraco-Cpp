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
#include "Baralho.h"

#define QUANTIDADE_DE_DECKS 2
#define SIZE 52
#define MORTOSIZE 11
#define MAOSIZE 11

using namespace std;

class morto
{

public:

    vector <carta> mortoVetor;
    morto();
    setMorto(deckDeCartas *baralho);

private:

};
