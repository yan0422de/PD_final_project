//  Game.cpp
//  PD_final_splendor
//  Created by yan on 2023/12/13.

#include "Game.h"    
#include <iostream>
#include <fstream>
#include <string>
#include "Cards.h"
#include "Players.h"
#include <vector>

using namespace std;

//constructor
Game::Game(){
    createCardDeck();
}
//
// create all cards
void Game::createCardDeck()
{
    ifstream cardFile("card_data.txt");
    if(cardFile)
    {
        int level = 0, score = 0, color = 0, white = 0, black = 0, red = 0, green = 0, blue = 0;
        string colorName;
        for(int i = 0; i < MAX_CARD_NUM; i++)
        {
            // Read
            cardFile >> level >> score >> colorName >> white >> black >> red >> green >> blue;
            
            // color to index
            color = ColorToIndex(colorName);
            
            Card* newCard = new Card(level, color, score, white, black, red, green, blue);

            // Add the raw pointer to the appropriate vector
            if (i < 40)
                mines.push_back(newCard);
            else if (i < 70 && i >= 40)
                vendors.push_back(newCard);
            else
                transport.push_back(newCard);
        }
    }
    else
        throw logic_error("Load Failed!");
    
    cardFile.close();
    
    return;
}


int Game::ColorToIndex(string color) {
    //returns pertinent color
    if (color == "WHITE") {
        return 0;
    }
    if (color == "BLACK") {
        return 1;
    }
    if (color == "RED") {
        return 2;
    }
    if (color == "GREEN") {
        return 3;
    }
    if (color == "BLUE") {
        return 4;
    }
    if (color == "GOLD") {
        return 5;
    }
    return 0;
};
