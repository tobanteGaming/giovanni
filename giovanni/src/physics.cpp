#include "physics.hpp"

namespace gio
{
Physics::Physics(Player& p, std::vector<Floor>& o) : player_(p), objects_(o) {}

void Physics::OnSetup(int width, int height)
{
    auto floor = Floor {};
    floor.SetSize(width, height);
    objects_.push_back(floor);

    auto object = Floor {};
    object.SetSize(width / 3.f, height * 0.8f);
    objects_.push_back(object);
}

void Physics::OnUpdate(float timestep)
{

    // Gravity
    for (auto& o : objects_)
    {

        if (player_.GetStatus() == Player::Status::Jumping || player_.GetStatus() == Player::Status::Falling)
        {
            position += timestep * (velocity + timestep * acceleration / 2);
            velocity += timestep * acceleration;

            if (o.IsInXRange(player_.GetShape()))
            {
                if (player_.GetPosition().y + 100 > o.GetShape().getPosition().y)
                {
                    player_.SetStatus(Player::Status::Standing);
                }
            }

            printf("Vel: %f \n", velocity);
            printf("Acc: %f \n \n", acceleration);
        }
        else
        {
            position = o.GetShape().getPosition().y - 100;
            velocity = 0.f;
            player_.SetStatus(Player::Status::Standing);
        }
    }

    player_.SetPosition({player_.GetPosition().x, position});

    // Shoot

    auto& bullets = player_.GetBullets();

    for (auto& o : objects_)
    {

        auto const index = std::find_if(bullets.begin(), bullets.end(), [f = o](Bullet const& b) mutable {
            return !(b.GetPosition().y >= f.GetShape().getSize().y);
        });

        if (index != bullets.end())
        {
            bullets.erase(index);
        }
    }
}
void Physics::OnEvent(sf::Event e)
{

    // Jump

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && (velocity == 0.f))
    {
        printf("Sprung\n");
        velocity = -1000.f;
        player_.SetStatus(Player::Status::Jumping);
    }
}

}  // namespace gio
