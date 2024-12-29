#ifndef INKY_CPP
#define INKY_CPP

#include "Inky.h"

//ctor
Inky::Inky(const sf::RenderWindow& window): Ghost(window){
    this->defaultX = 338.f;
    this->defaultY = 314.f;
    this->shape.setPosition(defaultX, defaultY);
    this->strategy = new ThreeTurnsAhead();
    //Blue Ghost
    this->shape.setFillColor(sf::Color(0, 239, 239));
}

//dtor
Inky::~Inky(){
    delete this->strategy;
}

#endif