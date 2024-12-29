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
            this->movementSpeedX = -0.1f;
            this->movementSpeedY = 0.f;
            break;
        case 1:
            this->movementSpeedX = 0.1f;
            this->movementSpeedY = 0.f;
            break;
        case 2:
            this->movementSpeedX = 0.f;
            this->movementSpeedY = 0.1f;
            break;
        case 3:
            this->movementSpeedX = 0.f;
            this->movementSpeedY = -0.1f;
            break;
        case 10:
            this->movementSpeedX = 0.f;
            this->movementSpeedY = 0.f;
            break;
    }
}

void Ghost::setPath(sf::CircleShape& pacman, const std::vector<std::vector<int>>& bitmap){
    //Checks if the timer went off, and if so sets the new path accordingly
    path = strategy->setPath(shape, pacman, bitmap);
}

void Ghost::updateWallCollisions(const std::vector<std::vector<int>>& bitmap, const std::vector<bool>& flags){
    //Will be a messy bunch of if statements for now, until a better solution is derived
    //Top right corner collision
    if(flags.at(0) && flags.at(1) && flags.at(2)){
        if(movementSpeedX > 0){
            shape.setPosition(shape.getPosition().x - 1, shape.getPosition().y);
        }
        else{
            shape.setPosition(shape.getPosition().x, shape.getPosition().y + 1);
        }
    }
    //Top left corner collision
    else if(flags.at(0) && flags.at(1) && flags.at(3)){
        if(movementSpeedX < 0){
            shape.setPosition(shape.getPosition().x + 1, shape.getPosition().y);
        }
        else{
            shape.setPosition(shape.getPosition().x, shape.getPosition().y + 1);
        }
    }
    //Bottom left corner collision
    else if(flags.at(0) && flags.at(2) && flags.at(3)){
        if(movementSpeedX < 0){
            shape.setPosition(shape.getPosition().x + 1, shape.getPosition().y);
        }
        else{
            shape.setPosition(shape.getPosition().x, shape.getPosition().y - 1);
        }
    }
    //Bottom right corner collision
    else if(flags.at(1) && flags.at(2) && flags.at(3)){
        if(movementSpeedX > 0){
            shape.setPosition(shape.getPosition().x - 1, shape.getPosition().y);
        }
        else{
            shape.setPosition(shape.getPosition().x, shape.getPosition().y - 1);
        }
    }
    //Left collision
    else if(flags.at(0) && flags.at(3)){
        shape.setPosition(shape.getPosition().x + 1, shape.getPosition().y);
    }
    //Right collision
    else if(flags.at(1) && flags.at(2)){
        shape.setPosition(shape.getPosition().x - 1, shape.getPosition().y);
    }
    //Top collision
    else if(flags.at(0) && flags.at(1)){
        shape.setPosition(shape.getPosition().x, shape.getPosition().y + 1);
    }
    //Bottom collsion
    else if(flags.at(2) && flags.at(3)){
        shape.setPosition(shape.getPosition().x, shape.getPosition().y - 1);
    }
    else{
        shape.setPosition(shape.getPosition().x, shape.getPosition().y - 1);
    }
}

void Ghost::update()
{
    int curr_col = floor(shape.getGlobalBounds().getPosition().x/24);
    int curr_row = floor(shape.getGlobalBounds().getPosition().y/24);
    //Check first to see if there are elements in the path list
    if(path.empty()){
        //Should never occur, but ghosts should stop if it does
        setDirection(10);
    }
    else{
        std::vector<int> next_corner = path.at(path.size()-1);
        //Check if movement is required in the x direction
        if(next_corner.at(0) == curr_row){
            //Need to move left
            if(next_corner.at(1) < curr_col){setDirection(0);}
            //Right
            else{setDirection(1);}
        }
        //Movement required in the y direction
        else{
            //Need to move up
            if(next_corner.at(0) < curr_row){setDirection(3);}
            //Down
            else{setDirection(2);}
        }
    }
    this->shape.setPosition(this->shape.getPosition().x + this->movementSpeedX, this->shape.getPosition().y + this->movementSpeedY);
}

void Ghost::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}

#endif