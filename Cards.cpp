// Cards.cpp

#include "Cards.h"
#include <vector>
#include <fstream>
#include <iostream>


Card::Card(int level, int colorIdx, int score, int white, int black, int red, int green, int blue)
 : level(level), color(colorIdx), score(score){
    // Use operator overloading, equals to spendDimd.diamonds[something]
    spendDimd[WHITE] = white;    
    spendDimd[BLACK] = black;
    spendDimd[RED] = red;
    spendDimd[GREEN] = green;
    spendDimd[BLUE] = blue;
}

Card::Card(const Card& card){
    this->level = card.level;
    this->color = card.color;
    this->score = card.score;
    this->spendDimd = card.spendDimd;
}

bool Card::operator==(const Card& card) const{ // Used to compare 2 cards when buyReservedCard
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

int Card::getScore(){
    return this->score;
}

int Card::getColor(){
    return this->color;
}

Diamond Card::getDiamond() const{
    return this->spendDimd;
}

int Card::getEachDiamond(int idx) const{
    return this->spendDimd[idx];
}
