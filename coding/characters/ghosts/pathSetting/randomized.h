#ifndef RANDOMIZED_H
#define RANDOMIZED_H
#include "pathStrategy.h"
#include "pathStrategy.cpp"

class Randomized: public PathStrategy{
    public:
        std::vector<std::vector<int>> setPath(const sf::Shape& src, const sf::Shape& dest, const std::vector<std::vector<int>>& bitmap) override;
};

#endif