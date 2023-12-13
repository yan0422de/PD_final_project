// Cards.cpp
//test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!====================================
#include "Cards.h"
#include <vector>
#include <fstream>
#include <map>

using namespace std;

Card::Card(int level, int color, int score, int white, int black, int red, int green, int blue)
 : level(level), color(color), score(score)
{
    // Use operator overloading, equals to spendDimd.diamonds[something]
    spendDimd[WHITE] = white;
    spendDimd[BLACK] = black;
    spendDimd[RED] = red;
    spendDimd[GREEN] = green;
    spendDimd[BLUE] = blue;
}

Card::Card(const Card& card)
{
    this->level = card.level;
    this->color = card.color;
    this->score = card.score;
    this->spendDimd = card.spendDimd;
}

bool Card::operator==(const Card& card) const // Used to compare 2 cards when buyHoldCard
{
    if(this->level != card.level)
        return false;
    else if(this->color != card.color)
        return false;
    else if(this->score != card.score)
        return false;
    else if(this->spendDimd != card.spendDimd)
        return false;
    else
        return true;
}

int Card::getScore()
{
    return this->score;
}

int Card::getColor()
{
    return this->color;
}

Diamond Card::getDiamond() const
{
    return this->spendDimd;
}

// Map color string to int
map<string, int> colorMap = {
    {"WHITE", 0},
    {"BLACK", 1},
    {"RED", 2},
    {"GREEN", 3},
    {"BLUE", 4}
};

// create all cards
vector<Card> Card::createCardDeck()
{
    ifstream cardFile("card_data.txt");
    if(cardFile)
    {
        for(int i = 0; i < MAX_CARD_NUM; i++)
        {
            int level = 0, score = 0, color = 0, white = 0, black = 0, red = 0, green = 0, blue = 0;
            string colorName;
            // Read
            cardFile >> level >> score >> colorName >> white >> red >> black >> blue >> green;
            
            color = colorMap[colorName];
            cardDeck.push_back(Card(level, color, score, white, black, red, green, blue));
        }
    }
    else
        throw logic_error("Load Failed!");
    
    cardFile.close();
    
    return cardDeck;
}


// vector<Cards> createCardDeck()
// {
//     vector<Cards> cardDeck;
//     // level 3
//     cardDeck.push_back(Cards(3, BLUE, 5, 7, 0, 0, 0, 3)); // 5-2
//     cardDeck.push_back(Cards(3, WHITE, 5, 3, 7, 0, 0, 0));
//     cardDeck.push_back(Cards(3, BLACK, 5, 0, 3, 7, 0, 0));
//     cardDeck.push_back(Cards(3, RED, 5, 0, 0, 3, 7, 0));
//     cardDeck.push_back(Cards(3, GREEN, 5, 3, 7, 0, 3, 7));

//     cardDeck.push_back(Cards(3, WHITE, 4, 0, 7, 0, 0, 0)); // 4-1
//     cardDeck.push_back(Cards(3, BLACK, 4, 0, 0, 7, 0, 0));
//     cardDeck.push_back(Cards(3, RED, 4, 0, 0, 0, 7, 0));
//     cardDeck.push_back(Cards(3, GREEN, 4, 0, 0, 0, 0, 7));
//     cardDeck.push_back(Cards(3, BLUE, 4, 7, 0, 0, 0, 0));

//     cardDeck.push_back(Cards(3, WHITE, 4, 3, 6, 3, 0, 0)); // 4-3
//     cardDeck.push_back(Cards(3, BLACK, 4, 0, 3, 6, 3, 0));
//     cardDeck.push_back(Cards(3, RED, 4, 0, 0, 3, 6, 3));
//     cardDeck.push_back(Cards(3, GREEN, 4, 3, 0, 0, 3, 6));
//     cardDeck.push_back(Cards(3, BLUE, 4, 6, 3, 0, 0, 3));

