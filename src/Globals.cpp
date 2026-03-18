#include "Globals.hpp"
#include <cmath>

sf::Vector2f round(const sf::Vector2f& vector)
{
    return sf::Vector2f{ std::round(vector.x), std::round(vector.y) };
}

sf::Vector2f coordToVector2f(int x, int y)
{
    return sf::Vector2f((static_cast<float>(x) + 0.5f) * Globals::Game::GRID_CELL_SIZE, (static_cast<float>(y) + 0.5f) * Globals::Game::GRID_CELL_SIZE);
}

sf::Vector2f coordToVector2f(const sf::Vector2u& coords)
{
    return coordToVector2f(static_cast<int>(coords.x), static_cast<int>(coords.y));
}

sf::Vector2f coordToVector2f(const sf::Vector2i& coords)
{
    return coordToVector2f(coords.x, coords.y);
}

sf::Vector2i Vector2fToCoord(const sf::Vector2f& pos)
{
    int x { static_cast<int>(std::round(pos.x / Globals::Game::GRID_CELL_SIZE - 0.5f)) };
    int y { static_cast<int>(std::round(pos.y / Globals::Game::GRID_CELL_SIZE - 0.5f)) };
    return sf::Vector2i(x, y);
}

bool outOfBounds(const sf::Vector2f& pos)
{
    return (pos.x < 0 || pos.x >= Globals::Window::WIDTH || pos.y < 0 || pos.y >= Globals::Window::HEIGHT);
}

bool outOfBounds(const sf::Vector2i& pos)
{
    return (pos.x < 0 || pos.x > Globals::Window::X_MAX || pos.y < 0 || pos.y > Globals::Window::Y_MAX);
}
bool outOfBounds(const sf::Vector2u& pos)
{
    return outOfBounds(static_cast<sf::Vector2i>(pos));
}

// void centerText(sf::Text& text)
// {
//     auto textCenter { text.getGlobalBounds().getSize() / 2.f };
//     auto localBounds { textCenter + text.getLocalBounds().getPosition() };
//     auto rounded { round(localBounds) };
//     text.setOrigin(rounded);
// }
