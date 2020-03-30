#include "player.hpp"

#include <algorithm>
#include <numeric>

namespace gio
{
Player::Player()
{
    body_.setPosition({0.f, 0.f});
    body_.setSize({50.f, 100.f});
    body_.setFillColor({255, 0, 0});
}
void Player::OnDraw(sf::RenderWindow& w)
{

    for (auto& b : activeBullets)
    {
        b.OnDraw(w);
    }
    //      auto it = std::remove(c.begin(), c.end(), value);
    // auto r = std::distance(it, c.end());
    // c.erase(it, c.end());
    // return r;

    auto const index = std::find_if(activeBullets.begin(), activeBullets.end(),
                                    [&w](Bullet const& b) { return b.GetPosition().x > w.getSize().x; });

    if (index != activeBullets.end())
    {
        activeBullets.erase(index);
    }

    w.draw(body_);
}
void Player::OnEvent(sf::Event e)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        auto bullet = Bullet();
        bullet.SetPosition(GetPosition());
        printf("geschossen\n");

        activeBullets.push_back(bullet);
    }
}

void Player::SetPosition(sf::Vector2f pos) { body_.setPosition(pos); }
sf::Vector2f Player::GetPosition() const { return body_.getPosition(); }

}  // namespace gio