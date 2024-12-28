#ifndef PATHSTRATEGY_H
#define PATHSTRATEGY_H
#include <SFML/Graphics.hpp>

//Interface that implements Strategy pattern for ghost movement
class PathStrategy{
    public:
        virtual void setPath(const sf::Shape& src, const sf::Shape& dest) = 0;
};

#endif