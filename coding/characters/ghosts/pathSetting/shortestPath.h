#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H
#include "pathStrategy.h"

class ShortestPath: public PathStrategy{
    public:
        void setPath(const sf::Shape& src, const sf::Shape& dest) override;
};

#endif