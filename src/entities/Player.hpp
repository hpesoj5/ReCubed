#pragma once

#include "Globals.hpp"
#include "grid/Grid.hpp"
#include "input/IInputObserver.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

using sf::Vector2f;
using sf::Vector2i;

class PlayerBase : public Input::IInputObserver
{
public:
    explicit PlayerBase(Grid::Grid& grid);
    virtual ~PlayerBase() = default;

    // getters
    Vector2i getPosition() const { return m_pos; }
    bool outOfBounds() const { return !m_grid.inBounds(m_pos); }
    bool isAtGoal() const { return m_atGoal; }

    // position setters
    void resetGoal() { m_atGoal = false; }
    void setStartPosition(int x, int y) { m_startPos = Vector2i(x, y); }
    void setStartPosition(const Vector2i& pos) { m_startPos = pos; }
    void setPosition(int x, int y) { m_pos = Vector2i(x, y); m_sprite.setPosition(m_grid.coordsToVector2f(x, y)); }
    void setPosition(const Vector2i& pos) { m_pos = pos; m_sprite.setPosition(m_grid.coordsToVector2f(pos)); }
    void resetPosition() override { setPosition(m_startPos); }

    // actions
    void move(Globals::Direction dir); // calls virtual member function applyDirection
    void onDirectionInput(Globals::Direction dir) override { move(dir); }
    void draw(sf::RenderWindow& window) { window.draw(m_sprite); }

protected:
    Grid::Grid& m_grid;
    sf::RectangleShape m_sprite;
    Vector2i m_startPos;
    Vector2i m_pos;
    Grid::Tile::Tile m_goalTile;

    virtual Vector2i applyDirection(const Vector2i& delta) const = 0;

private:
    bool m_atGoal;
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
