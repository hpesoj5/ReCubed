#pragma once

#include <Globals.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

using sf::Vector2f;
using sf::Vector2i;

namespace Grid
{
    namespace Tile
    {
        enum class Tile
        {
            Empty,
            Wall,
            Goal,
            RGoal,

            NUM_TILES,
        };
        inline bool isWall(Tile tile) { return tile == Tile::Wall; }
        void setTileColor(sf::RectangleShape& sprite, Tile tile);
        void setTileTexture(sf::RectangleShape& sprite, Tile tile);
    }

    class Grid
    {
    public:
        Grid(int width, int height);
        void draw(sf::RenderWindow& window);

        int getWidth() const { return m_width; }
        int getHeight() const { return m_height; }

        bool inBounds(int x, int y) const { return (x >= 0 && x < m_width && y >= 0 && y < m_height); }
        bool inBounds(const sf::Vector2i& pos) const { return inBounds(pos.x, pos.y); }

        Vector2f coordsToVector2f(int x, int y) const;
        Vector2f coordsToVector2f(const Vector2i& pos) const { return coordsToVector2f(pos.x, pos.y); }

    private:
        int m_width;
        int m_height;

        sf::RectangleShape m_sprite;
        std::vector<std::vector<Tile::Tile>> m_tiles;
    };
}
