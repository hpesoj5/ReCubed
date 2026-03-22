#pragma once

#include "Globals.hpp"
#include "grid/Grid.hpp"
#include "input/InputObserver.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

using sf::Vector2f;
using sf::Vector2i;

class PlayerBase : public Input::InputObserver
{
public:
    explicit PlayerBase(Grid::Grid& grid);
    virtual ~PlayerBase() = default;

    Vector2i getPosition() const { return m_pos; }
    bool outOfBounds() const;
    void onDirectionInput(Globals::Direction dir) override { move(dir); }
    void move(Globals::Direction dir); // calls virtual member function applyDirection
    void setPosition(int x, int y) { m_pos = Vector2i(x, y); m_sprite.setPosition(m_grid.coordsToVector2f(x, y)); }
    void setPosition(const Vector2i& pos) { m_pos = pos; m_sprite.setPosition(m_grid.coordsToVector2f(pos)); }
    void draw(sf::RenderWindow& window) { window.draw(m_sprite); }

protected:
    Grid::Grid& m_grid;
    sf::RectangleShape m_sprite;
    Vector2i m_pos;

    virtual Vector2i applyDirection(const Vector2i& delta) const = 0;
};

class Player: public PlayerBase
{
public:
    explicit Player(Grid::Grid& grid);

protected:
    Vector2i applyDirection(const Vector2i& delta) const override { return delta; }
};

class ReversePlayer: public PlayerBase
{
public:
    explicit ReversePlayer(Grid::Grid& grid);

protected:
    Vector2i applyDirection(const Vector2i& delta) const override { return -delta; }
};
