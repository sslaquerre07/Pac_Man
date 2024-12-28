#ifndef PINKY_H
#define PINKY_H

#include "ghost.h"
#include "ghost.cpp"
#include "./pathSetting/randomized.h"
#include "./pathSetting/randomized.cpp"

class Pinky: public Ghost{
    public:
        Pinky(const sf::RenderWindow& window);
        ~Pinky();
};

#endif