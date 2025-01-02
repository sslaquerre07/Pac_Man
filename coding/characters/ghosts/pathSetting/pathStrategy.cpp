#include "pathStrategy.h"

bool PathStrategy::isValid(const std::vector<std::vector<int>>& bitmap, int row, int col) {
    return row >= 0 && row < static_cast<int>(bitmap.size()) &&
           col >= 0 && col < static_cast<int>(bitmap[0].size()) &&
           bitmap[row][col] < 2;
}

// Function to calculate Manhattan distance
int PathStrategy::calculateDistance(int row1, int col1, int row2, int col2) {
    return std::abs(row1 - row2) + std::abs(col1 - col2);
}

//Decides where the next corner for ghosts to re-evaluate is 
std::vector<int> PathStrategy::reachCorner(const std::vector<std::vector<int>>& bitmap, int row, int col, int direction){
    int init_row = row;
    int init_col = col;
    switch(direction){
        //Left
        case 0:
            while((col > 0 && bitmap.at(row).at(col-1) < 2)){
                col--;
            }
            break;
        //Right
        case 1:
            while((col < 27 && bitmap.at(row).at(col+1) < 2 )){
                col++;
            }
            break;
        //Down
        case 2:
            while((bitmap.at(row+1).at(col) < 2)){
                row++;
            }
            break;
        //Up
        case 3:
            while((bitmap.at(row-1).at(col) < 2)){
                row--;
            }
            break;
    }
    //Return the corner
    return {row, col};
}