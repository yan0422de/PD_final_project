//  Game.cpp
//  PD_final_splendor

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Cards.h"
#include "Players.h"
#include <vector>

using namespace std;

// constructor
Game::Game() {
    // create player object and store them as pointers
    for (int i = 0; i < Players_CNT; i++)
        players[i] = new Player;
    // prepare for the game
    createCardDeck();
    setboard();

}
// destructor
Game::~Game() {
    for (int i = 0; i < Players_CNT; i++) {
        delete players[i];
        players[i] = nullptr;
    }
}

// play the game
void Game::playGame() {
    while (!game_over) {
        // determine whose turn it is
        playerNum = player1_turn ? 1 : 2;

        get_command(playerNum);

        gem_cnt_over_10(playerNum);

        if (Player_Wins()) {
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
    if (cardFile)
    {
        int level = 0, score = 0, colorIdx = 0, white = 0, black = 0, red = 0, green = 0, blue = 0;
        string colorName;
        for (int i = 0; i < MAX_CARD_NUM; i++)
        {
            // Read
            cardFile >> level >> score >> colorName >> white >> red >> black >> blue >> green;

            // color to index
            colorIdx = ColorToIndex(colorName);


            // Add the raw pointer to the appropriate vector
            if (i < 40) {
                Card* newCard = new Card(i, level, colorIdx, score, white, black, red, green, blue, "mines", sf::RectangleShape(sf::Vector2f(75.0f, 130.0f)), sf::Vector2f(200.f, 510.0f), sf::Vector2f(200.f, 510.0f));
                mines.push_back(newCard);
            }
                
            else if (i < 70 && i >= 40) {
                Card* newCard = new Card((i - 40), level, colorIdx, score, white, black, red, green, blue, "transport", sf::RectangleShape(sf::Vector2f(75.0f, 130.0f)), sf::Vector2f(200.f, 345.0f), sf::Vector2f(200.f, 345.0f));
                transport.push_back(newCard);
            }
                
            else {
                Card* newCard = new Card((i - 70), level, colorIdx, score, white, black, red, green, blue, "vendors", sf::RectangleShape(sf::Vector2f(75.0f, 130.0f)), sf::Vector2f(200.f, 180.0f), sf::Vector2f(200.f, 180.0f));
                vendors.push_back(newCard);
            }
        }
    }
    else
        throw logic_error("Load Failed!");

    cardFile.close();

    return;
}

/* set the 12 cards on the board. Set the first row of board with 4 cards in vendors, second with transport, and third with mines
 */
void Game::setboard() {
    for (int i = 0; i < Card_COLS; i++) {
        board[0][i] = vendors[i];
        board[1][i] = transport[i];
        board[2][i] = mines[i];
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            Card* card = board[i][j];
            cout << card->getColor() << card->getDiamond()[0] << card->getDiamond()[1] << card->getDiamond()[2] << card->getDiamond()[3] << card->getDiamond()[4] << '\n';
        }
    }
}

void Game::get_command(int playerNum) { // 1 or 2
    // receive info. from frontend
    // note: these int are indexes
    bool buy = command[0], buyReserve = command[1], take2Gems = command[2], take3Gems = command[3], reserve = command[4];   // command: { 0, 0, 1, 0, 0 }
    cout << command[0] << command[1] << command[2] << command[3] << command[4] << '\n';
    int cardRow = cardpos[0], cardCol = cardpos[1];
    cout << cardpos[0] << cardpos[1] << '\n';
    int colorIdx[3] = { -1, -1, -1 };
    if (take2Gems) {    // { 0, 0, 0, 2, 0, 0 }
        for (int i = 0; i < 6; i++) {
            if (dimondcolor[i] == 2) {
                colorIdx[0] = i; break;
            }
        }
    }
    if (take3Gems) {    // { 1, 0, 0, 1, 0, 1 }
        int didx = 0;
        for (int i = 0; i < 6; i++) {
            if (dimondcolor[i] == 1) {
                colorIdx[didx] = i; didx++;
            }
        }
    }
    
    // determine which actions to do
    if (buy) {
        cout << "buy card " << cardRow << " " << cardCol << "\n";
        players[playerNum - 1]->buyCard(boughtcard);
        cout << "updateboard\n";
        update_board(cardRow, cardCol);
        cout << "done buy\n";
    }
    if (buyReserve)
        players[playerNum - 1]->buyCard(this->reservedCard);
    if (take2Gems)
        players[playerNum - 1]->takeDiamond(colorIdx[0]);
    if (take3Gems)
        players[playerNum - 1]->takeDiamond(colorIdx[0], colorIdx[1], colorIdx[2]);
    if (reserve) {
        players[playerNum - 1]->reserveCard(this->reservedCard);
        update_board(cardRow, cardCol);
    }

    // clear the things used above
    for (int i = 0; i < 5; i++) {
        command[i] = 0;
    }
    for (int i = 0; i < 2; i++) {
        cardpos[i] = 0;
    }
    for (int i = 0; i < 6; i++) {
        dimondcolor[i] = 0;
    }
    taked_gems = 0;
    reservedCard = 0;

    return;
}



// update the board
void Game::update_board(int cardRow, int cardCol) {

    board[cardRow][cardCol] = nullptr;
    // check if there is enough card to update the board
    if (cardRow == 2 && showedMinesCnt <= 39) {
        board[cardRow][cardCol] = mines[showedMinesCnt];
        showedMinesCnt++;
    }
    if (cardRow == 1 && showedTransportCnt <= 29) {
        board[cardRow][cardCol] = transport[showedTransportCnt];
        showedTransportCnt++;
    }
    if (cardRow == 0 && showedVendorsCnt <= 19) {
        board[cardRow][cardCol] = vendors[showedVendorsCnt];
        showedVendorsCnt++;
    }

}

void Game::gem_cnt_over_10(int playerNum) {
    int total_gem = players[playerNum - 1]->getAllGemCnt();

    if (total_gem > 10) {
        if (total_gem == 11) {
            int colorIdx = 0;
            //==========================================


            // color = i;
            //==========================================
            players[playerNum - 1]->returnDiamond(colorIdx);
        }
        else if (total_gem == 12) {
            int colorIdx_1 = 0, colorIdx_2 = 0;
            //===========================================



            //===========================================
            players[playerNum - 1]->returnDiamond(colorIdx_1, colorIdx_2);
        }
        else if (total_gem == 13) {
            int colorIdx_1 = 0, colorIdx_2 = 0, colorIdx_3 = 0;
            //===========================================



            //===========================================
            players[playerNum - 1]->returnDiamond(colorIdx_1, colorIdx_2, colorIdx_3);
        }
    }

    return;
}

int Game::Player_Wins() {
    if (players[0]->getPoint() >= 15) {
        // player 2 can play one last round
        get_command(2);
        if (players[1]->getPoint() < 15) {    // player 1 win
            return 1;
        }
        else {
            isTied = true; // tie
            return 3;
        }
    }
    else if (players[1]->getPoint() >= 15) {    // player 2 win
        return 2;
    }
    return 0;
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

