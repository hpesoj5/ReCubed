#include "LevelParser.hpp"
#include <fstream>
#include <stdexcept>

namespace Levels
{
    LevelData LevelParser::parse(const std::string& filepath)
    {
        std::ifstream file(filepath);
        std::string line;
        std::vector<std::string> lines;

        while (std::getline(file >> std::ws, line))
            lines.push_back(line);

        int height { static_cast<int>(lines.size()) };
        int width { static_cast<int>(lines[0].size()) };

        LevelBuilder builder;
        builder.setDimensions(width, height);

        for (int y {}; y < height; ++y)
        {
            for (int x {}; x < width; ++x)
            {
                Grid::Tile::Tile tile { charToTile(lines[y][x]) };
                if (tile != Grid::Tile::Tile::Empty)
                    builder.setTile(x, y, tile);

                switch (tile)
                {
                case Grid::Tile::Tile::Start:
                    builder.setPlayerStart(x, y);
                    break;

                case Grid::Tile::Tile::RStart:
                    builder.setRPlayerStart(x, y);
                    break;

                case Grid::Tile::Tile::Goal:
                    builder.setPlayerGoal(x, y);
                    break;

                case Grid::Tile::Tile::RGoal:
                    builder.setRPlayerGoal(x, y);
                    break;

                default: break;
                }
            }
        }

        return builder.build();
    }

    Grid::Tile::Tile LevelParser::charToTile(char c)
    {
        switch (c)
        {
        case '.': return Grid::Tile::Tile::Empty;
        case '#': return Grid::Tile::Tile::Wall;
        case 'P': return Grid::Tile::Tile::Start;
        case 'R': return Grid::Tile::Tile::RStart;
        case 'p': return Grid::Tile::Tile::Goal;
        case 'r': return Grid::Tile::Tile::RGoal;
        default:  throw(std::invalid_argument("Invalid tile character"));
        }
    }
}
