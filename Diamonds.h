#ifndef Diamonds_h
#define Diamonds_h

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
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
private:
    sf::CircleShape shape;
    sf::Color color;
    sf::Vector2f position;

public:
    int diamonds[DIAMOND_TYPE_NUM];

    // Constructor
    Diamond();
    Diamond(int num);
    Diamond(int num, sf::CircleShape shape, sf::Color color, sf::Vector2f position);
    sf::CircleShape* getShape();
    void setPosition(sf::Vector2f position);

    // Operator Overloading
    bool operator!=(const Diamond& d) const;
    const Diamond& operator-=(const Diamond& d);
    int operator[] (int i) const;
    int& operator[] (int i);
};

#endif