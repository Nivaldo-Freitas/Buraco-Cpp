
#include <algorithm>
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

void organizaVetor(vector <carta> *vetor)
{
    sort(vetor->begin(), vetor->end(),
    [](const carta& atual, const carta& proximo)
    {
        return atual.peso < proximo.peso;
    });
    sort(vetor->begin(), vetor->end(),
    [](const carta& atual, const carta& proximo)
    {
        return atual.naipe < proximo.naipe;
        ;
    });
}

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
    organizaVetor(&maoVetor);
}

mao::printMao()
{
    organizaVetor(&maoVetor);
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

carta mao::tiraCarta(int selecionador)
{
    carta currentCard = maoVetor[selecionador];
    maoVetor.erase(maoVetor.begin()+selecionador);
    return currentCard;
}

vector <carta> mao::puxaSequencia(int tamanhoDaSequencia, vector <int> indicesDasCartasSelecionadas)
{
        vector <carta> vetorAuxiliar;
        for(int x= 0; x<tamanhoDaSequencia; x++)
        {
            vetorAuxiliar.push_back(tiraCarta(indicesDasCartasSelecionadas[x]));
            for(int z= 0; z<tamanhoDaSequencia; z++)
            {
                indicesDasCartasSelecionadas[z]--;
            }
        }
        return vetorAuxiliar;
}

mao::verificaNaipe(int tamanhoDaSequencia, vector <int> indicesDasCartasSelecionadas)
{
    vector <carta> vetorAuxiliar;
    for(int h = 1; h<tamanhoDaSequencia;h++)
    {
        int aux=0;
        if(maoVetor[indicesDasCartasSelecionadas[h-1]].naipe == maoVetor[indicesDasCartasSelecionadas[h]].naipe)
        {
            aux++;
            if(aux == (tamanhoDaSequencia-1))
            {
                if(!puxaSequencia(tamanhoDaSequencia, indicesDasCartasSelecionadas).empty())
                {
                    return true;
                }
            }
        }else{
            return false;
        }
    }
}

mao::verificaNaipe(int indiceDaSequencia, int indiceDaCarta, mesa *MesaJogador)
{
    if(maoVetor[indiceDaCarta].naipe == MesaJogador->mesaJogador[indiceDaSequencia][1].naipe)
    {
        return true;
    }else{
        return false;
    }
}



