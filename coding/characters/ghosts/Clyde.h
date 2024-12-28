#ifndef CLYDE_H
#define CLYDE_H

#include "ghost.h"
#include "ghost.cpp"
#include "./pathSetting/randomized.h"
#include "./pathSetting/randomized.cpp"

class Clyde: public Ghost{
    public:
        Clyde(const sf::RenderWindow& window);
        ~Clyde();
};

#endif