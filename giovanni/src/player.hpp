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

    void SetPosition(sf::Vector2f);
    sf::Vector2f GetPosition() const;

private:
    sf::RectangleShape body_ {};
};

}  // namespace gio
