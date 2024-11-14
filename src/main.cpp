#include <iostream>
#include <SFML/Graphics.hpp>

#include "SFML_Animation/Game.hpp"

int main()
{
    Game game;
    game.run();

    // ~Game() called to close everything.

    return 0;
}
