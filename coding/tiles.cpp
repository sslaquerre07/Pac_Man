#include "tiles.h"

//initialization
void tiles::initShape(const sf::RenderWindow& window)
{
    switch(this->type)
    {
        case POINTS:
            this->circle.setRadius(3.f);
            this->circle.setFillColor(sf::Color::White);
            break;
        case SUPER:
            this->circle.setRadius(6.f);
            this->circle.setFillColor(sf::Color::White);
            break;
        case WALL:
            this->rect.setSize(sf::Vector2f(24.f, 24.f));
            this->rect.setFillColor(sf::Color::Red);
            break;

    }
}

//Constructors and Destructor
tiles::tiles()
{
    this->visited = false;
    this->type = 0;
}

tiles::tiles(const sf::RenderWindow& window, int type) : type(type)
{
    this->visited = false;
    this->initShape(window);
}

tiles::~tiles()
{

}

//Getters
const int& tiles::getType() const
{
    return this->type;
}

//Functions
void tiles::update()
{

}

void tiles::render(sf::RenderTarget& target, int& row, int& col)
{
    switch(this->type)
    {
        case POINTS:
            this->circle.setPosition(col*24.f+12.f, row*24.f+12.f);
            if(!this->visited){
                target.draw(this->circle);
            }
        case SUPER:
            this->circle.setPosition(col*24.f+12.f, row*24.f+12.f);
            if(!this->visited){
                target.draw(this->circle);
            }
        case WALL:
            this->rect.setPosition(col*24.f, row*24.f);
            target.draw(this->rect);
    }

}