//     cardDeck.push_back(Cards(3, WHITE, 3, 0, 3, 5, 3, 3)); // 3-4
//     cardDeck.push_back(Cards(3, BLACK, 3, 3, 0, 3, 5, 3));
//     cardDeck.push_back(Cards(3, RED, 3, 3, 3, 0, 3, 5));
//     cardDeck.push_back(Cards(3, GREEN, 3, 5, 3, 3, 0, 3));
//     cardDeck.push_back(Cards(3, BLUE, 3, 3, 5, 3, 3, 0));

//     // level 2
//     cardDeck.push_back(Cards(2, WHITE, 3, 6, 0, 0, 0, 0)); // 3-1
//     cardDeck.push_back(Cards(2, BLACK, 3, 0, 6, 0, 0, 0));
//     cardDeck.push_back(Cards(2, RED, 3, 0, 0, 6, 0, 0));
//     cardDeck.push_back(Cards(2, GREEN, 3, 0, 0, 0, 6, 0));
//     cardDeck.push_back(Cards(2, BLUE, 3, 0, 0, 0, 0, 6));

//     cardDeck.push_back(Cards(2, WHITE, 2, 0, 3, 5, 0, 0)); // 2-2
//     cardDeck.push_back(Cards(2, BLACK, 2, 0, 0, 3, 5, 0));
//     cardDeck.push_back(Cards(2, RED, 2, 3, 5, 0, 0, 0));
//     cardDeck.push_back(Cards(2, GREEN, 2, 0, 0, 0, 3, 5));
//     cardDeck.push_back(Cards(2, BLUE, 2, 5, 0, 0, 0, 3));

//     cardDeck.push_back(Cards(2, WHITE, 2, 0, 0, 5, 0, 0)); // 2-1
//     cardDeck.push_back(Cards(2, BLACK, 2, 5, 0, 0, 0, 0));
//     cardDeck.push_back(Cards(2, RED, 2, 0, 5, 0, 0, 0));
//     cardDeck.push_back(Cards(2, GREEN, 2, 0, 0, 0, 5, 0));
//     cardDeck.push_back(Cards(2, BLUE, 2, 0, 0, 0, 0, 5));

//     cardDeck.push_back(Cards(2, WHITE, 2, 0, 2, 4, 1, 0)); // 2-3
//     cardDeck.push_back(Cards(2, BLACK, 2, 0, 0, 2, 4, 1));
//     cardDeck.push_back(Cards(2, RED, 2, 1, 0, 0, 2, 4));
//     cardDeck.push_back(Cards(2, GREEN, 2, 4, 1, 0, 0, 2));
//     cardDeck.push_back(Cards(2, BLUE, 2, 2, 4, 1, 0, 0));

//     cardDeck.push_back(Cards(2, WHITE, 1, 2, 0, 3, 0, 3)); // 1-3(2-3-3)
//     cardDeck.push_back(Cards(2, BLACK, 1, 3, 2, 0, 3, 0));
//     cardDeck.push_back(Cards(2, RED, 1, 0, 3, 2, 0, 3));
//     cardDeck.push_back(Cards(2, GREEN, 1, 3, 0, 3, 2, 0));
//     cardDeck.push_back(Cards(2, BLUE, 1, 0, 3, 0, 3, 2));

//     cardDeck.push_back(Cards(2, WHITE, 1, 0, 2, 2, 3, 0)); // 1-3(2-2-3)
//     cardDeck.push_back(Cards(2, BLACK, 1, 3, 0, 0, 2, 2));
//     cardDeck.push_back(Cards(2, RED, 1, 2, 3, 2, 0, 0));
//     cardDeck.push_back(Cards(2, GREEN, 1, 2, 2, 0, 0, 3));
//     cardDeck.push_back(Cards(2, BLUE, 1, 0, 0, 3, 2, 2));

//     // level 1
//     cardDeck.push_back(Cards(2, WHITE, 1, 0, 0, 0, 4, 0)); // 1-1
//     cardDeck.push_back(Cards(2, BLACK, 1, 0, 0, 0, 0, 4));
//     cardDeck.push_back(Cards(2, RED, 1, 4, 0, 0, 0, 0));
//     cardDeck.push_back(Cards(2, GREEN, 1, 0, 4, 0, 0, 0));
//     cardDeck.push_back(Cards(2, BLUE, 1, 0, 0, 4, 0, 0));

