#ifndef GHOST_H
#define GHOST_H

#include <SFML/Graphics.hpp>

enum GhostType {BLINKY = 0, PINKY, INKY, CLYDE};

class Ghost
{
    public:
        //Constructors and Destructor 
        Ghost(const sf::RenderWindow& window, int type);
        ~Ghost();

        //Getters
        const int& getType();
        const sf::CircleShape& getShape();

        //Functions
        void update();
        void render(sf::RenderTarget& target);


    private:
        int type;
        float movementSpeed;

        sf::CircleShape shape;

        void initshape();
};



#endif