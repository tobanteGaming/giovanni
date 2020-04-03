#pragma once

#include "floor.hpp"
#include "player.hpp"

#include "SFML/Graphics.hpp"

namespace gio
{
class Physics
{
public:
    Physics(Player& p, std::vector<Floor>& o);

    void OnSetup(int width, int height);
    void OnUpdate(float timestep);
    void OnEvent(sf::Event e);

private:
    float acceleration {3000.f};
    float position {};
    float velocity {};

    Player& player_;

    std::vector<Floor>& objects_;
};
}  // namespace gio
