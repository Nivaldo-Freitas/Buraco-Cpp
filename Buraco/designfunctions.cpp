#pragma once

#include <iostream>
#include <ios>
#include <limits>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

#include "designfunctions.h"

#define DISPLAYSIZE 12

using namespace std;

void getSeparator(){
    cout << endl << "----------------------------------------" << endl;
}
void getBlock(){
    cout << endl << "========================================" << endl;
}
void getDoubleChoice(string first, string second){
    getSeparator();
    cout << first << "          |          " << second << endl;
}
void getTripleChoice(string first, string second, string third)
{
    getSeparator();
    cout << first << "          |          " << second << "          |          " << third << endl;
    getSeparator();
}
void getQuadrupleChoice(string first, string second, string third, string fourth)
{
    getSeparator();
    cout << first << "          |          " << second << "          |          " << third << "          |          " << fourth << endl;
}

void getCardDisplay(string card)
{
    string displayAux[DISPLAYSIZE] = {"|", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "|"};
    int k = 0;
    for(int i=((DISPLAYSIZE-card.size())/2); i<DISPLAYSIZE;i++)
    {
        if(k<card.size())
        {
            displayAux[i]=card[k];
            k++;
        }
    }
    for(int i=0; i<DISPLAYSIZE;i++)
    {
        cout << displayAux[i];
    }
}

void getChoice(string frase)
{
    cout << endl << frase;
    getSeparator();
    cout << endl << "Sua resposta: ";
}
