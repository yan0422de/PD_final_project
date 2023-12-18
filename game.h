// game.h

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "Cards.h"
#include "Players.h"
#include <vector>

using namespace std;


class Game {
public:

    static const int Card_ROWS = 3;
    static const int Card_COLS = 4;
    static const int GEMS = 6;
    static const int Players_CNT = 2;

    int taked_gems = 0;
    // command
    int command[5] = { 0, 0, 0, 0, 0 };     // buy, buy_reserve, tak2gems, tak3gems, reserve
    // card pos
    Card* boughtcard;
    int cardpos[2] = { 0, 0 };              // cardRow, cardCol
    // reserved card
    Card* reservedCard;                     // reservedCard
    // color
    int dimondcolor[6] = { 0, 0, 0, 0, 0, 0 };      // white, black, red, green, blue, gold

    // create the car deck
    void createCardDeck();

    // set the game board
    void setboard();

    // constructor vars
    int showedMinesCnt = 4;
    int showedTransportCnt = 4;
    int showedVendorsCnt = 4;
    // represent player 1 or 2
    int playerNum = 1;

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

    int Player_Wins();

    // Specific action functions

    int ColorToIndex(string color_str);

    // clearing memory
    void clear_memory();

    // constructor
    Game();
    // destructor
    ~Game();

    //main gameplay
    void playGame();

};

#endif
