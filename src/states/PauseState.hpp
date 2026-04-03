#pragma once

#include "IGameState.hpp"
#include "input/IInputObserver.hpp"
#include "ui/menus/PauseMenu.hpp"

class PauseState final : public IGameState, public Input::IInputObserver
{
public:
    PauseState(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState, IGameState* playingState);

    void onEnter(Input::InputHandler& input) override;
    void onExit(Input::InputHandler& input) override;
    void update(float dt) override { m_menu.update(dt); }
    void draw(sf::RenderWindow& window) override;

    bool onEscapePressed() override;

private:
    IGameState* m_playingState;
    UI::Menu::PauseMenu m_menu;
    PopStateCallback m_popState;
};
