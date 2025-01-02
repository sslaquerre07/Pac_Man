#ifndef PATHSTRATEGY_H
#define PATHSTRATEGY_H
#include <SFML/Graphics.hpp>
#include <chrono>
#include <math.h>
#include <iostream>
#include <queue>

//Interface that implements Strategy pattern for ghost movement
class PathStrategy{
    public:
        virtual std::vector<std::vector<int>> setPath(const sf::Shape& src, const sf::Shape& dest, const std::vector<std::vector<int>>& bitmap, bool isIntersection) = 0;
        std::vector<int> reachCorner(const std::vector<std::vector<int>>& bitmap, int row, int col, int direction);
        bool isValid(const std::vector<std::vector<int>>& bitmap, int row, int col);
        int calculateDistance(int row1, int col1, int row2, int col2);
};

#endif