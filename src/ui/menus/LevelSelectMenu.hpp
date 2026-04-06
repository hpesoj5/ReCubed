#pragma once

#include "input/IInputObserver.hpp"
#include "states/IGameState.hpp"
#include "ui/Components.hpp"
#include <vector>

namespace UI::Menu
{
    class LevelSelectMenu final : public Input::IInputObserver
    {
    public:
        LevelSelectMenu(TransitionCallback setState, TransitionCallback pushState, PopStateCallback popState);

        void subscribeTo(Input::InputHandler& input);
        void unsubscribeFrom(Input::InputHandler& input);
        void update(float /* dt */);
        void draw(sf::RenderWindow& window);

        void onDirectionInput(Globals::Direction dir) override;
        void onMouseHover(const Vector2f& pos) override;
        bool onConfirm() override;

    private:
        UI::Components::Label m_title;
        std::vector<UI::Components::Button> m_levelButtons;
        Vector2f m_lastMousePos;
        int m_selectedIndex;
        bool m_active;

        // no page buttons for now
    };
}
