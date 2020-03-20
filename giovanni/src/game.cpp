#include "game.hpp"
#include <iostream>

namespace gio
{
Game::Game(std::string n, sf::RenderWindow& w) : name_(n), window_(w) {}
std::string Game::GetName() const { return name_; }
void Game::OnSetup()
{
    auto const width  = window_.getSize().x;
    auto const height = window_.getSize().y;

    auto const shapeWidth  = shape_.getSize().x;
    auto const shapeHeight = shape_.getSize().y;

    shape_.setPosition({0.f, height * 0.95f});
    shape_.setSize({static_cast<float>(width), height * 0.05f});
    shape_.setFillColor({129, 59, 10});
}
void Game::OnFrame() { window_.draw(shape_); }
void Game::OnEvent(sf::Event e)
{
    if (e.type == sf::Event::Closed) window_.close();
    if (e.type == sf::Event::Resized)
    {
        std::cout << "resized: " << e.size.width << " " << e.size.height << '\n';
    }
}
}  // namespace gio