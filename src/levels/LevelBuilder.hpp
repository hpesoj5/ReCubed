#pragma once

#include "grid/Grid.hpp"
#include <SFML/System/Vector2.hpp>
#include <vector>

using sf::Vector2i;

namespace Levels
{
    struct LevelData
    {
        int width;
        int height;
        std::vector<std::vector<Grid::Tile::Tile>> tiles;

        Vector2i playerStart;
        Vector2i rPlayerStart;
        Vector2i playerGoal;
        Vector2i rPlayerGoal;
    };

    class LevelBuilder
    {
    public:
        LevelBuilder& setDimensions(int width, int height);
        LevelBuilder& setTile(int x, int y, Grid::Tile::Tile tile);
        LevelBuilder& setTile(const Vector2i& pos, Grid::Tile::Tile tile) { return setTile(pos.x, pos.y, tile); }
        LevelBuilder& setPlayerStart(int x, int y) { return setPlayerStart(Vector2i(x, y)); }
        LevelBuilder& setPlayerStart(const Vector2i& pos) { m_data.playerStart = pos; return *this; }
        LevelBuilder& setRPlayerStart(int x, int y) { return setRPlayerStart(Vector2i(x, y)); }
        LevelBuilder& setRPlayerStart(const Vector2i& pos) { m_data.rPlayerStart = pos; return *this; }
        LevelBuilder& setPlayerGoal(int x, int y) { return setPlayerGoal(Vector2i(x, y)); }
        LevelBuilder& setPlayerGoal(const Vector2i& pos) { m_data.playerGoal = pos; return *this; }
        LevelBuilder& setRPlayerGoal(int x, int y) { return setRPlayerGoal(Vector2i(x, y)); }
        LevelBuilder& setRPlayerGoal(const Vector2i& pos) { m_data.rPlayerGoal = pos; return *this; }
        LevelData build() { return m_data; }

    private:
        LevelData m_data;
    };
}
