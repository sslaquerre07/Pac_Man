#include "pathStrategy.h"

//Only checks for corners with more than two valid directions
bool PathStrategy::isCorner(const std::vector<std::vector<int>>& bitmap, int row, int col){
    int valid_directions = 0;
    //If for some reason a wall gets passed in should return false
    if(bitmap.at(row).at(col) > 1){return false;}
    //Otherwise check all four directions and increment as needed
    if(bitmap.at(row).at(col-1) < 2){valid_directions++;}
    if(bitmap.at(row).at(col+1) < 2){valid_directions++;}
    if(bitmap.at(row-1).at(col) < 2){valid_directions++;}
    if(bitmap.at(row+1).at(col) < 2){valid_directions++;}
    //Return true if 3 or more directions can be traveled
    return valid_directions > 2;
}

//Decides where the next corner for ghosts to re-evaluate is 
std::vector<int> PathStrategy::reachCorner(const std::vector<std::vector<int>>& bitmap, int row, int col, int direction){
    int init_row = row;
    int init_col = col;
    switch(direction){
        //Left
        case 0:
            while((bitmap.at(row).at(col-1) < 2)){
                if(isCorner(bitmap, row, col) && (row != init_row && col != init_col)){break;}
                col--;
            }
            break;
        //Right
        case 1:
            while((bitmap.at(row).at(col+1) < 2)){
                if(isCorner(bitmap, row, col) && (row != init_row && col != init_col)){break;}
                col++;
            }
            break;
        //Down
        case 2:
            while((bitmap.at(row+1).at(col) < 2)){
                if(isCorner(bitmap, row, col) && (row != init_row && col != init_col)){break;}
                row++;
            }
            break;
        //Up
        case 3:
            while((bitmap.at(row-1).at(col) < 2)){
                if(isCorner(bitmap, row, col) && (row != init_row && col != init_col)){break;}
                row--;
            }
            break;
    }
    //Return the corner
    return {row, col};
}