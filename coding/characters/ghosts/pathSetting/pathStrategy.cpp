#include "pathStrategy.h"

std::vector<int> PathStrategy::reachCorner(const std::vector<std::vector<int>>& bitmap, int row, int col, int direction){
    switch(direction){
        //Left
        case 0:
            while(bitmap.at(row).at(col-1) < 2){col--;}
            break;
        //Right
        case 1:
            while(bitmap.at(row).at(col+1) < 2){col++;}
            break;
        //Down
        case 2:
            while(bitmap.at(row+1).at(col) < 2){row++;}
            break;
        //Up
        case 3:
            while(bitmap.at(row-1).at(col) < 2){row--;}
            break;
    }
    //Return the corner
    return {row, col};
}