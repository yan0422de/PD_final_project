// Players.cpp

#include "Players.h"
#include <string>
#include <vector>

using namespace std;

Player::Player() : point(0), myDiamonds(0)
{
    for(int i = 0; i < MAX_BONUS_NUM; i++)
        this->bonus[i] = 0;
}

void Player::buyCard(Card* card)
{
    if(this->myDiamonds >= card->getDiamond()){
        // spend diamonds
        this->myDiamonds -= card->getDiamond();
    }
    else if(this->myDiamonds[GOLD] >= card->getDiamond() - this->myDiamonds)
        spendByGOLD(*card); // only when diamonds are insufficient
    else
        throw logic_error("You CAN'T Buy This Card!");
    
    // update personal status
    this->myCards.push_back(card);
    this->point += card->getScore();
    this->bonus[card->getColor()]++;
}

void Player::reserveCard(Card* card)
{
    if(this->myReservedCards.size() == 3)
        throw logic_error("Too much reserved cards");
    if(diamond_bank[GOLD] > 0){
        this->myDiamonds[GOLD]++;
        diamond_bank[GOLD]--;
    }
    this->myReservedCards.push_back(card);
}

void Player::buyReservedCard(Card* card)
{
    for(int i = 0; i < this->myReservedCards.size(); i++)
    {
        if(this->myReservedCards[i] == card)
        {
            this->myReservedCards.erase(this->myReservedCards.begin() + i);
            buyCard(card);
        }
    }
}

void Player::spendByGOLD(const Card& card)
{
    for (int color = 0; color < 5; color++) 
    {
        int diffDiamonds = card.getDiamond()[color] - this->myDiamonds[color];
        if(diffDiamonds > 0 && this->myDiamonds[GOLD] >= diffDiamonds) // spend by GOLD
        {
            this->myDiamonds[color] = 0;
            this->myDiamonds[GOLD] -= diffDiamonds;
        }
        else // spend by diamonds
            this->myDiamonds[color] -= card.getDiamond()[color];
    }
}

void Player::takeDiamond(int color1, int color2, int color3)
{
    if(getAllGemCnt() > 7)
    {
        int diff = 10 - getAllGemCnt();
        throw logic_error("Please Return " + to_string(diff));
    } // game will catch the exception and invoke Diamond::returnDiamond()
    this->myDiamonds[color1]++;
    this->myDiamonds[color2]++;
    this->myDiamonds[color3]++;
}
void Player::takeDiamond(int color)
{
    if(getAllGemCnt() > 8)
    {
        int diff = 10 - getAllGemCnt();
        throw logic_error("Please Return " + to_string(diff));
    } // game will catch the exception and invoke Diamond::returnDiamond()
    this->myDiamonds[color] += 2;
}

int Player::getAllGemCnt()
{
    int cnt = 0;
    for(int i = 0; i < DIAMOND_TYPE_NUM; i++){
        cnt += this->myDiamonds[i];
    }
    return cnt;

}

// only fieldDiamond can invoke
void Player::returnDiamond(int color) // return 1
{
    this->myDiamonds[color]--;
    diamond_bank[color]++;
}
void Player::returnDiamond(int color1, int color2) // return 2
{
    this->myDiamonds[color1]--;
    this->myDiamonds[color2]--;
    diamond_bank[color1]++;
    diamond_bank[color2]++;
}
void Player::returnDiamond(int color1, int color2, int color3) // return 3
{
    this->myDiamonds[color1]--;
    this->myDiamonds[color2]--;
    this->myDiamonds[color3]--;
    diamond_bank[color1]++;
    diamond_bank[color2]++;
    diamond_bank[color3]++;
}
int Player::getPoint(){
    return this->point;
}
