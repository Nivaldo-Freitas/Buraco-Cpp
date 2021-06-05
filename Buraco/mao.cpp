
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
    for(int i=0; i<maoVetor.size();i++)
    {
        cout << maoAux.back().print() << "  |  ";
        maoAux.pop_back();
    }
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

//mao::selecionaCarta(int selecionador)
//{
    //return maoVetor[selecionador];
//}
