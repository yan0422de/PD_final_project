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
    int discount[MAX_BONUS_NUM];   // discount
    
public:
    Player();
    // Getter
    int getAllGemCnt();
    int getPoint();
    // player actions
    void buyCard(Card* card);
    void reserveCard(Card* card);
    void buyReservedCard(Card* card);
    void spendByGOLD(const Card& card);

    void takeDiamond(int colorIdx);
    void takeDiamond(int colorIdx_1, int colorIdx_2, int colorIdx_3);

    void returnDiamond(int colorIdx);
    void returnDiamond(int colorIdx_1, int colorIdx_2);
    void returnDiamond(int colorIdx_1, int colorIdx_2, int colorIdx_3);
};

#endif
