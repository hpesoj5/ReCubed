#pragma once

#include "IGameState.hpp"
#include "input/IInputObserver.hpp"
#include "ui/menus/PauseMenu.hpp"

class PauseState final : public IGameState, public Input::IInputObserver
{
public:
    PauseState(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState);

    void onEnter(Input::InputHandler& input) override;
    void onExit(Input::InputHandler& input) override;
    void update(float dt) override { m_menu.update(dt); }
    void draw(sf::RenderWindow& window) override { m_menu.draw(window); }

    bool onEscapePressed() override;

private:
    UI::Menu::PauseMenu m_menu;
    PopStateCallback m_popState;
};
