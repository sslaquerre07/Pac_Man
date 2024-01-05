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
        sf::CircleShape& getShape();
        const float& getDefaultX();
        const float& getDefaultY();
        
        //Functions
        void update();
        void render(sf::RenderTarget& target);


    private:
        int type;
        float movementSpeed;

        float defaultX;
        float defaultY;

        sf::CircleShape shape;

        void initshape();
};



#endif