#include "player.hpp"

namespace gio
{
Player::Player()
{
    body_.setPosition({0.f, 0.f});
    body_.setSize({50.f, 100.f});
    body_.setFillColor({255, 0, 0});
}
void Player::OnDraw(sf::RenderWindow& w) { w.draw(body_); }
void Player::OnEvent(sf::Event e) {}

void Player::SetPosition(sf::Vector2f pos) { body_.setPosition(pos); }
sf::Vector2f Player::GetPosition() const { return body_.getPosition(); }

}  // namespace gio