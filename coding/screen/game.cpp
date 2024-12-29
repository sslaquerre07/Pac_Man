#ifndef GAME_CPP
#define GAME_CPP

#include "Game.h"
#include <math.h>

//Constructors and Destructor
Game::Game()
{      
    //Initialize the bitmap to layout the map            
                   //0,1,2,3,4,5,6,7,8,9,A,B,C,D,D,C,B,A,9,8,7,6,5,4,3,2,1,0
    this->bitmap = {{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
                    {2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2},
                    {2,0,2,2,2,2,0,2,2,2,2,2,0,2,2,0,2,2,2,2,2,0,2,2,2,2,0,2},
                    {2,1,2,2,2,2,0,2,2,2,2,2,0,2,2,0,2,2,2,2,2,0,2,2,2,2,1,2},
                    {2,0,2,2,2,2,0,2,2,2,2,2,0,2,2,0,2,2,2,2,2,0,2,2,2,2,0,2},
                    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
                    {2,0,2,2,2,2,0,2,2,0,2,2,2,2,2,2,2,2,0,2,2,0,2,2,2,2,0,2},
                    {2,0,0,0,0,0,0,2,2,0,0,0,2,2,2,2,0,0,0,2,2,0,0,0,0,0,0,2},
                    {2,2,2,2,2,2,0,2,2,2,2,0,2,2,2,2,0,2,2,2,2,0,2,2,2,2,2,2},
                    {2,2,2,2,2,2,0,2,2,2,2,0,2,2,2,2,0,2,2,2,2,0,2,2,2,2,2,2},
                    {2,2,2,2,2,2,0,2,2,0,0,0,0,0,0,0,0,0,0,2,2,0,2,2,2,2,2,2},
                    {2,2,2,2,2,2,0,2,2,0,2,2,2,3,3,2,2,2,0,2,2,0,2,2,2,2,2,2},
                    {2,2,2,2,2,2,0,2,2,0,2,2,2,3,3,2,2,2,0,2,2,0,2,2,2,2,2,2},
                    {0,0,0,0,0,0,0,0,0,0,2,2,3,3,3,3,2,2,0,0,0,0,0,0,0,0,0,0},
                    {2,2,2,2,2,2,0,2,2,0,2,2,2,2,2,2,2,2,0,2,2,0,2,2,2,2,2,2},
                    {2,2,2,2,2,2,0,2,2,0,2,2,2,2,2,2,2,2,0,2,2,0,2,2,2,2,2,2},
                    {2,2,2,2,2,2,0,2,2,0,2,2,2,2,2,2,2,2,0,2,2,0,2,2,2,2,2,2},
                    {2,2,2,2,2,2,0,2,2,0,2,2,2,2,2,2,2,2,0,2,2,0,2,2,2,2,2,2},
                    {2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2},
                    {2,0,2,2,2,2,0,2,2,2,2,2,0,2,2,0,2,2,2,2,2,0,2,2,2,2,0,2},
                    {2,1,2,2,2,2,0,2,2,2,2,2,0,2,2,0,2,2,2,2,2,0,2,2,2,2,1,2},
                    {2,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,2},
                    {2,2,2,0,2,2,0,2,2,0,2,2,2,2,2,2,2,2,0,2,2,0,2,2,0,2,2,2},
                    {2,0,0,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,0,0,2},
                    {2,0,2,2,2,2,2,2,2,2,2,2,0,2,2,0,2,2,2,2,2,2,2,2,2,2,0,2},
                    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
                    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}};
    // Setup basic variables
    this->initVariables();
    //Ghost setup
    this->ghosts.push_back(new Inky(*this->window));
    this->ghosts.push_back(new Blinky(*this->window));
    this->ghosts.push_back(new Pinky(*this->window));
    this->ghosts.push_back(new Clyde(*this->window));
    //Based on bitmap
    this->initMap();
    //Standard SFML setup
    this->initWindow();
    this->initFonts();
    this->initText();
}

Game::~Game()
{
    delete this->window;
}

//Private Functions
void Game::initVariables()
{
    this->window = nullptr;

    //Game Logic initialization
    this->endGame = false;
    this->points = 0;
    this->lives = 3;
    this->map.resize(56);
}

void Game::initMap()
{
    for(int i = 0; i<bitmap.size(); i++){
        for(int j = 0; j<bitmap.at(i).size(); j++){
            this->map.at(i).push_back(tiles(*this->window, bitmap.at(i).at(j)));
        }
    }
}

