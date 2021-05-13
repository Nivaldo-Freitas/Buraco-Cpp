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
carta::carta(string pesoDaCarta, string naipeDaCarta)
{
    peso = pesoDaCarta;
    naipe = naipeDaCarta;
}
//print function definition

string carta::print()
{
    //return the way the card will be displayed
    return (peso + " of " + naipe);
}

//Cria o as SIZE cartas do deck
deckDeCartas::deckDeCartas()
{
    //insere todos os possiveis pesos de cada naipe
    string arrayDePesos[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    //insere todos os possiveis naipes
    string arrayDeNaipes[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    // *----------- Criando o deck vazio -----------* //
        //inicializa deck atrav�s da classe carta para um novo array usando o new
        baralho=new carta[SIZE];
        cout << "Baralho criado com sucesso \n";

    // *----------- Inserindo cartas -----------* //
        //cria um loop para colocar cada carta no novo array
        cout << "Inserindo cartas no baralho... \n";
        for(int count = 0; count < SIZE; count++)
        {
            //a carta dentro do baralho na posi��o count receber� os pesos e naipes
            baralho[count] = carta(arrayDePesos[count % 13], arrayDeNaipes[count / 13]);
        }
        cout << "Insercao bem sucedida. \n";
        system("pause");

    // *----------- Printando as cartas apos embaralhadas -----------* //
        for(int count = 0; count < SIZE; count++)
        {
        carta currentCard = baralho[count];
        cout << currentCard.print() << " ";
        cout << count << endl;
        }
}

deckDeCartas::embaralha()
{
        //Crio um loop para embaralhar as cartas 6 vezes
        for (int j=0; j<6; j++) {
            for(int first = 0; first < SIZE; first++)
            {

            // *----------- Embaralhando as cartas -----------* //
            // crio um int chamado Second e seto ele como  igual ao operador randomico
            int second = (rand() + time(0)) % SIZE;
            // Igualo currentCard � baralho na posi��o first (lembrando que current card � uma class card)
            carta currentCard = baralho[first];
            // Troco a carta dentro de baralho na posi��o first por baralho na posi��o second
            baralho[first] = baralho[second];
            // Troco a carta dentro de baralho na posi��o second por currentCard
            baralho[second] = currentCard;
            }
        j++;
        }
}
//deckDeCartas::criaMorto()
//{

//}
