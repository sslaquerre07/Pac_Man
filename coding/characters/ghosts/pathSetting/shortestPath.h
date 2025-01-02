#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H
#include "pathStrategy.h"

class ShortestPath: public PathStrategy{
    public:
        std::vector<std::vector<int>> setPath(const sf::Shape& src, const sf::Shape& dest, const std::vector<std::vector<int>>& bitmap, bool isIntersection) override;
};

#endif