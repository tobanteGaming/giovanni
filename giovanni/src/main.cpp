#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "game.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Giovanni");
    auto game = gio::Game {"Giovanni", window};
    game.OnSetup();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) { game.OnEvent(event); }
        window.clear({25, 25, 25});
        game.OnFrame();
        window.display();
    }
    return EXIT_SUCCESS;
}