//     cardDeck.push_back(Cards(2, WHITE, 0, 3, 1, 0, 0, 1)); // 0-3(1-1-3)
//     cardDeck.push_back(Cards(2, BLACK, 0, 0, 1, 3, 1, 0));
//     cardDeck.push_back(Cards(2, RED, 0, 1, 3, 1, 0, 0));
//     cardDeck.push_back(Cards(2, GREEN, 0, 1, 0, 0, 1, 3));
//     cardDeck.push_back(Cards(2, BLUE, 0, 0, 0, 1, 3, 1));

//     cardDeck.push_back(Cards(2, WHITE, 0, 0, 1, 0, 2, 2)); // 0-3(1-2-2)
//     cardDeck.push_back(Cards(2, BLACK, 0, 2, 0, 1, 0, 2));
//     cardDeck.push_back(Cards(2, RED, 0, 2, 2, 0, 1, 0));
//     cardDeck.push_back(Cards(2, GREEN, 0, 0, 2, 2, 0, 1));
//     cardDeck.push_back(Cards(2, BLUE, 0, 1, 0, 2, 2, 0));

//     cardDeck.push_back(Cards(2, WHITE, 0, 0, 1, 1, 2, 1)); // 0-4(1-1-1-2)
//     cardDeck.push_back(Cards(2, BLACK, 0, 1, 0, 1, 1, 2));
//     cardDeck.push_back(Cards(2, RED, 0, 2, 1, 0, 1, 1));
//     cardDeck.push_back(Cards(2, GREEN, 0, 1, 2, 1, 0, 1));
//     cardDeck.push_back(Cards(2, BLUE, 0, 1, 1, 2, 1, 0));

//     cardDeck.push_back(Cards(2, WHITE, 0, 0, 2, 0, 0, 2)); // 0-2(2-2)
//     cardDeck.push_back(Cards(2, BLACK, 0, 2, 0, 0, 2, 0));
//     cardDeck.push_back(Cards(2, RED, 0, 2, 0, 2, 0, 0));
//     cardDeck.push_back(Cards(2, GREEN, 0, 0, 0, 2, 2, 0));
//     cardDeck.push_back(Cards(2, BLUE, 0, 0, 2, 0, 2, 0));

//     cardDeck.push_back(Cards(2, WHITE, 0, 0, 1, 1, 1, 1)); // 0-4(1-1-1-1)
//     cardDeck.push_back(Cards(2, BLACK, 0, 1, 0, 1, 1, 1));
//     cardDeck.push_back(Cards(2, RED, 0, 1, 1, 0, 1, 1));
//     cardDeck.push_back(Cards(2, GREEN, 0, 1, 1, 1, 0, 1));
//     cardDeck.push_back(Cards(2, BLUE, 0, 1, 1, 1, 1, 0));

//     cardDeck.push_back(Cards(2, WHITE, 0, 0, 0, 0, 0, 3)); // 0-1
//     cardDeck.push_back(Cards(2, BLACK, 0, 0, 0, 0, 3, 0));
//     cardDeck.push_back(Cards(2, RED, 0, 3, 0, 0, 0, 0));
//     cardDeck.push_back(Cards(2, GREEN, 0, 0, 0, 3, 0, 0));
//     cardDeck.push_back(Cards(2, BLUE, 0, 0, 3, 0, 0, 0));

//     cardDeck.push_back(Cards(2, WHITE, 0, 0, 1, 2, 0, 0)); // 0-2(1-2)
//     cardDeck.push_back(Cards(2, BLACK, 0, 0, 0, 1, 2, 0));
//     cardDeck.push_back(Cards(2, RED, 0, 0, 0, 0, 1, 2));
//     cardDeck.push_back(Cards(2, GREEN, 0, 2, 0, 0, 0, 1));
//     cardDeck.push_back(Cards(2, BLUE, 0, 1, 2, 0, 0, 0));

//     return cardDeck;
// }
