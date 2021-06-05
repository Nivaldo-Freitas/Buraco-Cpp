#pragma once

#include <iostream>
#include <ios>
#include <limits>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

#define QUANTIDADE_DE_DECKS 2
#define SIZE 52
#define MORTOSIZE 11
#define MAOSIZE 11

#include "designfunctions.h"
#include "Baralho.h"

#include "morto.h"

using namespace std;

morto::morto()
{
    //
}

morto::setMorto(deckDeCartas *baralho)
{
    for(int i=0; i<MORTOSIZE;i++)
    {
        mortoVetor.push_back(baralho->tiraCarta());
    }
}
