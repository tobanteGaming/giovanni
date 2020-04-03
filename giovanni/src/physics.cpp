#include "physics.hpp"

namespace gio
{
Physics::Physics(Player& p, std::vector<Floor>& o) : player_(p), objects_(o) {}

void Physics::OnSetup(int width, int height)
{
    auto floor = Floor {};
    floor.SetSize(width, height);
    objects_.push_back(floor);
}

void Physics::OnUpdate(float timestep)
{

    // Gravity
    for (auto& o : objects_)
    {

        if ((player_.GetPosition().y + 100 < o.GetShape().getPosition().y) && (jumpCount == 0))
        {
            position += timestep * (velocity + timestep * acceleration / 2);
            velocity += timestep * acceleration;

            printf("Vel: %f \n", velocity);
            printf("Acc: %f \n \n", acceleration);
        }
        else if (jumpCount == 0)
        {
            position = o.GetShape().getPosition().y - 100;
        }
    }

    // Jump

    if (jumpCount > 0)
    {
        position -= timestep * (velocity + timestep * acceleration / 2);
        velocity -= timestep * acceleration * 20.f;

        printf("Vel: %f \n", velocity);
        printf("Acc: %f \n \n", acceleration);

        jumpCount--;
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
    for (auto& o : objects_)
    {
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            && (player_.GetPosition().y + 100 == o.GetShape().getPosition().y))
        {
            printf("Sprung\n");
            jumpCount = 10;
            velocity  = 2000.f;
        }
    }
}

}  // namespace gio