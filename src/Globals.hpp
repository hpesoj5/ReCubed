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
    };

    namespace Window
    {
        inline constexpr int WIDTH { 400 };
        inline constexpr int HEIGHT { 400 };

        void centerText(sf::Text& text);
    }

    namespace Animations
    {
        extern float PLAYER_DURATION;

        sf::Vector2f lerp(const sf::Vector2f& a, const sf::Vector2f& b, float t);
        float easeInOut(float t);
    }

    namespace LevelButtons
    {
        inline constexpr int NUM_COLUMNS { 4 };
        inline constexpr float SIZE_1D { 40.f };
        inline constexpr float GAP_1D { 20.f };
        inline constexpr float TOTAL_WIDTH { SIZE_1D * NUM_COLUMNS + GAP_1D * (NUM_COLUMNS - 1) };
        extern const sf::Vector2f SIZE;
        extern const sf::Vector2f GAP;
        extern const sf::Vector2f TOP_LEFT_POS;
    }

    namespace Colors
    {
        extern const sf::Color BG;
        extern const sf::Color FG;
        extern const sf::Color GRID_LINE;

        extern const sf::Color WALL;
        extern const sf::Color EMPTY;
        extern const sf::Color PLAYER;
        extern const sf::Color RPLAYER;
        extern const sf::Color PLAYER_OUTLINE;
        extern const sf::Color GOAL;
        extern const sf::Color RGOAL;
    }

    namespace Game
    {
        inline constexpr int TILE_SIZE { 8 };
        inline constexpr int SIZE_MULTIPLIER { 4 };
        inline constexpr float GRID_CELL_SIZE { TILE_SIZE * SIZE_MULTIPLIER };

        inline constexpr int NUM_LEVELS { 10 };

        inline int highestLevel {};
    }

    namespace Player
    {
        inline constexpr float SIZE_MULTIPLIER { 0.75f };
        inline constexpr float SIZE { Game::TILE_SIZE * Game::SIZE_MULTIPLIER * SIZE_MULTIPLIER };
    }

    namespace Text
    {
        inline constexpr int DEFAULT_SIZE { 30 };
        inline constexpr int TITLE_SIZE { 50 };

        extern sf::Font DEFAULT_FONT;
        extern sf::Font DEFAULT_FONT_ITALIC;

        void loadFont(sf::Font& font, const std::string& filepath);
        void loadFonts();
    }

    namespace Texture
    {
        extern sf::Texture ATLAS;
        void loadTexture();
    }

    namespace UI
    {
        extern const sf::Vector2f TITLE_POSITION;
        extern const sf::Vector2f LABEL_SIZE;
        inline constexpr float BUTTON_VERTICAL_GAP { 80 };
        inline constexpr float BUTTON_TOP_YPOS { Window::HEIGHT - 225.f };
    }
}

sf::Vector2f round(const sf::Vector2f& vector);
