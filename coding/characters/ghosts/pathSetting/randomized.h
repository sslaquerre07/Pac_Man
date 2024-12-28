#ifndef RANDOMIZED_H
#define RANDOMIZED_H
#include "pathStrategy.h"

class Randomized: public PathStrategy{
    public:
        void setPath(const sf::Shape& src, const sf::Shape& dest) override;
};

#endif