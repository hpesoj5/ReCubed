#pragma once

#include "states/IGameState.hpp"
#include "ui/Components.hpp"

namespace UI::Menu
{
    class PauseMenu final
    {
    public:
        PauseMenu(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState);

        void subscribeTo(Input::InputHandler& input);
        void unsubscribeFrom(Input::InputHandler& input);
        void update(float dt);
        void draw(sf::RenderWindow& window);

    private:
        UI::Components::Label m_pausedTitle;
        UI::Components::Button m_pauseButton;
        UI::Components::Button m_resumeButton;
        UI::Components::Button m_settingsButton;
        UI::Components::Button m_quitButton;
        sf::RectangleShape m_overlay;
    };
}
