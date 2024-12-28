#ifndef GHOST_H
#define GHOST_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "./pathSetting/pathStrategy.h"

class Ghost
{
    public:
        //Constructors and Destructor 
        Ghost(const sf::RenderWindow& window);
        virtual ~Ghost();

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
        void update();
        void render(sf::RenderTarget& target);
        void setPath();

    protected:
        //Data members
        int type;
        float movementSpeedX;
        float movementSpeedY;
        std::vector<int> validDirections;
        float defaultX;
        float defaultY;
        sf::CircleShape shape;
        //Path Strategy set dynamically for the different ghosts
        PathStrategy* strategy;
};



#endif