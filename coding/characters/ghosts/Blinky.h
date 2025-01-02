#ifndef BLINKY_H
#define BLINKY_H

#include "ghost.h"
#include "ghost.cpp"
#include "./pathSetting/threeTurnsAhead.h"
#include "./pathSetting/threeTurnsAhead.cpp"

class Blinky: public Ghost{
    public:
        //Ctor and dtor (Copy ctor and assignment operator not needed for now)
        Blinky(const sf::RenderWindow& window);
        ~Blinky();
};

#endif