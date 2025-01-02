#ifndef THREETURNSAHEAD_H
#define THREETURNSAHEAD_H
#include "pathStrategy.h"

class ThreeTurnsAhead: public PathStrategy{
    public:
        std::vector<std::vector<int>> setPath(const sf::Shape& src, const sf::Shape& dest, const std::vector<std::vector<int>>& bitmap, bool isIntersection) override;
};

#endif