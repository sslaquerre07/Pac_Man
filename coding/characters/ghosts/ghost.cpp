#ifndef GHOST_CPP
#define GHOST_CPP

#include "ghost.h"

//Constructors and Destructor
Ghost::Ghost(const sf::RenderWindow& window)
{   
    this->movementSpeedX = 0.f;
    this->movementSpeedY = 0.f;
    this->validDirections = {0,0,0,0};
    this->shape.setRadius(9.f);
}

Ghost::~Ghost()
{

}

//Getters
sf::CircleShape& Ghost::getShape()
{
    return this->shape;
}

const int& Ghost::getType()
{
    return this->type;
}

const float& Ghost::getDefaultX()
{
    return this->defaultX;
}

const float& Ghost::getDefaultY()
{
    return this->defaultY;
}

const int& Ghost::getDirection(const int& index)
{
    return this->validDirections.at(index);
}

const int Ghost::getCurrRow()
{
    if(int(this->shape.getPosition().y) % 24 <= 5)
    {
        return int(floor(this->shape.getPosition().y / 24));
    }
    else
    {
        return 1;
    }
}

const int Ghost::getCurrCol()
{
    if(int(this->shape.getPosition().x) % 24 <= 5)
    {
        return int(floor(this->shape.getPosition().x / 24));
    }
    else
    {
        return 10;
    }
}

//Setters
void Ghost::setGoodDirection(const int& index)
{
    this->validDirections.at(index) = 1;
}

void Ghost::setDirection(const int& index)
{
    switch(index)
    {
        case 0:
            this->movementSpeedX = -1.f;
            this->movementSpeedY = 0.f;
            break;
        case 1:
            this->movementSpeedX = 1.f;
            this->movementSpeedY = 0.f;
            break;
        case 2:
            this->movementSpeedX = 0.f;
            this->movementSpeedY = 1.f;
            break;
        case 3:
            this->movementSpeedX = 0.f;
            this->movementSpeedY = -1.f;
            break;
        case 10:
            this->movementSpeedX = 0.f;
            this->movementSpeedY = 0.f;
            break;
    }
}

void Ghost::update()
{
    this->shape.setPosition(this->shape.getPosition().x + this->movementSpeedX, this->shape.getPosition().y + this->movementSpeedY);
}

void Ghost::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}

#endif