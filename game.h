#ifndef SPLENDORGAME_H
#define SPENDORGAME_H

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
    static const int Card_ROWS = 3;
    static const int Card_COLS = 4;
    static const int GEMS = 6;

    //Constructor functions
    void initialize_decks(vector<Card*> *point_to_deck, int num_Cards);

    void populate_vectors(vector<Card*> *point_to_deck, int num_Cards, string filename, int skip);

    void populate_grid();

    //constructor vars
    int mines_count = 3;
    int transport_count = 3;
    int vendors_count = 3;
    int gem_bank[6] = {4, 4, 4, 4, 4, 5};


    vector<Card *> mines;
    vector<Card *> vendors;
    vector<Card *> transport;
    
    Player player1;
    Player player2;
    Card*grid[3][4];

    //Main game loop functions
    void p2(int num);

    void Return_gems(int num);

    void br(int num);

    void buy(int num);

    void p3(int *num);

    void r(int num);

    string valid_move(int num);

    void mod_deck(int num);

    void update_player(int num, int remove_gems[5], int gold);

    void update_grid(int num, int remove_gems[5], int gold);

    void reserve_error(int num);

    void over_10();

    void get_command();

    void Player_Wins();

    //main game loop vars
    bool game_over = false;
    bool player1_turn = true;
    int num;
    int total_gems = 0;
    string first = "";
    string second = "";
    string third = "";
    string fourth = "";
    string result;
    int intsecond = 0;
    int intthird = 0;

    // Specific action functions
    string indexToColor(int number);

    int ColorToIndex(string color);

    int get_row();

    void remove_gems(int gems[6]);

    Player *get_player(int num);

    void clean_board();

    void deck_check();

    //clearing memory
    void clear_memory();
};

#endif
