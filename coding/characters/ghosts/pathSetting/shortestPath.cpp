#ifndef SHORTESTPATH_CPP
#define SHORTESTPATH_CPP

#include "shortestPath.h"

std::vector<std::vector<int>> ShortestPath::setPath(const sf::Shape& src, const sf::Shape& dest, const std::vector<std::vector<int>>& bitmap, bool isIntersection){
    //Initialize appropriate vars
    std::vector<std::vector<int>> corners = {};
    int src_row = floor(src.getGlobalBounds().getPosition().y/24);
    int src_col = floor(src.getGlobalBounds().getPosition().x/24);
    int dest_row = floor(dest.getGlobalBounds().getPosition().y/24);
    int dest_col = floor(dest.getGlobalBounds().getPosition().x/24);
    //First, check if the ghost is still in the loading zone and if so, navigate out
    if(bitmap.at(src_row).at(src_col) == 3){
        int temp = src_row;
        while(bitmap.at(temp).at(src_col) == 3){
            temp--;
        }
        corners.push_back({temp, src_col});
    }
    return corners;
}

#endif