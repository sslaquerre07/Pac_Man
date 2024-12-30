#ifndef GHOST_H
#define GHOST_H

#include <iostream>
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
        void updateWallCollisions(const std::vector<std::vector<int>>& bitmap, const std::vector<bool>& flags);
        void update();
        void render(sf::RenderTarget& target);
        void setPath(sf::CircleShape& pacman, const std::vector<std::vector<int>>& bitmap);

    protected:
        //Data members
        int type;
        float movementSpeedX;
        float movementSpeedY;
        std::vector<int> validDirections;
        std::vector<std::vector<int>> path;
        float defaultX;
        float defaultY;
        sf::CircleShape shape;
        //Path Strategy set dynamically for the different ghosts
        PathStrategy* strategy;

        //Private(ish) Functions
        bool inPosistion();
};



#endif