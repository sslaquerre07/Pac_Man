#ifndef GHOST_CPP
#define GHOST_CPP

#include "ghost.h"

//Constructors and Destructor
Ghost::Ghost(const sf::RenderWindow& window)
{   
    this->movementSpeedX = 0.f;
    this->movementSpeedY = 0.f;
    this->shape.setRadius(9.f);
}

Ghost::~Ghost()
{

}

//Private functions
//Sees if the ghost is in position to move to its next corner
bool Ghost::inPosistion(){
    const std::vector<int>& next_corner = path.at(0);
    const float& curr_x = shape.getGlobalBounds().getPosition().x;
    const float& curr_y = shape.getGlobalBounds().getPosition().y;
    //Now, check all corners and make sure they are in the correct frame to progress
    if(floor((curr_x)/24) != next_corner.at(0) || floor((curr_y)/24) != next_corner.at(1)){
        return false;
    }
    if(floor((curr_x+18)/24) != next_corner.at(0) || floor((curr_y)/24) != next_corner.at(1)){
        return false;
    }
    if(floor((curr_x+18)/24) != next_corner.at(0) || floor((curr_y+18)/24) != next_corner.at(1)){
        return false;
    }
    if(floor((curr_x)/24) != next_corner.at(0) || floor(curr_y+18/24) != next_corner.at(1)){
        return false;
    }
    //If none of the above conditions are met, the ghost is in its required tile
    return true;
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
            this->movementSpeedX = -0.5;
            this->movementSpeedY = 0;
            break;
        case 1:
            this->movementSpeedX = 0.5;
            this->movementSpeedY = 0;
            break;
        case 2:
            this->movementSpeedX = 0;
            this->movementSpeedY = 0.5;
            break;
        case 3:
            this->movementSpeedX = 0;
            this->movementSpeedY = -0.5;
            break;
        case 10:
            this->movementSpeedX = 0;
            this->movementSpeedY = 0;
            break;
        default:
            std::cout << "Invalid index provided: " << index << std::endl;
            break;
    }
}

void Ghost::setPath(sf::CircleShape& pacman, const std::vector<std::vector<int>>& bitmap){
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
    if(path.empty() || inPosistion()){
        //Should never occur, but ghosts should stop if it does
        setDirection(10);
    }
    else{
        std::vector<int> next_corner = path.at(0);
        //If the origin is in the right spot but not quite in position yet
        if(next_corner.at(0) == curr_row && next_corner.at(1) == curr_col){
            //Nothing to be done, just keep doing what you're doing
        }
        //Check if movement is required in the x direction
        else if(next_corner.at(0) == curr_row){
            //Need to move left
            if(next_corner.at(1) < curr_col){setDirection(0);}
            //Right
            else{setDirection(1);}
        }
        //Movement required in the y direction
        else if(next_corner.at(1) == curr_col){
            //Need to move up
            if(next_corner.at(0) < curr_row){setDirection(3);}
            //Down
            else{setDirection(2);}
        }
        else{
            setDirection(10);
        }
    }
    this->shape.setPosition(this->shape.getPosition().x + this->movementSpeedX, this->shape.getPosition().y + this->movementSpeedY);
}

void Ghost::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}

#endif