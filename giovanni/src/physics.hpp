#pragma once

#include "player.hpp"

#include "SFML/Graphics.hpp"

namespace gio
{
class Physics
{
public:
    Physics(Player& p);

    void OnSetup(int width, int height);
    void OnUpdate(float timestep);
    void OnEvent(sf::Event e);

    sf::RectangleShape const& GetFloor() const { return floor_; }

private:
    float acceleration {10.f};
    float position {};
    float mass {1.f};
    float velocity {};

    Player& player_;

    sf::RectangleShape floor_ {{100.f, 100.f}};
};
}  // namespace gio