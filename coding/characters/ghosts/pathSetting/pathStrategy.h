#ifndef PATHSTRATEGY_H
#define PATHSTRATEGY_H
#include <SFML/Graphics.hpp>
#include <chrono>
#include <math.h>

//Interface that implements Strategy pattern for ghost movement
class PathStrategy{
    public:
        virtual std::vector<std::vector<int>> setPath(const sf::Shape& src, const sf::Shape& dest, const std::vector<std::vector<int>>& bitmap) = 0;
};

#endif