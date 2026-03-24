#include "Globals.hpp"
#include "Player.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

using sf::Vector2f;
using sf::Vector2i;

PlayerBase::PlayerBase(Grid::Grid& grid)
    : m_grid { grid }
    , m_sprite{ sf::RectangleShape{ Vector2f(Globals::Player::SIZE, Globals::Player::SIZE) } }
    , m_pos{ 0, 0 }
{
    m_sprite.setOrigin(m_sprite.getSize() / 2.f);
    setPosition(m_pos);

    m_sprite.setOutlineThickness(-2.f);
    m_sprite.setOutlineColor(Globals::Colors::PLAYER_OUTLINE);
}

void PlayerBase::move(Globals::Direction dir)
{
    Vector2i currPos { getPosition() };
    Vector2i delta;

    switch (dir)
    {
    case Globals::Direction::Up:    delta = {  0, -1 }; break;
    case Globals::Direction::Down:  delta = {  0,  1 }; break;
    case Globals::Direction::Left:  delta = { -1,  0 }; break;
    case Globals::Direction::Right: delta = {  1,  0 }; break;
    }

    Vector2i newPos { currPos + applyDirection(delta) };
    if (m_grid.inBounds(newPos) && !m_grid.isWall(newPos))
    {
        m_pos = newPos;
        setPosition(newPos);
    }

    if (m_grid.isTile(m_pos, m_goalTile))
        m_atGoal = true;
    else
        m_atGoal = false;

    // future: check for collision with other entities excluding other player
}



Player::Player(Grid::Grid& grid)
    : PlayerBase{ grid }
{
    m_sprite.setFillColor(Globals::Colors::PLAYER);
    m_goalTile = Grid::Tile::Tile::Goal;
}



ReversePlayer::ReversePlayer(Grid::Grid& grid)
    : PlayerBase{ grid }
{
    m_sprite.setFillColor(Globals::Colors::RPLAYER);
    m_goalTile = Grid::Tile::Tile::RGoal;
}
