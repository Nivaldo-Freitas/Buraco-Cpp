#include <iostream>
#include <ios>
#include <limits>
#include <stdio.h>
#include <vector>
#define SIZE 52
#include <cstdlib>
#include <ctime>
using namespace std;

//create a class called card
class carta
{
public:
//construtor padrão de cartas vazias
carta();
//Construtor com parametros, para preencher as cartas vazias criadas
carta(string pesoDaCarta, string naipeDaCarta);
//print function
string print();
//Cria duas strings para naipe e pesos da carta
string peso;
string naipe;

private:

};

//create a class for deckOfCards
class deckDeCartas
{
public:
//keep track of what card you are dealing with
string currentCard;
// Default constructor: assigns the 52 cards to deck
deckDeCartas();
//variable card with a pointer to deck
carta *baralho;
embaralha();
private:

};
