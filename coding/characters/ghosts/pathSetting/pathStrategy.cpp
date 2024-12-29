#include "pathStrategy.h"

//Starts the timer every x seconds
void PathStrategy::start(){
    start_time = std::chrono::steady_clock::now();
}

//Runs the setPath function if a certain number of seconds has passed, varied based on the ghost
void PathStrategy::check_timer(int seconds, const sf::Shape& src, const sf::Shape& dest){
    auto current_time = std::chrono::steady_clock::now();
    if(std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count() > seconds){
        setPath(src, dest);
        start();
    }
    //If condition not met, then the algorithm will not run
}