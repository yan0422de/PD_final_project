// Cards.h

#ifndef Cards_h
#define Cards_h

#include "Diamonds.h"

const int MAX_CARD_NUM = 90;

class Card
{
private:
    int level;    // level 1 ~ 3 (bad -> good)
    int color;    // discounted color
    int score;    // added point to player
    Diamond spendDimd;
    vector<Card> cardDeck;
    
public:
    // Constructor
    Card(int level, int color, int score, int white, int black, int red, int green, int blue);
    // Copy Constructor
    Card(const Card& card);
    // Operator Overloading
    bool operator==(const Card& card) const;
    // Getter
    int getScore();
    int getColor();
    Diamond getDiamond() const;
    // Initalize all cards
    vector<Card> createCardDeck();
};

#endif
