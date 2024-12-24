#include <iostream>
//Must include the cpp files for subdirectory structure to work
#include "./screen/game.h"
#include "./screen/game.cpp"

int main()
{
    //Init srand
    srand(static_cast<unsigned>(time(NULL)));
    //Call Game default constructor
    Game game;

    while(game.running())
    {
        //Update the Game
        game.update();
        //Render to the screen
        game.render();
    }

    //End of application
    return 0;
}