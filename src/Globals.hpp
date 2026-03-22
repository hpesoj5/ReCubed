#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

namespace Globals
{
    enum class Direction
    {
        Up,
        Down,
        Left,
        Right,
        NUM_DIRECTIONS,
    };

    namespace Game
    {
        inline constexpr int TILE_SIZE { 8 };
        inline constexpr int SIZE_MULTIPLIER { 4 };
        inline constexpr float GRID_CELL_SIZE { TILE_SIZE * SIZE_MULTIPLIER };
    }

    namespace Player
    {
        inline constexpr float SIZE_MULTIPLIER { 0.75 };
        inline constexpr float SIZE { Game::TILE_SIZE * Game::SIZE_MULTIPLIER * SIZE_MULTIPLIER };
        inline const sf::Color COLOR(0, 0, 255);
        inline const sf::Color REVERSE_COLOR(255, 0, 0);
    }

    namespace Text
    {
        inline constexpr int DEFAULT_SIZE { 30 };
        inline sf::Font DEFAULT_FONT;
    }

    namespace Window
    {
        inline constexpr int WIDTH { 320 };
        inline constexpr int HEIGHT { 320 };


        inline const sf::Color BG_COLOR(255, 255, 255);
        inline const sf::Color FG_COLOR(0, 0, 0);
    }
}

sf::Vector2f round(const sf::Vector2f& vector);

// void centerText(sf::Text& text);
