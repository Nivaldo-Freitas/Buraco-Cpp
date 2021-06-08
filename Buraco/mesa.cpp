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
#include "lixo.h"
#include "mao.h"
#include "jogador.h"
#include "morto.h"
#include "Baralho.h"

#include "mesa.h"

using namespace std;

mesa::mesa()
{
    //
}

mesa::printMesa()
{
    cout << endl << "Sua mesa e: " << endl;
    for(int i = 0; i< mesaJogador.size();i++)
    {
        for(int j = 0; j< mesaJogador[i].size();j++)
        {
            getCardDisplay(mesaJogador[i][j].print());
            cout << endl;
        }
    }
    getSeparator();
}

mesa::recebeNovaSequencia(vector <carta> sequenciaRecebida)
{
    for(int i = 0; i< mesaJogador.size();i++)
    {
        if(mesaJogador[i].empty())
        {
           // mesaJogador[i].push_back(sequenciaRecebida);
        }
    }
}

mesa::setMesa(deckDeCartas *baralho)
{
    mortoJogador.setMorto(baralho);
}
