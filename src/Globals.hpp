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
        inline constexpr unsigned int TILE_SIZE { 8 };
        inline constexpr unsigned int SIZE_MULTIPLIER { 4 };
        inline constexpr float GRID_CELL_SIZE { TILE_SIZE * SIZE_MULTIPLIER };
    }

    namespace Player
    {
        inline constexpr float SIZE_MULTIPLIER { 0.8 };
        inline constexpr float SIZE { Game::TILE_SIZE * Game::SIZE_MULTIPLIER * SIZE_MULTIPLIER };
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
        inline constexpr unsigned int WIDTH { 320 };
        inline constexpr unsigned int HEIGHT { 320 };

        inline constexpr int X_MAX { WIDTH / Game::TILE_SIZE / Game::SIZE_MULTIPLIER - 1 };
        inline constexpr int Y_MAX { HEIGHT / Game::TILE_SIZE / Game::SIZE_MULTIPLIER - 1 };

        inline const sf::Color BG_COLOR(255, 255, 255);
        inline const sf::Color FG_COLOR(0, 0, 0);
    }
}

sf::Vector2f round(const sf::Vector2f& vector);
sf::Vector2f coordToVector2f(int x, int y);
sf::Vector2f coordToVector2f(const sf::Vector2u& coords);
sf::Vector2f coordToVector2f(const sf::Vector2i& coords);
sf::Vector2i Vector2fToCoord(const sf::Vector2f& pos);

bool outOfBounds(const sf::Vector2f& pos);
bool outOfBounds(const sf::Vector2i& pos);
bool outOfBounds(const sf::Vector2u& pos);

// void centerText(sf::Text& text);
