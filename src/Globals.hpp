#pragma once

#include <SFML/Graphics.hpp>

namespace Globals
{
    inline constexpr unsigned int TILE_SIZE { 8 };
    inline constexpr unsigned int WINDOW_WIDTH { 400 };
    inline constexpr unsigned int WINDOW_HEIGHT { 400 };

    inline constexpr unsigned int DEFAULT_TEXT_SIZE { 30 };

    inline sf::Font DEFAULT_FONT;

    inline const sf::Color DEFAULT_BG_COLOR(255, 255, 255);
    inline const sf::Color DEFAULT_FG_COLOR(0, 0, 0);

    inline constexpr unsigned int PLAYER_SIZE { TILE_SIZE * 4 };
    inline const sf::Color PLAYER_COLOR(0, 0, 255);
    inline const sf::Color REVERSE_PLAYER_COLOR(255, 0, 0);
}

sf::Vector2f round(const sf::Vector2f& vector);

void centerText(sf::Text& text);
