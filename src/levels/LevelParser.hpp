#pragma once

#include "LevelBuilder.hpp"
#include "grid/Grid.hpp"
#include <string>

namespace Levels
{
    class LevelData;

    class LevelParser
    {
    public:
        static LevelData parse(const std::string& filepath);

    private:
        static Grid::Tile::Tile charToTile(char c);
    };
}
