#include "LevelBuilder.hpp"

namespace Levels
{
    LevelBuilder& LevelBuilder::setDimensions(int width, int height)
    {
        m_data.width = width;
        m_data.height = height;
        m_data.tiles = std::vector<std::vector<Grid::Tile::Tile>>(width, std::vector<Grid::Tile::Tile>(height));
        return *this;
    }

    LevelBuilder& LevelBuilder::setTile(int x, int y, Grid::Tile::Tile tile)
    {
        m_data.tiles.at(x).at(y) = tile;
        return *this;
    }
}
