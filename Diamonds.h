// Diamonds.h

#ifndef Diamonds_h
#define Diamonds_h

#include <vector>

using namespace std;

const int DIAMOND_EXP_GOLD = 5;
// init diamonds numuber
extern int diamond_bank[6];

enum DiamondType    // Global
{
    WHITE,    // 0 (auto)
    BLACK,    // 1
    RED,      // 2
    GREEN,    // 3
    BLUE,     // 4
    GOLD,     // 5
    DIAMOND_TYPE_NUM    // 6
};

class Diamond
{
public:
    vector<int> diamonds;
    
    // Constructor
    Diamond();
    Diamond(int num);
    // Operator Overloading
    bool operator!=(const Diamond& d) const;
    const Diamond& operator-=(const Diamond& d);
    int operator[] (int i) const;
    int& operator[] (int i);
    
};

#endif // Diamond.h
