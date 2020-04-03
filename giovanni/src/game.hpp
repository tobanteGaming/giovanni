#pragma once

#include "bullet.hpp"
#include "floor.hpp"
#include "physics.hpp"
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
    sf::Font font_;

    sf::RenderWindow& window_;

    gio::Player player_ {};
    std::vector<Floor> objects_ {};
    gio::Physics physics_ {player_, objects_};

    sf::Clock clock_ {};
    float lastFrameTime_ {};
};
}  // namespace gio