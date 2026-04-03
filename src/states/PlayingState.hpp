#pragma once

#include "IGameState.hpp"
#include "entities/Player.hpp"
#include "grid/Grid.hpp"
#include "input/IInputObserver.hpp"
#include "ui/components/Button.hpp"

namespace Input { class InputHandler; }
namespace sf { class RenderWindow; }

class PlayingState final : public IGameState, public Input::IInputObserver
{
public:
    PlayingState(int level, TransitionCallback setState, TransitionCallback pushState, PopStateTransitionCallback popState);

    void onEnter(Input::InputHandler& input) override;
    void onExit(Input::InputHandler& input) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;
    void onEscapePressed() override;

private:
    Grid::Grid m_grid;
    int m_level;
    Player m_player;
    ReversePlayer r_player;
    UI::Components::Button m_pauseButton;

    TransitionCallback m_setState;
    TransitionCallback m_pushState;
    PopStateTransitionCallback m_popState;
};
