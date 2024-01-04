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
            this->shape.setPosition(288.f, 312.f);
            break;
        case PINKY:
            this->shape.setPosition(312.f, 312.f);
            break;
        case INKY:
            this->shape.setPosition(336.f, 312.f);
            break;
        case CLYDE:
            this->shape.setPosition(360.f, 312.f);
            break;
    }
}

Ghost::~Ghost()
{

}

//Getters
const sf::CircleShape& Ghost::getShape()
{
    return this->shape;
}

const int& Ghost::getType()
{
    return this->type;
}

//Functions
void Ghost::update()
{

}

void Ghost::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}