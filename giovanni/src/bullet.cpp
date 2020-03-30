#include "bullet.hpp"

namespace gio
{
Bullet::Bullet()
{
    body_.setSize({10.f, 10.f});
    body_.setFillColor({255, 0, 0});
}
void Bullet::OnDraw(sf::RenderWindow& w, float timestep)
{
    auto xPos = body_.getPosition().x;
    auto yPos = body_.getPosition().y;

    float y = 1.1f * y;

    body_.setPosition({xPos += 1000.f * timestep, yPos += 1});

    w.draw(body_);
}
void Bullet::OnEvent(sf::Event e) {}

void Bullet::SetPosition(sf::Vector2f pos) { body_.setPosition(pos); }
sf::Vector2f Bullet::GetPosition() const { return body_.getPosition(); }

}  // namespace gio