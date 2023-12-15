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
    // init diamonds numuber
    // int diamond_bank[6] = {4, 4, 4, 4, 4, 5};
    
    static const int Players_CNT = 2;
    static const int Card_ROWS = 3;
    static const int Card_COLS = 4;
    static const int GEMS = 6;

    // create the car deck
    void createCardDeck();

    // set the game table
    void setTable();

    // constructor vars
    int showedMinesCnt = 4;
    int showedTransportCnt = 4;
    int showedVendorsCnt = 4;
    // represent player 1 or 2
    int num = 0;

    // store each level of cards
    vector<Card*> mines;
    vector<Card*> vendors;
    vector<Card*> transport;

    //main game loop vars
    bool game_over = false;
    bool player1_turn = true;
    bool isTied = false;
    
    Player* players[Players_CNT];
   
    Card* table[Card_ROWS][Card_COLS];

    //Main game loop functions

    // 有個函數要更新被買走的牌（紀錄該等級的牌已經拿幾張出來），有個函數要檢查排堆（40, 30, 20）還有沒有牌

    void update_player(int num, int remove_gems[5], int gold);

    void update_grid(int num, int remove_gems[5], int gold);

    void gem_cnt_over_10(int num);

    void get_command(int num);

    bool Player_Wins();


    // Specific action functions

    int ColorToIndex(string color);

    // clearing memory
    void clear_memory();
    
public:
    //constructor
    Game();

    //main gameplay
    void playGame();

    
};

#endif

