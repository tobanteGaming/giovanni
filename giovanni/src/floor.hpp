#pragma once

#include "SFML/Graphics.hpp"

namespace gio
{
class Floor
{
public:
    void SetSize(int width, int height)
    {
        floor_.setPosition({0.f, height * 0.95f});
        floor_.setSize({static_cast<float>(width), height * 0.05f});
        floor_.setFillColor({129, 59, 10});
    }

    sf::RectangleShape& GetShape() { return floor_; }

private:
    sf::RectangleShape floor_ {{100.f, 100.f}};
};

}  // namespace gio