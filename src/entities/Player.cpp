#include "Globals.hpp"
#include "Player.hpp"

PlayerBase::PlayerBase(const Vector2f& pos)
    : m_sprite{ sf::RectangleShape{ Vector2f(Globals::PLAYER_SIZE, Globals::PLAYER_SIZE) } }
{
    m_sprite.setOrigin(m_sprite.getSize() / 2.f);
    m_sprite.setPosition(pos);
}

Player::Player(const Vector2f& pos)
    : PlayerBase{ pos }
{
    m_sprite.setFillColor(Globals::PLAYER_COLOR);
}

ReversePlayer::ReversePlayer(const Vector2f& pos)
    : PlayerBase{ pos }
{
    m_sprite.setFillColor(Globals::REVERSE_PLAYER_COLOR);
}
