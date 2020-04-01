#include "physics.hpp"

namespace gio
{
Physics::Physics(Player& p, Floor& f) : player_(p), floor_(f) {}

void Physics::OnSetup(int width, int height) { floor_.SetSize(width, height); }

void Physics::OnUpdate(float timestep)
{

    // Gravity

    if ((player_.GetPosition().y + 100 < floor_.GetShape().getPosition().y) && (jumpCount == 0))
    {
        position += timestep * (velocity + timestep * acceleration / 2);
        velocity += timestep * acceleration;

        printf("Vel: %f \n", velocity);
        printf("Acc: %f \n \n", acceleration);
    }
    else if (jumpCount == 0)
    {
        position = floor_.GetShape().getPosition().y - 100;
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

    auto const index = std::find_if(bullets.begin(), bullets.end(), [f = floor_](Bullet const& b) mutable {
        return !(b.GetPosition().y >= f.GetShape().getSize().y);
    });

    if (index != bullets.end())
    {
        bullets.erase(index);
    }
}
void Physics::OnEvent(sf::Event e)
{

    // Jump
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        && (player_.GetPosition().y + 100 == floor_.GetShape().getPosition().y))
    {
        printf("Sprung\n");
        jumpCount = 10;
        velocity  = 2000.f;
    }
}

}  // namespace gio