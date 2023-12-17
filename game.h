// game.h

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <string>
#include "Cards.h"
#include "Players.h"
#include <vector>

using namespace std;


class Game {
private:

    static const int Card_ROWS = 3;
    static const int Card_COLS = 4;
    static const int GEMS = 6;
    static const int Players_CNT = 2;

    // create the car deck
    void createCardDeck();

    // set the game board
    void setboard();

    // constructor vars
    int showedMinesCnt = 4;
    int showedTransportCnt = 4;
    int showedVendorsCnt = 4;
    // represent player 1 or 2
    int playerNum = 0;

    // store each level of cards
    vector<Card*> mines;
    vector<Card*> transport;
    vector<Card*> vendors;

    //main game loop vars
    bool game_over = false;
    bool player1_turn = true;
    bool isTied = false;
    
    Player* players[Players_CNT];
   
    Card* board[Card_ROWS][Card_COLS];

    //Main game loop functions

    void gem_cnt_over_10(int playerNum);

    void get_command(int playerNum);

    // 更新被買走的牌（紀錄該等級的牌已經拿幾張出來），有個函數要檢查排堆（40, 30, 20）還有沒有牌
    void update_board(int cardRow, int cardCol);

    bool Player_Wins();

    // Specific action functions

    int ColorToIndex(string color_str);

    // clearing memory
    void clear_memory();
    
public:
    // constructor
    Game();
    // destructor
    ~Game();
    
    //main gameplay
    void playGame();
    
};

#endif
