#pragma once

#include "Globals.hpp"
#include "input/InputObserver.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

using sf::Vector2f;
using sf::Vector2i;

class PlayerBase : public Input::InputObserver
{
public:
    PlayerBase(const Vector2f& pos);
    virtual ~PlayerBase() = default;

    sf::Vector2i getPosition() const { return Vector2fToCoord(m_sprite.getPosition()); }
    bool outOfBounds() const;
    void onDirectionInput(Globals::Direction dir) override { move(dir); }
    void move(Globals::Direction dir); // calls virtual member function applyDirection
    void setPosition(int x, int y) { m_sprite.setPosition(coordToVector2f(x, y)); }
    void setPosition(const Vector2i& pos) { setPosition(pos.x, pos.y); }
    void draw(sf::RenderWindow& window) { window.draw(m_sprite); }

protected:
    sf::RectangleShape m_sprite;

    virtual Vector2i applyDirection(const Vector2i& delta) const = 0;
};

class Player: public PlayerBase
{
public:
    Player(const Vector2f& pos=Vector2f(0, 0));

protected:
    Vector2i applyDirection(const Vector2i& delta) const override { return delta; }
};

class ReversePlayer: public PlayerBase
{
public:
    ReversePlayer(const Vector2f& pos=Vector2f(0, 0));

protected:
    Vector2i applyDirection(const Vector2i& delta) const override { return -delta; }
};
