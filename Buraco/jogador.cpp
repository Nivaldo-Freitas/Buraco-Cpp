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
#include "lixo.h"

#include "jogador.h"

#define QUANTIDADE_DE_DECKS 2
#define SIZE 52
#define MORTOSIZE 11
#define MAOSIZE 11

using namespace std;

jogador::jogador()
{
  //
}

jogador::setPlayer(deckDeCartas *baralho)
{
    // Aciona a função encheMao através do ponteiro do baralho usando o this "->"
    MaoJogador.encheMao(baralho);
}

jogador::saca(deckDeCartas *baralho)
{
    // Aciona a função addCard através do ponteiro do baralho usando o this "->"
    MaoJogador.addCard(baralho->tiraCarta());
}

carta jogador::descarta(int posicao, lixo *lixo)
{
    //carta currentCard = MaoJogador[posicao];
    //MaoJogador.erase(find(MaoJogador.begin(),MaoJogador.end(),currentCard));
    //lixo.recebecurrentCard;
}

jogador::pegaLixo(lixo *lixo)
{
    MaoJogador.recebeLixo(lixo);
}

jogador::printMao()
{
    MaoJogador.printMao();
}
