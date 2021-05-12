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
//default constructer
carta();
//constructer with parameters
carta(string cardFace, string cardSuit);
//print function
string print();

private:
//create two card variables face and suit
string face;
string suit;

};

//create a class for deckOfCards
class deckDeCartas
{
public:

// Default constructor: assigns the 52 cards to deck
criaDeckDeCartas();
embaralha();
//deals out one card from the deck of 52, refrences class card
carta dealCard();



private:
//variable card with a pointer to deck
carta *baralho; // an array of cards of size SIZE
//keep track of what card you are dealing with
string currentCard;
//shuffles the deck once all the cards are assigned
};
