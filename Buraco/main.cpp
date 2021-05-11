#include <iostream>
#include "designfunctions.h"
#include <ios>
#include <limits>
#include <stdio.h>
#include <vector>
#include "Baralho.h"
#include <cstdlib>
#include <ctime>

using namespace std;

void executaJogo(int qtJogadores){
    //declare deckofcards(from class) called deck
    cout << "primeira linha de executa jogo" << endl;
    deckDeCartas deck;
    cout << "passei pelo deck de cartas" << endl;
    //declate car called(from class) current card
    //card currentCard;
    //shuffle the deck that you just initalized
    //deck.shuffle();
    //determine how many cards you want to print out to the user
    //right now it is two because we decided that each player will get two cards when they start
    for( int i = 0; i <= 104; i++)
    {
        //set current card equal to deck.dealcard
        //the return value will replace it

        carta currentCard = deck.dealCard();
        //include to actually print out current card in the format we want
        cout << currentCard.print() << endl;
    }
}

void gameStart(){

    int qtJogadores = 0;
    getDoubleChoice("1 - Solo", "2 - Dupla");
    getSeparator();
    cout << "Sua resposta: ";
    cin >> qtJogadores;
    cout << "\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(qtJogadores == 1 || qtJogadores == 2){
        cout << "aa" << endl;
        executaJogo(qtJogadores);
    }else{

        getBlock();
        cout << "Informe um valor correto" << endl;
        cout << "Dupla ou Solo?" << endl;
        getBlock();
        gameStart();
    }
}
void endGame(){
    string escolha = "";
    getSeparator();
    cout << "Deseja Jogar Novamente?" << endl;
    getDoubleChoice("s - Sim", "n - Nao");
    cin >> escolha;

    if(escolha == "s"){
            gameStart();

    }else if(escolha != "n"){
        getBlock();
        cout << "Informe um valor correto" << endl;
        getBlock();
        endGame();
    }
}

int main()
{
    cout << "Bem vindo, quantos jogadores?" << endl;
    gameStart();
    endGame();
    return 0;
    }
