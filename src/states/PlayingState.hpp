#pragma once

#include "IGameState.hpp"
#include "entities/Player.hpp"
#include "grid/Grid.hpp"
#include <functional>
#include <memory>

namespace Input { class InputHandler; }
namespace sf { class RenderWindow; }

class PlayingState : public IGameState
{
public:
    using TransitionCallback = std::function<void(std::unique_ptr<IGameState>)>;

    PlayingState(int level, TransitionCallback onTransition);

    void onEnter(Input::InputHandler& input) override;
    void onExit(Input::InputHandler& input) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

private:
    Grid::Grid m_grid;
    int m_level;
    Player m_player;
    ReversePlayer r_player;

    TransitionCallback m_onTransition;
};
