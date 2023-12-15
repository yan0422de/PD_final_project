// Players.h

#ifndef Players_h
#define Players_h

#include "Diamonds.h"
#include "Cards.h"

const int MAX_BONUS_NUM = 5;

class Player
{
private:
    int point;
    Diamond myDiamonds;
    vector<Card*> myCards;
    vector<Card*> myReservedCards;
    int bonus[MAX_BONUS_NUM];   // discount
    
public:
    Player();
    // Getter
    int getAllGemCnt();
    int getPoint();
    
    void buyCard(Card* card);
    void reserveCard(Card* card);
    void buyReservedCard(Card* card);
    void spendByGOLD(const Card& card);
    void takeDiamond(int color);
    void takeDiamond(int color1, int color2, int color3);
    void returnDiamond(int color); // only fieldDiamond can invoke
    void returnDiamond(int color1, int color2);
    void returnDiamond(int color1, int color2, int color3);
};

#endif
