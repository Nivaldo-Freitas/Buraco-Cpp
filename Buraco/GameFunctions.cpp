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
    lixo lixo;
    lixo.setLixo(&baralho);
    iniciaJogada(&Jogador, &lixo,&baralho);
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
        system("cls");
        executaJogo(qtJogadores);
    }else{
        system("cls");
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
// FUNÇÕES DA FASE DE EDIÇÃO

void menuNovaSequencia(jogador *Jogador, lixo *lixo)
{
    vector <int> vetorComIndices;
    int tamanhoDaSequencia;
    cout << endl << "O digite o tamanho da sequencia que vai baixar:";
    getSeparator();
    cout << endl << "Sua resposta: ";
    cin >> tamanhoDaSequencia;
    getSeparator();
    Jogador->printMaoVertical();
    getBlock();
    cout << endl << "Digite a posicao das cartas que usará para criar sua sequencia";
    cout << endl << "Sua resposta: ";
    int posicao;
    for(int k= 0; k<tamanhoDaSequencia;k++)
    {
        cin >> posicao;
        vetorComIndices.push_back(posicao);
    }
    Jogador->novaSequencia(tamanhoDaSequencia, vetorComIndices);
    faseDeEdicao(Jogador, lixo);
}
void menuEditaSequencia(jogador *Jogador, lixo *lixo)
{
    getSeparator();
    Jogador->printMesa();
    getSeparator();
    cout << endl << "Qual Sequencia Deseja Editar?";
}
void menuEdicao(jogador *Jogador,lixo *lixo)
{
    int opcaoEscolhida;
    Jogador->printMao();
    Jogador->printMesa();
    lixo->printLixo();
    cout << endl << "O digite o numero do que deseja fazer:";
    getDoubleChoice("1 - Baixar NOVA SEQUENCIA", "2 - Editar a sequencia na Mesa");
    getSeparator();
    cout << "Sua resposta: ";
    cin >> opcaoEscolhida;
    if(opcaoEscolhida == 1)
    {
        system("cls");
        menuNovaSequencia(Jogador, lixo);
    }
    if(opcaoEscolhida == 2)
    {
        system("cls");
        menuEditaSequencia(Jogador,lixo);
    }
}
void menuDescarte(jogador *Jogador, lixo *lixo)
{
    int posicaoDaCartaNoVetor = 0;
    system("cls");
    Jogador->printMaoVertical();
    cout << "Escolha qual carta vai descartar:" << endl;
    cout << "Sua resposta: ";
    cin >> posicaoDaCartaNoVetor;
    Jogador->descarta(posicaoDaCartaNoVetor, lixo);
    Jogador->printMao();
    lixo->printLixo();
}
void faseDeEdicao(jogador *Jogador, lixo *lixo)
{
    system("cls");
    Jogador->printMao();
    int opcaoEscolhida = 0;
    cout << endl << "O digite o numero do que deseja fazer:";
    getDoubleChoice("1 - Editar a Mesa", "2 - Escolher uma carta para Descartar");
    getSeparator();
    cout << "Sua resposta: ";
    cin >> opcaoEscolhida;
    if(opcaoEscolhida == 1)
    {
        system("cls");
        menuEdicao(Jogador, lixo);
    }
    if(opcaoEscolhida == 2)
    {
        system("cls");
        menuDescarte(Jogador, lixo);
    }
    if(opcaoEscolhida != 1 && opcaoEscolhida != 2)
    {
        faseDeEdicao(Jogador, lixo);
    }
}

// FUNÇÕES DE INICIO DE JOGADA
void menuSaque(jogador *Jogador, lixo *lixo, deckDeCartas *baralho)
{
    int opcaoEscolhida = 0;
    cout << endl << "O digite o numero do que deseja fazer:";
    getTripleChoice("1 - Sacar do Lixo", "2 - Sacar do Monte", "3 - Ver Mao,Mesa e Lixo");
    getSeparator();
    cout << "Sua resposta: ";
    cin >> opcaoEscolhida;
    if(opcaoEscolhida == 1)
    {
        Jogador->pegaLixo(lixo);
        faseDeEdicao(Jogador, lixo);
    }
    if(opcaoEscolhida == 2)
    {
        Jogador->sacaMonte(baralho);
        faseDeEdicao(Jogador, lixo);
    }
    if(opcaoEscolhida == 3)
    {
        system("cls");
        Jogador->printMao();
        Jogador->printMesa();
        lixo->printLixo();
        menuSaque(Jogador,lixo,baralho);
    }
    if(opcaoEscolhida != 1 && opcaoEscolhida != 2 && opcaoEscolhida != 3)
    {
        system("cls");
        getBlock();
        cout << "insira um numero valido dentre as opcoes" << endl;
        getBlock();
        menuSaque(Jogador,lixo,baralho);
    }
}
void iniciaJogada(jogador *Jogador, lixo *lixo, deckDeCartas *baralho)
{
    Jogador->printMao();
    menuSaque(Jogador,lixo,baralho);
}

