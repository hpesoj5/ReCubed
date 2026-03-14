#pragma once

#include <SFML/Graphics.hpp>

namespace Globals
{
    namespace Game
    {
        inline constexpr unsigned int TILE_SIZE { 8 };
    }

    namespace Player
    {
        inline constexpr unsigned int SIZE { Game::TILE_SIZE * 4 };
        inline const sf::Color COLOR(0, 0, 255);
        inline const sf::Color REVERSE_COLOR(255, 0, 0);
    }

    namespace Text
    {
        inline constexpr unsigned int DEFAULT_SIZE { 30 };
        inline sf::Font DEFAULT_FONT;
    }

    namespace Window
    {
        inline constexpr unsigned int WIDTH { 400 };
        inline constexpr unsigned int HEIGHT { 400 };
        inline const sf::Color BG_COLOR(255, 255, 255);
        inline const sf::Color FG_COLOR(0, 0, 0);
    }
}

sf::Vector2f round(const sf::Vector2f& vector);

void centerText(sf::Text& text);
