#ifndef GHOST_H
#define GHOST_H

#include <SFML/Graphics.hpp>
#include <cmath>

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
        const int& getDirection(const int& index);
        const int getCurrRow();
        const int getCurrCol();

        //Setters
        void setGoodDirection(const int& index);
        void setDirection(const int& index);
        
        //Functions
        void updateClydeDirection();
        int ClydeSwitchTimer();
        void update();


        void render(sf::RenderTarget& target);


    private:
        int type;
        float movementSpeedX;
        float movementSpeedY;
        std::vector<int> validDirections;

        float defaultX;
        float defaultY;

        sf::CircleShape shape;

        void initshape();
};



#endif