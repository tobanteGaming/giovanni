#include "bullet.hpp"
#include <cstdio>

namespace gio
{
Bullet::Bullet(bool right) : right_(right)
{

    body_.setSize({10.f, 10.f});
    body_.setFillColor({255, 0, 0});
}

void Bullet::OnDraw(sf::RenderWindow& w, float timestep)
{
    auto xPos = body_.getPosition().x;
    auto yPos = body_.getPosition().y;

    position += timestep * (velocity + timestep * acceleration / 2);
    velocity += timestep * acceleration;

    auto const x = (right_ ? 1000.f : -1000.f) * timestep;

    body_.setPosition({xPos += x, yPos + position});

    w.draw(body_);
}
void Bullet::OnEvent(sf::Event e) {}

void Bullet::SetPosition(sf::Vector2f pos) { body_.setPosition(pos); }
sf::Vector2f Bullet::GetPosition() const { return body_.getPosition(); }

}  // namespace gio
