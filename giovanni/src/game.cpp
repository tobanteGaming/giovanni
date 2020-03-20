#include "game.hpp"

namespace gio
{
Game::Game(std::string n, sf::RenderWindow& w) : name_(n), window_(w) {}
std::string Game::GetName() const { return name_; }
void Game::OnSetup() {}
void Game::OnFrame() { window_.draw(shape_); }
void Game::OnEvent(sf::Event e)
{
    if (e.type == sf::Event::Closed) window_.close();
}
}  // namespace gio