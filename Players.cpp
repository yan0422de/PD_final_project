// Players.cpp

#include "Players.h"
#include <string>
#include <vector>

using namespace std;

Player::Player() : point(0), myDiamonds(0){
    for(int i = 0; i < MAX_BONUS_NUM; i++)
        this->discount[i] = 0;
}

void Player::buyCard(Card* card){
    bool canBuy = true, useGold = false;
    int my_gold_cnt = myDiamonds[GOLD];    // I don't want directly modify 'myDiamonds[GOLD]'
    
    for(int i = 0; i < DIAMOND_EXP_GOLD; i++){
        if(this->myDiamonds[i] + this->discount[i] < card->getDiamond()[i]){    // insufficinet
            int gap = card->getDiamond()[i] - this->myDiamonds[i] - this->discount[i];
            
            if(my_gold_cnt < gap){
                canBuy = false;
                break;
            }
            else{
                useGold = true;
                my_gold_cnt -= gap;
                continue;
            }
        }
    }
    if(canBuy && !useGold){
        for(int i = 0; i < DIAMOND_EXP_GOLD; i++){
            // spend diamonds
            card->getDiamond()[i] -= this->discount[i];    // substract my discount first
            this->myDiamonds -= card->getDiamond();    // then use my gems
            // update diamond_bank
            diamond_bank[i] += (card->getDiamond()[i] - this->discount[i]);
        }
    }
    else if(canBuy && useGold)
        spendByGOLD(*card);
    else
        throw logic_error("You CAN'T Buy This Card!");
    
    // update personal status
    this->myCards.push_back(card);
    this->point += card->getScore();
    this->discount[card->getColor()]++;
}

void Player::spendByGOLD(const Card& card){
    for (int colorIdx = 0; colorIdx < DIAMOND_EXP_GOLD; colorIdx++)
    {
        int gap = card.getDiamond()[colorIdx] - this->myDiamonds[colorIdx] - this->discount[colorIdx];
        
        // find which color of gem is sufficient
        if(gap > 0 && this->myDiamonds[GOLD] >= gap){  // spend by GOLD
            // update diamond_bank
            diamond_bank[colorIdx] += this->myDiamonds[colorIdx];
            this->myDiamonds[colorIdx] = 0;
            
            diamond_bank[GOLD] += gap;
            this->myDiamonds[GOLD] -= gap;
        }
        // spend normally
        else {
            // spend by diamonds
            card.getDiamond()[colorIdx] -= this->discount[colorIdx];
            this->myDiamonds -= card.getDiamond();
            // update diamond_bank
            diamond_bank[colorIdx] += (card.getDiamond()[colorIdx] - this->discount[colorIdx]);
        }
    }

}

void Player::reserveCard(Card* card){
    if(this->myReservedCards.size() == 3)
        throw logic_error("Too much reserved cards");
    if(diamond_bank[GOLD] > 0){    // gift
        this->myDiamonds[GOLD]++;
        diamond_bank[GOLD]--;
    }
    this->myReservedCards.push_back(card);
}

void Player::buyReservedCard(Card* card){
    for(int i = 0; i < this->myReservedCards.size(); i++)
    {
        if(this->myReservedCards[i] == card)
        {
            this->myReservedCards.erase(this->myReservedCards.begin() + i);
            buyCard(card);
        }
        else
            throw logic_error("You DON'T have this card");
    }
}

void Player::takeDiamond(int colorIdx_1, int colorIdx_2, int colorIdx_3){
    if(diamond_bank[colorIdx_1] > 0 && diamond_bank[colorIdx_2] > 0 && diamond_bank[colorIdx_3] > 0){
        this->myDiamonds[colorIdx_1]++;
        diamond_bank[colorIdx_1]--;
        this->myDiamonds[colorIdx_2]++;
        diamond_bank[colorIdx_2]--;
        this->myDiamonds[colorIdx_3]++;
        diamond_bank[colorIdx_3]--;
    }
    else
        throw logic_error("Gem bank don't have enough gem");
}

void Player::takeDiamond(int colorIdx){
    if(diamond_bank[colorIdx] > 2){
        this->myDiamonds[colorIdx] += 2;
        diamond_bank[colorIdx] -= 2;
    }
    else
        throw logic_error("Gem bank don't have enough gem");
}

// only fieldDiamond can invoke
void Player::returnDiamond(int colorIdx){ // return 1
    if(myDiamonds[colorIdx] > 0){
        this->myDiamonds[colorIdx]--;
        diamond_bank[colorIdx]++;
    }
    else
        throw logic_error("You don't have enough gem to return");
}
void Player::returnDiamond(int colorIdx_1, int colorIdx_2){ // return 2
    if(myDiamonds[colorIdx_1] > 0 && myDiamonds[colorIdx_2] > 0){
        this->myDiamonds[colorIdx_1]--;
        this->myDiamonds[colorIdx_2]--;
        diamond_bank[colorIdx_1]++;
        diamond_bank[colorIdx_2]++;
    }
    else
        throw logic_error("You don't have enough gem to return");
}

void Player::returnDiamond(int colorIdx_1, int colorIdx_2, int colorIdx_3){ // return 3
    if(myDiamonds[colorIdx_1] > 0 && myDiamonds[colorIdx_2] > 0 && myDiamonds[colorIdx_3] > 0){
        this->myDiamonds[colorIdx_1]--;
        this->myDiamonds[colorIdx_2]--;
        this->myDiamonds[colorIdx_3]--;
        diamond_bank[colorIdx_1]++;
        diamond_bank[colorIdx_2]++;
        diamond_bank[colorIdx_3]++;
    }
    else
        throw logic_error("You don't have enough gem to return");
}

int Player::getAllGemCnt(){
    int cnt = 0;
    for(int i = 0; i < DIAMOND_TYPE_NUM; i++){
        cnt += this->myDiamonds[i];    
    }
    return cnt;
}

int Player::getPoint(){
    return this->point;
}
