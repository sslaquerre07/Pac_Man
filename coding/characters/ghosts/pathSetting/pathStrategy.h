#ifndef PATHSTRATEGY_H
#define PATHSTRATEGY_H
#include <SFML/Graphics.hpp>
#include <chrono>

//Interface that implements Strategy pattern for ghost movement
class PathStrategy{
    protected:
        std::chrono::time_point<std::chrono::steady_clock> start_time;

    public:
        virtual void setPath(const sf::Shape& src, const sf::Shape& dest) = 0;
        void start();
        void check_timer(int seconds, const sf::Shape& src, const sf::Shape& dest);
};

#endif