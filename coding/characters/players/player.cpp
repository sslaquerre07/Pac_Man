#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "player.h"

//Private Functions
void Player::initVariables()
{
    this->movementSpeed = 1.f;
}

void Player::initShape()
{
    this->shape.setFillColor(sf::Color::Yellow);
    this->shape.setRadius(10.f);
}

//Constructors and Destructor
Player::Player(float x, float y)
{
    //Use Arguments to set the position of the player
    this->shape.setPosition(x, y);
    this->initVariables();
    this->initShape();
}

Player::~Player()
{

}

//Getters
sf::CircleShape& Player::getShape()
{
    return this->shape;
}

const float Player::getMovementSpeed(){
    return movementSpeed;
}

//Private functions


//Functions
void Player::updateWallCollisions(const std::vector<std::vector<int>>& bitmap, const std::vector<bool>& flags){
    //Will be a messy bunch of if statements for now, until a better solution is derived
    //Top right corner collision
    if(flags.at(0) && flags.at(1) && flags.at(2)){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            shape.setPosition(shape.getPosition().x - 1, shape.getPosition().y);
        }
        else{
            shape.setPosition(shape.getPosition().x, shape.getPosition().y + 1);
        }
    }
    //Top left corner collision
    else if(flags.at(0) && flags.at(1) && flags.at(3)){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            shape.setPosition(shape.getPosition().x + 1, shape.getPosition().y);
        }
        else{
            shape.setPosition(shape.getPosition().x, shape.getPosition().y + 1);
        }
    }
    //Bottom left corner collision
    else if(flags.at(0) && flags.at(2) && flags.at(3)){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            shape.setPosition(shape.getPosition().x + 1, shape.getPosition().y);
        }
        else{
            shape.setPosition(shape.getPosition().x, shape.getPosition().y - 1);
        }
    }
    //Bottom right corner collision
    else if(flags.at(1) && flags.at(2) && flags.at(3)){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
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

void Player::updateAllCollisions(const std::vector<std::vector<int>>& bitmap, std::vector<std::vector<tiles>>& map, int& points, const std::vector<bool>& flags){
    //Calculations below can cause errors if going out of bounds left or right, so check for that first
    if(shape.getGlobalBounds().getPosition().x < 1){
        shape.setPosition(648, 312);
    }
    else if(shape.getGlobalBounds().getPosition().x >= 653){
        shape.setPosition(0, 312);
    }
    //Get the row and column that PacMan is in
    int row = floor(shape.getGlobalBounds().getPosition().y / 24);
    int col = floor(shape.getGlobalBounds().getPosition().x / 24);
    //Regular point tile
    if(bitmap.at(row).at(col) == 0 && !map.at(row).at(col).getVisited()){
        map.at(row).at(col).setVisited();
        points += 10;
    }
    //Superball
    else if(bitmap.at(row).at(col) == 1 && !map.at(row).at(col).getVisited()){
        map.at(row).at(col).setVisited();
        points += 50;
        //Eventually, also turn the ghosts into panic mode
    }
    //Wall collisions
    for(int i = 0; i < flags.size(); i++){
        if(flags.at(i)){
            updateWallCollisions(bitmap, flags);
            return;
        }
    }
}

void Player::updateInput()
{
    //Keyboard input

    //Left and right
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->shape.move(-this->movementSpeed, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->shape.move(this->movementSpeed, 0.f);
    }
    
    //Up and down
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->shape.move(0.f, -this->movementSpeed);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->shape.move(0.f, this->movementSpeed);
    }    
}

void Player::update(const sf::RenderTarget* target)
{
    this->updateInput();
}

//The arg in this function is necessary because this class has no access 
//to the window and must know where to render
void Player::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}

#endif