#include "Globals.hpp"
#include "Player.hpp"

PlayerBase::PlayerBase(const Vector2f& pos)
    : m_sprite{ sf::RectangleShape{ Vector2f(Globals::Player::SIZE, Globals::Player::SIZE) } }
{
    m_sprite.setOrigin(m_sprite.getSize() / 2.f);
    m_sprite.setPosition(pos);
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
