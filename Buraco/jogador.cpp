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
#include "mesa.h"

#include "jogador.h"

#define QUANTIDADE_DE_DECKS 2
#define SIZE 52
#define MORTOSIZE 11
#define MAOSIZE 11

using namespace std;

jogador::jogador(deckDeCartas *baralho)
{
  setPlayer(baralho);
}

jogador::setPlayer(deckDeCartas *baralho)
{
    // Aciona a função encheMao através do ponteiro do baralho usando o this "->"
    MaoJogador.setMao(baralho);
    MesaJogador.setMesa(baralho);

}

jogador::sacaMonte(deckDeCartas *baralho)
{
    // Aciona a função addCard através do ponteiro do baralho usando o this "->"
    MaoJogador.addCard(baralho->tiraCarta());
}

carta jogador::descarta(int posicao, lixo *lixo)
{
    lixo->addCard(MaoJogador.tiraCarta(posicao));
}

jogador::pegaLixo(lixo *lixo)
{
    MaoJogador.recebeLixo(lixo);
}

jogador::printMao()
{
    MaoJogador.printMao();
}

jogador::novaSequencia(int tamanhoDaSequencia, vector <int> indicesDasCartasSelecionadas, lixo *lixo)
{
    if(MaoJogador.verificaNaipe(tamanhoDaSequencia, indicesDasCartasSelecionadas))
    {
        MesaJogador.recebeNovaSequencia(MaoJogador.puxaSequencia(tamanhoDaSequencia, indicesDasCartasSelecionadas));
    }
}

jogador::printSequencia(int indiceDaSequencia)
{
    cout << endl << "Você escolheu editar a sequencia: ";
    MesaJogador.printSequencia(indiceDaSequencia);
    getSeparator();
}

jogador::editaSequencia(int indiceDaSequencia)
{
    int indiceDaCarta = 0;
    indiceDaSequencia--;
    this->printSequencia(indiceDaSequencia);
    this->printMao();
    cout << "Escolha qual carta vai adicionar a Sequencia: ";
    cin >> indiceDaCarta;
    if(MaoJogador.verificaNaipe(indiceDaSequencia, indiceDaCarta, &MesaJogador))
    {
        MesaJogador.editaSequencia(indiceDaSequencia, MaoJogador.tiraCarta(indiceDaCarta));
    }

}

jogador::printMesa()
{
    MesaJogador.printMesa();
}
