#ifndef PINKY_CPP
#define PINKY_CPP

#include "Pinky.h"

Pinky::Pinky(const sf::RenderWindow& window):Ghost(window){
    this->defaultX = 314.f;
    this->defaultY = 314.f;
    this->shape.setPosition(defaultX, defaultY);
    this->strategy = new Randomized();
    //Pink Ghost
    this->shape.setFillColor(sf::Color(255, 153, 204));
}

Pinky::~Pinky(){
    delete this->strategy;
}

#endif