#ifndef BLINKY_H
#define BLINKY_H

#include "ghost.h"
#include "ghost.cpp"
#include "./pathSetting/shortestPath.h"
#include "./pathSetting/shortestPath.cpp"

class Blinky: public Ghost{
    public:
        //Ctor and dtor (Copy ctor and assignment operator not needed for now)
        Blinky(const sf::RenderWindow& window);
        ~Blinky();
};

#endif