#pragma once

#include "SFML/Graphics.hpp"

namespace gio
{
class Bullet
{
public:
    Bullet();
    void OnDraw(sf::RenderWindow& w, float timestep);
    void OnEvent(sf::Event e);

    void SetPosition(sf::Vector2f);
    sf::Vector2f GetPosition() const;

private:
    sf::RectangleShape body_ {};

    float acceleration {50.f};
    float position {};
    float mass {2.f};
    float velocity {};
};

}  // namespace gio
