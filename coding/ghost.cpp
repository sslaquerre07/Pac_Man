#include "ghost.h"

//Private Functions
void Ghost::initshape()
{
    switch(this->type)
    {
        case BLINKY:
            this->shape.setFillColor(sf::Color(255, 57, 57));
            break;
        case PINKY:
            this->shape.setFillColor(sf::Color(255, 153, 204));
            break;
        case INKY:
            this->shape.setFillColor(sf::Color(0, 239, 239));
            break;
        case CLYDE:
            this->shape.setFillColor(sf::Color(255, 204, 51));
            break;
    }
    this->shape.setRadius(9.f);
}

//Constructors and Destructor
Ghost::Ghost(const sf::RenderWindow& window, int type): type(type)
{   
    this->movementSpeed = 1.f;
    this->initshape();
    switch(this->type)
    {
        case BLINKY:
            this->defaultX = 288.f;
            this->defaultY = 312.f;
            this->shape.setPosition(defaultX, defaultY);
            break;
        case PINKY:
            this->defaultX = 312.f;
            this->defaultY = 312.f;
            this->shape.setPosition(defaultX, defaultY);
            break;
        case INKY:
            this->defaultX = 336.f;
            this->defaultY = 312.f;
            this->shape.setPosition(defaultX, defaultY);
            break;
        case CLYDE:
            this->defaultX = 360.f;
            this->defaultY = 312.f;
            this->shape.setPosition(defaultX, defaultY);
            break;
    }
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

//Functions
void Ghost::update()
{

}

void Ghost::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}