#include "Game.h"

//Constructors and Destructor
Game::Game()
{
    this->initVariables();
    this->initMap();
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
    this->TopLeft();
    this->TopRight();
    this->BottomLeft();
    this->BottomRight();
}

void Game::TopLeft()
{
    int row, col;
    for(row = 0; row < 14; row++){
        for(col = 0; col < 14; col++){
            if(row == 0){
                this->map.at(row).push_back(tiles(*this->window, 2));
            }
            else if(row == 1){
                if(col == 0 || col == 13){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
            else if(row == 2 || row == 3 || row == 4){
                if(col == 1 || col == 6 || col == 12){
                    if(row == 3 && col == 1){
                        this->map.at(row).push_back(tiles(*this->window, 1));
                    }
                    else{
                        this->map.at(row).push_back(tiles(*this->window, 0));
                    }
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else if(row == 5){
                if(col == 0){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
            else if(row == 6){
                if(col == 1 || col == 6 || col == 9){
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else if(row == 7){
                if(col == 0 || col == 7 || col == 8 || col == 13){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
            else if(row == 8 || row == 9){
                if(col == 6 || col == 12){
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else if(row == 10){
                if(col <= 5|| col == 7 || col == 8){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
            else if(row == 11 || row == 12){
                if(col == 6 || col == 9){
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
                else if(col == 13){
                    this->map.at(row).push_back(tiles(*this->window, 3));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else{
                if(col >= 10){
                    if(col >= 12){
                        this->map.at(row).push_back(tiles(*this->window, 3));
                    }
                    else{
                        this->map.at(row).push_back(tiles(*this->window, 2));
                    }
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
        }
    }
}

void Game::TopRight()
{
    int row, col;
    for(row = 0; row < 14; row++){
        for(col = 13; col >= 0; col--){
            if(row == 0){
                this->map.at(row).push_back(tiles(*this->window, 2));
            }
            else if(row == 1){
                if(col == 0 || col == 13){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
            else if(row == 2 || row == 3 || row == 4){
                if(col == 1 || col == 6 || col == 12){
                    if(row == 3 && col == 1){
                        this->map.at(row).push_back(tiles(*this->window, 1));
                    }
                    else{
                        this->map.at(row).push_back(tiles(*this->window, 0));
                    }
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else if(row == 5){
                if(col == 0){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
            else if(row == 6){
                if(col == 1 || col == 6 || col == 9){
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else if(row == 7){
                if(col == 0 || col == 7 || col == 8 || col == 13){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
            else if(row == 8 || row == 9){
                if(col == 6 || col == 12){
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else if(row == 10){
                if(col <= 5|| col == 7 || col == 8){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
            else if(row == 11 || row == 12){
                if(col == 6 || col == 9){
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
                else if(col == 13){
                    this->map.at(row).push_back(tiles(*this->window, 3));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else{
                if(col >= 10){
                    if(col >= 12){
                        this->map.at(row).push_back(tiles(*this->window, 3));
                    }
                    else{
                        this->map.at(row).push_back(tiles(*this->window, 2));
                    }
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
        }
    }
}

void Game::BottomLeft()
{
    int row, col;
    for(row = 14; row < 28; row++){
        for(col = 0; col < 14; col++){
            if(row == 13+14){
                this->map.at(row).push_back(tiles(*this->window, 2));
            }
            else if(row == 0+14 || row == 1+14 || row == 3+14 || row == 4+14){
                if(col == 6 || col == 9){
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else if(row == 2+14){
                if(col == 6 || col >= 9){
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else if(row == 5+14){
                if(col == 0 || col == 13){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
            else if(row == 6+14 || row == 7+14){
                if(col == 1 || col == 6 || col == 12){
                    if(row == 7+14 && col == 1){
                        this->map.at(row).push_back(tiles(*this->window, 1));
                    }
                    else{
                        this->map.at(row).push_back(tiles(*this->window, 0));
                    }
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else if(row == 8+14){
                if(col == 0 || col == 4 || col == 5){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
            else if(row == 9+14){
                if(col == 3 || col == 6 || col == 9){
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else if(row == 10+14){
                if(col == 0 || col == 7 || col == 8 || col == 13){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
            else if(row == 11+14){
                if(col == 1 || col == 12){
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else{
                if(col==0){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
        }
    }
}

void Game::BottomRight()
{
    int row, col;
    for(row = 14; row < 28; row++){
        for(col = 13; col >= 0; col--){
            if(row == 13+14){
                this->map.at(row).push_back(tiles(*this->window, 2));
            }
            else if(row == 0+14 || row == 1+14 || row == 3+14 || row == 4+14){
                if(col == 6 || col == 9){
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else if(row == 2+14){
                if(col == 6 || col >= 9){
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else if(row == 5+14){
                if(col == 0 || col == 13){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
            else if(row == 6+14 || row == 7+14){
                if(col == 1 || col == 6 || col == 12){
                    if(row == 7+14 && col == 1){
                        this->map.at(row).push_back(tiles(*this->window, 1));
                    }
                    else{
                        this->map.at(row).push_back(tiles(*this->window, 0));
                    }
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else if(row == 8+14){
                if(col == 0 || col == 4 || col == 5){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
            else if(row == 9+14){
                if(col == 3 || col == 6 || col == 9){
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else if(row == 10+14){
                if(col == 0 || col == 7 || col == 8 || col == 13){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
            else if(row == 11+14){
                if(col == 1 || col == 12){
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
            }
            else{
                if(col==0){
                    this->map.at(row).push_back(tiles(*this->window, 2));
                }
                else{
                    this->map.at(row).push_back(tiles(*this->window, 0));
                }
            }
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

void Game::updateText()
{
    std::stringstream ss;

    ss << "Points: " << this->points << "\t"
        << "Lives: " << this->lives << "\n";
    this->uiText.setString(ss.str());
}

void Game::updateDefaultCollision()
{
    for(size_t i = 0; i<this->map.size();i++){
        for(size_t j = 0; j<this->map.at(i).size();j++){
            if(this->map.at(i).at(j).getType() == 0 || this->map.at(i).at(j).getType() == 1){
                if(this->PacMan.getShape().getGlobalBounds().intersects(this->map.at(i).at(j).getCircleShape().getGlobalBounds()) && !this->map.at(i).at(j).getVisited()){
                    this->map.at(i).at(j).setVisited();
                    if(this->map.at(i).at(j).getType() == 0)
                        this->points += 10;
                    else if(this->map.at(i).at(j).getType() == 1)
                        this->points += 50;
                }
            }
            else{
                if(this->PacMan.getShape().getGlobalBounds().intersects(this->map.at(i).at(j).getRectShape().getGlobalBounds())){
                    updateWallCollison(i, j);
                }
            }
        }
    }
}

void Game::updateWallCollison(size_t row, size_t col)
{
    float row_pos = row*24;
    float col_pos = col*24;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        col_pos += 25.f;
        this->PacMan.getShape().setPosition(col_pos+1, this->PacMan.getShape().getPosition().y);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        col_pos -= 19.f;
        this->PacMan.getShape().setPosition(col_pos+1, this->PacMan.getShape().getPosition().y);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        row_pos += 25.f;
        this->PacMan.getShape().setPosition(this->PacMan.getShape().getPosition().x, row_pos+1);
    }
    else{
        row_pos -= 19.f;
        this->PacMan.getShape().setPosition(this->PacMan.getShape().getPosition().x, row_pos+1);
    }
}

void Game::update()
{
    this->pollEvents();
    this->updateText();
    this->PacMan.update(this->window);
    this->Blinky.update();
    this->Bluey.update();
    this->Inky.update();
    this->Clyde.update();

    this->updateDefaultCollision();
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
    this->Blinky.render(*this->window);
    this->Bluey.render(*this->window);
    this->Inky.render(*this->window);
    this->Clyde.render(*this->window);


    this->window->display();
}
