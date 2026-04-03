#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <string_view>

namespace Globals
{
    enum class Direction
    {
        Up,
        Down,
        Left,
        Right,
    };

    namespace Animations
    {
        inline float PLAYER_DURATION { 0.1f };

        sf::Vector2f lerp(const sf::Vector2f& a, const sf::Vector2f& b, float t);
        float easeInOut(float t);
    }

    namespace Colors
    {
        inline const sf::Color BG { 255, 255, 255 };
        inline const sf::Color FG { 0, 0, 0 };
        inline const sf::Color GRID_LINE { 0, 0, 0, 63 };


        inline const sf::Color WALL { 0, 0, 0 };
        inline const sf::Color EMPTY { sf::Color::Transparent };
        inline const sf::Color PLAYER { 0, 0, 255 };
        inline const sf::Color RPLAYER { 255, 0, 0 };
        inline const sf::Color PLAYER_OUTLINE { 0, 0, 0 };
        inline const sf::Color GOAL { 0, 0, 255, 63 };
        inline const sf::Color RGOAL { 255, 0, 0, 63 };
    }

    namespace Game
    {
        inline constexpr int TILE_SIZE { 8 };
        inline constexpr int SIZE_MULTIPLIER { 4 };
        inline constexpr float GRID_CELL_SIZE { TILE_SIZE * SIZE_MULTIPLIER };

        inline constexpr int NUM_LEVELS { 10 };
    }

    namespace Player
    {
        inline constexpr float SIZE_MULTIPLIER { 0.75 };
        inline constexpr float SIZE { Game::TILE_SIZE * Game::SIZE_MULTIPLIER * SIZE_MULTIPLIER };
    }

    namespace Text
    {
        inline constexpr int DEFAULT_SIZE { 30 };
        inline sf::Font DEFAULT_FONT;
        inline sf::Font DEFAULT_FONT_ITALIC;

        void loadFont(sf::Font& font, const std::string& filepath);
    }

    namespace UI
    {
        inline const sf::Vector2f LABEL_SIZE { 150, 50 };
    }

    namespace Window
    {
        inline constexpr int WIDTH { 320 };
        inline constexpr int HEIGHT { 320 };

        void centerText(sf::Text& text);
    }
    inline int test;
}

sf::Vector2f round(const sf::Vector2f& vector);