void Game::initWindow()
{
    this->videoMode.height = 710;
    this->videoMode.width = 672;
    this->window = new sf::RenderWindow(this->videoMode, "Pac Man", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(144);
}

void Game::initFonts()
{
    if(!this->font.loadFromFile("C:/GitHub/Pac_Man/Fonts/arial.ttf"))
    {
        std::cout << "Failed to load in the font" << "\n";
    }
}

void Game::initText()
{
    this->uiText.setPosition(0.f, 680.f);
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(24);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setString("NONE");
}

double Game::map_to_coord(int map_pos){
    return (double) map_pos*24.0;
}

int Game::coord_to_map(double coord){
    return floor(coord/24);
}

//Getters
const bool Game::running() const
{
    return this->window->isOpen();
}

//Functions

//Updating
void Game::pollEvents()
{
    //Event polling
    //Whenever an event occurs, saves it into the ev variable for evaluation
    while(this->window->pollEvent(ev))
    {
        switch(ev.type)
        {
        case sf::Event::Closed:
            //Whenever the window is closed, it sends it to the event ev, the actual closing must be done manually
            this->window->close();
            break;
        //How to check if a key is pressed at all, use for movement!
        case sf::Event::KeyPressed:
            if(ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
        //Checks if the health in game is less than 0
        if(this->lives <= 0)
            this->window->close();

    }
}

//Print game text
void Game::updateText()
{
    std::stringstream ss;

    ss << "Points: " << this->points << "\t"
        << "Lives: " << this->lives << "\n";
    this->uiText.setString(ss.str());
}

//Used to flag all kinds of collisions (Even when a corner is caught)
std::vector<bool> Game::flagCollisions(sf::CircleShape shape){
    std::vector<bool> flags = {false, false, false, false};
    float origin_x = shape.getGlobalBounds().getPosition().x;
    float origin_y = shape.getGlobalBounds().getPosition().y;
    //Top left
    if(bitmap.at(coord_to_map(origin_y)).at(coord_to_map(origin_x)) == 2){
        flags.at(0) = true;
    } 
    //Top right
    if(bitmap.at(coord_to_map(origin_y)).at(coord_to_map(origin_x+18)) == 2){
        flags.at(1) = true;
    }
    //Bottom right
    if(bitmap.at(coord_to_map(origin_y+18)).at(coord_to_map(origin_x+18)) == 2){
        flags.at(2) = true;
    }
    //Bottom left
    if(bitmap.at(coord_to_map(origin_y+18)).at(coord_to_map(origin_x)) == 2){
        flags.at(3) = true;
    }
    return flags;
}

//Handles collisions with the ghosts (Just live ones for now)
void Game::updateDeathCollision(sf::CircleShape& PacMan, sf::CircleShape& Ghost)
{
    if(PacMan.getGlobalBounds().intersects(Ghost.getGlobalBounds())){
        for(int i = 0; i < this->ghosts.size(); i++){
            this->ghosts.at(i)->getShape().setPosition(this->ghosts.at(i)->getDefaultX(), this->ghosts.at(i)->getDefaultY());
        }
        PacMan.setPosition(24.f, 24.f);
        this->lives -= 1;
    }
}

void Game::validGhostDirections(Ghost& Ghost)
{
    //Left Check
    if(this->map.at(Ghost.getCurrRow()).at(Ghost.getCurrCol()-1).getType() != 2)
    {
        Ghost.setGoodDirection(0);
    }
    //Right Check
    if(this->map.at(Ghost.getCurrRow()).at(Ghost.getCurrCol()+1).getType() != 2)
    {
        Ghost.setGoodDirection(1);
    }
    //Up Check
    if(this->map.at(Ghost.getCurrRow()-1).at(Ghost.getCurrCol()).getType() != 2)
    {
        Ghost.setGoodDirection(2);
    }
    //Down Check
    if(this->map.at(Ghost.getCurrRow()+1).at(Ghost.getCurrCol()).getType() != 2)
    {
        Ghost.setGoodDirection(3);
    }
}

void Game::update()
{
    this->pollEvents();
    this->updateText();

    //Updating Ghost Data
    for(int i = 0; i<ghosts.size(); i++){
        //Updating direction
        validGhostDirections(*ghosts.at(i));
        //Updating ghost position
        ghosts.at(i)->update();
        //Checking for collisions
        //Check for ghost collisions here
        updateDeathCollision(PacMan.getShape(), ghosts.at(i)->getShape());
    }

    //Doing the same for pacman
    this->PacMan.update(this->window);
    this->PacMan.updateAllCollisions(bitmap, map, points, flagCollisions(this->PacMan.getShape()));
    
}

//Rendering
void Game::renderText(sf::RenderTarget& target)
{
    target.draw(this->uiText);
}

void Game::renderMap(sf::RenderTarget& target)
{
    for(int i = 0; i < this->map.size();i++){
        for(int j = 0; j < this->map.at(i).size();j++){
            this->map.at(i).at(j).render(*this->window, i, j);
        }
    }
}

void Game::render()
{
    /*
        - Clear old frame
        - Render Objects
        - Display frame in new window
    */

    this->window->clear();
    //Draw game objects

    //Render the text for the game
    this->renderText(*this->window);
    this->renderMap(*this->window);
    this->PacMan.render(this->window);
    for(int i = 0; i<ghosts.size(); i++){
        ghosts.at(i)->render(*this->window);
    }
    this->window->display();
}

#endif