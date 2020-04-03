#pragma once

#include "bullet.hpp"

#include "SFML/Graphics.hpp"

namespace gio
{
class Player
{
public:
    enum class Status
    {
        Standing,
        Jumping,
        Falling
    };

    Player();
    void OnDraw(sf::RenderWindow& w, float timestep);
    void OnEvent(sf::Event e);

    void SetPosition(sf::Vector2f);
    sf::Vector2f GetPosition() const;

    void SetStatus(Status s) { status = s; }
    Status GetStatus() const noexcept { return status; }

    std::vector<Bullet>& GetBullets() { return activeBullets; }

private:
    sf::RectangleShape body_ {};
    std::vector<Bullet> activeBullets {};
    Status status {Status::Falling};

    bool lookRight = true;
};

}  // namespace gio
