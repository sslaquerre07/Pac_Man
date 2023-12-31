#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

#include "tiles.h"
#include "player.h"
#include "ghost.h"


class Game
{
    public:
        Game();
        ~Game();

        //Getters
        const bool running() const;

        //Functions
        void pollEvents();
        void updateText();
        void updateDefaultCollision(sf::CircleShape& shape);
        void updateWallCollison(size_t row, size_t col, sf::CircleShape& shape);
        void updateDeathCollision(sf::CircleShape& PacMan, sf::CircleShape& Ghost);
        void validGhostDirections(Ghost& Ghost);
        void update();

        void renderText(sf::RenderTarget& target);
        void renderMap(sf::RenderTarget& target);
        void render();

        void TopLeft();
        void TopRight();
        void BottomLeft();
        void BottomRight();

    private:
        //Variables 
        //Window
        sf::RenderWindow* window;
        sf::Event ev;
        sf::VideoMode videoMode;

        //Game Objects
        Player PacMan;
        Ghost* Blinky = new Ghost(*this->window, 0);
        Ghost* Pinky = new Ghost(*this->window, 1);
        Ghost* Inky = new Ghost(*this->window, 2);
        Ghost* Clyde = new Ghost(*this->window, 3);

        //Resources 
        sf::Font font;

        //Text
        sf::Text uiText;

        //Game Logic (Requires initialization)
        bool endGame;
        unsigned points;
        unsigned lives;

        //Game objects
        std::vector<std::vector<tiles>> map;

        //Private Functions
        void initVariables();
        void initMap();
        void initWindow();
        void initFonts();
        void initText();

};


#endif