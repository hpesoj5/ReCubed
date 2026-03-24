#include "Grid.hpp"
#include "Globals.hpp"

void Grid::Tile::setTileColor(sf::RectangleShape& sprite, Tile tile)
{
    switch (tile)
    {
    case Tile::Empty:
        sprite.setFillColor(Globals::Window::BG_COLOR);
        sprite.setOutlineColor(Globals::Game::GRID_LINE_COLOR);
        sprite.setOutlineThickness(-1.f);
        break;

    case Tile::Wall:
        sprite.setFillColor(sf::Color::Black);
        break;

    case Tile::Goal:
        sprite.setFillColor(Globals::Player::GOAL_COLOR);
        sprite.setOutlineColor(Globals::Game::GRID_LINE_COLOR);
        sprite.setOutlineThickness(-1.f);
        break;

    case Tile::RGoal:
        sprite.setFillColor(Globals::Player::REVERSE_GOAL_COLOR);
        sprite.setOutlineColor(Globals::Game::GRID_LINE_COLOR);
        sprite.setOutlineThickness(-1.f);
        break;

    default: break;
    }
}

Grid::Grid::Grid(int width, int height)
    : m_width { width }
    , m_height { height }
    , m_sprite { sf::RectangleShape(Vector2f(width * Globals::Game::GRID_CELL_SIZE, height * Globals::Game::GRID_CELL_SIZE)) }
{
    m_tiles.reserve(width); // x: horizontal axis, y: vertical axis
    for (int i {}; i < width; ++i)
        m_tiles.push_back(std::vector<Tile::Tile>(height, Tile::Tile::Empty));

    m_sprite.setOrigin(m_sprite.getSize() / 2.f);
    m_sprite.setPosition(Globals::Window::WIDTH / 2.f, Globals::Window::HEIGHT / 2.f);
    m_sprite.setFillColor(sf::Color::Transparent);
    m_sprite.setOutlineThickness(2.f);
    m_sprite.setOutlineColor(Globals::Window::FG_COLOR);
}


void Grid::Grid::draw(sf::RenderWindow& window)
{
    for (int i {}; i < m_width; ++i) for (int j {}; j < m_height; ++j)
    {
        sf::RectangleShape tileSprite(Vector2f(Globals::Game::GRID_CELL_SIZE, Globals::Game::GRID_CELL_SIZE));
        tileSprite.setOrigin(tileSprite.getSize() / 2.f);
        tileSprite.setPosition(coordsToVector2f(i, j));
        setTileColor(tileSprite, m_tiles[i][j]);
        //setTileTexture(tileSprite, tile);

        window.draw(tileSprite);
    }
    window.draw(m_sprite);
}

Vector2f Grid::Grid::coordsToVector2f(int x, int y) const
{
    float diffX { static_cast<float>(x) - (static_cast<float>(m_width) / 2.f - 0.5f) };
    float diffY { static_cast<float>(y) - (static_cast<float>(m_height) / 2.f - 0.5f) };

    Vector2f centerPos { m_sprite.getPosition() };

    return Vector2f(
        centerPos.x + (diffX * static_cast<float>(Globals::Game::GRID_CELL_SIZE)),
        centerPos.y + (diffY * static_cast<float>(Globals::Game::GRID_CELL_SIZE))
    );
}
