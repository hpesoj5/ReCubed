#pragma once

#include "states/IGameState.hpp"
#include "ui/Components.hpp"

namespace Input { class InputHandler; }

namespace UI::Menu
{
    class MainMenu final
    {
    public:
        MainMenu(TransitionCallback setState, TransitionCallback pushState, PopStateTransitionCallback popState);

        void subscribeTo(Input::InputHandler& input);
        void unsubscribeFrom(Input::InputHandler& input);
        void update(float dt);
        void draw(sf::RenderWindow& window);

    private:
        UI::Components::Label m_title;
        UI::Components::Button m_startButton;
        UI::Components::Button m_settingsButton;
        UI::Components::Button m_quitButton;
    };
}
