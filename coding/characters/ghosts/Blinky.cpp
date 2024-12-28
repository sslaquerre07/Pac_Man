#ifndef BLINKY_CPP
#define BLINKY_CPP

#include "Blinky.h"

//ctor
Blinky::Blinky(const sf::RenderWindow& window): Ghost(window){
    this->defaultX = 290.f;
    this->defaultY = 314.f;
    this->shape.setPosition(defaultX, defaultY);
    this->strategy = new ShortestPath();
    this->shape.setFillColor(sf::Color(255, 57, 57));
}

//dtor
Blinky::~Blinky(){
    delete this->strategy;
}

#endif