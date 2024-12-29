#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <math.h>
#include "../../screen/tiles.h"
#include "../../screen/tiles.cpp"

class Player
{
    private:
        sf::CircleShape shape;
        float movementSpeed;

        //Private functions
        void initVariables();
        void initShape();

    public:
        Player(float x = 24.f, float y = 24.f);
        ~Player();

        //Accessors
        sf::CircleShape& getShape();
        const float getMovementSpeed();

        //Functions
        void updateWallCollisions(const std::vector<std::vector<int>>& bitmap, const std::vector<bool>& flags);
        void updateAllCollisions(const std::vector<std::vector<int>>& bitmap, std::vector<std::vector<tiles>>& map, int& points, const std::vector<bool>& flags);
        void updateInput();
        void update(const sf::RenderTarget* target);
        void render(sf::RenderTarget* target);

};


#endif