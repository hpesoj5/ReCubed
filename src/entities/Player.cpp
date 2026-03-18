#include "Globals.hpp"
#include "Player.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <stdexcept>

using sf::Vector2f;
using sf::Vector2i;

PlayerBase::PlayerBase(const Vector2f& pos)
    : m_sprite{ sf::RectangleShape{ Vector2f(Globals::Player::SIZE, Globals::Player::SIZE) } }
{
    m_sprite.setOrigin(m_sprite.getSize() / 2.f);
    m_sprite.setPosition(pos);
}

bool PlayerBase::outOfBounds() const
{
    return ::outOfBounds(getPosition());
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
    default: throw std::invalid_argument("Invalid Direction");
    }

    Vector2i newPos { currPos + applyDirection(delta) };
    if (!::outOfBounds(newPos))
        setPosition(newPos);

    // future: check for collision with other player and all obstacles
}



Player::Player(const Vector2f& pos)
    : PlayerBase{ pos }
{
    m_sprite.setFillColor(Globals::Player::COLOR);
}



ReversePlayer::ReversePlayer(const Vector2f& pos)
    : PlayerBase{ pos }
{
    m_sprite.setFillColor(Globals::Player::REVERSE_COLOR);
}
