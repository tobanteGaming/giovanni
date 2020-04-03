#pragma once

#include "SFML/Graphics.hpp"

#include <cstdio>

namespace gio
{
class Bullet
{
public:
    Bullet(bool right);
    void OnDraw(sf::RenderWindow& w, float timestep);
    void OnEvent(sf::Event e);

    void SetPosition(sf::Vector2f);
    sf::Vector2f GetPosition() const;

private:
    sf::RectangleShape body_ {};

    float acceleration {50.f};
    float position {};
    float velocity {};

    bool right_ = true;
};

}  // namespace gio
