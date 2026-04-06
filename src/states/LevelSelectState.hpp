#pragma once

#include "IGameState.hpp"
#include "input/IInputObserver.hpp"
#include "ui/menus/LevelSelectMenu.hpp"

namespace Input { class InputHandler; }
namespace sf { class RenderWindow; }

class LevelSelectState final : public IGameState, public Input::IInputObserver
{
public:
    LevelSelectState(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState)
        : m_menu { setState, pushState, popState }
        , m_setState { setState }
        , m_popState { popState }
    {}

    void onEnter(Input::InputHandler& input) override;
    void onExit(Input::InputHandler& input) override;
    void update(float dt) override { m_menu.update(dt); }
    void draw(sf::RenderWindow& window) override { m_menu.draw(window); }

    bool onEscapePressed() override;

private:
    UI::Menu::LevelSelectMenu m_menu;
    TransitionCallback m_setState;
    PopStateCallback m_popState;
};
