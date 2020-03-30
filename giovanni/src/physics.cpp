#include "physics.hpp"

namespace gio
{
Physics::Physics(Player& p) : player_(p) {}

void Physics::OnSetup(int width, int height)
{
    auto const shapeWidth  = floor_.getSize().x;
    auto const shapeHeight = floor_.getSize().y;

    floor_.setPosition({0.f, height * 0.95f});
    floor_.setSize({static_cast<float>(width), height * 0.05f});
    floor_.setFillColor({129, 59, 10});
}

void Physics::OnUpdate(float timestep)
{

    if (player_.GetPosition().y + 100 < floor_.getPosition().y)
    {
        position += timestep * (velocity + timestep * acceleration / 2);
        velocity += timestep * acceleration;
    }
    else
    {
        position = floor_.getPosition().y - 100;
    }

    player_.SetPosition({player_.GetPosition().x, position});
}
void Physics::OnEvent(sf::Event e) {}

}  // namespace gio