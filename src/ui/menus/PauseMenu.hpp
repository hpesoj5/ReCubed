#pragma once

#include "input/IInputObserver.hpp"
#include "states/IGameState.hpp"
#include "ui/Components.hpp"
#include <array>

namespace UI::Menu
{
    class PauseMenu final : public Input::IInputObserver
    {
    public:
        PauseMenu(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState);

        void subscribeTo(Input::InputHandler& input);
        void unsubscribeFrom(Input::InputHandler& input);
        void update(float dt);
        void draw(sf::RenderWindow& window);

        void onDirectionInput(Globals::Direction dir) override;
        void onMouseHover(const Vector2f& pos) override;
        bool onConfirm() override;

    private:
        UI::Components::Label m_pausedTitle;
        UI::Components::Button m_pauseButton;
        std::array<UI::Components::Button, 3> m_buttons;
        UI::Components::Button& m_resumeButton;
        UI::Components::Button& m_settingsButton;
        UI::Components::Button& m_quitButton;
        sf::RectangleShape m_overlay;
        Vector2f m_lastMousePos;
        int m_selectedIndex;
        bool m_active;
    };
}
