#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>


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
        void update();

        void renderText(sf::RenderTarget& target);
        void render();

    private:
        //Variables 
        //Window
        sf::RenderWindow* window;
        sf::Event ev;
        sf::VideoMode videoMode;

        //Resources 
        sf::Font font;

        //Text
        sf::Text uiText;

        //Game Logic (Requires initialization)
        bool endGame;
        unsigned points;
        unsigned lives;

        //Game objects

        //Private Functions
        void initVariables();
        void initWindow();
        void initFonts();
        void initText();

};


#endif