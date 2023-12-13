// Players.cpp

#include "Players.h"
#include <string>
#include <vector>

using namespace std;

Player::Player() : point(0), myDimonds(0)
{
    for(int i = 0; i < MAX_BONUS_NUM; i++)
        bonus[i] = 0;
}

Player::~Player()
{
}

void Player::buyCard(Card card)
{
    myCards.push_back(Card(card));
    point += card.getScore();
    bonus[card.getColor()]++;

    // spend
    if(myDimonds >= card.getDiamond())
        myDimonds -= card.getDiamond();
    else if(myDimonds[GOLD] >= card.getDiamond() - myDimonds)
        spendByGOLD(card); // only when diamonds are insufficient
    else
        throw logic_error("You CAN'T Buy This Card!");
}

void Player::reservedCard(Card card)
{
    if(myReservedCards.size() == 3)
        throw logic_error("Too much reserved cards");
    myDimonds[GOLD]++;
    myReservedCards.push_back(Card(card));
}

void Player::buyReservedCard(Card card)
{
    for(int i = 0; i < myReservedCards.size(); i++)
    {
        if(myReservedCards[i] == card)
        {
            myReservedCards.erase(myReservedCards.begin() + i);
            this->buyCard(card);
        }
    }
}

void Player::spendByGOLD(const Card& card)
{
    for (int color = 0; color < 5; color++) 
    {
        int diffDiamonds = card.getDiamond()[color] - myDimonds[color];
        if(diffDiamonds > 0 && myDimonds[GOLD] >= diffDiamonds) // spend by GOLD
        {
            myDimonds[color] = 0;
            myDimonds[GOLD] -= diffDiamonds;
        }
        else // spend by diamonds
            myDimonds[color] -= card.getDiamond()[color];
    }
}

void Player::takeDiamond(int color1, int color2, int color3)
{
    if(myDimonds.getAllCnt() > 7)
    {
        int diff = 10 - myDimonds.getAllCnt();
        throw logic_error("Please Return " + to_string(diff));
    } // game will catch the exception and invoke Diamond::returnDiamond()
    myDimonds[color1]++;
    myDimonds[color2]++;
    myDimonds[color3]++;
}
void Player::takeDiamond(int color)
{
    if(myDimonds.getAllCnt() > 8)
    {
        int diff = 10 - myDimonds.getAllCnt();
        throw logic_error("Please Return " + to_string(diff));
    } // game will catch the exception and invoke Diamond::returnDiamond()
    myDimonds[color] += 2;
}
