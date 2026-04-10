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
    PlayingState(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState, int level);

    void onEnter(Input::InputHandler& input) override;
    void onExit(Input::InputHandler& input) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;
    bool onEscapePressed() override;

private:
    Grid::Grid m_grid;
    Player m_player;
    ReversePlayer r_player;
    UI::Components::Button m_pauseButton;

    TransitionCallback m_setState;
    TransitionCallback m_pushState;
    PopStateCallback m_popState;
    int m_level;
};
