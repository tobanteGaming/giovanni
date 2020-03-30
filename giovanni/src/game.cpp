#include "game.hpp"
#include <iostream>

namespace gio
{
Game::Game(std::string n, sf::RenderWindow& w) : name_(n), window_(w)
{
    if (!font_.loadFromFile("assets/kremlin.ttf"))
    {
        std::cout << "error loading font\n";
    }

    window_.setFramerateLimit(60);
}

std::string Game::GetName() const { return name_; }

void Game::OnSetup()
{
    auto const width  = window_.getSize().x;
    auto const height = window_.getSize().y;

    auto const shapeWidth  = floor_.getSize().x;
    auto const shapeHeight = floor_.getSize().y;

    floor_.setPosition({0.f, height * 0.95f});
    floor_.setSize({static_cast<float>(width), height * 0.05f});
    floor_.setFillColor({129, 59, 10});
}

void Game::OnFrame()
{
    auto const currentTime = clock_.getElapsedTime().asSeconds();
    auto const timestep    = currentTime - lastFrameTime_;
    lastFrameTime_         = currentTime;

    sf::Text fps;
    fps.setFont(font_);  // font is a sf::Font
    fps.setString(std::to_string(static_cast<int>(timestep * 1000)));
    fps.setCharacterSize(24);  // in pixels, not points!
    fps.setFillColor(sf::Color::Red);
    fps.setStyle(sf::Text::Bold | sf::Text::Underlined);
    fps.setPosition({500.f, 0.f});
    window_.draw(fps);

    if (player_.GetPosition().y + 100 < floor_.getPosition().y)
    {
        position += timestep * (velocity + timestep * acceleration / 2);
        velocity += timestep * acceleration;
    }
    else
    {
        position = floor_.getPosition().y - 100;
    }

    player_.SetPosition({player_.GetPosition().x, position});

    window_.draw(floor_);
    player_.OnDraw(window_, timestep);
    // std::cout << player_.GetPosition().x << " " << player_.GetPosition().y << std::endl;
}

void Game::OnEvent(sf::Event e)
{
    if (e.type == sf::Event::Closed) window_.close();
    if (e.type == sf::Event::Resized)
    {
        std::cout << "resized: " << e.size.width << " " << e.size.height << '\n';
    }
    player_.OnEvent(e);
}
}  // namespace gio