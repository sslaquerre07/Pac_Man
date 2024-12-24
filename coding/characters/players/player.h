#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
    private:
        sf::CircleShape shape;
        float movementSpeed;
        void initVariables();
        void initShape();

    public:
        Player(float x = 24.f, float y = 24.f);
        ~Player();

        //Accessors
        sf::CircleShape& getShape();

        //Functions
        void updateInput();
        void update(const sf::RenderTarget* target);
        void render(sf::RenderTarget* target);

};


#endif