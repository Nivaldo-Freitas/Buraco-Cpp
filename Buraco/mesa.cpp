#include <iostream>
#include <ios>
#include <limits>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <algorithm>

#define QUANTIDADE_DE_DECKS 2
#define SIZE 52
#define MORTOSIZE 11
#define MAOSIZE 11

#include "designfunctions.h"
#include "lixo.h"
#include "mao.h"
#include "jogador.h"
#include "morto.h"
#include "Baralho.h"

#include "mesa.h"

using namespace std;

void organizaMesa(vector <carta> *vetor)
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

mesa::mesa()
{
    //
}

mesa::printMesa()
{
    if(mesaJogador.size() > 0)
    {
        cout << endl << "Sua mesa e: " << endl;
        for(int i = 0; i< mesaJogador.size(); i++)
        {
            cout << "sequencia: " << i+1;
            this->printSequencia(i);
            cout << endl;
        }
        cout << endl;
    }else{
        cout << endl << "Mesa Vazia" << endl;
    }
    getSeparator();
}
carta mesa::recebeCarta(int selecionador, vector <carta> sequenciaRecebida)
{
    carta currentCard = sequenciaRecebida[selecionador];
    sequenciaRecebida.erase(sequenciaRecebida.begin()+(selecionador));
    return currentCard;
}

mesa::recebeNovaSequencia(vector <carta> sequenciaRecebida)
{
    mesaJogador.push_back(sequenciaRecebida);
}

mesa::editaSequencia(int indiceDaSequencia, carta carta)
{
    mesaJogador[indiceDaSequencia].push_back(carta);
    organizaMesa(&mesaJogador[indiceDaSequencia]);
}

mesa::printSequencia(int indiceDaSequencia)
{
    for(int i = 0; i<mesaJogador[indiceDaSequencia].size();i++)
    {
        getCardDisplay(mesaJogador[indiceDaSequencia][i].print());
    }
    getSeparator();
}

mesa::setMesa(deckDeCartas *baralho)
{
    mortoJogador.setMorto(baralho);
}
