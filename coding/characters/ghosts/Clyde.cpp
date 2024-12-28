#ifndef CLYDE_CPP
#define CLYDE_CPP

#include "Clyde.h"

Clyde::Clyde(const sf::RenderWindow& window): Ghost(window){
    this->defaultX = 362.f;
    this->defaultY = 314.f;
    this->shape.setPosition(defaultX, defaultY);
    this->strategy = new Randomized();
    this->shape.setFillColor(sf::Color(255, 204, 51));
}

Clyde::~Clyde(){
    delete this->strategy;
}

#endif