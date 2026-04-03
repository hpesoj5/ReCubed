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
    Vector2f getGlobalPosition() const { return m_sprite.getPosition(); }
    bool outOfBounds() const { return !m_grid.inBounds(m_pos); }
    bool isAtGoal() const { return m_atGoal; }
    bool isAnimating() const { return m_animProgress < 1.f; }

    // position setters
    void resetGoal() { m_atGoal = false; }
    void setStartPosition(int x, int y) { m_startPos = Vector2i(x, y); }
    void setStartPosition(const Vector2i& pos) { m_startPos = pos; }
    void setPosition(int x, int y) { m_pos = Vector2i(x, y); m_sprite.setPosition(m_grid.coordsToVector2f(x, y)); }
    void setPosition(const Vector2i& pos) { m_pos = pos; m_sprite.setPosition(m_grid.coordsToVector2f(pos)); }
    void setTargetPosition(int x, int y) { m_targetPos = Vector2i(x, y); }
    void setTargetPosition(const Vector2i& pos) { m_targetPos = pos; }
    void resetPosition() override { setPosition(m_startPos); setTargetPosition(m_startPos); }

    // actions
    void move(Globals::Direction dir); // calls virtual member function applyDirection
    void onDirectionInput(Globals::Direction dir) override { if (!isAnimating()) move(dir); }
    void update(float dt);
    void draw(sf::RenderWindow& window) { window.draw(m_sprite); }

protected:
    sf::RectangleShape m_sprite;
    Grid::Tile::Tile m_goalTile;

    virtual Vector2i applyDirection(const Vector2i& delta) const = 0;

private:
    Grid::Grid& m_grid;
    Vector2i m_startPos;
    Vector2i m_pos;
    Vector2i m_targetPos;
    bool m_atGoal;
    float m_animProgress;
    static inline float animDuration { Globals::Animations::PLAYER_DURATION };
};



class Player final : public PlayerBase
{
public:
    explicit Player(Grid::Grid& grid);

protected:
    Vector2i applyDirection(const Vector2i& delta) const override { return delta; }
};



class ReversePlayer final : public PlayerBase
{
public:
    explicit ReversePlayer(Grid::Grid& grid);

protected:
    Vector2i applyDirection(const Vector2i& delta) const override { return -delta; }
};
