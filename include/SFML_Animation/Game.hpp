#ifndef INCLUDE_GAME_HPP
#define INCLUDE_GAME_HPP

#include <SFML/Graphics.hpp>

// should be singleton
class Game
{
public:
    Game() = default;
    ~Game() = default;
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    void run();
};

#endif