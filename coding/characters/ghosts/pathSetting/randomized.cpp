#ifndef RANDOMIZED_CPP
#define RANDOMIZED_CPP

#include "randomized.h"

std::vector<std::vector<int>> Randomized::setPath(const sf::Shape& src, const sf::Shape& dest, const std::vector<std::vector<int>>& bitmap){
    //Initialize appropriate vars
    std::vector<std::vector<int>> corners = {};
    int src_row = floor(src.getGlobalBounds().getPosition().y/24);
    int src_col = floor(src.getGlobalBounds().getPosition().x/24);
    //First, check if the ghost is still in the loading zone and if so, navigate out
    if(bitmap.at(src_row).at(src_col) == 3){
        int temp = src_row;
        while(bitmap.at(temp).at(src_col) == 3){
            temp--;
        }
        corners.push_back({temp, src_col});
    }
    //Set a random corner now
    //Get all possible next corners
    else{
        std::vector<std::vector<int>> possible_corners = {};
        for(int i = 0; i < 4; i++){
            //Must verify that it is another corner and not just the same spot
            std::vector<int> corner = reachCorner(bitmap, src_row, src_col, i);
            if(corner.at(0) != src_row || corner.at(1) != src_col){
                possible_corners.push_back(reachCorner(bitmap, src_row, src_col, i));
            }
        }
        //Grab random corner from the list
        // Seed the random number generator
        std::srand(std::time(0));
        // Generate a random index and grab that corner
        int random_number = std::rand() % possible_corners.size();
        corners.push_back(possible_corners.at(random_number));
    }
    //Return the list of corners
    return corners;
}

#endif