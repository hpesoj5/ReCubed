#pragma once

#include "IGameState.hpp"
#include "input/InputHandler.hpp"
#include "ui/menus/MainMenu.hpp"
#include <functional>
#include <memory>

class MainMenuState final : public IGameState
{
public:
    using TransitionCallback = std::function<void(std::unique_ptr<IGameState>)>;
    MainMenuState(TransitionCallback onTransition)
        : m_menu { onTransition }
    {}

    void onEnter(Input::InputHandler& input) override { m_menu.subscribeTo(input); }
    void onExit(Input::InputHandler& input) override { m_menu.unsubscribeTo(input); }
    void update(float dt) override { m_menu.update(dt); }
    void draw(sf::RenderWindow& window) override { m_menu.draw(window); }

private:
    UI::Menu::MainMenu m_menu;
};
