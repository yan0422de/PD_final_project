#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>

#include <string>
#include "Cards.h"
#include "Players.h"
#include <vector>
#include <map>

using namespace std;

class Game {
public:
    //constructor
    Game(string filename);

    //main gameplay
    void playGame();

private:
    static const int Player_CNT = 2;
    static const int Card_ROWS = 3;
    static const int Card_COLS = 4;
    static const int GEMS = 6;

    //Constructor functions
   

    

    void populate_grid();

    //constructor vars
    int minesCnt = 3;
    int transportCnt = 3;
    int vendorsCnt = 3;

    vector<Card *> mines;
    vector<Card *> vendors;
    vector<Card *> transport;
    
    Player* players[Player_CNT];
   
    Card* grid[Card_ROWS][Card_COLS];

    //Main game loop functions
    
    string valid_move(int num);

    // 有個函數要更新被買走的牌（紀錄該等級的牌已經拿幾張出來），有個函數要檢查排堆（40, 30, 20）還有沒有牌

    void update_player(int num, int remove_gems[5], int gold);

    void update_grid(int num, int remove_gems[5], int gold);

    void over_10();

    void get_command();

    void Player_Wins();

    //main game loop vars
    bool game_over = false;
    bool player1_turn = true;

    // Specific action functions

    int ColorToIndex(string color);

    //clearing memory
    void clear_memory();
};

#endif
