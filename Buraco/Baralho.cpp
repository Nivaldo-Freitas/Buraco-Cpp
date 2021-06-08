#include <iostream>
#include <ios>
#include <limits>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

#include "designfunctions.h"
#include "jogador.h"
#include "mao.h"
#include "lixo.h"

#include "Baralho.h"

#define QUANTIDADE_DE_DECKS 2
#define SIZE 52
#define MORTOSIZE 11
#define MAOSIZE 11

using namespace std;

//default constructor
carta::carta()
{
 // aqui adiciona um elemento vazio ao vetor do baralho.
}

//constructor com dois parametros
carta::carta(int pesoDaCarta, int naipeDaCarta)
{
    peso = pesoDaCarta;
    naipe = naipeDaCarta;
}
//print function definition

string carta::print()
{
    string pesoAux;
    string naipeAux;
    switch(peso)
    {
        case 1:
            pesoAux = "Ace";
            break;
        case 11:
            pesoAux = "Jack";
            break;
        case 12:
            pesoAux = "Queen";
            break;
        case 13:
            pesoAux = "King";
            break;
        default:
            stringstream A;
            A << peso;
            A >> pesoAux;
            break;
    }
    switch(naipe)
    {
        case 0:
            naipeAux = "C";
            break;
        case 1:
            naipeAux = "D";
            break;
        case 2:
            naipeAux = "P";
            break;
        case 3:
            naipeAux = "E";
            break;
    }
    return (pesoAux + " of " + naipeAux);
}

//Cria o as SIZE cartas do deck
deckDeCartas::deckDeCartas()
{
    //insere todos os possiveis pesos de cada naipe
    int arrayDePesos[] = {1, 2, 3, 4, 5, 6 , 7, 8, 9, 10, 11, 12, 13};
    //*-----------insere todos os possiveis naipes-----------*
    int arrayDeNaipes[] = {0, 1, 2, 3};

    // *----------- Inserindo cartas -----------* //
        //cria um loop para colocar cada carta no novo array
    for(int i = 0; i < QUANTIDADE_DE_DECKS; i++)
    {
        for(int k = 0; k < SIZE; k++)
        {
            //-----------* a carta dentro do baralho na posição count receberá os pesos e naipes -----------*
            baralho.push_back(carta(arrayDePesos[k % 13], arrayDeNaipes[k / 13]));
        }
    }
    embaralha();
}

deckDeCartas::embaralha()
{
    //*-----------Crio um loop para embaralhar as cartas 6 vezes-----------*
    for (int j=0; j<40; j++)
    {
        for(int first = 0; first < baralho.size(); first++)
        {
                    // *----------- Embaralhando as cartas -----------* //
            // crio um int chamado Second e seto ele como  igual ao operador randomico
            int second = (rand() + time(0)) % SIZE;
            // Igualo currentCard à baralho na posição first (lembrando que current card é uma class card)
            carta currentCard = baralho[first];
            // Troco a carta dentro de baralho na posição first por baralho na posição second
            baralho[first] = baralho[second];
            // Troco a carta dentro de baralho na posição second por currentCard
            baralho[second] = currentCard;
        }
    j++;
    }
}

deckDeCartas::printaTudo()
{
    vector <carta> baralhoAux = baralho;
    // *----------- Printando as cartas -----------* //
    for(int i = 0; i < baralho.size(); i++)
    {
        carta currentCard = baralhoAux.back();
        baralhoAux.pop_back();
        getCardDisplay(currentCard.print());
        cout << endl;
    }
}

carta deckDeCartas::tiraCarta()
{
    carta currentCard = baralho.back();
    baralho.pop_back();
    return currentCard;
}
