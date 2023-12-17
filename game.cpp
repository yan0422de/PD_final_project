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
    // prepare for the game
    createCardDeck();
    setboard();
    // start the game
    playGame();
}

// play the game
void Game::playGame(){
    while(!game_over){
        // determine whose turn it is
        playerNum = player1_turn ? 1 : 2;
        
        get_command(playerNum);
        
        gem_cnt_over_10(playerNum);
        
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
        int level = 0, score = 0, colorIdx = 0, white = 0, black = 0, red = 0, green = 0, blue = 0;
        string colorName;
        for(int i = 0; i < MAX_CARD_NUM; i++)
        {
            // Read
            cardFile >> level >> score >> colorName >> white >> black >> red >> green >> blue;
            
            // color to index
            colorIdx = ColorToIndex(colorName);
            
            Card* newCard = new Card(level, colorIdx, score, white, black, red, green, blue);

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

/* set the 12 cards on the board. Set the first row of board with 4 cards in vendors, second with transport, and third with mines
 */
void Game::setboard(){
    for(int i = 0; i < Card_COLS; i++){
        board[0][i] = vendors[19 - i];
        board[1][i] = transport[29 - i];
        board[2][i] = mines[39 - i];
    }
}

void Game::get_command(int playerNum){
    // receive info. from frontend
    // note: these int are indexes
    int cardRow = 0, cardCol = 0;
    int colorIdx_1 = 0, colorIdx_2 = 0, colorIdx_3 = 0;
    bool buy = 0, buyReserve = 0, take2Gems = 0, take3Gems = 0, reserve = 0;
    // determine which actions to do
    if(buy)
        players[playerNum - 1]->buyCard(board[cardRow][cardCol]);
        update_board(cardRow, cardCol);
    if(buyReserve)
        players[playerNum - 1]->buyReservedCard(board[cardRow][cardCol]);
    if(take2Gems)
        players[playerNum - 1]->takeDiamond(colorIdx_1);
    if(take3Gems)
        players[playerNum - 1]->takeDiamond(colorIdx_1, colorIdx_2, colorIdx_3);
    if(reserve){
        players[playerNum - 1]->reserveCard(board[cardRow][cardCol]);
        update_board(cardRow, cardCol);
    }
    return;
}



// update the board
void Game::update_board(int cardRow, int cardCol){
    delete board[cardRow][cardCol];
    board[cardRow][cardCol] = nullptr;
    // check if there is enough card to update the board
    if(cardRow == 0 && showedMinesCnt <= 39){
        board[cardRow][cardCol] = mines[39 - showedMinesCnt];
        showedMinesCnt++;
    }
    if(cardRow == 1 && showedTransportCnt <= 29){
        board[cardRow][cardCol] = transport[29 - showedTransportCnt];
        showedTransportCnt++;
    }
    if(cardRow == 2 && showedVendorsCnt <= 19){
        board[cardRow][cardCol] = vendors[19 - showedVendorsCnt];
        showedVendorsCnt++;
    }

}

void Game::gem_cnt_over_10(int playerNum){
    int total_gem = players[playerNum - 1] -> getAllGemCnt();

    if(total_gem > 10){
        if(total_gem == 11){
            int colorIdx = 0;
            //==========================================


            // color = i;
            //==========================================
            players[playerNum - 1]->returnDiamond(colorIdx);
        }
        else if(total_gem == 12){
            int colorIdx_1 = 0, colorIdx_2 = 0;
            //===========================================



            //===========================================
            players[playerNum - 1]->returnDiamond(colorIdx_1, colorIdx_2);
        }
        else if(total_gem == 13){
            int colorIdx_1 = 0, colorIdx_2 = 0, colorIdx_3 = 0;
            //===========================================



            //===========================================
            players[playerNum - 1]->returnDiamond(colorIdx_1, colorIdx_2, colorIdx_3);
        }
    }
    
    return;
}

bool Game::Player_Wins(){
    if(players[0] -> getPoint() >= 15){
        // player 2 can play one last round
        get_command(2);
        if(players[1] -> getPoint() < 15){    // player 1 win
            return true;
        }
        else{
            isTied = true; // tie
            return true;
        }
    }
    else if(players[1] -> getPoint() >= 15){    // player 2 win
        return true;
    }
    return true;
}

int Game::ColorToIndex(string color_str) {
    // returns pertinent color
    if (color_str == "WHITE") {
        return 0;
    }
    if (color_str == "BLACK") {
        return 1;
    }
    if (color_str == "RED") {
        return 2;
    }
    if (color_str == "GREEN") {
        return 3;
    }
    if (color_str == "BLUE") {
        return 4;
    }
    if (color_str == "GOLD") {
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
