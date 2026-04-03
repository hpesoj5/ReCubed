#pragma once

#include "IGameState.hpp"
#include "input/InputHandler.hpp"
#include "ui/menus/MainMenu.hpp"

class MainMenuState final : public IGameState
{
public:
    MainMenuState(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState)
        : m_menu { setState, pushState, popState }
    {}

    void onEnter(Input::InputHandler& input) override { m_menu.subscribeTo(input); }
    void onExit(Input::InputHandler& input) override { m_menu.unsubscribeFrom(input); }
    void update(float dt) override { m_menu.update(dt); }
    void draw(sf::RenderWindow& window) override { m_menu.draw(window); }

private:
    UI::Menu::MainMenu m_menu;
};
