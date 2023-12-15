// Diamonds.cpp

#include "Diamonds.h"

using namespace std;

int diamond_bank[6] = {4, 4, 4, 4, 4, 5};

// Init to 0
Diamond::Diamond()
{
    diamonds.resize(DIAMOND_TYPE_NUM, 0);
    for(int i = 0; i < DIAMOND_TYPE_NUM; i++)
        diamonds[i] = 0;
}

Diamond::Diamond(int num)
{
    for(int i = 0; i < DIAMOND_TYPE_NUM; i++)
        diamonds[i] = num;
}

bool Diamond::operator!=(const Diamond& d) const // to compare 2 cards
{
    if(this->diamonds[WHITE] == d.diamonds[WHITE])
        return false;
    else if(this->diamonds[BLACK] == d.diamonds[BLACK])
        return false;
    else if(this->diamonds[RED] == d.diamonds[RED])
        return false;
    else if(this->diamonds[GREEN] == d.diamonds[GREEN])
        return false;
    else if(this->diamonds[BLUE] == d.diamonds[BLUE])
        return false;
    else
        return true;
}

bool Diamond::operator>=(const Diamond& d) const
{
    if(this->diamonds[WHITE] < d.diamonds[WHITE])
        return false;
    else if(this->diamonds[BLACK] < d.diamonds[BLACK])
        return false;
    else if(this->diamonds[RED] < d.diamonds[RED])
        return false;
    else if(this->diamonds[GREEN] < d.diamonds[GREEN])
        return false;
    else if(this->diamonds[BLUE] < d.diamonds[BLUE])
        return false;
    else
        return true;
}

const Diamond& Diamond::operator-=(const Diamond& d) // when buy card, use to spend myDiamond
{
    for(int i = 0; i < 5; i++)
    {
        if(d.diamonds[i] > 0)
            this->diamonds[i] -= d.diamonds[i];
    }
    return *this;
}

const int Diamond::operator-(const Diamond& d) // when buy card, use to check GOLD could replace diamonds
{
    int ans = 0;
    for(int i = 0; i < DIAMOND_TYPE_NUM - 1; i++)
    {
        if((this->diamonds[i] - d[i]) < 0) // insufficient
            ans += d[i] - diamonds[i];
    }
    return ans;
}

int Diamond::operator[] (int i) const // read more easily (eg: myDiamond[RED] == myDiamond.diamonds[RED])
{
    if(i < 0 || i > DIAMOND_TYPE_NUM)
        exit(1); // exception
    return diamonds[i];
}

int& Diamond::operator[] (int i) // can be assigned or modified
{
    if(i < 0 || i > DIAMOND_TYPE_NUM)
        exit(1); // expect
    return diamonds[i];
}

