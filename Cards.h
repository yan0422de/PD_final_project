#ifndef Cards_h
#define Cards_h

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Diamonds.h"

const int MAX_CARD_NUM = 90;

class Card
{
private:
    int id;
    int level;    // level 1 ~ 3 (bad -> good)
    int color;    // discounted color (0 ~ 6 stand for white, black, red, green, blue, gold)
    int score;    // added point to player
    Diamond spendDimd;

    std::string type;
    sf::RectangleShape shape;
    sf::Texture texture;
    sf::Vector2f position;
    sf::Vector2f targetPosition;

public:
    Card() {};
    Card(int id, int level, int colorIdx, int score, int white, int black, int red, int green, int blue, std::string type, sf::RectangleShape shape, sf::Vector2f position, sf::Vector2f targetPosition);
    // Copy Constructor
    Card(const Card& card);
    // Operator Overloading
    bool operator==(const Card& card) const;
    // Getter
    int getScore();
    int getColor();
    Diamond getDiamond() const;
    // Initalize all cards
    int getEachDiamond(int idx) const; 
    
    sf::RectangleShape* getShape();
    void setPosition(sf::Vector2f position);
    void setTargetPosition(sf::Vector2f position);
    void moveToTarget(float movespeed);

};
#endif
