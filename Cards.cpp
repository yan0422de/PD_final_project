#include "Cards.h"
#include <SFML/Graphics.hpp>
#include <string>

Card::Card(int id, int level, int colorIdx, int score, int white, int black, int red, int green, int blue, std::string type, sf::RectangleShape shape, sf::Vector2f position, sf::Vector2f targetPosition)
    : level(level), color(colorIdx), score(score) {
    // Use operator overloading, equals to spendDimd.diamonds[something]
    this->id = id;
    this->type = type;
    this->shape = shape;
    this->texture.loadFromFile(type + "_" + std::to_string(score) + std::to_string(colorIdx) + std::to_string(white) + std::to_string(red) + std::to_string(black) + std::to_string(blue) + std::to_string(green) + ".png.png");
    this->shape.setTexture(&texture);
    this->position = position;
    this->shape.setPosition(this->position);
    this->targetPosition = targetPosition; 
    
    spendDimd[WHITE] = white;
    spendDimd[BLACK] = black;
    spendDimd[RED] = red;
    spendDimd[GREEN] = green;
    spendDimd[BLUE] = blue;
}

Card::Card(const Card& card) {
    this->level = card.level;
    this->color = card.color;
    this->score = card.score;
    this->id = card.id;
    this->type = card.type;
    this->shape = card.shape;
    this->position = card.position;
    this->targetPosition = card.targetPosition;

}

bool Card::operator==(const Card& card) const { // Used to compare 2 cards when buyReservedCard
    if (this->level != card.level)
        return false;
    else if (this->color != card.color)
        return false;
    else if (this->score != card.score)
        return false;
    else if (this->spendDimd != card.spendDimd)
        return false;
    else
        return true;
}

int Card::getScore() {
    return this->score;
}

int Card::getColor() {
    return this->color;
}

Diamond Card::getDiamond() const {
    return this->spendDimd;
}

int Card::getEachDiamond(int idx) const {
    return this->spendDimd[idx];
}

void Card::setPosition(sf::Vector2f position)
{
    this->position = position;
    this->shape.setPosition(this->position);
}

void Card::setTargetPosition(sf::Vector2f position)
{
    this->targetPosition = position;
}

sf::RectangleShape* Card::getShape()
{
    return &(this->shape);
}

void Card::moveToTarget(float moveSpeed)
{
    sf::Vector2f direction = this->targetPosition - this->position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (distance > 3.0f)
    {
        direction /= distance;
        this->setPosition(this->position + direction * moveSpeed);
    }
    else {
        this->setPosition(this->targetPosition);
    }
}