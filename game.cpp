//  Game.cpp
//  PD_final_splendor
//  Created by yan on 2023/12/13.

#include "game.h"    
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
    setTable();
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
                transport.push_back(newCard);
            else
                vendors.push_back(newCard);
        }
    }
    else
        throw logic_error("Load Failed!");
    
    cardFile.close();
    
    return;
}

// set the 12 cards on the table
void Game::setTable(){
    // set the first row of table with 4 cards in vendors, second with transport, and third with mines
    for(int i = 0; i < Card_COLS; i++){
        table[0][i] = vendors[19 - i];
        table[1][i] = transport[29 - i];
        table[2][i] = mines[39 - i];
    }
}
// play the game
void Game::playGame(){
    while(!game_over){
        if(player1_turn){
            get_command();
        }
    }





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
int main(){
    Game myGame;
    return 0;
}
