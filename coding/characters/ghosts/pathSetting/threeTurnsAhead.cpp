#ifndef THREETURNSAHEAD_CPP
#define THREETURNSAHEAD_CPP

#include "threeTurnsAhead.h"

std::vector<std::vector<int>> ThreeTurnsAhead::setPath(const sf::Shape& src, const sf::Shape& dest, const std::vector<std::vector<int>>& bitmap, bool isIntersection){
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
    //Algorithm implemented here (Limited enough turns to not implement recursively)
    else{
        // List of possible directions: {left, right, up, down}
        std::vector<int> directions = {0, 1, 2, 3};
        std::vector<std::vector<int>> path; // To store the sequence of corners

        int closest_distance = std::numeric_limits<int>::max();
        std::vector<int> third_corner;

        // BFS-like exploration
        for (int d1 : directions) {
            std::vector<int> corner1 = reachCorner(bitmap, src_row, src_col, d1);
            if (corner1.at(0) == src_row && corner1.at(1) == src_col) continue; // Skip invalid directions

            for (int d2 : directions) {
                std::vector<int> corner2 = reachCorner(bitmap, corner1[0], corner1[1], d2);
                if (corner2.at(0) == corner1.at(0) && corner2.at(1) == corner1.at(1)) continue; // Skip invalid directions

                for (int d3 : directions) {
                    std::vector<int> corner3 = reachCorner(bitmap, corner2[0], corner2[1], d3);
                    if (corner3.at(0) == corner2.at(0) && corner3.at(1) == corner2.at(1)) continue; // Skip invalid directions

                    // Calculate the distance of the third corner to the destination
                    int distance = calculateDistance(corner3[0], corner3[1], dest_row, dest_col);
                    if (distance < closest_distance) {
                        closest_distance = distance;
                        third_corner = corner3;
                        // Update the path
                        path = {corner1, corner2, corner3};
                    }
                }
            }
        }
        return path; // Return the sequence of corners leading to the third turn
    }
    
    return corners;
}

#endif