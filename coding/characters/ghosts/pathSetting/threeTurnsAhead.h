#ifndef THREETURNSAHEAD_H
#define THREETURNSAHEAD_H
#include "pathStrategy.h"

class ThreeTurnsAhead: public PathStrategy{
    public:
        void setPath(const sf::Shape& src, const sf::Shape& dest) override;
};

#endif