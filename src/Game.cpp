#include <iostream>
#include <SFML/Graphics.hpp>

#include "cppProjectTemplate/Game.hpp"
#include "cppProjectTemplate/Animation.hpp"

void Game::run()
{
    sf::RenderWindow window{ sf::VideoMode{ 512, 512 }, "Bouncing Ball", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize };


    // creating a texture
    sf::Texture playerTexture;
    playerTexture.loadFromFile("../assets/flame-spritesheet-nobackground.png");   // note the path; I haven't used .. to go up a folder, which is weird... Maybe it is from the folder where you're actually compiling your code from, and not where the cpp file is present. 

    // instantiating an Animation object
    // 4, 1 is the information for the flame spritesheet i'm using
    Animation animation{ &playerTexture, sf::Vector2u{4, 1}, 0.2f };

    // creating a player
    sf::RectangleShape player{ sf::Vector2f{ 100.f, 125.f } };
    player.setPosition(206.f, 206.f);
    player.setTexture(&playerTexture);

    float deltaTime{ 0.f };
    sf::Clock clock;
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                std::cout << "Program closed.\n";
                window.close();
                break;
            default:
                break;
            }
        }

        animation.update(0, deltaTime);
        player.setTextureRect(animation.m_uvRect);

        window.clear();
        window.draw(player);
        window.display();
    }
}
