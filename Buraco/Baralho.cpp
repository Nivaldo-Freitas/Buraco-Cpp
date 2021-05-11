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
#define SIZE 52

using namespace std;

//default constructor
carta::carta()
{
 // aqui adiciona um elemento vazio ao vetor do baralho.
}

//constructor with two parameters
carta::carta(string cardFace, string cardSuit)
{
    face = cardFace;
    suit = cardSuit;
}
//print function definition
string carta::print()
{
    //return the way the card will be displayed
    return (face + " of " + suit);
}

//assigns the 52 cards to deck
deckDeCartas::deckDeCartas()
{
    //insere todos os possiveis pesos de cada naipe
    string pesos[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    //insere todos os possiveis naipes
    string naipe[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    //inicializa deck através da classe carta para um novo array usando o new
    carta *baralho1=new carta[SIZE];
    //limpa o valor da carta atual
    currentCard = "";
    //crio um loop para colocar cada carta no novo array
    for(int count = 0; count < SIZE; count++)
    {
        //deck at postion count will be equal to card, each with a different face and suit
        baralho1[count] = carta(pesos[count % 13], naipe[count / 13]);
    }
}
//shuffles the deck once all the cards are assigned
void deckDeCartas::embaralha()
{
    //start at current card
    currentCard = "";
    //create a for loop so all 52 cards will be shuffled
    for(int first = 0; first < SIZE; first++)
    {
        //create an int called second and set it equal to the random operator
        int second = (rand() + time(0)) % SIZE;
        //create an int called temp and set it equal to the deck at the first postiion
        carta temp = deck[first];
        //swap deck at first and second postion
        deck[first] = deck[second];
        //swap deck and temp
        deck[second] = temp;
    }
}


carta deckDeCartas::dealCard()
{
    //se não estivermos sem cartas
    int k;
    stringstream intcurrentCard(currentCard);
    intcurrentCard >> k;
    if(k > SIZE)
    {
        //embaralha
        embaralha();
    }
    //se não estivermos sem cartas
    if( k < SIZE)
    {
        //return deck at that current card and then increment
        return (deck[k++]);
    }
    //return the first card in the deck that we just found
    return (deck[0]);
}
