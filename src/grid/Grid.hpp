#pragma once

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
            BorderT,
            BorderB,
            BorderL,
            BorderR,
            BorderTL,
            BorderTR,
            BorderBL,
            BorderBR
        };
        inline bool isWall(Tile tile) { return tile == Tile::Wall; }
        void setTileColor(sf::RectangleShape& sprite, Tile tile);
        void setTileTexture(sf::RectangleShape& sprite, Tile tile);
    }

    class Grid
    {
    public:
        Grid() = default;
        Grid(int width, int height, const std::vector<std::vector<Tile::Tile>>& tiles);
        void draw(sf::RenderWindow& window);
        void setTile(int x, int y, Tile::Tile tile) { m_tiles.at(x).at(y) = tile; }
        void setTile(const Vector2i& pos, Tile::Tile tile) { setTile(pos.x, pos.y, tile); }

        int getWidth() const { return m_width; }
        int getHeight() const { return m_height; }

        bool isTile(int x, int y, Tile::Tile tile) const { return m_tiles.at(x).at(y) == tile; }
        bool isTile(const Vector2i& pos, Tile::Tile tile) const { return isTile(pos.x, pos.y, tile); }
        bool isWall(int x, int y) const { return Tile::isWall(m_tiles.at(x).at(y)); }
        bool isWall(const Vector2i& pos) const { return isWall(pos.x, pos.y); }
        bool inBounds(int x, int y) const { return (x > 0 && x < m_width - 1 && y > 0 && y < m_height - 1); }
        bool inBounds(const Vector2i& pos) const { return inBounds(pos.x, pos.y); }

        Vector2f coordsToVector2f(int x, int y) const;
        Vector2f coordsToVector2f(const Vector2i& pos) const { return coordsToVector2f(pos.x, pos.y); }

    private:
        int m_width;
        int m_height;

        sf::RectangleShape m_sprite;
        std::vector<std::vector<Tile::Tile>> m_tiles;
    };
}
