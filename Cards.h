// Cards.h

#ifndef Cards_h
#define Cards_h

#include "Diamonds.h"

const int MAX_CARD_NUM = 90;

class Card
{
private:
    int level;    // level 1 ~ 3 (bad -> good)
    int color;    // discounted color (0 ~ 6 stand for white, black, red, green, blue, gold)
    int score;    // added point to player
    Diamond spendDimd;
    
public:
    Card(){};
    // Constructor
    Card(int level, int colorIdx, int score, int white, int black, int red, int green, int blue);
    // Copy Constructor
    Card(const Card& card);
    // Operator Overloading
    bool operator==(const Card& card) const;
    // Getter
    int getScore();
    int getColor();
    Diamond getDiamond() const;
    // Initalize all cards
    int getEachDiamond(int idx) const;
};

#endif
