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

//artes
void getSeparator(){
    std::cout << "----------------------------------------" << std::endl;
}
void getBlock(){
    std::cout << "========================================" << std::endl;
}
void getDoubleChoice(std::__cxx11::string first, std::__cxx11::string second){
    std::cout << first << "                     " << second << std::endl;
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
