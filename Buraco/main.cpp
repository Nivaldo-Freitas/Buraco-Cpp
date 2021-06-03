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

int main()
{
    cout << "Bem vindo, quantos jogadores?" << endl;
    gameStart();
    endGame();
    return 0;
    }
