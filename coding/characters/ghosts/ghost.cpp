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
    this->movementSpeedX = 0.f;
    this->movementSpeedY = 0.f;
    this->initshape();
    this->validDirections = {0,0,0,0};
    switch(this->type)
    {
        case BLINKY:
            this->defaultX = 290.f;
            this->defaultY = 314.f;
            this->shape.setPosition(defaultX, defaultY);
            break;
        case PINKY:
            this->defaultX = 314.f;
            this->defaultY = 314.f;
            this->shape.setPosition(defaultX, defaultY);
            break;
        case INKY:
            this->defaultX = 338.f;
            this->defaultY = 314.f;
            this->shape.setPosition(defaultX, defaultY);
            break;
        case CLYDE:
            this->defaultX = 362.f;
            this->defaultY = 314.f;
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

//Functions
void Ghost::updateClydeDirection()
{
    int index;
    do{
        index = rand() % 4;
    }while(!this->validDirections.at(index));
    this->setDirection(index);
}

int Ghost::ClydeSwitchTimer()
{
    sf::Clock clock;
    sf::Time interval = sf::seconds(1.0f); // Set the interval to 5 seconds
    sf::Time elapsed = sf::Time::Zero;

    // Update elapsed time
    elapsed += clock.restart();

    // Check if the interval has passed
    if (elapsed >= interval) {
        elapsed = sf::Time::Zero; // Reset the elapsed time
        return 1;
    }
    return 0;

}

void Ghost::update()
{
    switch(this->type)
    {
        case BLINKY:
            break;
        case PINKY:
            break;
        case INKY:
            break;
        case CLYDE:
            //if(this->ClydeSwitchTimer())
            // this->updateClydeDirection();
            break;
    }
    this->shape.setPosition(this->shape.getPosition().x + this->movementSpeedX, this->shape.getPosition().y + this->movementSpeedY);
}

void Ghost::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}