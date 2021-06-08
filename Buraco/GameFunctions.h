#pragma once
#include <iostream>
#include <ios>
#include <limits>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

#define SIZE 52
#define MORTOSIZE 11
#define MAOSIZE 11

using namespace std;

void executaJogo(int qtJogadores);
void gameStart();
void endGame();
void menuDescarte(jogador *Jogador, lixo *lixo);
void menuNovaSequencia(jogador *Jogador);
void menuEdicao(jogador *Jogador);
void faseDeEdicao(jogador *Jogador,lixo *lixo);
void menuSaque(jogador *Jogador, lixo *lixo, deckDeCartas *baralho);
void iniciaJogada(jogador *Jogador, lixo *lixo,deckDeCartas *baralho);
