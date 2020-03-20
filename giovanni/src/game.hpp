#pragma once

#include "player.hpp"

#include "SFML/Graphics.hpp"

#include <string>

namespace gio
{
class Game
{
public:
    Game(std::string n, sf::RenderWindow& w);
    std::string GetName() const;

    void OnSetup();
    void OnFrame();
    void OnEvent(sf::Event e);

private:
    std::string name_;
    sf::RenderWindow& window_;
    sf::RectangleShape floor_ {{100.f, 100.f}};
    gio::Player player_ {};
    sf::Clock clock_ {};
    float lastFrameTime_ {};

    float acceleration {10.f};
    float position {};
    float mass {1.f};
    float velocity {};
};
}  // namespace gio