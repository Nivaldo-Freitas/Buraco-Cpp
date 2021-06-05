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

#define SIZE 52
#define MORTOSIZE 11
#define MAOSIZE 11

using namespace std;

class lixo
{
public:

    vector <carta> lixoVetor;
    lixo(deckDeCartas *baralho);
    setLixo(deckDeCartas *baralho);
    carta retornaTopo();
    retornaSizeDoLixo();

private:

};
