#ifndef TILES_H
#define TILES_H

#include <SFML/Graphics.hpp>

enum TileTypes {POINTS = 0, SUPER, WALL, NROFTYPEs};

class tiles{
    public:
        //Constructors and Destructor
        tiles();
        tiles(const sf::RenderWindow& window, int type);
        ~tiles();

        //Getter and Setters
        const int& getType() const;

        //Functions
        void update();
        void render(sf::RenderTarget& target, int& row, int&col);


    private:
        int type;
        bool visited;

        //Two possible shapes
        sf::CircleShape circle;
        sf::RectangleShape rect;

        //private Functions
        void initShape(const sf::RenderWindow& window);

};






#endif