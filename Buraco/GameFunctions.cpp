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
#include "jogador.h"
#include "lixo.h"

#include "GameFunctions.h"

using namespace std;

void executaJogo(int qtJogadores){
    deckDeCartas baralho;
    baralho.embaralha();
    jogador Jogador(&baralho);
    lixo lixo(deckDeCartas *baralho);
    Jogador.printMao();
    baralho.printaTudo();
}
void gameStart()
{
    int qtJogadores = 0;
    getDoubleChoice("1 - Solo", "2 - Dupla");
    getSeparator();
    cout << "Sua resposta: ";
    cin >> qtJogadores;
    cout << "\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(qtJogadores == 1 || qtJogadores == 2){
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
