#pragma once

#include "IGameState.hpp"
#include "entities/Player.hpp"
#include "grid/Grid.hpp"

namespace Input { class InputHandler; }
namespace sf { class RenderWindow; }

class PlayingState : public IGameState
{
public:
    PlayingState(int level);

    void onEnter(Input::InputHandler& input) override;
    void onExit(Input::InputHandler& input) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    Grid::Grid m_grid;
    Player m_player;
    ReversePlayer r_player;
};
