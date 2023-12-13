// Diamonds.h

#ifndef Diamonds_h
#define Diamonds_h

#include <vector>

using namespace std;

const int DIAMOND_EXP_GOLD = 5;

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
private:
    vector<int> dimonds;
    
public:
    //vector<int> dimonds;
    
    // Constructor
    Diamond();
    Diamond(int num);
    // Operator Overloading
    bool operator!=(const Diamond& d) const;
    bool operator>=(const Diamond& d) const;
    const Diamond& operator-=(const Diamond& d);
    const int operator-(const Diamond& d);
    int operator[] (int i) const;
    int& operator[] (int i);
    // Getter
    int getAllCnt();
    void returnDiamond(int color, Diamond playerD); // only fieldDiamond can invoke
    void returnDiamond(int color1, int color2, Diamond playerD);
    void returnDiamond(int color1, int color2, int color3, Diamond playerD);
    // int getPre();
    // int getNext();
    // int getPreOpist();
    // int getNextOpist();
};

#endif // Diamond.h
