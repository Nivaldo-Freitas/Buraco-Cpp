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
    //Declara o deck, preenche, embaralha e print.
    deckDeCartas baralho1;
    system("pause");
    baralho1.embaralha();
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
