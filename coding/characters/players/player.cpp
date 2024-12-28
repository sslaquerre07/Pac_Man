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

//Functions
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