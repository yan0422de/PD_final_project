// Diamonds.cpp

#include "Diamonds.h"

using namespace std;

// Init to 0
Diamond::Diamond()
{
    dimonds.resize(DIAMOND_TYPE_NUM, 0);
    for(int i = 0; i < DIAMOND_TYPE_NUM; i++)
        dimonds[i] = 0;
}

Diamond::Diamond(int num)
{
    for(int i = 0; i < DIAMOND_TYPE_NUM; i++)
        dimonds[i] = num;
}

bool Diamond::operator!=(const Diamond& d) const // to compare 2 cards
{
    if(this->dimonds[WHITE] == d.dimonds[WHITE])
        return false;
    else if(this->dimonds[BLACK] == d.dimonds[BLACK])
        return false;
    else if(this->dimonds[RED] == d.dimonds[RED])
        return false;
    else if(this->dimonds[GREEN] == d.dimonds[GREEN])
        return false;
    else if(this->dimonds[BLUE] == d.dimonds[BLUE])
        return false;
    else
        return true;
}

bool Diamond::operator>=(const Diamond& d) const
{
    if(this->dimonds[WHITE] < d.dimonds[WHITE])
        return false;
    else if(this->dimonds[BLACK] < d.dimonds[BLACK])
        return false;
    else if(this->dimonds[RED] < d.dimonds[RED])
        return false;
    else if(this->dimonds[GREEN] < d.dimonds[GREEN])
        return false;
    else if(this->dimonds[BLUE] < d.dimonds[BLUE])
        return false;
    else
        return true;
}

const Diamond& Diamond::operator-=(const Diamond& d) // when buy card, use to spend myDiamond
{
    for(int i = 0; i < 5; i++)
    {
        if(d.dimonds[i] > 0)
            this->dimonds[i] -= d.dimonds[i];
    }
    return *this;
}

const int Diamond::operator-(const Diamond& d) // when buy card, use to check GOLD could replace diamonds
{
    int ans = 0;
    for(int i = 0; i < DIAMOND_TYPE_NUM - 1; i++)
    {
        if((this->dimonds[i] - d[i]) < 0) // insufficient
            ans += d[i] - dimonds[i];
    }
    return ans;
}

int Diamond::operator[] (int i) const // read more easily (eg: myDiamond[RED] == myDiamond.diamonds[RED])
{
    if(i < 0 || i > DIAMOND_TYPE_NUM)
        exit(1); // exception
    return dimonds[i];
}

int& Diamond::operator[] (int i) // can be assigned or modified
{
    if(i < 0 || i > DIAMOND_TYPE_NUM)
        exit(1); // expect
    return dimonds[i];
}

int Diamond::getAllCnt()
{
    int cnt = 0;
    for(int i = 0; i < DIAMOND_TYPE_NUM; i++)
        cnt += dimonds[i];
    return cnt;
}

// only fieldDiamond can invoke
void Diamond::returnDiamond(int color, Diamond playerD) // return 1
{
    this->dimonds[color]++;
    playerD[color]--;
} 
void Diamond::returnDiamond(int color1, int color2, Diamond playerD) // return 2
{
    this->dimonds[color1]++;
    this->dimonds[color2]++;
    playerD[color1]--;
    playerD[color2]--;
}
void Diamond::returnDiamond(int color1, int color2, int color3, Diamond playerD) // return 3
{
    this->dimonds[color1]++;
    this->dimonds[color2]++;
    this->dimonds[color3]++;
    playerD[color1]--;
    playerD[color2]--;
    playerD[color3]--;
}
