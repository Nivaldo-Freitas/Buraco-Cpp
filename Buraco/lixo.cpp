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
#include "mao.h"
#include "jogador.h"

#include "lixo.h"

#define QUANTIDADE_DE_DECKS 2
#define SIZE 52
#define MORTOSIZE 11
#define MAOSIZE 11

using namespace std;

lixo::lixo()
{
    //
}

lixo::setLixo(deckDeCartas *baralho)
{
    lixoVetor.push_back(baralho->tiraCarta());
}

carta lixo::retornaTopo()
{
    carta currentCard = lixoVetor.back();
    lixoVetor.pop_back();
    return currentCard;
}

lixo::retornaSizeDoLixo()
{
    return lixoVetor.size();
}

lixo::printLixo()
{
    vector <carta> lixoAux = lixoVetor;
    cout << endl << "O lixo e: " << endl;
    for(int i=0; i<lixoVetor.size();i++)
    {
        cout << lixoAux.back().print() << "  |  ";
        lixoAux.pop_back();
    }
    getSeparator();
}

lixo::addCard(carta carta)
{
    lixoVetor.push_back(carta);
}
