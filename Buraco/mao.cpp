
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
#include "jogador.h"
#include "lixo.h"

#include "mao.h"

#define SIZE 52
#define MORTOSIZE 11
#define MAOSIZE 11

using namespace std;

mao::mao()
{
    //
}

mao::setMao(deckDeCartas *baralho)
{
    for(int i=0; i<MAOSIZE;i++)
    {
        maoVetor.push_back(baralho->tiraCarta());
    }
}

mao::printMao()
{
    vector <carta> maoAux = maoVetor;
    cout << endl << "Sua mao e: " << endl;
    for(int i=0; i<maoVetor.size();i++)
    {
        cout << maoAux.back().print() << "  |  ";
        maoAux.pop_back();
    }
    getSeparator();
}

mao::printMaoVertical()
{
    vector <carta> maoAux = maoVetor;
    cout << endl << "Sua mao e: " << endl;
    for(int i=0; i<maoVetor.size();i++)
    {
        getCardDisplay(maoAux.back().print());
        cout << maoVetor.size()-(i+1) << endl;
        maoAux.pop_back();
    }
    getSeparator();
}

mao::addCard(carta cartaSelecionada)
{
    maoVetor.push_back(cartaSelecionada);
}

mao::recebeLixo(lixo *lixo)
{
    for(int i=0; i<lixo->retornaSizeDoLixo();i++)
    {
        maoVetor.push_back(lixo->retornaTopo());
    }
}

carta mao::selecionaCarta(int selecionador)
{
    carta currentCard = maoVetor[selecionador];
    maoVetor.erase(maoVetor.begin()+(selecionador));
    return currentCard;
}
