#pragma once

#include "SFML/Graphics.hpp"

namespace gio
{
class Player
{
public:
    Player();
    void OnDraw(sf::RenderWindow& w);
    void OnEvent(sf::Event e);

private:
    sf::RectangleShape body_ {};
};

}  // namespace gio
