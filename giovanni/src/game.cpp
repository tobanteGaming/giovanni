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

    window_.setFramerateLimit(30);
}

std::string Game::GetName() const { return name_; }

void Game::OnSetup() { physics_.OnSetup(window_.getSize().x, window_.getSize().y); }

void Game::OnFrame()
{
    auto const currentTime = clock_.getElapsedTime().asSeconds();
    auto const timestep    = currentTime - lastFrameTime_;
    lastFrameTime_         = currentTime;

    physics_.OnUpdate(timestep);

    sf::Text fps;
    fps.setFont(font_);  // font is a sf::Font
    fps.setString(std::to_string(static_cast<int>(timestep * 1000)));
    fps.setCharacterSize(24);  // in pixels, not points!
    fps.setFillColor(sf::Color::Red);
    fps.setStyle(sf::Text::Bold | sf::Text::Underlined);
    fps.setPosition({500.f, 0.f});
    window_.draw(fps);

    window_.draw(physics_.GetFloor());
    player_.OnDraw(window_, timestep);
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