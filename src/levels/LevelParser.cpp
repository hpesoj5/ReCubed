#include "LevelParser.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace Levels
{
    LevelData LevelParser::parse(const std::string& filepath)
    {
        std::ifstream file(filepath);

        if (!file)
        {
            std::ostringstream err;
            err << "Error opening file " << filepath;
            throw std::runtime_error(err.str()); // throws for now, will have a better alternative later on
        }

        std::string line;
        std::vector<std::string> lines;

        while (std::getline(file >> std::ws, line))
            lines.push_back(line);

        int height { static_cast<int>(lines.size()) };
        int width {};
        try { width = static_cast<int>(lines.at(0).size()); }
        catch (const std::out_of_range& e)
        {
            std::ostringstream err;
            err << "File " << filepath << " is empty";
            throw std::out_of_range(err.str());
        }

        LevelBuilder builder;
        builder.setDimensions(width, height);

        bool startExists {};
        bool rStartExists {};
        bool goalExists {};
        bool rGoalExists {};

        for (int y {}; y < height; ++y)
        {
            for (int x {}; x < width; ++x)
            {
                Grid::Tile::Tile tile;

                try { tile = charToTile(lines.at(y).at(x)); }
                catch (const std::out_of_range& e)
                {
                    std::ostringstream err;
                    err << "File " << filepath << ": tile at column " << x << " and row " << y << " can't be read";
                    throw std::out_of_range(err.str());
                }
                catch (const std::invalid_argument& e)
                {
                    std::ostringstream err;
                    err << "File " << filepath << ": tile at column " << x << " and row " << y << " has an invalid character";
                    throw std::invalid_argument(err.str());
                }

                if (tile != Grid::Tile::Tile::Empty)
                    builder.setTile(x, y, tile);

                switch (tile)
                {
                case Grid::Tile::Tile::Start:
                    if (startExists)
                    {
                        std::ostringstream err;
                        err << "File " << filepath << ": start tile already exists";
                        throw std::runtime_error(err.str());
                    }
                    startExists = true;
                    builder.setPlayerStart(x, y);
                    break;

                case Grid::Tile::Tile::RStart:
                    if (rStartExists)
                    {
                        std::ostringstream err;
                        err << "File " << filepath << ": rstart tile already exists";
                        throw std::runtime_error(err.str());
                    }
                    rStartExists = true;
                    builder.setRPlayerStart(x, y);
                    break;

                case Grid::Tile::Tile::Goal:
                    if (goalExists)
                    {
                        std::ostringstream err;
                        err << "File " << filepath << ": goal tile already exists";
                        throw std::runtime_error(err.str());
                    }
                    goalExists = true;
                    builder.setPlayerGoal(x, y);
                    break;

                case Grid::Tile::Tile::RGoal:
                    if (rGoalExists)
                    {
                        std::ostringstream err;
                        err << "File " << filepath << ": rgoal tile already exists";
                        throw std::runtime_error(err.str());
                    }
                    rGoalExists = true;
                    builder.setRPlayerGoal(x, y);
                    break;

                default: break;
                }
            }
        }

        if (!startExists || !rStartExists || !goalExists || !rGoalExists)
        {
            std::ostringstream err;
            err << "File" << filepath << ": one of [start, rstart, goal, rgoal] does not exist";
            throw std::runtime_error(err.str());
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
