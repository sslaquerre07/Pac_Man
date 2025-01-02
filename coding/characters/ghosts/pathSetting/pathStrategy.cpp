#include "pathStrategy.h"

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