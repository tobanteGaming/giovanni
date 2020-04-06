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
    void SetName(std::string n){name = n;}
    std::string GetName() const {return name;}

    bool IsInXRange(sf::RectangleShape const& obj) const
    {

        if (obj.getPosition().x < floor_.getPosition().x + floor_.getSize().x)
        {
            if (obj.getPosition().x + obj.getSize().x > floor_.getPosition().x)
            {
                return true;
            }
        }

        return false;
    }

private:
    sf::RectangleShape floor_ {{100.f, 100.f}};
    std::string name{};
};

}  // namespace gio
