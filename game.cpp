//  Game.cpp
//  PD_final_splendor

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
    setTable();
    playGame();
}

// play the game
void Game::playGame(){
    while(!game_over){
        num = player1_turn ? 1 : 2;    // identify which player round
       
        get_command(num);
        
        gem_cnt_over_10(num);
        
        if(Player_Wins()){
            clear_memory();
            return;
        }
        player1_turn = !player1_turn;    // switch player
    }
}


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

/* set the 12 cards on the table. Set the first row of table with 4 cards in vendors, second with transport, and third with mines
 */
void Game::setTable(){
    for(int i = 0; i < Card_COLS; i++){
        table[0][i] = vendors[19 - i];
        table[1][i] = transport[29 - i];
        table[2][i] = mines[39 - i];
    }
}

void Game::get_command(int num){
    // receive info. from frontend
    players[num]->buyCard(table[0][0]);    // for test
    return;
}

void Game::gem_cnt_over_10(int num){
    int total_gem = players[num] -> getAllGemCnt();
    
    if(total_gem > 10){
        if(total_gem == 11){
            int color = 0;
            //get_command(num);
            players[num]->returnDiamond(color);
        }
        else if(total_gem == 12){
            int color1 = 0, color2 = 0;
            //get_command(num);
            players[num]->returnDiamond(color1, color2);
        }
        else if(total_gem == 13){
            int color1 = 0, color2 = 0, color3 = 0;
            //get_command(num);
            players[num]->returnDiamond(color1, color2, color3);
        }
    }
    
    return;
}

bool Game::Player_Wins(){
    if(players[1] -> getPoint() >= 15){
        // player 2 can play once
        // get_command(num)
        if(players[2] -> getPoint() < 15){
            return true;
        }
        else{
            isTied = true;    // tie
            return true;
        }
    }
    else if(players[2] -> getPoint() >= 15){
        return true;
    }
    
    return false;
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

void Game::clear_memory() {
    for (auto card : mines) {
        delete card;
    }
    mines.clear();
    
    for (auto card : transport) {
        delete card;
    }
    transport.clear();

    for (auto card : vendors) {
        delete card;
    }
    vendors.clear();
}
