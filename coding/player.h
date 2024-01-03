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
        Player(float x = 0.f, float y = 0.f);
        ~Player();

        //Accessors
        const sf::CircleShape& getShape() const;

        //Functions
        void updateInput();
        void update(const sf::RenderTarget* target);
        void render(sf::RenderTarget* target);

};


#endif