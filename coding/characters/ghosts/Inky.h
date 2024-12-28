#ifndef INKY_H
#define INKY_H

#include "ghost.h"
#include "ghost.cpp"
#include "./pathSetting/threeTurnsAhead.h"
#include "./pathSetting/threeTurnsAhead.cpp"

class Inky: public Ghost{
    public:
        //Ctor and dtor (Copy ctor and assignment operator not needed for now)
        Inky(const sf::RenderWindow& window);
        ~Inky();
};

#endif