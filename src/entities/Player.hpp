#pragma once

#include "Globals.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

using sf::Vector2f;

class PlayerBase
{
public:
    PlayerBase(const Vector2f& pos);
    virtual ~PlayerBase() = default;

    virtual void move(const Vector2f& dir) = 0;

protected:
    sf::RectangleShape m_sprite;
};

class Player: public PlayerBase
{
public:
    Player(const Vector2f& pos=Vector2f(0, 0));

    void move(const Vector2f& dir) override;

private:
};

class ReversePlayer: public PlayerBase
{
public:
    ReversePlayer(const Vector2f& pos=Vector2f(0, 0));

    void move(const Vector2f& dir) override;

private:
};
